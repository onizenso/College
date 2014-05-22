/* filename : functions.cpp
   purpose:   Demonstrate parameter passing and use of reference type in C++ 

   Compile with debugging flags:   $ g++ -g functions.cpp
   Load into debugger:             $ gdb a.out
   Use debugging commands          gdb> break main
                                   gdb> run
                                   gdb> s                                   */

#include <iostream>

using namespace std;

static int MAX = 10;

class Stuff {
public:
    Stuff (int c=0 ) { count = c; }
    void setCount(int i) { count = i; } 
    int getCount() { return count; } 
private:
    int count;
};

// demonstrate the difference between C++ & type and Java pass-by-value
void fun(int i, int& iref, Stuff& sref ) // i, iref, sref are formal parameters
{
   printf("address of formal parameter i: %p\n", &i);  
   printf("address of formal parameter iref: %p\n", &iref);  
   printf("address of formal parameter sref: %p\n", &sref);  
   
   i = 10;                  // modifies the temporary variable in fun
   iref = 999;              // modifies the actual variable in calling routine 
   sref.setCount(200);      // modifies Stuff object in caller
   Stuff new_stuff(999);    // create a Stuff object local to this procedure
   sref = new_stuff;        // bit-copy of new_stuff to sref  
   new_stuff.setCount(222); // this doesn't modify anything in the caller
}


void increment (int* ii) 
{ ii++;   // this modifies the pointer's value not the value of the integer
  printf("address of formal parameter int*: %p\n", ii);  
}

int main( )
{
   MAX = 11;
   int i = 1;         
   int& ref = i;          // ref is an alias for i 
   int* ptr = &i;         // ptr is an indirect reference to i 

   int x = ref;           // x = 1
   ref++;                 // modifies i 
   ptr++;                 // modifies ptr


   int j = 2;      
 
   int** dptr = &ptr;    // pointer syntax is messy
   *dptr = &j;           // ptr now references another variable

                         // reference syntax is clean
   ref = j;              // bind ref to another variable

   Stuff s(100);
   printf("address of actual parameter i  : %p\n", &i);  
   printf("address of actual parameter s  : %p\n", &s);   


   cout << "Stuff before fun: " << s.getCount() << endl;  
   fun(j, i, s);            // i and s are actual parameters
   cout << "Stuff after fun: " << s.getCount() << endl;  
   cout << "i after fun: " << i << endl;  

   printf("address of actual parameter i  : %p\n", &i);  
   printf("address of actual parameter s  : %p\n", &s); 

   printf("address of actual parameter ptr: %p\n", ptr);  
   increment(ptr);          // value of actual parameter ptr is not changed 
   cout << "*ptr: " << i 
   << endl;
  
   Stuff * sptr = new Stuff;
   delete sptr;
 
   return 0;
}

/* Sample output:
 
 */
