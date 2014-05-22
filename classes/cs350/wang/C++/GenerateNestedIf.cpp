
/**
 * Name: Huaqing Wang
 * Description:
 *
 * Date:
 * */

#include <iostream>
#include <iomanip>
using namespace std;

int main( int argc, char * argv[] ) {

    // cout << "Enter number of nested ifs to generate: ";
    int n = 1000;
    // cin  >> n;

    for ( int i = 0; i < n; i++ )
      cout << "\t\t" << ( i == 0 ? "if": "else if" ) << " ( exp == "
	   << i << " ) caseCount[" << i << "]++;\n";

    return 0;
}
