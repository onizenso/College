/* filename: main.cpp 
   purpose:  demonstrates the use of try, throw and catch and throwing
   exception objects */

#include "student.h"
#include "exception.h"

int main()
{ 
   StudentList SL;  

 //    you can't have a catch without a try preceeding it
   try {
     SL.Input( );      
     cout << "Printed only if a FileOpenError is NOT thrown.";  
   }

   // the catch block must immediately follow the catch block
   catch ( const FileOpenError & err ) {
      cerr << err.what() << endl;
      char ch;
      cout << "A FileOpenError was thrown. Press ENTER to execute next line.."
           << endl;
      cin.get(ch); 
      // throw err;  /* throwing from main will give you a runtime error */  
   } 

   String name("John White");
   String cname("Psych 100");
   long id = 999999;
   float credits = 5;
   float gpts = 3.5; 
        
   StudentRecord * SR = new StudentRecord (name,id);
   Course * cPtr = new Course(cname, credits, gpts);

   try {
      SR->AddCourse(cPtr); 
      cPtr->setCourse(cname.setString("Biol 200"), 10, 4.5);
      SR->AddCourse(cPtr); 
      cout << SR;   
      SL.Add(SR);  
   }
   catch ( const RangeError & err ) {
      cerr << err.what() << endl;
   }
   catch ( ... ) {
      cout << "\n\nUnknown Exception caught in main ..\n\n";
   } 

   cout << "Since this line at the end of main() is outside any try block \n"
        << "it will be executed\n"; 
   // cout << SL;       // display StudentList

return 0;
}