
/* 
 *
 * */
#include <cstdarg>
#include <iostream>
#include <iomanip>

using namespace std;

int add ( int x, int y, int n, ... ) {

    va_list parameters; 
    int sum = x + y;

    cout << " n = " << n << endl;

    va_start ( parameters, n );

   for (int i = 0; i < n; i ++ )
       sum += va_arg ( parameters, int);

   va_end ( parameters) ;

   return sum;
}


int main( int argc, char * *argv ) {

    cout << " add(1, 2, 3, 3, 2, 1 ) = " << add ( 1, 2, 3, 3, 2, 1 ) << endl;

    cout << " add(1, 2, 5 , 1, 2, 3, 4, 5 ) = " << add ( 1, 2, 3, 4, 5, 6) << endl;

    return 0;
}
