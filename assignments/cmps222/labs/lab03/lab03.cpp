/*
*  Nik Ramsey
*  CMPS 222
*  Winter 2012
*/
#include "cmps222lib.h"
#include <iomanip>
ofstream LOGFILE;


// your functions or file includes
void PrintArray(int *target, int count)
{
    LOGFILE << POS_IN_PROGRAM << "starting PrintArray(); " << endl;
    for(int loop=0; loop<count; loop++)
    {
       	cout<< *(target+loop) << ", ";
    }

    cout<<endl<<endl;
    LOGFILE << POS_IN_PROGRAM << "ending PrintArray(); " << endl;
}

void SortAscending (int *target, int count)
{   
    int *temp = new int[count];

    for(int loop2=0; loop2<count; loop2++)
    {
    	for(int loop1=0; loop1<count-1; loop1++)
    	{
		if(*(target+loop1)>*(target+loop1+1))
		{
  		LOGFILE << POS_IN_PROGRAM << "swapping positions "
	    	<< loop1 << " and " << loop1+1 << endl;
	    	swap(*(temp+loop1),*(target+loop1));
	    	swap(*(target+loop1),*(target+loop1+1));
	    	swap(*(target+loop1+1),*(temp+loop1));
		}
    	}
    }
}

void SortDescending (int *target, int count)
{   
    int *temp = new int[count];

    for(int loop2=0; loop2<count; loop2++)
    {
    	for(int loop1=0; loop1<count-1; loop1++)
    	{
		if(*(target+loop1)<*(target+loop1+1))
		{
  		LOGFILE << POS_IN_PROGRAM << "swapping positions "
	    	<< loop1 << " and " << loop1+1 << endl;
	    	swap(*(temp+loop1),*(target+loop1));
	    	swap(*(target+loop1),*(target+loop1+1));
	    	swap(*(target+loop1+1),*(temp+loop1));
		}
    	}
    }
}

int main()
{
LOGFILE.open("lab03.log",ios::trunc);
if (LOGFILE.is_open())
  LOGFILE << POS_IN_PROGRAM << "start of logging" << endl;
else 
  {
  cout << "Unable to open file for logging.";
  return 1;
  }
	
// now all your regular stuff can go here
const int size = 10;
int i_array[size]; 

for(int loop = 0; loop<size; loop++)
{
    *(i_array+loop) = CreateRandomNumber(1,99);
}

cout<<"Original: \n";
PrintArray(i_array, size);


cout<<"After SortAscending: \n";
SortAscending(i_array, size);
PrintArray(i_array, size);

cout<<"After SortDescending: \n";
SortDescending(i_array, size);
PrintArray(i_array, size);

// close the logfile and exit
LOGFILE.close();
return 0;
}
