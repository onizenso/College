// Member function definitions for class Circle
#include <iostream>
#include "circle.h"

Circle::Circle( double r, int a, int b )
   : Point( a, b )  // call base-class constructor
{ setRadius( r ); }

void Circle::setRadius( double r ) { radius = r > 0 ? r : 0; }

double Circle::getRadius() const { return radius; }

double Circle::area() const 
   { return 3.14159 * radius * radius; }

void Circle::print() const
{
   cout << "Circle::print()\n";
   Point::print();
   cout << "Radius = " << radius << endl;
}
