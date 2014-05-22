#include <iostream>
#include <sstream>
#include "testmain.h"

using namespace std;


int main()
{
    booklist a;
    a.Push("12345GA4", 3);
    a.Push("84592F4G", 2); 
    a.Push("12345GA4", 3); 

    //Book a,b,c;
    booklist b(a);

    cout<< a.ToString()<< endl;
    cout<< b.ToString()<< endl;
    cout<< c.ToString()<< endl;

}
