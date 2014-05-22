/* 	Filename: 	student.cpp
	Purpose:	implementation of Student Registration System */

#include "student.h"
#include "exception.h"    // error handling classes

/*----------------------- Student Class------------------------------*/

void Student::Display() const
{
   cout << ID << "\t" << name << endl;
}

/*-------------------  StudentRecord   -------------------------------*/

StudentRecord::StudentRecord (StudentRecord *s):clist(s->clist)       
// copy constructor
{ 
   totcredits = s->totcredits; 
   totgpts = s->totgpts;
   GPA = s->GPA; 
   // set the values in the base class 
   setName(s->getName()); 
   setID(s->getID());
}

void StudentRecord::AddCourse( Course * c)
{ 
  clist.Add(c);
  totcredits += c->getCredits();
  totgpts += c->getGpts();
  if (totcredits != 0) GPA = totgpts/totcredits;
}

/*-----------------  StudentList Class   -------------------------------*/

StudentList::StudentList (const StudentList & s)   //  copy constructor
 {
	for( int x = 0; x < s.index; x++ )
	{
	   // get new object and call StudentRecord copy constructor
	   student[x] = new StudentRecord(s.student[x]);
	}
	index = s.index;
 }

void StudentList::Add(Item *s)
{
   try {
      if (index >= MAXLIST)
         throw RangeError( __FILE__ ,__LINE__, index );
      else {
         // call StudentRecord copy constructor and cast s to StudentRecord 
         student[index] = new StudentRecord((StudentRecord *)s); 
         index = index+1;
      }
   }

   // the catch block must immediately follow the try block 
   catch ( const RangeError & R ) {
      cout << R;
      throw R;
      // it makes no sense to put code after the throw!!
   } 
cout << "This line in StudentList::Add is executed if the exception is \n" << 
         "NOT thrown back to main or if there was no exception...\n\n";
}

void StudentList::Remove()
{
    if( Empty() )
        cout << "List is empty!" << endl;
    else {
	delete student[--index];
	 }
}

void StudentList::Clear()
{
	int x;
        for (x=0; x < index; x++)
           delete student[index];
        index = 0;
}

void StudentList::Input( )
{
  // temp input objects...

  char ch;
  StudentRecord * sr = new StudentRecord;
  Course * c = new Course;

/*  open input file with the following format:

	S 12345 MilongPell
	C Poli Sci 5 20
	C History 101 5 15
	C Chemistry 5 5 10
	S 23456 PennlookJanezz
	C Pysch 300 101 5 15

*/
   char * fname = "data"; 
   ifstream infile ( fname );
   try {
     if( !infile ) {
        throw FileOpenError( __FILE__ ,__LINE__, fname );
      } 
   } 
   catch ( const FileOpenError & F ) {
      throw F;   // you need to throw it back to main...
   } 
   cout << "The remaining code is executed if you don't throw back to main.." 
        << endl; 
  // read a line at a time of StudentRecords and associated courses
   infile.get(ch);
   while ( ! infile.eof() ) 
   {
      if (ch == 'S')
      {
         infile >> sr;
         Add( sr );
      }
      else 
         if (ch == 'C') {
           infile >> c; 
           student[index-1]->AddCourse( c );
         }
      
      infile.get(ch);
   }
   infile.close();
   delete c;
   delete sr;
}
/*------------------ CourseList Class -------------------------------*/

CourseList::CourseList(const CourseList & c)   // copy constructor
 {
	for( int x = 0; x < c.index; x++ )
	{
	   course[x] = new Course;
	   *(course[x]) = *(c.course[x]);
	}
	index = c.index;
 }

void CourseList::Add(Item *c)
{
   try {
      if (index >= MAXLIST)
         throw RangeError( __FILE__ ,__LINE__, index );
      else {
         course[index] = new Course((Course *)c);
         index++;
       }
    }
   catch ( const RangeError & R ) {
      cout << R;
      throw R;
   } 
}

void CourseList::Remove()
{
    if( Empty() )
        cout << "List is empty!" << endl;
    else {
	delete course[--index];
	 }
}

void CourseList::Clear()
{
	int x;
        for (x=0; x < index; x++)
           delete course[index];
        index = 0;
}

/* -------------------Overloaded Output Operators -------------------------*/

ostream & operator << (ostream &os,  Course * c)
{
  os << setw(15) << c->name << setw(8) << c->credits << setw(9) 
     << c->gpts  << endl;
  return os; 
}

ostream & operator << (ostream & os, CourseList & cl)
{
  for (int i = 0; i < cl.Size(); i++)
     os << (Course *) cl.getCourse(i);  
  return os; 
}

ostream & operator << (ostream & os, StudentRecord * s)

/*  Note: another way to access info from base class is to cast 's' to
    Student class and overload << for Student  */

{
  os << s->getName() << " " << s->getID() << "  TotalCredits: " 
     <<  s->totcredits 
     << "  TotalGradePts: " << s->totgpts << "  GPA: " << setprecision(2) 
     << s->GPA << endl << endl;
  os << setw(15) << "Courses" << setw(8) << "Credits" << setw(9) << "GradePts" << endl;
  os << setw(15) << "=======" << setw(8) <<  "=======" << setw(9) << "========" << endl;
  os << s->clist << endl << endl; 
  return os; 
}

ostream & operator << (ostream & os, StudentList & sl)
{
  for (int i = 0; i < sl.index; i++)
     os << (StudentRecord *) sl.getStudent(i);  
     os << endl;
  return os; 
}

/* -------------------Overloaded Input Operators -------------------------*/

istream & operator >> (istream & is,  Course * c)
{
  is >> c->name >> c->credits >> c->gpts;
  return is; 
}


istream & operator >> ( istream & is, Student * s)
{
  is >> s->ID >> s->name; 
  return is; 
}

istream & operator >> ( istream & is, StudentRecord * s)
{
  is >> (Student *) s;    // input Student data
  return is; 
}
