
/**
 * Name: Huaqing Wang
 * Description:
 *
 * Date:
 * */

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main( int argc, char * argv[] ) {

    char s[] = "( 1 + 2 * 30 )";

    cout << "Input string = |" << s << "|\n";
    char * pch = strtok(s, " ");

    while ( pch != NULL ) {
	cout << pch << ", ";
	pch = strtok(NULL, " ");
    }

    return 0;
}
