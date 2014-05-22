#include <iostream>
#include <fstream>

using namespace std;
ofstream LOGFILE;



#include "t_stack.h"
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





 t_stack<person> person_stack;

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



cout << "Adding p1, p2, p3 to the stack" << endl;

person_stack.push(p1);
person_stack.push(p2);
person_stack.push(p3);


cout << endl;
cout << "While (! person_stack.isEmpty() )   call pop and then toString() on the value returned" << endl;
while (! person_stack.isEmpty() )
  cout << person_stack.pop().ToString() << endl;

cout << endl;


cout << "Adding p1, p2, p3 to the stack again" << endl;

person_stack.push(p1);
person_stack.push(p2);
person_stack.push(p3);

cout << "before sort " << endl;
cout << person_stack[0].ToString() << endl;
cout << person_stack[1].ToString() << endl;
cout << person_stack[2].ToString() << endl;
cout << endl;


person_stack.sort();
cout << "after sort " << endl;
cout << person_stack[0].ToString() << endl;
cout << person_stack[1].ToString() << endl;
cout << person_stack[2].ToString() << endl;
cout << endl;




cout << "end of main" << endl;

LOGFILE.close();
return 0;
}

