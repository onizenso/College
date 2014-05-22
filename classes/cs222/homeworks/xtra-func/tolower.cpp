#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

void toLower(string *);

int main(){

    string test1;
    string *strptr;

    test1 = "This IS cap STRING";
    strptr = &test1;
    cout<< "Test string before toLower: " <<endl;
    cout<< test1;

    test1 = toLower(strptr);
    cout<< "The test string after toLower: " <<endl;
    cout<< test1;

}

void toLower(string *str){
    string::iterator i = 0;
    while(str[i]){
       if(isupper(str[i]))
	       tolower(str[i]);
	       }
	       }
	       
	       
