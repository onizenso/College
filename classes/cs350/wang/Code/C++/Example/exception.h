// exceptions.h  - user defined exception classes 

#ifndef EXCEPTIONS_H 
#define EXCEPTIONS_H 

#include <iostream>
#include <string.h>

using namespace std;

const unsigned FileNameSize = 40; // must handle longest filename on system.

/*-------------------Out-of-Range Subscript Exception Class-----------------*/
class RangeError {

friend ostream & operator <<( ostream & os, const RangeError & err )
   { os << "\nRangeError exception thrown: "
       << err.fileName
       << ", line " << err.lineNumber
       << " index = " << err.value
       << endl;
      return os;
   }

public:
  RangeError( const char * fname,
              unsigned line,
              unsigned subscr )
  {
    strncpy(fileName, fname, FileNameSize);
    lineNumber = line;
    value = subscr;
  }

   /* Returns a C-style character string describing the general cause of
      the current error (the same string passed to the ctor).  */

   const char * what()  const
   {  return "RangeError exception";
   }

private:
  char fileName[FileNameSize+1];
  unsigned lineNumber;
  unsigned value;
};


/*-------------------File Open Exception Class-----------------*/

class FileOpenError {
public:
  FileOpenError ( const char * fname, unsigned line, char * infile )
  {
    strncpy(fileName, fname, FileNameSize);
    strncpy(infileName, infile, FileNameSize);
    lineNumber = line;
  }
   const char * what() const {
       return "File Open Exception";
   }

  friend ostream & operator <<( ostream & os,
         const FileOpenError & err )
  {
    os << "\nFile Open exception thrown: "
       << err.fileName
       << ", line " << err.lineNumber
       << " , Missing File: " << err.infileName
       << endl;
    return os;
  }

private:
  char fileName[FileNameSize+1];
  unsigned lineNumber;
  char infileName[FileNameSize+1];   // the file that can't be opened 
};

#endif
