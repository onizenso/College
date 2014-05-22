/* demonstrate static scope rules in C */
#include <stdio.h>
  
void funa();  // this is a function name ; is it static or extern

static int static_var = 15;
int GLOBAL = 10;

int test(int *);
int test2(char *);
  
int main(){
  int w, x, y, z, n;     // S1 
     { int x, z;         // S2
	 y = 1;          // references y in scope S1
	 { int x, y;     // S3 
	     w = 1;      // references w in scope S1 
	 }
     }
  z = 1;  // references z in scope S1  
  char str[4]; 
//  test(n);
  test2(str);
  int size = 5;
  int i = 0;
  int num = 0;
   static_var = 14;
  int list[size];
  int first, minimum, temp, index;

  {
    static int static_var = 15;
   
  }  
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
  funa();
return 0;

}
int  test(int * num) { return 0; } 
int  test2(char * num) { return 0; } 
