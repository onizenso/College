// Member function definitions for class String

#include "string.h"
#include <iomanip>
#include <string>
#include <cstring>
#include <assert.h>

using namespace std;

// Conversion constructor: Convert char * to String
String::String( const char *s ) : length( strlen( s ) )
{
   setString( s );         // call utility function
}

// Copy constructor
String::String( const String &copy ) : length( copy.length )
{
   setString( copy.sPtr ); // call utility function
}

// Destructor
String::~String()
{
   delete [] sPtr;         // reclaim string
}

// Overloaded = operator for char *
const String &String::operator=( const char *in_str )
{
   delete [] sPtr;
   length = strlen( in_str );
   sPtr = new char[ length + 1 ]; // allocate storage
   assert( sPtr != 0 );          // terminate if memory not allocated
   strcpy( sPtr, in_str );       // copy literal to object
   return *this;
}

// Overloaded = operator; avoids self assignment
const String &String::operator=( const String &right )
{
   if ( &right != this ) {         // avoid self assignment
      delete [] sPtr;              // prevents memory leak
      length = right.length;       // new String length
      setString( right.sPtr );     // call utility function
   }
   else
      cout << "Attempted assignment of a String to itself\n";

   return *this;   // enables cascaded assignments
}

// Concatenate right operand to this object and
// store in this object.
const String &String::operator+=( const String &right )
{
   char *tempPtr = sPtr;        // hold to be able to delete
   length += right.length;      // new String length
   sPtr = new char[ length + 1 ]; // create space
   assert( sPtr != 0 );   // terminate if memory not allocated
   strcpy( sPtr, tempPtr );     // left part of new String
   strcat( sPtr, right.sPtr );  // right part of new String
   delete [] tempPtr;           // reclaim old space
   return *this;                // enables cascaded calls
}

// Is this String empty?
bool String::operator!() const { return length == 0; }

// Is this String equal to right String?
bool String::operator==( const String &right ) const
   { return strcmp( sPtr, right.sPtr ) == 0; }

// Is this String less than right String?
bool String::operator<( const String &right ) const
   { return strcmp( sPtr, right.sPtr ) < 0; }

// Return a reference to a character in a String as an lvalue.
char &String::operator[]( int subscript )
{
   // First test for subscript out of range
   assert( subscript >= 0 && subscript < length );

   return sPtr[ subscript ];  // creates lvalue
}

// Return a reference to a character in a String as an rvalue.
const char &String::operator[]( int subscript ) const
{
   // First test for subscript out of range
   assert( subscript >= 0 && subscript < length );

   return sPtr[ subscript ];  // creates rvalue
}

// Return a substring beginning at index and
// of length subLength
String String::operator()( int index, int subLength )
{
   // ensure index is in range and substring length >= 0
   assert( index >= 0 && index < length && subLength >= 0 );

   // determine length of substring
   int len;

   if ( ( subLength == 0 ) || ( index + subLength > length ) )
      len = length - index;
   else
      len = subLength;

   // allocate temporary array for substring and 
   // terminating null character
   char *tempPtr = new char[ len + 1 ];
   assert( tempPtr != 0 ); // ensure space allocated

   // copy substring into char array and terminate string
   strncpy( tempPtr, &sPtr[ index ], len );
   tempPtr[ len ] = '\0';

   // Create temporary String object containing the substring
   String tempString( tempPtr );
   delete [] tempPtr;  // delete the temporary array

   return tempString;  // return copy of the temporary String
}

// Return string length
int String::getLength() const { return length; }

// Utility function to be called by constructors and 
// assignment operator.
const String & String::setString( const char *string2 )
{
   sPtr = new char[ length + 1 ]; // allocate storage
   assert( sPtr != 0 );  // terminate if memory not allocated
   strcpy( sPtr, string2 );       // copy literal to object
   return *this;
}

// Overloaded output operator
ostream &operator<<( ostream &output, const String &s )
{
   output << s.sPtr;
   return output;   // enables cascading
}

// Overloaded input operator
istream &operator>>( istream &input, String &s )
{
   char buff[ 100 ];   // buffer to store input
   input >> setw( 100 ) >> buff;
   s = buff;        // use String class assignment operator
   return input;    // enables cascading
}
