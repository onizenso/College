/* filename: strings.c

   demonstrate how char arrays (strings) are stored 
   
   $ gcc strings.c  
 
   The address space for an application contains the stack, code, data, and 
   the heap.  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stuff();

int MAX = 7; 
int int_array[50000000];

int main()
{
  int y = 6;
  printf("\nAddresses in the code segment of the executable:\n",&MAX);
  printf("global &MAX is : %p\n",&MAX);
  printf("global &int_array of size 300 : %p\n",&int_array);
  printf("If you change the array size, the size of the executable changes.\n");
  printf("\nThe runtime stack grows downwards from a high address:\n");
  printf("main: &int is: %p\n\n",&y);
  stuff();
  return 0;
}

void stuff ()
{
  /* demonstrate heap dynamic and stack dynamic arrays */
  int n;
  char fstr[100];  /* fixed string */
  printf("Enter size : ");
  scanf ("%d",&n); 
  char * str = (char *) malloc(sizeof(char[n]));
  int * x = (int *) malloc(sizeof(int));
  strcpy(fstr,str);
  int stack_arr[n]; 
   
  /* demonstrate that arrays are "limited" dynamic length in C
     and not allocated exactly the number of bytes specified  */ 
  int start = 0;    // just to mark address
  char str2[10] = "hi";
  char str3[20] = "hello";
  char str4[30] = "hello goodbye";

  printf("stack frame of stuff\n");
  printf("stack dynamic array : %p\n",stack_arr);
  printf("&start is   : %p\n",&start);
  printf("&str2[10] is: %p\n",str2);
  printf("&str3[20] is: %p\n",str3);
  printf("&str4[30] is: %p\n\n",str4);
  printf("The heap grows up from a low memory address:\n");
  printf("heap dynamic &str[n]: %p\n",str);
  printf("heap dynamic &x     : %p\n\n",x);

}
/* sample output with 3 strings of size [20] :
&str2[20] is: ffbef9e0  
&str3[20] is: ffbef9c8   24 bytes
&str4[20] is: ffbef9b0   24 bytes


sample output with 3 strings of various size:
&str2[10] is: ffbef9f0
&str3[20] is: ffbef9d8 24 bytes
&str4[30] is: ffbef9b8 32 bytes


*/

