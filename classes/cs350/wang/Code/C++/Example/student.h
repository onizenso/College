// class definition for a simple student database

#include <iostream>
#include <iomanip>
#include <fstream>

#include <stdlib.h>
#include "string.h"

using namespace std;

const unsigned int MAXLIST = 20;

/*-----------------Abstract Base Classes -----------------------------*/

class Item {

public:
    virtual ~Item() {}    /* since destructors are not inherited 
                             a virtual destructor should be declared in any
                             base class used for polymorphism  */
    virtual void Display () = 0;
};


class List {

public:
   virtual ~List() {}
   virtual void Add (Item *) {} 
   virtual void Remove () = 0;
   virtual int Size() = 0;
   virtual bool Full() = 0;
   virtual bool Empty() = 0;
   virtual void Clear() = 0;
};
/*-----------------------------------------------------------------*/
class Course: public Item {

public:
        ~Course() { } 
	Course() { credits=0; gpts = 0;}

	Course(String &n, float c, float g) 
                        { name=n; credits=c; gpts=g; }

	Course(Course *c)   // copy constructor
                        { name=c->name; credits=c->credits; gpts=c->gpts; }

	void setCourse (const String &n, float c, float g) 
                        { name=n; credits=c; gpts=g; }

	String getName() const { return name; }
	float getCredits() const { return credits; }
	float getGpts() const { return gpts; }

        void Display () { cout << "Display in Derived Class"; }
	friend ostream & operator <<  ( ostream &, Course *);
	friend istream & operator >> ( istream &, Course *);

private:
	String name;
	float credits;
	float gpts;
};

class CourseList: public List {

public:
	CourseList() {index = 0; }
	CourseList(const CourseList &);
       	~CourseList() { Clear(); }

        // implementations of abstract base class members
       	void Add(Item *);
      	void Remove();
      	bool Empty() { return index == 0; }
   	bool Full() { return index == MAXLIST; }
	int Size() { return index; }
      	void Clear();

      	//const Course &  getCourse ( int pos ) { return *(course[pos]); }
      	Course *  getCourse ( int pos ) { return course[pos]; }
	friend ostream & operator << ( ostream &, CourseList &);

private:
	int index;
	Course * course[ MAXLIST ];
};

class Student {

protected:
	Student() { }
        virtual ~Student() { }
	Student ( String & n, long id)   { name = n; ID = id; }
public:
	void setStudent ( String &n, long id ) { name = n; ID = id;}
        const String & getName () { return name; } 
        void setName (const String & n) { name = n; } 
        long getID ()  { return ID; }
        void setID (long id)  { ID = id; }
	void Display() const;
     
	friend istream & operator >> ( istream &, Student *);

private:
	String name;
	long ID;
};

class StudentRecord :public Student, public Item {
 
public:
	StudentRecord () 
	   { totcredits = 0; totgpts = 0, GPA = 0;}

	StudentRecord(String &name, long id) :Student(name, id)
	   { totcredits = 0; totgpts = 0, GPA = 0;}

	StudentRecord (StudentRecord *s);       // copy constructor

	float getTotGpts () { return totcredits; }
	float getTotCredits () { return totcredits; }
	float getGPA() { return GPA; }
 	void  AddCourse (Course *);	

        void Display() {cout << "Display in StudentRecord class"; }
	const StudentRecord & getStudent() const { return *this; }

	friend ostream & operator << ( ostream &, StudentRecord *);
	friend istream & operator >> ( istream &, StudentRecord *);

private:
	float totcredits;
	float totgpts;
	float GPA;
	CourseList clist;
};

class StudentList {

public:
	StudentList() {index = 0; }
	StudentList(const StudentList &);
       	~StudentList() {}
        void Input ();

        void Add(Item *);
        void Remove();
        bool Empty() { return index == 0; }
        bool Full() { return index == MAXLIST; }
        int Size() { return index; }
        void Clear();

      	StudentRecord *  getStudent ( int pos ) { return student[pos]; }
	friend ostream & operator << (ostream &, StudentList &);

private:
	int index;
	StudentRecord * student[ MAXLIST ];
};
