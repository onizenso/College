/* Filename:   main.cpp
   Purpose:    lab01 cs 350
   Descrip:    instantiates a template class List object and tests
               all methods; incorporates simple try and catch blocks for 
               error handling; reads output file from the command line
 
note:  rand and time are part of the runtime environment of gnu C++ v.3--
       no need to include time.h and stdlib.h */ 

#include <iostream>
#include <fstream>
#include <exception>
#include "list.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

int main ( int argc, char *argv[] )
{

 // char * filename = "this string is the longest filename acceptable";
  if ( argc != 2 ) { 
     cout << "Usage: "<< argv[0] <<" <filename>\n";  // usage statement
     return 0;
  }

  ofstream logf(argv[1]);
  if ( !logf.is_open() ) {
     cout<<"Could not open file\n";
     return 0;
  }

  srand(time(NULL));

  streambuf *buf = cerr.rdbuf();   // keep the cerr buffer to reconnect later 
  cerr.rdbuf( logf.rdbuf() );      // redirect cerr

  /* The simplest method of handling exceptions is to put everything into a 
     single try block in main and use a generic handler.  Note: don't put 
     declarations in a try block if you want to see vars outside that block. */

  List<int> iList;
  List<double> dList;
  List<double>  dList2(dList);

  try {
     // throw an exception from C++ stdexception library
     throw 99;

     for (int i = 0; i < 10; i++)
     {
       iList.add(rand() % 51 + 1 );        
       dList.add( (rand() % 51 + 4) / 3.0 ); 
     }  

  
   }
   catch (const RangeError &err)
   {
      cerr << "from main: " << err << endl;
   }

   // generic handler must be the last handler for a try block
   catch (...){
     cerr << "\n99 error caught...\n" << endl;
   } 
   try {
     cout << "Your integer List: ";
     cout << "Size: " << iList.size() << endl;
     cout << iList;

     cout << "Your double List: ";
     cout << "Size: " << dList.size() << endl;
     dList.print();

     cout << endl << "Swap position 3 and 15 in dList:" << endl;
     dList.swap(3,15);
     dList.print();
   }
   catch (const RangeError &err)
   {
      cerr << "from main: " << err << endl;
   }


   try { 
    cout << endl << "call dList.Max(3,7): " << endl;
    cout << "Position " << dList.max(3,7) << " is bigger";
  
    cout << endl << "Sorting dList: " << endl;

    dList.sort();
    dList.print();
   }

   catch (const RangeError &err)
   {
      cerr << "from main: " << err << endl;
   } 
 
  try { 
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
 
   }  
   catch (const RangeError &err)
   {
      cerr << "from main: " << err << endl;
   } 


   /* this catches anything */ 
   catch (...)
   {
     cerr << "\nsome generic error was caught...\n" << endl;
   }

   cout << "\nThis code is executed after the error handlers are finished!\n";

   /* reconnect cerr or you will get a seg fault */
   cerr.rdbuf(buf);
  
  return 0;

}
