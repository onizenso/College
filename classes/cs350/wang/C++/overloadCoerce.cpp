#include <iostream>
#include <cstring>
using namespace std;

void  f ( long v ) { cout << "In f ( long ) : " << v << endl ; }
void  f ( int   v ) { cout << "In f ( int ) : " << v << endl ; }

int main( int agc, char ** ags ) {

    int x; double y;

    f ( (long) 5.0 ); // this call has no problem, f ( long ) will be called.
    f ( 5.0 );	      // this call is not clear which of f ( int ) and f ( double) will be called.

    return 0; 
}
