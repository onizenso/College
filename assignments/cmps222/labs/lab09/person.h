#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <ostream>
#include <fstream>

using namespace std;


extern ofstream LOGFILE;// LOGFILE is a global that we delcare in main so we need this here so it compiles


#define POS_IN_PROGRAM " file:"<<__FILE__<<" ,function:" << __FUNCTION__<<" ,line:"<<__LINE__<<" "





// put your person class here
//
//
class person
{
private:
// data members here
  string f_name, m_initial, l_name, phone, address1,address2, city, state, zip;
public:
person();
// addtional fuction declarations here
bool SetFName(string);
bool SetMInitial(string);
bool SetLName(string);
bool SetPhone(string);
bool SetAddress1(string);
bool SetAddress2(string);
bool SetCity(string);
bool SetState(string);
bool SetZip(string);

string FormattedName();
string ToString();
string ToColonDelimited();

void operator = ( person & );
bool operator < ( person & );
bool operator > ( person & );
};





