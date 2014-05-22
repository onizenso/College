/* DO NOT TRY THIS CODE ON A CS SERVER. TRY IT ON YOUR OWN PC */

// example of predefined exception handling for memory allocation  
// the program attempts to use all available memory from the heap

#include <iostream>
#include <new>

using namespace std;

int main()
{
   
   double *ptr[ 50 ];
  
   /* new.h contains the exception bad_alloc */ 
   try {   
      for ( int i = 0; i < 50; i++ ) {
         ptr[ i ] = new double[ 5000000 ];
         cout << "Allocated 5000000 doubles in ptr[ " 
              << i << " ]\n";
      }
   }
   catch ( bad_alloc exception) {
      cout << "Exception occurred: " 
           << exception.what() << endl;
   }
   
   return 0;
}

