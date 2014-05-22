/*
*  Nik Ramsey
*  CMPS 222
*  Winter 2012
*/
#include "cmps222lib.h"   
ofstream LOGFILE;


// your functions or file includes
void PromptForInt(string message, int *target)
{
    const int count = 5;
    int i = 0;
  LOGFILE << POS_IN_PROGRAM << "start PromptForInt(" << i<< ");" << endl;

    cout<< " " << endl;
    cout << message << endl;
    cout<< " " << endl;

    do
    {
    cout<< "Enter an integer: ";
    cin>>*(target+i);
    i++;
    cout<< " " << endl;
    }while(i<count);

  LOGFILE << POS_IN_PROGRAM << "end of PromptForInt(" << i << ");" << endl;
}
//-----------------------------------------------------------------------------------------
void PromptForChar(string message, char *target)
{
    const int count = 5;
    int i = 0;
  LOGFILE << POS_IN_PROGRAM << "start PromptForChar(" << i<< ");" << endl;

    cout<< " " << endl;
    cout << message << endl;
    cout<< " " << endl;

    do
    {
    cout<< "Enter a char: ";
    cin>>*(target+i);
    i++;
    cout<< " " << endl;
    }while(i<count);

  LOGFILE << POS_IN_PROGRAM << "end of PromptForChar(" << i << ");" << endl;
}
//-----------------------------------------------------------------------------------------
void DumpInt(string dmpIntMsg, int *target)
{
    const int count = 5;
    int i = 0;
  LOGFILE << POS_IN_PROGRAM << "start DumpInt(" << i<< ");" << endl;

    cout<< " " << endl;
    cout << dmpIntMsg << endl;

    do
    {
    cout<< "position >" <<i<< "< variable size >" << sizeof(*(target+i)) 
	<<"< address >" << target+i << "< value >" << *(target+i) << "<" 
	<< endl;
    i++;
    }while(i<count);

  LOGFILE << POS_IN_PROGRAM << "end of DumpInt(" << i << ");" << endl;
}

void DumpChar(string dmpCharMsg, char *target)
{
    const int count = 5;
    int i = 0;
    
  LOGFILE << POS_IN_PROGRAM << "start DumpChar(" << i<< ");" << endl;

    cout<< " " << endl;
    cout << dmpCharMsg << endl;

    do
    {
    cout<< "position >" <<i<< "< variable size >" << sizeof(*(target+i)) 
	<<"< address >" << (void*)(target+i) << "< value >" 
	<< *(target+i) << "<" << endl;
    i++;
    }while(i<count);

  LOGFILE << POS_IN_PROGRAM << "end of DumpChar(" << i << ");" << endl;
}

int main()
{
LOGFILE.open("lab2_part1.log",ios::trunc);
if (LOGFILE.is_open())
  LOGFILE << POS_IN_PROGRAM << "start of logging" << endl;
else 
  {
  cout << "Unable to open file for logging.";
  return 1;
  }
	
// now all your regular stuff can go here

char c_array[5];
int i_array[5];
string intMsg = "Populate the int array with values.";
string charMsg = "Populate the char array with values.";
string dmpIntMsg = "Dump the data in the int array";
string dmpCharMsg = "Dump the data in the char array";

PromptForInt(intMsg, i_array);
PromptForChar(charMsg, c_array);

DumpInt(dmpIntMsg, i_array);
DumpChar(dmpCharMsg, c_array);


// close the logfile and exit
LOGFILE.close();
return 0;
}
