// Demonstrate exception throwing using exception library.

#include <iostream>
#include <exception>    // standard exception class will handle divide by zero

using namespace std;

void test() 
{
   // Throw an exception and immediately catch it.
   try {
      cout << "\nGenerate exception in test() \n";
   //   throw 1;
      throw exception();  // generate a general exception
      cout << "Execute this code only if an exception is not thrown.";
   }

   catch( exception  e )
   {
      cout << "\n Exception handled in test()\n";
      throw;  // rethrow exception for further processing
      cout << "THIS CODE IS NEVER EXECUTED - so do not put code here. ";
   }

   catch ( int i )
   {
   cout << "This will print if you throw an integer.\n";
   } 
   cout << "This will print if you throw an int or you don't throw anything.\n";

}   

int main()
{
   try {
      double d =  3.3, e = 0.0;
      cout << "Generate a divide by zero error in main().\n";
      cout << d/e;
      test();
      cout << "This will execute only if an exception is not thrown.\n";
   }

//   cout << "If you put code here, your program won't compile.\n";
   
   catch ( exception e )
   {
      cout << "Exception handled in main\n";
   }  

   cout << "Program control continues after catch in main" << endl;

   return 0;
}
