
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

    int i(100); float j(3.14f); double k(4.49);
    void * a[] = { &i, &j, &k };

    cout << "* (int *)   a[0] = " <<     * (int *)a[0] << endl;
    cout << "* (float *) a[1] = " <<   * (float *)a[1] << endl;
    cout << "* (double *)a[2] = " <<  * (double *)a[2] << endl;
    
    return 0;
}
