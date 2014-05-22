// filename: file1.cpp
#include <iostream>
using namespace std;
static int y = 4;      /* internal linkage                    */
int x =5;              /* file scope and external linkage */
void func1 (int);      /* no linkage  */

main ()                /*  external linkage   */
{
    int w;             /*  Internal linkage                     */

    x = 10;
    cout << "\nBefore calling func1...." << endl;
    cout << "Extern x in file1: " << x << endl;
    cout << "Static y in file1: " << y << endl;
    extern int y;      /*  external linkage to y in file2  */
    static int a=3;    /*  internal linkage  */
    func1(x);          /* external linkage */
    cout << "\nAfter calling func1...." << endl;
    cout << "Extern x in file1: " << x << endl;
    cout << "Static y in file1: " << y << endl;
    {
      auto int a = 10;    /* internal linkage */
    }
}
