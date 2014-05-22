/*
*  Nik Ramsey
*  CMPS 222
*  Spring 2011
*/
#include "cmps222lib.h"  

ofstream LOGFILE;

/* person struct */

struct person
{
    string fname;
    string lname;
    int age;
};

/* 
 * parameter person struct
 * return void
 * output to the console a the person firstname + SPACE+ lastname
 * as well as age ex.
 * Name: Albert Brooks
 * Age: 48
 */
void PrintPerson(person input);

    
    
    
    
 /*
 * parameter struct person *
 * return void
 * Prompt the user for "Enter First Name: ", "Enter Last Name: " & "Enter Age: "
 * store the values in the struct
 */
void PopulatePerson( person * input);





/* compare person names for sorting in alphabetical order
 * parameter struct person  a & b
 * return int    if (person a < person b ) return a non-zero value
 * all other cases return 0
 * compare by lastname and if necessary firstname
 */
int ComparePersonName( person a, person b);





// your functions or file includes

int main()
{
LOGFILE.open("lab06.log",ios::trunc);
if (LOGFILE.is_open())
  LOGFILE << POS_IN_PROGRAM << "start of logging" << endl;
else 
  {
  cout << "Unable to open file for logging.";
  return 1;
  }
	
person a,b,c;

PopulatePerson( &a);
cout << endl;

PopulatePerson( &b);
cout << endl;

PopulatePerson( &c);
cout << endl;


cout <<"Print out the persons"<<endl;
PrintPerson(a);
PrintPerson(b);
PrintPerson(c);

cout << endl;

if (! ComparePersonName(a,b))
    swap(a,b);

if (! ComparePersonName(b,c))
    swap(b,c);

if (! ComparePersonName(a,b))
    swap(a,b);

cout <<"Print out the persons in order, testing the compare function"<<endl;
PrintPerson(a);
PrintPerson(b);
PrintPerson(c);

// close the logfile and exit
LOGFILE.close();
return 0;
}


void PopulatePerson( person * input)
{
  LOGFILE << POS_IN_PROGRAM << "start of PopulatePerson(person*)" << endl;
    cout<<endl;
    cout<<"Enter First Name: ";
    getline (cin,input->fname);
    cout<<endl;
    cout<<"Enter Last Name: ";
    getline(cin,input->lname);
    cout<<endl;
    cout<<"Enter Age: ";
    cin>>input->age;
    cin.ignore();
  LOGFILE << POS_IN_PROGRAM << "end of PopulatePerson(person*)" << endl;
} 

void PrintPerson(person input)
{
  LOGFILE << POS_IN_PROGRAM << "start of PrintPerson(person)" << endl;
    cout<<"Name: " << input.fname << " " << input.lname << endl;
    cout<<"Age: " << input.age;
    cout<<endl<<endl;
  LOGFILE << POS_IN_PROGRAM << "end of PrintPerson(person)" << endl;
}


int ComparePersonName( person a, person b)
{
  LOGFILE << POS_IN_PROGRAM << "start of ComparePerson(person a, person b)" << endl;
    if(a.fname<b.fname)
	return 88;
    else if(a.fname==b.fname && a.lname<b.lname)
	return 88;
    else
	return 0;
  LOGFILE << POS_IN_PROGRAM << "end of ComparePerson(person a, person b)" << endl;
}

