/*
*  Nik Ramsey
*  CMPS 222
*  Winter 2012
*/


#include <iostream>
#include <string>
#include "cmps222lib.h"  

ofstream LOGFILE;



#include "person.h"

// your functions or file includes

int main()
{
LOGFILE.open("lab08.log",ios::trunc);
if (LOGFILE.is_open())
  LOGFILE << POS_IN_PROGRAM << "start of logging" << endl;
else 
  {
  cout << "Unable to open file for logging.";
  return 1;
  }


  LOGFILE << POS_IN_PROGRAM << "create an instance of the person class" << endl;
	person p1;
  LOGFILE << POS_IN_PROGRAM << "set all the member values with Homers stats" << endl;
  LOGFILE << POS_IN_PROGRAM << "set f_name" << endl;
	p1.f_name = "Homer";
  LOGFILE << POS_IN_PROGRAM << "set m_initial" << endl;
	p1.m_initial="J";
  LOGFILE << POS_IN_PROGRAM << "set l_name" << endl;
	p1.l_name ="Simpson";
  LOGFILE << POS_IN_PROGRAM << "set phone" << endl;
	p1.phone="1235551212";
  LOGFILE << POS_IN_PROGRAM << "set ssn" << endl;
	p1.ssn=777885566;
  LOGFILE << POS_IN_PROGRAM << "set address.number" << endl;
	p1.address.number="742";
  LOGFILE << POS_IN_PROGRAM << "set address.street" << endl;
	p1.address.street="Evergreen Terrace";
  LOGFILE << POS_IN_PROGRAM << "set address.city" << endl;
	p1.address.city="Springfield";
  LOGFILE << POS_IN_PROGRAM << "set addresss.state" << endl;
	p1.address.state="Ga";
  LOGFILE << POS_IN_PROGRAM << "set addresss.zip" << endl;
	p1.address.zip=78541;
	  LOGFILE << POS_IN_PROGRAM << "test the ToString() Function" << endl;
cout << p1.ToString() << endl;

}
