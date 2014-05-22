// Lab 7 - Binary search

#include <iostream>
#include <limits>    // For numeric_limits
using namespace std;

#ifndef ELEMTYPE
#define ELEMTYPE int
#endif

// Binary search is given the array of elements, the element to search for,
// the index of the start of the search and the index of the end of the search.
// It returns the index where the value is found, or -1 if it is not found.
int binarySearch(ELEMTYPE *, ELEMTYPE, int, int);

int main()
{
  ELEMTYPE array[] = { 5, 9, 14, 23, 28, 32, 45, 64, 73, 92 };
  int size = 10;
  int index;
  ELEMTYPE key;

  while(1)
  {
    cout << "Enter element to search for (-1 to exit): ";
    cin >> key;

    if(cin.fail())
    {
      cout << "Invalid datatype. Please try again.\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }

    if(key == -1) break; // exit loop

    // Call binary search originally with the start=0 and the end=size-1
    index = binarySearch(array, key, 0, size-1);

    if(index == -1)
      cout << key << " not found in the array.\n";
    else
      cout << key << " found at index " << index << endl;

    cout << endl;
  }

  return 0;
}

//***************************************************************************
//
// Put body for binarySearch function here. See handout for pseudocode.
// Code will not compile without the body since a stub has not been put
// into this file.
//
//***************************************************************************

int binarySearch(ELEMTYPE *arr, ELEMTYPE key, int start, int end){
    if(start > end || start < 0)
        return -1;

    if(start == end){
        if(arr[start] == key)
            return start;
        else
            return -1;
    }

    int mid = (start+end)/2;
    
    if(arr[start]==key)
        return mid;
    else if(arr[mid] < key)
        return binarySearch(arr, key, mid+1, end);
    else
        return binarySearch(arr, key, start, mid-1);
}

