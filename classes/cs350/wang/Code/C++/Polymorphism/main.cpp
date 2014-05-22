/* Filename: main.cpp 
   Project:  circle-->point-->shape */   
   
#include <iostream>
#include <iomanip>
#include "shape.h"
#include "point.h"
#include "circle.h"

void test ( Shape & );
void test2 ( Shape * );

int main()
{

   cout << setiosflags( ios::fixed | ios::showpoint )
        << setprecision( 2 );
   Point point( 7, 11 );          
   Circle circle( 3.5, 22, 8 );  
   point.print();      
   cout << '\n';
   circle.print();    
   cout << '\n';
   Shape * sPtr  = &point;  
   cout << "sPtr = &point\n"; 
   sPtr->print();  
   cout << "Point calls area: " << sPtr->area(); 

   Circle * cptr = &circle; 
   sPtr = &circle;  // <== a mixed-mode implicit coercion from derived to base
   cout << "\nsPtr = &circle\n"; 
   sPtr->print(); 
   sPtr->Shape::print();
   test(*sPtr);
   test ( circle ); // <== circle is implicitly coerced from derived to base
   test2( cptr);
   test2( &circle );  // <== another implicit coercion; e.g. a downcast
   return 0;
}
void test( Shape & s )
{
  cout << "\nTest: \n";
  s.print();
}
void test2( Shape * s )
{
  cout << "\nTest2: \n";
  s->print();
}

