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
LOGFILE.open("lab1_part1.log",ios::trunc);
if (LOGFILE.is_open())
  LOGFILE << POS_IN_PROGRAM << "start of logging" << endl;
else 
  {
  cout << "Unable to open file for logging.";
  return 1;
  }
	
// now all your regular stuff can go here
 
    int myVal[]={99,88,777,3,55,76,23,0};
    int *valPtr = myVal;
    int i = 0;

    cout<<"creating int array with the initial " 
	<<"values 99,88,777,3,55,76,23,0" << endl;
    cout<<"Lets print out the values in the " 
	<<"array until we find a value of 0"<< endl;
    cout<<"The array contains ";
    
    do{
	cout<< *(myVal+i) << " ";
	i++;
    }while(*(myVal+i) != 0);

    cout<< " " << endl;

// close the logfile and exit
LOGFILE.close();
return 0;
}
