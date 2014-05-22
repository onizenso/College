#include <iostream>
#include <string>
#include "cmps222lib.h"  

ofstream LOGFILE;
#include "string_map.h"


int main()
{
LOGFILE.open("hw06.log",ios::trunc);
if (LOGFILE.is_open())
  LOGFILE << POS_IN_PROGRAM << "start of logging" << endl;
else 
  {
  cout << "Unable to open file for logging.";
  return 1;
  }

cout << endl<<endl<<endl;
cout << "create a string_map temp" << endl;
string_map  test(5);
cout << "test.Size() returns " << test.Size() << ", should be 0" << endl;

cout << endl<<endl;
cout << "calling Set(\"player name\",\"Mario\")"<<endl;
test.Set("player name","Mario");
cout <<endl;
cout << "test.Size() returns " << test.Size() << ", should be 1" << endl;
cout << "test.Get(\"player name\") returns " << test.Get("player name") << ", should be Mario " << endl;

cout <<endl;
cout << "using Set to change a value" << endl;
cout << "test.Set(\"player name\",\"Luigi\") returns " <<boolalpha << test.Set("player name","Luigi")<< ", should be true" << endl;

cout <<endl;
cout << "test.Size() returns " << test.Size() << ", should be 1" << endl;
cout << "test.Get(\"player name\") returns " << test.Get("player name") << ", should be Luigi " << endl;

cout << endl << endl << "test Exists" << endl;
cout << "test.Exists(\"player name\") returns " << test.Exists("player name") << ", should return true"<<endl;
cout << "test.Exists(\"Chef's Voice\") returns " << test.Exists("Chef's Voice") << ", should return false"<<endl;

cout <<endl;
cout << "add some new values" << endl;
cout << "test.Set(\"Chef's Voice\",\"Isaac Hayes\") returns " <<boolalpha << test.Set("Chef's Voice","Isaac Hayes")<< ", should be true"<<endl;
cout << "test.Set(\"Kenny's Voice\",\"Matt Stone\") returns " <<boolalpha << test.Set("Kenny's Voice","Matt Stone")<< ", should be true"<<endl;
cout << "test.Set(\"Ike looks like\",\"football\") returns " <<boolalpha << test.Set("Ike looks like","football")<< ", should be true"<<endl;
cout << "test.Set(\"location X-wing\",\"Degoba Swamp\") returns " <<boolalpha << test.Set("location X-wing","Degoba Swamp")<< ", should be true"<<endl;
cout << "test.Size() returns " << test.Size() << ", should be 5" << endl;
cout << "test.Set(\"Sham-Wow\",\"bought by morons\") returns " <<boolalpha << test.Set("Sham-Wow","bought by morons")<< ", should be false"<<endl;
cout << "test.Size() returns " << test.Size() << ", should be 5, last one should not have been added" << endl;

cout << "test.Get(\"Chef's Voice\") returns " << test.Get("Chef's Voice")<< ", should be Isaac Hayes"<<endl;
cout << "test.Get(\"Kenny's Voice\") returns " << test.Get("Kenny's Voice")<< ", should be Matt Stone"<<endl;


cout <<endl;
cout << "test.ToString() returns" << endl;
cout << test.ToString() << endl;


cout << "testing copy constructor"<< endl<< "test2 (test);" <<endl;
string_map test2(test);

cout << "test2.ToString() returns"<< endl;
cout << test2.ToString();


LOGFILE.close();

}
