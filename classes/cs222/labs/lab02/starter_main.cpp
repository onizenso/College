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
LOGFILE.open("errorlog.log",ios::trunc);
if (LOGFILE.is_open())
  LOGFILE << POS_IN_PROGRAM << "start of logging" << endl;
else 
  {
  cout << "Unable to open file for logging.";
  return 1;
  }
	
// now all your regular stuff can go here



// close the logfile and exit
LOGFILE.close();
return 0;
}
