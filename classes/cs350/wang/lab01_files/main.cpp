/* Filename:   main.cpp
   Purpose:    lab01 cs 350
   Descrip:    instantiates a template class List object; tests all methods; 
               incorporates simple try and catch blocks for error handling
 
note:  rand and time are part of the runtime environment of gnu C++ v.3--
       no need to include time.h and stdlib.h */ 

#include <iostream>
#include "list.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
  srand(time(NULL));


  /* The simplest method of handling exceptions is to put everything into a 
     single try block in main and use a generic handler.  Note: don't put 
     declarations you may refer to later in the try block. */

  try {

     // by default List objects are size 10   
     List<int> iList;
     List<double> dList;
     List<double>  dList2(dList);

     // there is a range error in the add function
     for (int i = 0; i < 10; i++)
     {
       iList.add(rand() % 51 + 1 ); 
       dList.add( (rand() % 51 + 4) / 3.0 ); 
     }  
  

     cout << "Your integer List: ";
     cout << "Size: " << iList.size() << endl;
     cout << iList;

     cout << "Your double List: ";
     cout << "Size: " << dList.size() << endl;
     dList.print();

     // this triggers an exception from C++ stdexcept
     cout << endl << "Swap position 3 and 15 in dList:" << endl;
  
     dList.swap(3,15);
     dList.print();


    cout << endl << "call dList.Max(3,7): " << endl;
    cout << "Position " << dList.max(3,7) << " is bigger";
  
    cout << endl << "Sorting dList: " << endl;

    dList.sort();
    dList.print();

  
    cout << endl << "Testing implicit copy constructor:\n";
    dList2.print();
    cout << endl << "Testing implicit assignment operator:\n";
    dList2.add(999.9);
    dList = dList2;
    dList.print();
 
    cout << endl << "Testing range error conditions: swap(1,15)\n";
    dList.swap(1,15);
    cout << endl << "Testing range error conditions: swap(-1,2)\n";
    dList.swap(-1,2);
 
   }  // end try block

   /* this catches user-defined RangeError objects  */
   catch (const RangeError &err)
   {
      cerr << "from main: " << err << endl;
   } 

   /* this catches anything */ 
   catch (...)
   {
     cerr << "\nsome unknown error was caught...\n" << endl;
   }

   cout << "\nThis code is executed after the error handler is finished!\n";
  
  return 0;

}
