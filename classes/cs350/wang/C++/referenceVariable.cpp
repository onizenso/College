
#include <iostream>
#include <cstring>
using namespace std;

int main( int agc, char ** ags ) {

    int x (100), & r (x), y(200);

    cout << "Adresss of  x = " << (&x) << endl;
    cout << "Adresss of &r = " << (&r) << endl;
    cout << "Adresss of  y = " << (&y) << endl;

	return 0; 
}

/* ----------- Output --------------
Adresss of  x = 0x7fff5fbff61c
Adresss of &r = 0x7fff5fbff61c
Adresss of  y = 0x7fff5fbff618
 */
