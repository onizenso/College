#include <iostream>
#include <string>
#include "cmps222lib.h"  

ofstream LOGFILE;


#include "person.h"


int main()
{
LOGFILE.open("hw05.log",ios::trunc);
if (LOGFILE.is_open())
  LOGFILE << POS_IN_PROGRAM << "start of logging" << endl;
else 
  {
  cout << "Unable to open file for logging.";
  return 1;
  }


person p1,p2,p3,p4,p5;
string temp= "supersuperduperextralonglastnameandthensomemore";

cout << "Test SetFName"<<endl;

cout << " Setting fname to \"" << temp << "\" : ";

if ( p1.SetFName(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;

temp ="somethingwitha:in it";
cout << " Setting fname to \"" << temp << "\" : ";

if ( p1.SetFName(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;

temp ="Clinton";
cout << " Setting fname to \"" << temp << "\" : ";

if ( p1.SetFName(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;

//---------------------------------------------------------------------

cout << endl <<endl << "Test SetMInitial"<<endl;

temp= "supersuperduperextralonglastnameandthensomemore";
cout << " Setting m_initial to \"" << temp << "\" : ";

if ( p1.SetMInitial(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;

temp ="somethingwitha:in it";
cout << " Setting m_initial to \"" << temp << "\" : ";

if ( p1.SetMInitial(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;

temp ="J";
cout << " Setting m_initial to \"" << temp << "\" : ";

if ( p1.SetMInitial(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;

//------------------------------------------------------------------


cout << endl <<endl << "Test SetLName"<<endl;

temp= "supersuperduperextralonglastnameandthensomemore";
cout << " Setting l_name to \"" << temp << "\" : ";

if ( p1.SetLName(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;

temp ="somethingwitha:in it";
cout << " Setting l_name to \"" << temp << "\" : ";

if ( p1.SetLName(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;

temp ="Eastwood";
cout << " Setting l_name to \"" << temp << "\" : ";

if ( p1.SetLName(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;

//------------------------------------------------------------------

cout << endl <<endl << "Test SetPhone"<<endl;

temp= "123456789012345678";
cout << " Setting phone to \"" << temp << "\" : ";

if ( p1.SetPhone(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;

temp ="1234:364";
cout << " Setting phone to \"" << temp << "\" : ";

if ( p1.SetPhone(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;

temp ="(559)551212";
cout << " Setting phone to \"" << temp << "\" : ";

if ( p1.SetPhone(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;


temp ="(559)555-1212";
cout << " Setting phone to \"" << temp << "\" : ";

if ( p1.SetPhone(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;


//------------------------------------------------------------------
//
cout << endl <<endl << "Test SetAddress1"<<endl;

temp= "supersuperduperextralonglastnameandthensomemore";
cout << " Setting Address1 to \"" << temp << "\" : ";

if ( p1.SetAddress1(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;

temp ="1234:364";
cout << " Setting Address1 to \"" << temp << "\" : ";

if ( p1.SetAddress1(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;

temp ="123 really nice street";
cout << "Setting Address1 to \"" << temp << "\" : ";

if ( p1.SetAddress1(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;


//------------------------------------------------------------------


cout << endl <<endl << "Test SetAddress2"<<endl;

temp= "supersuperduperextralonglastnameandthensomemore";
cout << " Setting Address2 to \"" << temp << "\" : ";

if ( p1.SetAddress2(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;

temp ="1234:364";
cout << " Setting Address2 to \"" << temp << "\" : ";

if ( p1.SetAddress2(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;

temp ="2nd address line";
cout << "Setting Address2 to \"" << temp << "\" : ";

if ( p1.SetAddress2(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;


//------------------------------------------------------------------
cout << endl <<endl << "Test SetCity"<<endl;

temp= "supersuperduperextralonglastnameandthensomemore";
cout << " Setting City to \"" << temp << "\" : ";

if ( p1.SetCity(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;

temp ="1234:364";
cout << " Setting City to \"" << temp << "\" : ";

if ( p1.SetCity(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;

temp ="Carmel";
cout << "Setting City to \"" << temp << "\" : ";

if ( p1.SetCity(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;


//------------------------------------------------------------------

cout << endl <<endl << "Test SetState"<<endl;

temp= "supersuperduperextralonglastnameandthensomemore";
cout << " Setting State to \"" << temp << "\" : ";

if ( p1.SetState(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;

temp ="1234:364";
cout << " Setting State to \"" << temp << "\" : ";

if ( p1.SetState(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;

temp ="Ca";
cout << "Setting State to \"" << temp << "\" : ";

if ( p1.SetState(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;


//------------------------------------------------------------------

cout << endl <<endl << "Test SetState"<<endl;

temp= "supersuperduperextralonglastnameandthensomemore";
cout << " Setting zip to \"" << temp << "\" : ";

if ( p1.SetZip(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;

temp ="1234:364";
cout << " Setting zip to \"" << temp << "\" : ";

if ( p1.SetZip(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;

temp ="93257";
cout << "Setting zip to \"" << temp << "\" : ";

if ( p1.SetZip(temp) )
	cout << "OK" << endl;
else
	cout << "FAILED" << endl;


//------------------------------------------------------------------


cout << endl << endl << "Test FormatedName() " << endl;
cout << "formatted name: " << endl << p1.FormattedName() << endl;

cout << endl << endl << "Test ToString() " << endl;

cout << p1.ToString() << endl;


cout << endl << endl << "Test ToColonDelimited() " << endl;

cout << p1.ToColonDelimited() << endl;



}
