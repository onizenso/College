
/**
 * Name: Huaqing Wang
 * Description:
 *
 * Date:
 * */

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

class NameAddress {

    protected:
	int		length;
	int		count;
	string *  	* pNames;
    	void   *  	* pAddrs;

    public:
	NameAddress ( int n ) {
	    length = n;  count = 0;
	    pNames 	=  new string * [n];
	    pAddrs	=  new  void * [n];
	}

	void add( string name, void * addr) {
	    if ( count >= length ) return ;
	    pNames[count] = new string (name);
	    pAddrs[count] = addr;
	    count ++;
	}
	const char * toString( int k ) {
	    static char s[101] ;
	    sprintf(s, "%30s\t%lu", pNames[k]->c_str(), (unsigned long) pAddrs[k]) ;
	    return s;
	}
	
	void show() {
	    for ( int i = 0; i < count; i++ )
		cout << toString(i) << endl;
	}
};
	

int factorial( int n ) {

    if ( n <= 1 ) { return 1; }
    return n * factorial( n - 1);
}

void showNameAddress( const char * title, NameAddress nd ) {

    cout << "\n\t\t" << title << endl;
    nd.show();
}

int main( int argc, char * argv[] ) {

    NameAddress codeSec(10) ;
    NameAddress dataSec(20) ;
    codeSec.add( "main(argc, argc )", (void*) main );
    codeSec.add( "factorial(n)", (void*) factorial);
    codeSec.add( "showNameAddress(title, nd)", (void*) showNameAddress);

    dataSec.add( "argc", (void*) &argc);
    dataSec.add( "argv", (void*) &argv);


    showNameAddress( "\n\t\tMemory Map for Code Section\n", codeSec) ;
    showNameAddress( "\n\n\t\tMemory Map for Data (partial ARIs)  Section\n", dataSec);

    

    return 0;
}
