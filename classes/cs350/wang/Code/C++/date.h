/* filename: date.h   
   project:  Date class */

#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date;   

class Date {
   friend istream & operator >> ( istream &, Date &);
   friend ostream &operator<<( ostream &, const Date & );

public:
   Date( int m = 1, int d = 1, int y = 1900 ); // constructor

   /* overloaded set methods */
   void setDate( const Date &d);  // set date
   void setDate( int, int, int ); // set date

   /* overloaded operators */
   Date &operator++();            // preincrement operator
   Date operator++( int );        // postincrement operator
   const Date &operator+=( int ); // add days, modify object

   /* utility methods */
   bool leapYear( int ) const;    // is this a leap year?
   bool endOfMonth( int ) const;  // is this end of month?
   void print() const {}  // print date in month/day/year format
   
   /* get methods */ 
   const Date & getDate() const {return *this;}   
   int getMonth() const {return month;} // return month
   int getDay() const {return day;}     // return day
   int getYear() const {return year;}   // return year 


private:
   int month;
   int day;
   int year;

   static const int days[];       // array of days per month
   void helpIncrement();          // utility function
};

#endif
