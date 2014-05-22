/* filename: types.c
   1. demonstrate C compiler coercions ( automatic type conversions )

   2. demonstrate enumerated data types 

   3. demonstrate side-effects  */

#include <stdio.h>
#include <limits.h>

int main(void)
{
  int an_int, b = 10;
  float c = 10.5;
  float d = 3.0;
  char ch = 'a';
  float result;  
  int iresult,i;
  unsigned int uint = UINT_MAX;

  const int * iptr = & iresult; 

  /* float coerced into an int */
  an_int = c;                       
  printf("10.5: %d \n", an_int);     

  /* int coerced into a float */
  c = an_int;                       
  printf("float c: %f \n", c);     

  /* char coerced into an int using ASCII decimal equivalence */
  an_int = ch + 3;  
  printf("'a' + 3 should be 100: %d \n", an_int);   

  /* make sure you use the proper formatting character for unsigned int */
  printf("max unsigned int uint: %u \n", uint); 
  
  i = uint; 
  printf("max unsigned int coerced into int: %d \n", i);   

  /* coercion from int to float */
  result = an_int / b;  
  printf("%d / %d = %f\n", an_int, b, result);     

  result = an_int / c;  
  printf("%d / %f = %f\n", an_int, c, result);     

  iresult = c / d;  
  printf("%f / %f = %d\n", c, d, iresult);     
                
  /* Objects of enumerated type are interpreted as objects of type signed int, 
     and are compatible with objects of other integral types. */

  /* test precedence of post increment op and side-effects */
  an_int = an_int++;
  printf("a = a++: %d \n", an_int);     

  // define a type 
  enum bgcolors { silver, mauve, pink, gray } background_color;
  typedef enum { ssilver, mmauve, ppink, ggray } Colors;

  // declare a variable of that type
  Colors my_colors;
  background_color = silver;
  my_colors = ssilver;


  //  background_color = 7;  <==  ANSI C OK, but GNU catches this
  //  background_color = 0;  <== GNU catches this also
 
  // define another type 
  enum new_colors { black = 15, red = 10, blue, green = -7, white = green+2 };

  /* note: nested functions are supported in GNU C but not ANSI C */

  /* unsigned int can be coerced into int or char or other integral type */ 
  void test ( char s ) {
      printf("enum green (-7): %i\n", green); 
      printf("enum black (15): %i\n", black); 
      printf("enum white (green+2): %i\n", white); 
  }
  test(black);    

  /* const int * is coerced into int * */
  void test2 ( int * ptr ) {
      *ptr = *ptr + 1;
      printf("const value changed from 3 to 4: %i\n", *ptr); 
  }
  /* *iptr = 3 */
  test2(iptr);    

  void test3 ( Colors c ) {
      printf("c: %i\n", c); 
  }
  /* enumerated types are compatible if same structure even without same name*/
  test3 (black);
   
  return 0;
}
