
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
const int size = 15;
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

void print ( ) {
    printf("\n\n\t\t%30s   %-15s  %s\n", "Variable Name", "Address", "Size/distnace to Next Program Unit");
    for ( int i = 0; i < size; i++ ) 
	printf("\t\t%30s %-17p  %lu\n", name[i].c_str(), address[i],
			i == size - 1 ? 0 :  (unsigned long)address[i+1] - (unsigned long) address[i] );
    printf("\n\n");
}

static int g1;
void fun ( int i  ) {
    static int si;
    	   int di;

    name[7] = "fun()'s static loc si"; 		address[7] = &si;
    name[8] = "fun()'s stack-dynamic di";  	address[8] = &di;
    name[9] = "fun()'s parameter i"; 		address[9] = &i;
}

static int g2;
int main( int argc, char * argv[] ) {
    int k(200);
    name[0] = "gloabl var g1";		address[0]  = &g1;
    name[1] = "gloabl var g2";		address[1] =  &g2;
    name[2] = "main()";      		address[2] = (void *) main;
    name[3] = "sortAddress()";         address[3] = (void *) sortAddress;
    name[4] = "print()";      		address[4] = (void *) print;
    name[5] = "fun()";			address[5] = (void *) fun ;
    name[6] = "main()'s param. argc";	address[6] = &argc;
    name[10] = "heap dynamic nameless 1";	address[10] = new int;
    name[11] = "heap dynamic nameless 2";	address[11] = new int;
    name[12] = "begining of memory";		address[12] = (void *) 0;
    name[13] = "end of memory";			address[13] = (void * ) (0x7fffa0000000);
    name[14] = "main's local int k";			address[14] = (void * ) & k;

    fun(100);

    sortAddress ( );
    print( );

    return 0;
}
