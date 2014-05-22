#include <iostream>
#include <cstdlib>

void centerstring(char *s){
    int len = strlen(s);
    int pos = (int)((50-len)/2);
    for(int i = 0; i < pos; i++)
        cout<< " ";

    cout<< s << endl;
return;
}

int count = 0;

void nextline(){
    if(count == 5){
        cout<< endl;
        count = 0;
    }
    ++count;
}

bool isInteger(char *input){
    int intbool;

    while(intbool = isdigit(*(input++)));

    return intbool ? true : false;
}

