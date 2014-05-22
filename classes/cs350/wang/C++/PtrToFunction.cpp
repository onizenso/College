/**
 * Name: Huaqing Wang
 * Description:
 *
 * Date:
 * */

#include <iostream>
#include <iomanip>
using namespace std;

char fun( char c ) {
    cout << "fun('" << c << "') is called.\n";
    return c;
}

int fun3( char (*f) (char ) ) {
    f('W');
    return 123;
}

int main( int argc, char * argv[] ) {

    cout << "fun = " << fun << endl;
    cout << "fun3(fun) = " << (fun3( fun )) << endl;

    return 0;
}
