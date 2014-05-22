/* filename: employ.h
   project:  declaration for an employee class demonstating dynamic memory

NOTE: Since Employee uses dynamic memory for private data members there 
MUST be an overloaded = operator and an explicit copy constructor to prevent
cross-linked pointers. These methods are not yet coded for this class.
*/

#ifndef EMPLOY_H
#define EMPLOY_H

class Employee {
public:
   Employee( const char*, const char* );  // constructor
   Employee( const Employee & );         //  copy constructor
   ~Employee();                         // destructor
   const char *getFirstName() const;    // return first name
   const char *getLastName() const;     // return last name

   // static member function
   static int getCount();  // return # objects instantiated

private:
   char *firstName;    // dynamic memory
   char *lastName;     // dynamic memory

   // static data member
   static int count;  // number of objects instantiated
};

#endif
