/* filename: hw08.c   hw08 sample problems */
  
# include <stdio.h>
#define SIZE  4 
  
int main () 
{
   int i, k;
   double d = 0.0;
   int array[SIZE] = {5,1,2,0};
   float num[SIZE] = {5.2,1.1,2.5,0.7};
   int x[SIZE][SIZE];
   int j=0;
   /********************************
   *   DEMONSTRATE C CONDITIONS    *
   *********************************/ 

   while (j = 0) ;    // this is legal
   while (d) ;       // this is legal


   /**********************************************
   *   DEMONSTRATE C UNCONDITIONAL BRANCHING     *
   **********************************************/ 
   
   while (j < 3)
   {
          if (array[j] < 1)
              goto out_of_bounds;
          else if (array[j] == 1) 
              break;  // breaks out of loop
          else if (array[j] > 1) {
              j++;
              continue;  // breaks to top of loop
          }
   }
   printf("break me out of here\n");
   out_of_bounds: printf("goto jail\n");
   
   for (i = 0; i < SIZE; i++) { 
      if (num[i] <= 1.00) // skip values <= 1.00 
           continue; 
      printf("value = %.2f\n", num[i]); 
   }
   
   for (i = 0; i < SIZE; i++) { 
      if (num[i] <= 1.00)  /* break for values <= 1.00 */ 
      {
         printf("value = %.2f\n", num[i]); 
         break;  // break loop not if
      } 
      printf("value = %.2f\n", num[i]); 
   }
 
 /*****************************************************
  *   DEMONSTRATE USER CONTROLLED LOOP ENTRY/EXIT     *   
  *****************************************************/
   goto jump_in;
   while (1) {
      printf("This never prints so I never make it here...\n");
      while (1)
          jump_in: 
          break;    // breaks out of inner loop only
      break;        // need another break for outer loop
   }
 
   /* initialize a matrix - assume SIZE is 4 */
   for ( i = 0; i < SIZE; i++ ) 
        for ( j = 0; j < SIZE; j++ ) 
           x[i][j] = i+j;   // [0 1 2 3] [1 2 3 4] [2 3 4 5] [3 4 5 6] 

   /* zero out row 3 */
   for ( i = SIZE-1; i == SIZE-1; i++ ) 
        for ( j = 0; j < SIZE; j++ ) 
            x[i][j] = 0; 
   
   /* look for that row using a gotos  */
   for ( i = 0; i < SIZE; i++ ) {
        for ( j = 0; j < SIZE; j++ ) {
           if ( x[i][j] != 0)
              goto reject;
        }
        printf ("the answer is: %d\n", i);
        break;
        reject: printf ("reject: %d \n", i);
   }
   
   /* code without gotos is a little strained */
   int flag;
   i = 0;
   while ( i < SIZE )
   {
      flag = 1;
      for ( j = 0; j < SIZE; j++ )  {
         if ( x[i][j] != 0) {
            flag = 0; 
         }
      }
   
      if ( flag == 1)  {
           printf("The answer is: %d\n", i);
           i = SIZE ;   // force a break
      } 
      i++;
   }  // end while



   /*******************************************
   *     DEMONSTRATE C-STYLE FOR LOOPS        *
   ********************************************/ 

   /* can code ANY CONSTRUCT with an IF and a GOTO!! 
     example: a C "for loop" */

   for (k=1; k<=10; k++) ;

   /*pseudocode:
   k = 1
   loop:
      if k > 10 then goto out
      k = k + 1
      goto loop
   out: ...  */
   
   /* can code a C "for loop" with a "while" */

   // loop variable can be a float
   float END = 10.0;
   for (d=1.2; d <= END; d+=1.2){
      d+=1;
      END--;
      printf("HI ");
   }
   printf("\nd: %f\n",d); 

   // the equivalent while
   d = 1.2;
   while ( d <= 10.0 ) {
      printf("HI ");
      d = d + 1.2;
   }
   printf("\nd: %f\n",d); 

 
   /* the equivalent pseudocode:
   k = 1.2
   loop:
      if k > 10 then goto out
      print "hi"
      k = k + 1.2
      goto loop
   out: ...  */

   // C for loops support optimum flexibility
   d=1.2;
   for (; d <= 10.0; printf("HI ")) {
      d += 1.2; // can change loop variable in loop
   }
   /* all parameters are optional! */
   for (;;)
     break; 
    
   /* a few other examples of  C-style for loops */
  int start=1;
  int end=5;
  for (i=start; i < end; i++) {
     printf("%d\n",i); 
     /* it is legal to modify the loop variable */
     if (i == 4){
        printf("skip 5\n"); 
        i++;
     }
     /* it is also legal to modify the loop parameters*/
     end = 10;
  }

  /* don't even need an explicit loop control variable */
  int counter = 0;
  for ( printf("start\n"); ; printf("looping\n") ) {
     counter++;
     if (counter > 5) break;
  }

  /*******************
    negative logic   
  ********************/

  flag = 0;
  while ( ! flag ){
     flag = 1;
  }
 
   /***********************************************************
   *   N-WAY SELECTION STATEMENT AND FLOW THROUGH SEMANTICS   *
   ***********************************************************/ 
   
  /* the multiple selection statement below is a switch with breaks
   
   if (( k == 1) || ( k == 2)) j = 2 * k - 1
   if (( k == 3) || ( k == 5)) j = 3 * k + 1
   if ( k == 4) || j = 4 * k - 1
   if (( k == 6) || ( k == 7)) || (k == 8)) j =  k - 2
   */
   
   k = 1;   
   switch (k)  // must be integral type
   {
    case 1: 
       // flow through  
    case 2:
       printf("\nm is 1 or 2\n", k);
       j = 2*k-1;
       break;
    case 3: 

    case 5:
       printf("\nm is 3 or 5\n", k);
       j = 3*k+1;
       break;
    case 4:
       printf("\nm is 4\n", k);
       j = 4*k-1;
       break;
    default:
      printf ("\neverything else, m =%d\n", k);
      j = k-2;
   }
   
/* if statements can replace a switch statement with breaks
   
   j = -3;
   int i;
   for ( i = 0; i < 3; i++) {
     switch (j+2) {
        case 3:
        case 2: j--; break;
        case 0: j += 2; break;
        default: j = 0;
     }
     if ( j > 0 ) break;
     j = 3 - i;
     }
   */
   
   j = -3;
   i = 0;
   while ( i < 3 && j > 0) {
      if ( j+2 == 2 )
         j--;
      else if ( j+2 == 0 )
         j += 2;
      else
         j = 0;
     i++;
     j = 3 - i;
   }
 
   // a switch with no breaks flows through everything   
   // what is printed if value is set to 2? to 3? to 5?

   int value = 2;
   switch (value) {
      case 1: printf("one\n");   
      case 2: printf("two\n");   
      case 3: printf("three\n");   
      case 4: printf("four\n");   
      case 5: printf("five\n");   
      default: printf("whatever\n"); 
   }

   return 0;
}
