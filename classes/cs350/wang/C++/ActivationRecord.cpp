/**
 * Name: Huaqing Wang
 * Description:
 *
 * Date:
 * */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>

using namespace std;

const int num_var = 15;
const int var_len = 31;

void * address[num_var];
char	 varNames[num_var][var_len];

void sortAndPrint() {

    char tmp[var_len];

    for ( int i = 0; i < num_var - 1; i ++ ) 
	for ( int j = i + 1; j < num_var; j ++ ) 
	    if ( address[j] < address[i] ) {
		swap( address[j], address[i] );
		strcpy( tmp, varNames[i] ); 
		strcpy( varNames[i], varNames[j] ); 
		strcpy( varNames[j], tmp);
	    }

    
    printf("\n\n\t\tSizes of int, long and void *, int *:  %lu, %lu, %lu, %lu\n",
	    sizeof(int), sizeof(long), sizeof(void *), sizeof( int * ) );
    printf("\n\n\t\t\tVariable Name       Address         Offset\n\n");
    for ( int i = 0; i < num_var ; i ++ ) 
    	printf("\t %30s  %17p  %lu\n", varNames[i], address[i],
		( i == num_var - 1 ? 0 : (unsigned long) address[i+1] - (unsigned long )address[i]) );

    cout << endl;
}

void q ( int q_par ) {
    int q_loc;
    int q_larr[q_par];

    strcpy( varNames[6], "q_loc");       address[6] = ( void *) (&q_loc) ;
    strcpy( varNames[7], "q_larr[n]");   address[7] = ( void *) (q_larr);
    strcpy( varNames[8], "q_par");       address[8] = ( void *) (&q_par);

    sortAndPrint();
}

void f ( int f_par ) {
    int f_loc;
    int f_larr[2];
    strcpy( varNames[3], "f_par");   address[3] = ( void *) (&f_par);
    strcpy( varNames[4], "f_loc");   address[4] = ( void *) (&f_loc);
    strcpy( varNames[5], "f_larr[2]");  address[5] = ( void *) (f_larr);
    q( 2 );
}



int main( int argc, char * argv[] ) {

    int	main_loc;


    strcpy( varNames[0], "main_argv");   address[0] = ( void *) (& argv) ;
    strcpy( varNames[1], "main_argc");   address[1] = ( void *) (& argc) ;
    strcpy( varNames[2], "main_loc");    address[2] = ( void *) (& main_loc) ;
    strcpy( varNames[9], "main(..)");    address[9] = ( void *)  main ;
    strcpy( varNames[10], "f(.)");    address[10] = ( void *) f  ;
    strcpy( varNames[11], "q(.)");    address[11] = ( void *) q ;
    strcpy( varNames[12], "sortAndPrint()");    address[12] = ( void *) sortAndPrint ;
    strcpy( varNames[13], "Beginsing of Address Space");    address[13] = ( void *) 0X000000000000;
    strcpy( varNames[14], "End of Address Space()");    address[14] = ( void *) 0X7fffffffffff;

    f( 100 );
    return 0;
}
