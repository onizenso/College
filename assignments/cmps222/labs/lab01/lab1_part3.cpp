/*
*  Nik Ramsey
*  CMPS 222
*  Winter 2012
*/
#include "cmps222lib.h"   
ofstream LOGFILE;


// your functions or file includes
int * AddArrayElems(int *input, int count)
{
  LOGFILE << POS_IN_PROGRAM << "start of function" << endl;
    int sum = 0;
    int loop = 0;
    while(loop<count){
	sum += *(input+loop);
	loop++;
    }

    cout<< "The sum of the first " << count << " elements is "
	<< sum << endl;
  LOGFILE << POS_IN_PROGRAM << "end of function" << endl;
}

int main()
{
LOGFILE.open("lab1_part3.log",ios::trunc);
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
    
    AddArrayElems(myVal, 2);
    AddArrayElems(myVal, 4);
    AddArrayElems(myVal, 8);
    AddArrayElems(myVal, 16);

    cout<< " " << endl;

// close the logfile and exit
LOGFILE.close();
return 0;
}
