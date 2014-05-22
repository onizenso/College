/**
 * Name: Huaqing Wang
 * Description:
 *
 * Date:
 * */

#include <iostream>
#include <iomanip>
using namespace std;

class A {

    protected:
       int i;
    public:
       A() { i = 100; }
       void show () { cout << "A.i = " << i << endl << endl; }
};

// class B : public A {
class B : protected A {

    protected:
	int i;
    public:
	B():A() { i = 200; }
	void show() {
	    cout << "B.i = " << i << endl ;
	    cout << "Inherited A::i = " << A::i << endl << endl;
	}
};


int main( int argc, char * argv[] ) {

    A a;
    B b;

    a.show();
    b.show();
    // b.A::show();
    return 0;
}
