/*
*  Nik Ramsey
*  CMPS 222
*  Winter 2012
*/
#include "cmps222lib.h"   
#include <iomanip>
ofstream LOGFILE;


// your functions or file include
#include "SortAscending.h"


int main()
{
LOGFILE.open("lab04.log",ios::trunc);
if (LOGFILE.is_open())
  LOGFILE << POS_IN_PROGRAM << "start of logging" << endl;
else 
  {
  cout << "Unable to open file for logging.";
  return 1;
  }
	
// now all your regular stuff can go here

string UserPrompt= "How many numbers would you like to use: ";
int *data;
int size = 0;

size = PromptUserForInt(UserPrompt);

data = new int[size];

  LOGFILE << POS_IN_PROGRAM << "add random values" << endl;
for(int loop=0; loop<size; loop++)
{
    *(data+loop)=CreateRandomNumber(1,99);
}

  LOGFILE << POS_IN_PROGRAM << "print it out" << endl;
for(int ploop=0; ploop<size; ploop++)
{
    cout<<"value >"<< *(data+ploop)<< "< size >" 
    << sizeof(*(data+ploop)) << "< address >"<< data+ploop << endl;
}

cout<<endl<<endl;

  LOGFILE << POS_IN_PROGRAM << "calling SortAscending" << endl;
SortAscending(data, size);

  LOGFILE << POS_IN_PROGRAM << "print it out" << endl;
for(int ploop=0; ploop<size; ploop++)
{
    cout<<"value >"<< *(data+ploop)<< "< size >" 
    << sizeof(*(data+ploop)) << "< address >"<< data+ploop << endl;
}

  LOGFILE << POS_IN_PROGRAM << "call delete[]" << endl;
delete [] data;
// close the logfile and exit
LOGFILE.close();
return 0;
}
