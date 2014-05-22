/*
*  Nik Ramsey
*  CMPS 222
*  Winter 2012
*/
#include "cmps222lib.h"
#include <iomanip>
ofstream LOGFILE;


// your functions or file includes
 
void PrintArray(int *array, int count, int *pos)
{
  LOGFILE << POS_IN_PROGRAM << "start of function;" << endl;

  ClearScreen();
  
  int i = 0; //loop counter
    do
    {
    cout<< "position >" << setw(2) << setfill('0') << right << i 
	<< "< pointer size >" << sizeof(*(pos+i)) 
	<< "< variable size >"<< sizeof(*(array+i)) << "< address >" 
	<< array+i << "< value >" << setw(2) << setfill('0') << right 
	<< *(array+i) << "<";
    if (pos == array+i)
	cout<< "  <---" << endl;
    else
	cout<< "" << endl;
    i++;
    }while(i<count);

  WaitHundredth(90);

  LOGFILE << POS_IN_PROGRAM << "end of function;" << endl;
}


int main()
{
LOGFILE.open("hw01.log",ios::trunc);
if (LOGFILE.is_open())
  LOGFILE << POS_IN_PROGRAM << "start of logging" << endl;
else 
  {
  cout << "Unable to open file for logging.";
  return 1;
  }
	
// now all your regular stuff can go here

const int count = 20;
const int repeat = 10;
int numArray[20];
int *pos = numArray;

//Loop counters for Position pointer increment/decrement
int u(0), d(0), r(0);

int min(1), max(99);

// Loop counter for filling the array
int loop = 0;


// Fills numArray with Random Numbers
while(loop<count)
{
    *(numArray+loop) = CreateRandomNumber(min, max);
    loop++;
}

while(r<repeat){
	// increments pos pointer 20 times
	// through entire array
	while(u<count){
    		PrintArray(numArray, count, pos);
    		pos++;
    		u++;
	}

	// decrements pos pointer 20 times
	// through entire array
	while(d<count){
    		pos--;
    		PrintArray(numArray, count, pos);
    		d++;
	}
	u=0;
	d=0;
}
// close the logfile and exit
LOGFILE.close();
return 0;
}
