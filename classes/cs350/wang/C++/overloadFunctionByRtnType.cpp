#include <iostream>
#include <cstring>
using namespace std;

int f( ) { return 5; }
double f( ) { return 3.1415926; }


int main( int agc, char ** ags ) {

    int x; double y;

    x = f();
    y = f();

    return 0; 
}
