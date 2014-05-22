/* Filename: main.cpp 
   Project:  Driver for Employ Class 
   Purpose:  Test the use of static members, assert, and dynamic memory    */


#include <iostream>
#include <cassert> 
#include "employ.h"

using namespace std;

int main()
{
   cout << "Number of employees before instantiation is "
        << Employee::getCount() << endl;   // use scope resolution operator 

   char fname[20] = "Samantha";
   Employee e ( fname, "Baker");

   // testing copy constructor  by making a duplicate of e
   Employee *e1Ptr = new Employee( e );

   Employee *e2Ptr = new Employee( "Sam", "Spade");
   
   cout << "Number of employees is "
        << e1Ptr->getCount();

/*   char* private = e1Ptr->getFirstName();
   char *newName = "NewName";
   strcpy(newName,private); */

   cout << "\n\nEmployee 1: "
        << e1Ptr->getFirstName()
        << " " << e1Ptr->getLastName()
        << "\nEmployee 2: "
        << e2Ptr->getFirstName()
        << " " << e2Ptr->getLastName() << "\n\n";

   delete e1Ptr;   // recapture memory
   delete e2Ptr;   // recapture memory
   e2Ptr = 0;

   cout << "Number of employees after deletion is "
        << Employee::getCount() << endl;

   return 0;
}
