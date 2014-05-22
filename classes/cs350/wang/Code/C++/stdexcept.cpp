// example of C++ standard library exception handling from stdexcept class 

#include <iostream>
#include <stdexcept>

using namespace std;

void function3() throw ( runtime_error )
{
   throw runtime_error( "runtime_error in function3" );
}

void function2() throw ( runtime_error )
{
   function3();
}

void function1() throw ( runtime_error )
{
   function2();
}

int main()
{
   try {
      function1();
   }
   catch ( runtime_error e )
   {
      cout << "Exception occurred: " << e.what() << endl;
   }

   return 0;
}
