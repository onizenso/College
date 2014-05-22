// Definition of class Circle
#ifndef CIRCLE_H
#define CIRCLE_H
#include "point.h"

using namespace std;

class Circle : public Point {
public:
   // This is a default constructor; call with 
   // Circle() to use all defaults
   // Circle(5.5) to set r and use defaults for x and y 
   // Circle(5.5, 2) to set r and x and use defaults for y
   // Circle(5.5, 2, 7) to override all defaults
   Circle( double r = 0.0, int x = 0, int y = 0 );

   void setRadius( double );
   double getRadius() const;
   virtual double area() const;
   virtual void print() const;
private:
   double radius;   // radius of Circle
};

#endif
