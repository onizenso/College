//Need to test for bugs and why nothing is printing to the screen

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

bool pTest(int);
void primeGen(long int, long int, long int);
void printList(long int*);

long int bfn;

int main(int argc, char* argv[])
{
    if(argc<2){cout<<"Do this: ./primeFactor <num>"<<endl; exit(EXIT_FAILURE);}
    bfn=atol(argv[1]);
    long int sqrBfn=(long int)floor(sqrt(bfn));
    long int lowLimit=(long int)floor(sqrt(sqrBfn));
    
    primeGen(lowLimit, sqrBfn, bfn);

    return 0;
}

void primeGen(long int start, long int stop)
{
    int tmp[400];
    int count=0;
    for(int n=start;n<stop;n++)
        if(bfn%n==0){ tmp[count++] = (pTest(n))?n:0; } 
    for(int m=0;m<400;m++){ cout<<tmp[m]<<" "; if(m%5){cout<<endl;} }
}

bool pTest(int num)
{
    int j=0;
    int lim = (int)floor(sqrt(num));
    for(int i=2;i<lim;i++)
    {
        if(num%i==0){return false;}
        do
        {
           j = ((int)pow(i,2)) + (i*j);
           if(num%j==0){return false;}
        }while(j<=num);
    }
    return true;
}
