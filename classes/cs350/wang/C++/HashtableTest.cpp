/**
 * Name: Huaqing Wang
 * Description:
 *
 * Date:
 * */

#include <iostream>
#include <iomanip>
#include "Hashtable.h"
#include "Member.h"

using namespace std;

int main( int argc, char * argv[] ) {

    Hashtable<Member> htb;
 
    char s[21]; 
    while ( true ) {
	htb.add( new Member() );
	cout << "\n\n Hashtable contents\n";
        htb.show();
	cin.getline(s, 21);
    }
    return 0;
}
