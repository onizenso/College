#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int recur(int);
void period(int*);
int num = 0;
int main(int argc, char* argv[]){
    if(argc != 2){
	printf("Use: ./recur <number to factor>");
	exit(EXIT_FAILURE);
    }
    
    if(recur(atoi(argv[1]))==-1){printf("You broke me!>=1");exit(EXIT_FAILURE);
    
    return 0;
}

int recur(int mem)
{
    int *tmp = &mem; 
    if(num < 1)
    {
        printf("Invalid input");
        exit(EXIT_FAILURE);
    }
    else if(num >= 1)
    {
        printf("%i", mem);
        period(tmp);
        mem-=1;
        recur(num);
    }
    else
        return num;
}

void period(int *cnt)
{
    //write this function to create counter that is
    //independent from the index used for the recur
    //function
}
