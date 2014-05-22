/* demonstrate structures and unions in C (e.g. record data type) 
   demonstrate bit fields */
  
#include <stdio.h>
#include <stdlib.h>
  
int main()
{
 
  typedef struct {
      char str[80];
  } Str80;

  int size = 5; 
  Str80 * str80s[size];
  
  str80s[0] = (Str80 *)malloc (sizeof(Str80));   
  str80s[1] = (Str80 *)malloc (sizeof(Str80));   

 
  
  /* structures may be nested and self-referential via pointers */
  typedef struct {
     char name[30];
     int ID;  
     struct {               /*  Nested structure */ 
          int day;
          int month;
          int year;
     } birth_date;
  
  } Employee;

  Employee jon, sue;    // this creates two variables of employee type
  Employee sam;
  
  sam.ID = 7347;
  jon.birth_date.day = 15;
  sue.ID = 7734;
 
  Employee * eptr = malloc(sizeof(Employee)); 
  eptr->ID = 9999;
  eptr->birth_date.day = 30;
  strcpy(eptr->name,"sam spade");
 
  /* example of structures using named and unnamed bit fields, which allow 
     data to be densely packed into storage */
  struct Bits { 
    unsigned int a:1;   // bit field of size 1 bit
    unsigned int :0 ;   // unnamed bit field of size 0 forces c to be aligned 
    unsigned int c:2;   // named bit field of size 2
    unsigned int b:1;   // named bit field of size 1 
  } bits;
  
  bits.a =5;   // assigns 'a' the least significant bit of 101
  bits.c =4;   // assigns 'c' the least 2 significant bits of 100
  
  printf("1 bits.a:(5)   %d \n", bits.a);
  printf("2 bits.c:(4)   %d \n", bits.c);

  bits.c =7;   // assigns 'c' the least 2 significant bits of 111
  printf("2 bits.c:(7)   %d \n", bits.c);

  bits.b =1;   // flip b bit 
  printf("bits.a %d & bits.b %d is %d \n", bits.a, bits.b, bits.a & bits.b);
  bits.b = bits.b << 1;   // left shift b bit 
  printf("bits.a %d & bits.b %d is %d \n", bits.a, bits.b, bits.a & bits.b);
  printf("bits.a %d | bits.b %d is %d \n", bits.a, bits.b, bits.a | bits.b);
  printf("bits.a %d ^ bits.b %d is %d \n", bits.a, bits.b, bits.a ^ bits.b);
  bits.b = 1;  
  printf("bits.a %d ^ bits.b %d is %d \n", bits.a, bits.b, bits.a ^ bits.b);
  return 0;
}
  
  /* sample output:
  1 bit :(5)   1
  2 bits:(4)   0
  2 bits:(7)   3
  
  */
