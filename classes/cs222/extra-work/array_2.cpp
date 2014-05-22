#include <iostream>
#include <string>
#include <iomanip> 


using namespace std;

/*
int * input : a pointer to the beginning of an integer array
int count   : the number of elements to print out
*/
void PrintArray(int * input, int count);

/*
int * input : a pointer to the beginning of an integer array
int count   : the number of elements to print out
print out elements in the array from postion (count -1) to postition 0
works the same as PrintArray but backwards
*/
void PrintArrayBackWards(int * input, int count);


int main()
{
int myarray1[] ={ 1,5,10,15,20,25,30,35,40,45,50};

cout << endl <<  "print all of myarray1 " << endl;
PrintArray(myarray1,11);

cout << endl << "print first 3  of myarray1 " << endl;
PrintArray(myarray1,3);

cout << endl << "print all of myarray1 " << endl;
PrintArrayBackWards(myarray1,11);

cout << endl << "print first 3  of myarray1 " << endl;
PrintArrayBackWards(myarray1,3);



return 0;
}


void PrintArray(int * input, int count)
{
    for(int loop=0; loop<count; loop++)
	cout<< *(input+loop) <<", ";
    	cout<< endl << endl;
}

void PrintArrayBackWards(int * input, int count)
{
    for(int loop=count-1; loop>=0; loop--)
	cout<< *(input+loop) <<", ";
    	cout<< endl << endl;
}
