/**
 * Name: Huaqing Wang
 * Description:
 *
 * Date:
 * */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
int loops = 10000000;
int size(20000);
using namespace std;
struct LargeArray {
    int a[20000];
};

int fun ( LargeArray a ) {
    int sum = 0;
    // for ( int i = 0; i < size; i= i + 100) sum += a.a[i];
    return a.a[size-1];
} 


int fun2 ( LargeArray & a ) {
    int sum = 0;
    // for ( int i = 0; i < size; i = i + 100) sum += a.a[i];
    return a.a[size-1];
} 

int main( int argc, char * argv[] ) {
    LargeArray a;
    clock_t start, end, diff, diff2;
    
    // test for pass-by-reference
    start = clock();
    for ( long i = 0; i < loops; i ++ ) fun2(a);
    end   = clock();
    diff2 = end - start;
    cout << " Time of calls to fun ( LargeArray & a ) = " 
	 << (double) diff2 /CLOCKS_PER_SEC << endl;

    // test for pass-by-reference
    start = clock();
    for ( long i = 0; i < loops; i ++ ) fun(a);
    end   = clock();
    diff = end - start;
    cout << " Time of calls to fun ( LargeArray v )   = " 
	 << (double ) diff / CLOCKS_PER_SEC << endl ;


    cout << " Ratio fun( LgArr v) / fun (LgArr &)    = " << endl
	 << (double) diff/diff2 << endl;
    return 0;
}
