/*
  Filename: range_error.h
  Purpose: a RangeError exception class 
  Note: __FUNC__ is deprecated and should be replaced by __func__ in the
  g++ compiler. 
*/

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const unsigned FileNameSize = 40;

//out of range subscript exception class
class RangeError {

  friend ostream & operator <<( ostream & os, const RangeError & err )
  { 
    os << "\nRangeError exception thrown: "
       << err.fileName
       << " Line: " << err.lineNumber
       << " Function: " << err.funcName
       << " Index: " << err.value
       << endl;
       return os;
  }

  public:

    RangeError( const char *fname, const char * func, int line, int subscr )
    {
      strncpy(fileName, fname, FileNameSize + 1);
      strncpy(funcName, func, FileNameSize + 1);
      lineNumber = line;
      value = subscr;
    }
   
    // a standard method for all range error classes  -- returns error type
    const char * what () const
    {  
       return "RangeError Exception";
    }
    
  private:
    char fileName [FileNameSize + 1];   // __FILE__
    char funcName [FileNameSize + 1];   // __FUNCTION__
    int lineNumber;                     // __LINE__
    int value;                          // the out-of-range index 
};

#endif
