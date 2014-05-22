/*
*  Nik Ramsey
*  CMPS 222
*  Spring 2011
*/
#include "cmps222lib.h"
#include "string_functions.h"  


ofstream LOGFILE;


// your functions or file includes

int main()
{
LOGFILE.open("hw3.log",ios::trunc);
if (LOGFILE.is_open())
  LOGFILE << POS_IN_PROGRAM << "start of logging" << endl;
else 
  {
  cout << "Unable to open file for logging.";
  return 1;
  }
	
cout << "\ntest Trim()\n" << endl;
cout << ("test" == Trim(" test") 	? "Pass":"Fail" )	<< endl;
cout << ("test" == Trim("	test") ? "Pass":"Fail" )	<< endl;
cout << ("test" == Trim(" 	test") ? "Pass":"Fail" )	<< endl;
cout << ("test" == Trim("test ") 	? "Pass":"Fail" )	<< endl;
cout << ("test" == Trim("test 	") 	? "Pass":"Fail" )	<< endl;


cout << "\n\n\ntest FrontTrim()\n" << endl;
cout << ("test" == FrontTrim(" test") 	? "Pass":"Fail" )	<< endl;
cout << ("test" == FrontTrim("	test") ? "Pass":"Fail" )	<< endl;
cout << ("test" == FrontTrim(" 	test") ? "Pass":"Fail" )	<< endl;
cout << ("test " == FrontTrim("test ") 	? "Pass":"Fail" )	<< endl;
cout << ("test 	" == FrontTrim("test 	") 	? "Pass":"Fail" )	<< endl;


cout << "\n\n\ntest BackTrim()\n" << endl;
cout << (" test" == BackTrim(" test") 	? "Pass":"Fail" )	<< endl;
cout << ("	test" == BackTrim("	test") ? "Pass":"Fail" )	<< endl;
cout << (" 	test" == BackTrim(" 	test") ? "Pass":"Fail" )	<< endl;
cout << ("test" == BackTrim("test ") 	? "Pass":"Fail" )	<< endl;
cout << ("test" == BackTrim("test 	") 	? "Pass":"Fail" )	<< endl;


cout << "\n\n\ntest ReplaceFirst()\n" << endl;
cout << ("dogdogcatdogcatdogcat" == ReplaceFirst("dogcatdogcatdogcatdogcat","cat","") ? "Pass":"Fail" ) << endl;
cout << ("dogdogdogcatdogcatdogcat" == ReplaceFirst("dogcatdogcatdogcatdogcat","cat","dog") ? "Pass":"Fail" ) << endl;
cout << ("dogcatdogcatdogcat" == ReplaceFirst("dogcatdogcatdogcatdogcat","tdogcat","t") ? "Pass":"Fail" ) << endl;
cout << ("aaaaaaaaaa" == ReplaceFirst("aaaaaaaaaa","b","b") ? "Pass":"Fail" ) << endl;


cout << "\n\n\ntest ReplaceLast()\n" << endl;
cout << ("a1a2a3a4a56" == ReplaceLast("a1a2a3a4a5a6","a","") ? "Pass":"Fail" ) << endl;
cout << ("a1a2a3a4a5b6" == ReplaceLast("a1a2a3a4a5a6","a","b") ? "Pass":"Fail" ) << endl;
cout << ("a1a2a3b4a5a6" == ReplaceLast("a1a2a3a4a5a6","3a4","3b4") ? "Pass":"Fail" ) << endl;
cout << ("aaaaaaaaaa" == ReplaceLast("aaaaaaaaaa","b","b") ? "Pass":"Fail" ) << endl;


cout << "\n\n\ntest Contains()\n" << endl;
cout << (true == Contains("a1a2a3a4a5a6","a") ? "Pass":"Fail" ) << endl;
cout << (true == Contains("a1a2a3a4a5a6","3a4") ? "Pass":"Fail" ) << endl;
cout << (false == Contains("a1a2a3a4a5a6","3b4") ? "Pass":"Fail" ) << endl;


cout << "\n\n\ntest ToLowerCase()\n" << endl;
cout << ("a1a2a3a4a56" == ToLowerCase("a1a2a3a4a56") ? "Pass":"Fail" ) << endl;
cout << ("a1a2a3a4a56" == ToLowerCase("a1a2A3a4a56") ? "Pass":"Fail" ) << endl;
cout << ("a1a2a3b4a5a6" == ToLowerCase("A1A2A3B4A5A6") ? "Pass":"Fail" ) << endl;


 //close the logfile and exit
LOGFILE.close();
return 0;
}
