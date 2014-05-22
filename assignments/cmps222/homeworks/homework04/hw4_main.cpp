/*
*  Nik Ramsey
*  CMPS 222
*  Winter 2011
*/
#include "cmps222lib.h"  
 
ofstream LOGFILE;

#include "dynamic_stack.h"


// your functions or file includes

int main()
{
LOGFILE.open("hw4.log",ios::trunc);
if (LOGFILE.is_open())
  LOGFILE << POS_IN_PROGRAM << "start of logging" << endl;
else 
  {
  cout << "Unable to open file for logging.";
  return 1;
  }
	
dynamic_stack mystack;

InitializeStack(&mystack);

cout << " the stack is initialized and nothing is added so the size should be 0,  Size() returns " << Size(&mystack) << endl;

cout << "Pushing the value 55" << endl;
PushInt(&mystack, 55);
cout << " the stack has one value inserted size should be 1, it Size() returns " << Size(&mystack) << endl;

cout << " PopInt should return the only value in the stack, 55.... it returns " << PopInt(&mystack) << endl;


cout << " the stack should have nothing again, so the size should be 0, it Size() returns " << Size(&mystack) << endl;

cout << "push the values 15-44" << endl;

int loop;
for (loop =0;loop<30;loop++)
   PushInt( &mystack,loop + 15);

while ( Size(&mystack) > 0)
   printf("Pop %d from the stack with a size of %d\n", PopInt(&mystack),  Size(&mystack)  );

cout << "calling DestroyStack" << endl;

DestroyStack(&mystack);

cout << "after calling DestroyStack" << endl;
 //close the logfile and exit
LOGFILE.close();
return 0;
}
