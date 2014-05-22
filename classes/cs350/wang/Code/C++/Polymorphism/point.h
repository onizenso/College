// Definition of class Point
#ifndef POINT_H
#define POINT_H

#include <iostream>
#include "shape.h"

using namespace std;

class Point : public Shape {
public:
   Point( int = 0, int = 0 );  // default constructor
   void setPoint( int, int );
   int getX() const { return x; }
   int getY() const { return y; }
   void print() const;
   void test() { }
private:
   int x, y;   // x and y coordinates of Point
};
#endif
