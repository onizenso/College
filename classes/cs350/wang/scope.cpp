/* ch. 5 example of static scoping rules in C/C++ */

#include <iostream>
using namespace std;
int main(void) {
   int a=1, b=3, c=5;  // definition 1 
   int x=1;
   while (x == 1 ) {
       x--;
       int b=2, c=4, d=6; // definition 2 
       cout << a << b << c << d << endl;   // local b c overrides b c in main  
       int x2=1;
       while (x2 == 1) {
          x2--;
          int c=10, d=20, e=30; // definition 3 
          cout << a << b << c << d << e << endl;   // everything is visible 
       }
       cout << a << b << c << d << endl;   // e is not visible 
    }
    cout << a << b << c << endl;   // d & e are not visible 
}

