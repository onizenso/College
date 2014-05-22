/**
 * Name: Huaqing Wang
 * Description:
 *
 * Date:
 * */

#include <iostream>
#include <iomanip>
using namespace std;

int add( int x, int y ) { return x + y; }


int sub( int u, int v ) { return u - v; }

int main( int argc, char * argv[] ) {


    // Define a poitner to function
    int ( * pf ) ( int, int );

    pf = add;   // let pf pointing at add

    cout << "Result of indirect call to add(1, 2) = " << pf(1, 2 ) << endl;


    pf = sub;
    cout << "Result of indirect call to sub(1, 2) = " << (*pf)(1, 2 ) << endl;

    return 0;
}
