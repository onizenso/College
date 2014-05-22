/* Filename:   list.h
   Purpose:    CS 350 Lab 1 
   Descrip:    a List template with C++ exception handling  
   Note: when compiling a template class the full code is checked by the 
   compiler only when you instantiate a template class object and you call 
   EACH and EVERY method.  */
 
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <iomanip>
#include <stdexcept>   
#include <stdio.h>
#include "range_error.h"

using namespace std;

template <class T>
class List  {
  template <class T1>
  friend ostream & operator << (ostream &, List<T1> & );

public:
  
  List();
  void add(const T &);
  void print();  
  int size();
  void swap(int, int);
  int max(int, int);
  void sort();

  static const int MAX = 10;

private:
  T list[MAX];
  int count;
};

template <class T>
List<T>::List()
{
  count = 0;
}


template <class T>
void List<T>::add(const T &value)
{
  // surround the out-of-bounds check in a try block
  try {
    if ( count >= MAX )
        throw RangeError (__FILE__, __func__, __LINE__, count);
  }
  // every try block must have a catch 
  catch ( const RangeError &err)
  {
     throw err;
  }
  // if we make it here we can safely add the value
   list[count++] = value;
}


template <class T>
void List<T>::print()
{
  // format for doubles just in case 
  cout << setiosflags( ios::fixed | ios::showpoint ) << setprecision( 1 );

  // this try block uses an exception from the standard library 
  try 
  {
     if ( count >= MAX )
        throw out_of_range ("stdexcept: out_of_range");
  }

  // every exception in the standard lib has a what() method
  catch ( const out_of_range err )
  {
      cerr << err.what() << endl;
      throw err;
  }

  // we can safely display the list 
  for (int i = 0; i < count; i++)
     cout << setw(7) << list[i];
  cout << endl;
}

template <class T>
int List<T>::size()
{
  return count;
}


template <class T>
void List<T>::swap(int i, int j)
// swap the value at position i with the value at position j 
{

  try
  {
    if (i < 0 || i >= count )
        throw RangeError (__FILE__, __func__, __LINE__, count);
    
    if (j < 0 || j >= count )
        throw RangeError (__FILE__, __func__, __LINE__, j);
  }
  catch (const RangeError &err)
  {
    cerr << err;
    throw err;
  }

  T temp;
  temp = list[i];
  list[i] = list[j];
  list[j] = temp; 
}

template <class T>
int List<T>::max(int i,int j)
/* return the larger position of the ith and jth element */
{

  try {
    if (i < 0 || i >= count || j < 0 || j >= count)
        throw RangeError (__FILE__, __func__, __LINE__, count);
  }
  catch (const RangeError &R)
  {
    cout << R;
    throw R;
  }

  if (list[i] > list[j]) 
   { return i; }
  else 
   { return j; }
}

template <class T>
void List<T>::sort()
/* optimized ascending bubble-sort algorithm */
{
  // check the value of count before sorting
  try {
    if (count >= MAX)
        throw RangeError (__FILE__, __func__, __LINE__, count);
  }

  catch (const RangeError &R) {
    cout << R;
    throw R;
  }

  // safe to sort
  for ( int i = 1; i < count; i++ )    // or <= count -1
         for ( int j = 0; j < count-i; j++ )    
            if ( list[j] > list[j+1] )      
               swap(j,j+1);
}

template <class T1>
ostream & operator << (ostream & out, List<T1> & l)
{
  // check the value of count before displaying 
  try {
    if (l.count >= List<T1>::MAX)
        throw RangeError ( __FILE__, __func__, __LINE__ , l.count);
  }
  catch (const RangeError &R) {
    cout << R;
    throw R;
  }

  // safe to display
  for ( int i = 0; i < l.count; i ++ )
       out << setw(5) << l.list[i] << " " << endl;
}
#endif
