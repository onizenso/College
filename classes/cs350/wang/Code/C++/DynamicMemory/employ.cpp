// Member function definitions for class Employee
#include <iostream>
#include <cstring> 
#include <cassert> 
#include "employ.h"

using namespace std;

// Initialize the static data member
int Employee::count = 0;

// Define the static member function that
// returns the number of employee objects instantiated.
int Employee::getCount() { return count; }

// Constructor dynamically allocates space for the
// first and last name and uses strcpy to copy
// the first and last names into the object
Employee::Employee( const char *first, const char *last )
{
   firstName = new char[ strlen( first ) + 1 ];
   assert( firstName != 0 );   // ensure memory allocated
   strcpy( firstName, first );

   lastName = new char[ strlen( last ) + 1 ];
   assert( lastName != 0 );    // ensure memory allocated
   strcpy( lastName, last );

   ++count;  // increment static count of employees
   cout << "Employee constructor for " << firstName
        << ' ' << lastName << " called." << endl;
}

// Copy constructor ensures that cross-linked pointers will not occur 
// the copy constructor generally performs the same tasks as the constructor
Employee::Employee( const Employee & src)
{
   firstName = new char[ strlen( src.firstName ) + 1 ];
   assert( firstName != 0 );   // ensure memory allocated
   strcpy( firstName, src.firstName );

   lastName = new char[ strlen( src.lastName ) + 1 ];
   assert( lastName != 0 );    // ensure memory allocated
   strcpy( lastName, src.lastName );

   ++count;  // increment static count of employees
}


// Destructor deallocates dynamically allocated memory
Employee::~Employee()
{
   cout << "~Employee() called for " << firstName
        << ' ' << lastName << endl;
   delete [] firstName;  // recapture memory
   delete [] lastName;   // recapture memory
   --count;  // decrement static count of employees
}

// Return first name of employee
const char *Employee::getFirstName() const
{
   // Const before return type prevents client from modifying
   // private data. Client should copy returned string before
   // destructor deletes storage to prevent undefined pointer.
   return firstName;
}

// Return last name of employee
const char *Employee::getLastName() const
{
   // Const before return type prevents client from modifying
   // private data. Client should copy returned string before
   // destructor deletes storage to prevent undefined pointer.
   return lastName;
}
