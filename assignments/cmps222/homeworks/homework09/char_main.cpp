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





cout << "create a stack of type char" << endl;

 t_stack<char> char_stack;



cout << "push a bunch of char to the stack" << endl;

char_stack.push('!');
char_stack.push('s');
char_stack.push('k');
char_stack.push('r');
char_stack.push('o');
char_stack.push('w');
char_stack.push(' ');
char_stack.push('t');
char_stack.push('i');
char_stack.push(' ');
char_stack.push('e');
char_stack.push('p');
char_stack.push('o');
char_stack.push('H');


cout << "There are " << char_stack.size() << " elements in the stack "<<endl;

cout << "The first element added is " << char_stack[0] << " the last element is " << char_stack[  char_stack.size()-1]<< endl;

cout << endl;


cout << "While (! char_stack.isEmpty() )   call pop and print value returned" << endl;
while (! char_stack.isEmpty() )
  cout << char_stack.pop() ;



cout << endl << "There are " << char_stack.size() << " elements in the stack "<<endl;


cout << "push a bunch of char to the stack... again" << endl;  
char_stack.push('!');
char_stack.push('s');
char_stack.push('k');
char_stack.push('r');
char_stack.push('o');
char_stack.push('w');
char_stack.push(' ');
char_stack.push('t');
char_stack.push('i');
char_stack.push(' ');
char_stack.push('e');
char_stack.push('p');
char_stack.push('o');
char_stack.push('H');



cout << endl << "now sorted " << endl;
char_stack.sort();
for (int loop =0;loop<char_stack.size();loop++)
   cout << char_stack[loop] << " ";



cout << endl;


LOGFILE.close();
return 0;
}

