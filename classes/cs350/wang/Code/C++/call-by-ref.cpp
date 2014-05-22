// demonstrate C++ call by reference, C call by value and function side-effects

#include <iostream>
using namespace std;

int funa(int & ref1, int & ref2){
   ref1++;   // these statements will modify the value in calling routine
   ref2++;   
   return ref1 + ref2;
}

void test(char * str){
    str[0] = 'a';
}

int main(){

int size = 5;
int size2 = 99;
int & iref = size;        // iref is a reference (aka alias) for size
iref++;                   // since iref is an alias, size is incremented
int & iref2 = size2;        // iref is a reference (aka alias) for size
iref = iref2;              // this assigns the value of size to be 99
iref2 = 66;
cout << "iref value is still 99:" << iref << endl;
cout << "size value is also 99:" << size << endl;

// test call by reference and function side-effects
cout << "Size value should be 14: " << funa(iref,iref) << endl;


// implicit address dereferencing 
cout <<  "iref: " << iref << " size: " << size << endl;
iref--;
cout <<  "iref: " << iref << " size: " << size << endl;

bool flag = false;
int i = 0;
int num = 0;
int list[size];
int first, minimum, temp, index;

int j = 0;
// test conditional target on assignment
(7 > 4) ? i : j = 5;
cout << "j should be 5: " << j << endl;

// test("hello");   <- segmentation fault if you call this

for (first = 0; first < size; first++){
   minimum = first;
   for (index = first; index < size; index++)
       if (list[minimum] > list[index]);
   minimum = index;
   temp = list[first];
   list[first] = list[minimum];
   list[minimum] = temp;

}

do {
  i++;
  num++;
}
while (i < 10);

/* a block containing no statements is legal */
 { } 
return 0;
}
