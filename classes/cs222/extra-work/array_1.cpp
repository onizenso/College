#include <iostream>
#include <string>
#include <iomanip> 


using namespace std;

/*
int * input : a pointer to the beginning of an integer array
int count   : the number of elements to print out
*/
void PrintArray(int * input, int count);

int main()
{
int myarray1[] ={ 1,5,10,15,20,25,30,35,40,45,50};

cout << "print all of myarray1 " << endl;
PrintArray(myarray1,11);


cout << "print first 3  of myarray1 " << endl;
PrintArray(myarray1,3);



return 0;
}
