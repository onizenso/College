
/**
 * Name: Huaqing Wang
 * Description:
 *
 * Date:
 * */

#include <iostream>
#include <iomanip>
using namespace std;

int f ( int & k ) {
    int t = k;
    k *= 10;
    return k;
}

int q( int k ) { return k; }


int main( int argc, char * argv[] ) {
    int x(2);

    cout << "f(x) + x + 1 = " << f(x) + x << endl;
    x = 2;
    cout << "x + 1 + f(x) = " << (x) + f(x) << endl;

    x = 2;
    cout << " ++x + q ( x ) = " << ++x + q(x) << endl;

    x = 2;
    cout << " q(x) + ++x = " << q(x) + ++x  << endl;

    return 0;
}
