/**
 * Name: Huaqing Wang
 * Description:
 *
 * Date:
 * */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>

using namespace std;

const int num_var = 9;
const int var_len = 21;

unsigned long address[num_var];
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

    
    printf("\t\tSizes of int, long and unsigned long, int *:  %d, %d, %d, %lu\n\n", sizeof(int), sizeof(long), sizeof(unsigned long), sizeof( int * ) );
    printf("\n\n\tVariable Name       Address         Offset\n\n");
    for ( int i = 0; i < num_var; i ++ ) 
    	printf("\t%-15s %18lu      %d\n", varNames[i], address[i], (i==num_var-1 ? 0 : address[i+1] - address[i]) );

    cout << endl;
}

void q ( int q_par ) {
    int q_loc;
    int q_larr[q_par];

    strcpy( varNames[6], "q_loc");       address[6] = ( unsigned long) (&q_loc) ;
    strcpy( varNames[7], "q_larr[n]");   address[7] = ( unsigned long) (q_larr);
    strcpy( varNames[8], "q_par");       address[8] = ( unsigned long) (&q_par);
}

void f ( int f_par ) {
    int f_loc;
    int f_larr[2];

    q( 2 );

    strcpy( varNames[3], "f_par");   address[3] = ( unsigned long) (&f_par);
    strcpy( varNames[4], "f_loc");   address[4] = ( unsigned long) (&f_loc);
    strcpy( varNames[5], "f_larr[2]");  address[5] = ( unsigned long) (f_larr);

}



int main( int argc, char * argv[] ) {

    int	main_loc;

    f( 100 );


    strcpy( varNames[0], "main_argv");   address[0] = ( unsigned long) (& argv) ;
    strcpy( varNames[1], "main_argc");   address[1] = ( unsigned long) (& argc) ;
    strcpy( varNames[2], "main_loc");    address[2] = ( unsigned long) (& main_loc) ;

    cout << "Address of argc = " << (unsigned long) &argc << endl;

    sortAndPrint();
    return 0;
}
