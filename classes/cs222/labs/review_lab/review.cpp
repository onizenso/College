/*
*  Nik Ramsey
*  CMPS 222
*  Winter 2012
*/
#include "cmps222lib.h"
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
  LOGFILE << POS_IN_PROGRAM << "start of logging" << endl;
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

int PromptUserForInt( string message)
{
  LOGFILE << POS_IN_PROGRAM << "start of function" << endl;
    int temp = 0;
    cout<< "" << message << endl;
    cin>>temp;

    return temp;
  LOGFILE << POS_IN_PROGRAM << "end of function" << endl;
}

void PrintMenu () 
{
  LOGFILE << POS_IN_PROGRAM << "start of function" << endl;
    cout<<"****************************************"<< endl
        <<" * 1. PrintArray                       *"<< endl
        <<" * 2. Fill Array                       *"<< endl
        <<" * 3. Fill Array with Random Numbers   *"<< endl
        <<" * 4. Add values in the array          *"<< endl
        <<" * 5. exit program                     *"<< endl
        <<" ***************************************" << endl;
  LOGFILE << POS_IN_PROGRAM << "end of function" << endl;
}

void PrintArray (int * start_of_the_array, int count)
{
  LOGFILE << POS_IN_PROGRAM << "start of function" << endl;
    int i=0;
    for (i; i < count; i++)
    {
	cout<< "" << endl;
	cout<< i << " ---- " << *(start_of_the_array+i) << endl;
    }
    cout<< "" <<endl;
  LOGFILE << POS_IN_PROGRAM << "end of function" << endl;
}

void FillArray(int * start_of_the_array, int count, int newval)
{
    int i=0;
    for (i; i<count; i++)
    {
	*(start_of_the_array+i) = newval;
    }
}

void FillArrayRandom(int * start_of_the_array, int count, int min, int max)
{
    int i=0;
    for (i; i<count; i++)
    {
	*(start_of_the_array+i) = CreateRandomNumber(min, max);
    }
}

int AddArrayElements(int * start_of_the_array, int count)
{
    int i = 0;
    int sum = 0;
    for(i; i<count; i++)
    {
	sum += *(start_of_the_array+i);
    }

    return sum;
}

