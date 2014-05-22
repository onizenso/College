// link this file with file1.cpp
/*------------------------------------------------------------------------
Filename: file2.cpp     testing linkage   */

#include <iostream>
using namespace std;

static int y = 100;      /* internal linkage */
void func1 (int arg1)  /*  func1 has external linkage, arg1 has no linkage */
{

  extern int x;         /*  External linkage                        */
  cout << "\nWithin func1......\n";
  cout << "Extern x in file2: " << x << endl;
  cout << "Static y in file2: " << y << endl;
}

