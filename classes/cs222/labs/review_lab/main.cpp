/*
*  Your Full Name
*  CMPS 222
*  Spring 2011
*/
#include "cmps22Xlib.h"
#include <iomanip>

ofstream LOGFILE;

using namespace std;
// your functions or file includes


int  PromptUserForInt( string message);
void PrintMenu ();
void PrintArray(int * start_of_the_array, int count);
void FillArray(int * start_of_the_array, int count, int newval);
void FillArrayRandom( int * start_of_the_array, int count, int min, int max);
int AddArrayElements(int * start_of_the_array, int count);


int main()
{
LOGFILE.open("errorlog.log",ios::trunc);
if (LOGFILE.is_open())
  LOGFILE << POS_IN_PROGRAM << "start of logging" << endl;
else 
  {
  cout << "Unable to open file for logging.";
  return 1;
  }
	
// now all your regular stuff can go here
int size = PromptUserForInt("how large would you like the array");

int * list = new int[ size];

// "list" is now a pointer to the array
int temp,sum,min,max;


int test =99;
while (test != 5)
  {
  PrintMenu();
  test = PromptUserForInt(">>");

  switch (test)
    {
    case 1: 
      PrintArray(list,size);
      break;

    case 2:	
      temp =PromptUserForInt("what number do you want to fill the array with?");
      FillArray(list,size,temp);
      break;

    case 3:
      min = PromptUserForInt("minimum value");
      max = PromptUserForInt("maximum value");
      FillArrayRandom(list, size, min, max);
      break;

    case 4:
      sum = AddArrayElements(list, size);
      cout << "the " << size << " elements in the array add up to " << sum << endl;
      break;

    case 5:
      return 0;
    
    }// end switch 
  } // end while


delete [] list;

// close the logfile and exit
LOGFILE.close();
return 0;
}





