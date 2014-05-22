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



/*
int * input : a pointer to the beginning of an integer array
int count   : the number of elements to search .. search from input[0] to input[count-1]
int val : the value you are searching for
return type int : the position that 'val' was found at , if you reach the end of the array without finding it return -1
*/

int FindPosition(int * input,int count, int val);



/*
int * input : a pointer to the beginning of an integer array
int count   : the number of elements to search .. search from input[0] to input[count-1]
int val : the value you are searching for
int val : newval  the value to replace it with
return type int : 1 if you found the value and did a replace, 0 if you did not
*/

int Replace(int * input,int count, int val,int newval);




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

cout << endl << "search the array for the value 35, should return 7" << endl;
cout << FindPosition(myarray1,11, 35) << endl;

cout << endl << "search the array for the value 95, should return -1" << endl;
cout << FindPosition(myarray1,11, 95) << endl;
	
	
cout << endl << "search the array for the value 35, replace with 99 should return 1" << endl;
cout << Replace(myarray1,11,35, 99) << endl;

cout << endl <<  "print all of myarray1 " << endl;
PrintArray(myarray1,11);


cout << endl << "search the array for the value 35, replace with 99 should return -1,  as 35 should be gone now" << endl;
cout << Replace(myarray1,11,35, 99) << endl;

cout << endl << "search the array for the value 99, replace with 35 should return 1" << endl;
cout << Replace(myarray1,11,99,35) << endl;

cout << endl <<  "print all of myarray1 " << endl;
PrintArray(myarray1,11);








return 0;
}
