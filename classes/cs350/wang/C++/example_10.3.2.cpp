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

const int num_var = 10;
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

    
    printf("\t\tSizes of int, float, and unsigned long, int *:  %d, %d, %d, %lu\n\n", sizeof(int),
	    sizeof(float ), sizeof(unsigned long), sizeof( int * ) );
    printf("\n\n\tVariable Name       Address         Offset\n\n");
    for ( int i = 0; i < num_var; i ++ ) 
    	printf("\t%-15s %18lu      %d\n\n", varNames[i], address[i], (i==num_var-1 ? 0 : address[i+1] - address[i]) );

    cout << endl;
}

void fun3( int  fun3_p_q ) {

    int fun3_l_x, fun3_l_y, fun3_l_z;

    strcpy( varNames[6], "fun3_p_q");       address[6] = ( unsigned long) (&fun3_p_q) ;
    strcpy( varNames[7], "fun3_l_x");       address[7] = ( unsigned long) (&fun3_l_x) ;
    strcpy( varNames[8], "fun3_l_y");       address[8] = ( unsigned long) (&fun3_l_y) ;
    strcpy( varNames[9], "fun3_l_z");       address[9] = ( unsigned long) (&fun3_l_z) ;
    return;
}

void fun2 ( int fun2_p_x ) {
    int fun2_l_y;

    fun3( fun2_l_y);

    strcpy( varNames[4], "fun2_l_y");       address[4] = ( unsigned long) (&fun2_l_y) ;
    strcpy( varNames[5], "fun2_p_x");       address[5] = ( unsigned long) (&fun2_p_x);
}

void fun1 ( int fun1_p_r ) {
    int fun1_l_s, fun1_l_t;

    fun2( fun1_l_s );

    strcpy( varNames[1], "fun1_p_r");   address[1] = ( unsigned long) (&fun1_p_r);
    strcpy( varNames[2], "fun1_l_s");   address[2] = ( unsigned long) (&fun1_l_s);
    strcpy( varNames[3], "fun1_l_t");   address[3] = ( unsigned long) (&fun1_l_t);

}



int main( ) {

    int	main_l_p;

    fun1( main_l_p );


    strcpy( varNames[0], "main_l_p");    address[0] = ( unsigned long) (& main_l_p) ;


    sortAndPrint();
    return 0;
}
