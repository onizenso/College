// Definition of abstract base class Shape
#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

using  namespace std;

class Shape {
public:
   virtual double area() const { return 0.0; }
   virtual void print() const { cout << "BASE" << endl; }
   virtual void test() = 0;
};

#endif
