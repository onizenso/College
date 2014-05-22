/*
*  Nik Ramsey
*  CMPS 222
*  Winter 2012
*/
#include "cmps222lib.h"   
#include <iomanip>
ofstream LOGFILE;


// your functions or file includes

int *int_array;
int count;
int capacity;


void PrintArray(int *array, int count)
{
  LOGFILE << POS_IN_PROGRAM << "starting PrintArray();" << endl;

    for (int i=0; i<count; i++)
    {
       LOGFILE << POS_IN_PROGRAM << "printing position "<< i << endl;
        cout<< "position >" << setw(2) << setfill('0') << right << i 
	    << "< variable size >" << sizeof(*(array+i)) << "< sizeof(pointer)>" 
	    << sizeof(array) << "< address >" << array+i << "< value >" 
	    << setw(2) << setfill('0') << right << *(array+i) << "<" << endl;
    }

    cout<< "" << endl;

  LOGFILE << POS_IN_PROGRAM << "ending PrintArray();" << endl;
}

void addAnInteger (int val)
{
  LOGFILE << POS_IN_PROGRAM << "start of addAnInteger" << endl;
  LOGFILE << POS_IN_PROGRAM << "array capacity is: " << capacity 
          << "array count is: " << count << " value to add: " << val << endl;
  if (count == capacity)
  {
      LOGFILE << POS_IN_PROGRAM << "resize forced"  << endl;
      cout << "resizing array from " << capacity << " to " << capacity*2 << endl;

      int * temp;
      temp = new int[capacity*2];

      for(int loop=0; loop < count; loop++)
	  temp[loop] = int_array[loop];

      delete [] int_array; 
      
      int_array = temp;
      capacity *= 2;
      
  }
  
  LOGFILE << POS_IN_PROGRAM << "array capacity is: " << capacity 
  << " array current count: " << count << " adding: " << val << endl;

      *(int_array+count) = val;
      count++;
}


int main()
{
LOGFILE.open("hw02.log",ios::trunc);
if (LOGFILE.is_open())
  LOGFILE << POS_IN_PROGRAM << "start of logging" << endl;
else 
  {
  cout << "Unable to open file for logging.";
  return 1;
  }
	
// now all your regular stuff can go here

count = 0;
capacity = 4;
int_array = new int[capacity];
int loop = 10;

for(loop; loop<40; loop+=10)
{
cout<< "Adding (" << loop << ")" << endl;
addAnInteger(loop);
}
cout<< "Print the array" << endl;
PrintArray(int_array, count);
cout << endl << endl;

for(loop; loop<70; loop+=10)
{
cout<< "Adding (" << loop << ")" << endl;
addAnInteger(loop);
}

cout<< "Print the array" << endl;
PrintArray(int_array, count);
cout << endl << endl;
for(loop; loop<100; loop+=10)
{
cout<< "Adding (" << loop << ")" << endl;
addAnInteger(loop);
}
cout<< "Print the array" << endl;
PrintArray(int_array, count);
cout << endl << endl;

for(loop; loop<130; loop+=10)
{
cout<< "Adding (" << loop << ")" << endl;
addAnInteger(loop);
}
cout<< "Print the array" << endl;
PrintArray(int_array, count);
cout << endl << endl;

for(loop; loop<160; loop+=10)
{
cout<< "Adding (" << loop << ")" << endl;
addAnInteger(loop);
}
cout<< "Print the array" << endl;
PrintArray(int_array, count);
cout << endl << endl;
// close the logfile and exit
LOGFILE.close();
return 0;
}
