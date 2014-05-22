#include <iostream>
#include <fstream>
#include "cmps222lib.h"

using namespace std;
ofstream LOGFILE;



#include "t_stack.h"

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





cout << "create a stack of type int" << endl;

 t_stack<int> int_stack;



cout << "push a bunch of int to the stack" << endl;

int_stack.push(36);
int_stack.push(16);
int_stack.push(26);
int_stack.push(11);
int_stack.push(21);
int_stack.push(31);
int_stack.push(41);



cout << "There are " << int_stack.size() << " elements in the stack "<<endl;

cout << "The first element added is " << int_stack[0] << " the last element is " << int_stack[  int_stack.size()-1]<< endl;

cout << endl;


cout << "While (! int_stack.isEmpty() )   call pop and print value returned" << endl;
while (! int_stack.isEmpty() )
  cout << int_stack.pop() << " ";



cout << endl << "There are " << int_stack.size() << " elements in the stack "<<endl;


cout << "push a bunch of int to the stack... again" << endl;  

int_stack.push(36);
int_stack.push(16);
int_stack.push(26);
int_stack.push(11);
int_stack.push(21);
int_stack.push(31);
int_stack.push(41);


cout << endl << "now sorted " << endl;
int_stack.sort();
for (int loop =0;loop<int_stack.size();loop++)
   cout << int_stack[loop] << " ";



cout << endl;


LOGFILE.close();
return 0;
}
