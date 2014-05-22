#include <stdio.h>

int main(){

int i=0;

for(; i <= 20; i++)
{
    if(((i % 3 == 0) && (i % 5 == 0)) && (i != 0))
	printf("fizbuz\n");
    else if((i % 3 == 0) && (i != 0)){ printf("fiz\n"); }
    else if((i % 5 == 0) && (i != 0)){ printf("buz\n"); }
    else
	printf("%i\n", i);
}
}
