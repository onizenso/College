/* cs 350
   d meyers
   demonstrates "free" unions in C */

#include <stdio.h>

int main()
{
/* the variable u1 will be statically allocated enough room to hold the
   largest of the three types, which in this case is a double; only one 
   value will be stored at any time */ 

   union u1_type {
      double f_val;
      int i_val;
      char c_val;
   } u1;

  /* use the dot operator to access union members*/
   u1.f_val = 'a';  // <== there is no type checking so this is OK 

  /* the first value of a union can be initialized when declared */
   union u2_type {
      float f_val;
      int i_val;
      char c_val;
   } u2 ={ 77.77 };

  u2_type u3;
  int n;
  printf("Enter an integer: ");
  scanf ("%d",&n); 
  printf("\nYou entered: %d\n",n);
  u1.i_val = n;

  /* it's up to the programmer to remember what value type the union has! */
  printf("u1: %d \n",u1.i_val);
  printf("u2: %f \n",u2.f_val);
  
  /* the compiler won't check it! */
  printf("u1: %c \n",u1.c_val);
   
  /* unions can be assigned to one another if of like type */
  u3 = u2;
//u1 = u2;  <== this won't work

 /* declare a union and show that members are aliases to the same address */
  typedef union {
      double dvalue;
      char svalue[20];
      float fvalue;
   } union_type;

  union_type my_union;
  my_union.dvalue = 3.14;

  /* show that the union members are aliases to the same memory location */
  printf("my_union.dvalue: %p \n", &my_union.dvalue);
  printf("my_union.svalue: %p \n", &my_union.svalue);
  printf("my_union.fvalue: %p \n", &my_union.fvalue);


  return 0;
}
