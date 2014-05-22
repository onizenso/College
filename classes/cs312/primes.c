#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char* chararr[]){
    if(argc > 2){
        printf("You fucked up");
        return 1;
    }
 
    const int full = 20;
    int pool[1000], prims[20];
    int n, c;
    int pcnt = 0;


    n = atoi(chararr[1]);

    if(n < 2 || n > 2000000){
        printf("ERROR: Invalid number. \n");
        printf("Enter value b/w 2 and 2 million \n");
        return 1;
    }

    int jim = 0;
    for(;jim < 1000; jim++){ 
        pool[jim] = jim + n; 
        //printf("%d ", pool[jim]);
    }

    c = 0; // set count to zero

    double halt;
    int mod = 2;

    while(pcnt < 20){
        halt = sqrt(n+c);
        if (pool[c] % mod == 0){
            pool[c] = 0;
            ++c;
            mod = 2;
        }  
        else{
            ++mod;
            if(mod > halt){
               prims[pcnt] = pool[c];
               ++c;
               ++pcnt;
               mod = 2;
            }
        }
    }

    int cdwn = 0;

    printf("And now for the primes.\n");
    for(; cdwn < 20; cdwn++){
        printf("Prime %d: %d\n", cdwn+1, prims[cdwn]);
    }

    return 0;
}
