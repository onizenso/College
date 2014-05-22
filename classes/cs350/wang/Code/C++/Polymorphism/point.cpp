// point.cpp
// Member function definitions for class Point
#include "point.h"

Point::Point( int a, int b ) { setPoint( a, b ); }

void Point::setPoint( int a, int b )
{
   x = a;
   y = b;
}

void Point::print() const 
   { cout << "Point::print(): " << '[' << x << ", " << y << ']' << endl; }
