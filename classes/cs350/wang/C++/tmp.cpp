
/**
 * Name: Huaqing Wang
 * Description:
 *
 * Date:
 * */

#include <iostream>
#include <iomanip>
using namespace std;

int main( int argc, char * argv[] ) {

    int *p = new int(100);

    cout << "*p = " << *p << endl;


    delete p;

    return 0;
}
