// Definition of a String class
#ifndef STRING1_H
#define STRING1_H

#include <iostream>

using namespace std;

class String {
   friend ostream &operator<<( ostream &, const String & );
   friend istream &operator>>( istream &, String & );

public:
   String( const char * = "" ); // conversion/default constructor
   String( const String & );    // copy constructor
   ~String();                   // destructor

   // get functions 
   const String & getString() const { return *this; } 
   int getLength() const;               // return string length

   // overloaded assignment operators
   const String &operator=( const char *in_str );
   const String &operator=( const String & );  

   // set functions
   const String & setString( const String &s) { *this = s; return *this;}
   const String & setString( const char * );  

   const String &operator+=( const String & ); // concatenation
   bool operator!() const;                  // is String empty?
   bool operator==( const String & ) const; // test s1 == s2
   bool operator<( const String & ) const;  // test s1 < s2

   // test s1 != s2
   bool operator!=( const String & right ) const
      { return !( *this == right ); }

   // test s1 > s2
   bool operator>( const String &right ) const
      { return right < *this; }
 
   // test s1 <= s2
   bool operator<=( const String &right ) const
      { return !( right < *this ); }

   // test s1 >= s2
   bool operator>=( const String &right ) const
      { return !( *this < right ); }

   char &operator[]( int );             // subscript operator
   const char &operator[]( int ) const; // subscript operator
   String operator()( int, int );       // return a substring

private:
   int length;                   // string length 
   char *sPtr;                   // pointer to start of string

};

#endif
