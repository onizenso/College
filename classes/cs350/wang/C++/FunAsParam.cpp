
#include <iostream>
#include <cstring>

using namespace std;

void fun ( int ( * parFun) (const char * ) ) {
    char s [] = "String passed to pFun.\n";

    cout << "\n\tfun:\t call parFun( s ) \n"; 
    int k = parFun ( s );
    cout << "\n\tfun: \treturn from parFun( ) = " << k << endl << endl;
}

int printReturn ( const char * str ) {

    cout << "\n\tprintReturn ( const * str ) : str = \t" << str << endl;

    return strlen( str );

}

int main( int agc, char ** ags ) {

	// call fun and pass printRetun to fun without any parameter.

        cout << "\n\n\tmain: \tcall fun ( printReturn )" << endl ;
    	fun( printReturn );

	return 0; 
}
