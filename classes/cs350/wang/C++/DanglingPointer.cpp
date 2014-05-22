/**
 * Name: Huaqing Wang
 * Description:
 *
 * Date:
 * */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

void show( int * a, int sz ) {

    for (int i = 0; i < sz; i ++ ) cout << setw(4) << a[i];

    cout << endl;
}

int main( int argc, char * argv[] ) {

    int * p1 ;
    p1 = new  int[10];

    int  *p2;
    p2 =  p1 ;
  

    for (int i = 0; i < 10; i ++ )  p1[i] = i * 2; 
    show(p1, 10);

    delete [] p1;
    // delete [] p2;
    show(p2, 10);
    show(p1, 10);

    cout << endl;


    // system("sleep 1");

    // show(p2, 100);
    


    return 0;
}
