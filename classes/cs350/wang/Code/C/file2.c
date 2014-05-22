#include <stdio.h>

static int static_var = 20;

void funa( )
{
 extern GLOBAL;
 GLOBAL = 10;
 print("SHOULD PRINT 9: GLOBAL = %d\n",GLOBAL);
}
