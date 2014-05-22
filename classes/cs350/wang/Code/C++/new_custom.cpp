// Demonstrating set_new_handler
#include <iostream>
#include <new>
#include <stdlib.h>

using namespace std;

void customNewHandler()
{ 
   cerr << "customNewHandler was called"; 
   abort();
}
   
int main()
{
   double *ptr[ 50 ];
   set_new_handler( customNewHandler );
   
   for ( int i = 0; i < 50; i++ ) {
      ptr[ i ] = new double[ 5000000 ];
      
      cout << "Allocated 5000000 doubles in ptr[ " 
           << i << " ]\n";
   }
   
   return 0;
}
