
/**
 * Name: Huaqing Wang
 * Description:
 *
 * Date:
 * */

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
const int size = 16;
void * address[size];
string name[size];

void sortAddress() {
    for ( int i = 0; i < size - 1; i ++ ) 
	for (int j = i + 1; j < size; j++ ) 
		if ( address[i] > address[j] ) {
		    swap( address[i], address[j] );
		    swap ( name[i], name[j] );
		}
}

void print (  ) {
    printf("\n\n\t\t%30s  %-15s  %s\n\n", "Program Unit Name", "Address", "Distnace to Next Program Unit");
    for ( int i = 0; i < size; i++ ) 
	printf("\t\t%30s %-17p  %lu\n", name[i].c_str(), address[i],
			i == size - 1 ? 0 :  (unsigned long)address[i+1] - (unsigned long) address[i] );
    printf("\n\n");
}

static int g1;
void fun ( int p1, double  p2 ) {
    static int si;
    	   int di;

    name[7] = "fun()'s static loc si"; 		address[7] = &si;
    name[8] = "fun()'s stack-dynamic di";  	address[8] = &di;
    name[9] = "fun()'s par int p1"; 		address[9] = &p1;
    name[10] = "fun()'s par double p2"; 	address[10] = &p2;
}

static int g2;
int main( int argc, char * argv[] ) {

    name[0] = "gloabl var g1";			address[0]  = &g1;
    name[1] = "gloabl var g2";			address[1] =  &g2;
    name[2] = "main()";      			address[2] = (void *) main;
    name[3] = "sortAddress()";          	address[3] = (void *) sortAddress;
    name[4] = "print()";      			address[4] = (void *) print;
    name[5] = "fun()";				address[5] = (void *) fun ;
    name[6] = "main()'s param. argc";		address[6] = &argc;
    name[11] = "heap dynamic nameless 1";	address[11] = (new int);
    name[12] = "heap dynamic nameless 2";	address[12] = (new int);
    name[13] = "begining of memory";		address[13] = (void *) 0;
    name[14] = "end of memory";			address[14] = (void * ) (0x7fffffffffff);
    name[15] = "main()'s argcv";		address[15] = &argv;

    double d;
    fun(argc, d);

    sortAddress ( );
    print();

    return 0;
}
