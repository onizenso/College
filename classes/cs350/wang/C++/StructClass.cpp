/**
 * Name: Huaqing Wang
 * Description:
 *
 * Date:
 * */

#include <iostream>
#include <iomanip>
using namespace std;

struct StrA {
    int a;
};

class ClassA {
    int a;
};

class ClassAF {
    int a;
    int f() { return a; }
};
class ClassAVF {
    int a;
    virtual int f() { return a; }
};



int main( int argc, char * argv[] ) {

    cout << "Size of StrA {int a; } = " << sizeof( StrA ) << endl;
    cout << "Size of ClassA {int a; } = " << sizeof( ClassA ) << endl;
    cout << "Size of ClassAF {int a; int f() } = " << sizeof( ClassAF ) << endl;
    cout << "Size of ClassAVF {int a; virtual int f() } = " << sizeof( ClassAVF ) << endl;

    return 0;
}

/* Output from the above code 
	Size of StrA {int a; } = 4
	Size of ClassA {int a; } = 4
	Size of ClassAF {int a; int f() } = 4
	Size of ClassAVF {int a; virtual int f() } = 16
*/

