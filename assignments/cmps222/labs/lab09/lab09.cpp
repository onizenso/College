#include <iostream>
#include <string>
#include "cmps222lib.h"  

ofstream LOGFILE;
#include "person.h"






int main()
{
LOGFILE.open("lab09.log",ios::trunc);
if (LOGFILE.is_open())
  LOGFILE << POS_IN_PROGRAM << "start of logging" << endl;
else 
  {
  cout << "Unable to open file for logging.";
  return 1;
  }

cout << endl<< endl;

person p1,p2,p3,p4;


p1.SetFName("Homer");
p1.SetMInitial("J");
p1.SetLName("Simpson");
p1.SetPhone("(559)555-1212");
p1.SetAddress1("742 Evergreen Terrace");
p1.SetAddress2("");
p1.SetCity("Springfield");
p1.SetState("Ga");
p1.SetZip("31329");

cout << "p1.ToString(): " << endl << p1.ToString();

p2.SetFName("Barny");
p2.SetMInitial("");
p2.SetLName("Gumble");
p2.SetPhone("(559)555-8899");
p2.SetAddress1("93 Super Lush Ct");
p2.SetAddress2("");
p2.SetCity("Springfield");
p2.SetState("Ga");
p2.SetZip("31329");
cout << endl<< endl;
cout << "p2.ToString(): " << endl << p2.ToString();

p3.SetFName("Moe");
p3.SetMInitial("");
p3.SetLName("Syzlak");
p3.SetPhone("(559)555-4856");
p3.SetAddress1("1024 Peanut St");
p3.SetAddress2("");
p3.SetCity("Springfield");
p3.SetState("Ga");
p3.SetZip("58008");
cout << endl<< endl;
cout << "p3.ToString(): " << endl << p3.ToString();

cout << endl<< endl;
cout << "Sort Accending" << endl;
// sort accending
if (p1 > p2) swap (p1,p2);
if (p2 > p3) swap (p2,p3);
if (p1 > p2) swap (p1,p2);
cout << p1.FormattedName() << endl;
cout << p2.FormattedName() << endl;
cout << p3.FormattedName() << endl;


cout << endl<< endl;
cout << "Sort Decending" << endl;
// sort decending
if (p1 < p2) swap (p1,p2);
if (p2 < p3) swap (p2,p3);
if (p1 < p2) swap (p1,p2);
cout << p1.FormattedName() << endl;
cout << p2.FormattedName() << endl;
cout << p3.FormattedName() << endl;

cout << "test the assignment" << endl;

cout << endl<< "p1.ToString()" << endl << p1.ToString() << endl;
cout <<"p4 = p1"<< endl;
p4 = p1;
cout << endl<< "p4.ToString()" << endl << p4.ToString() << endl;
cout <<"p4 = p2"<< endl;
p4 = p2;
cout << endl<< "p4.ToString()" << endl << p4.ToString() << endl;
//------------------------------------------------------------------

LOGFILE.close();
return 0;
}
