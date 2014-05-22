/*
*  Nik Ramsey
*  CMPS 222
*  Winter 2012
*/
#include "cmps222lib.h"   
ofstream LOGFILE;


// your functions or file includes


int main()
{
LOGFILE.open("Lab1_Part1.log",ios::trunc);
if (LOGFILE.is_open())
  LOGFILE << POS_IN_PROGRAM << "start of logging" << endl;
else 
  {
  cout << "Unable to open file for logging.";
  return 1;
  }
	
// now all your regular stuff can go here
const int SIZE = 8;
int valArr[SIZE]={99, 88, 777, 3, 55, 76, 23, 0};
int * loop;
loop = valArr;

do{
    cout << *loop << endl;
    loop++;
}while(*loop != '0');


// close the logfile and exit
LOGFILE.close();
return 0;
}
