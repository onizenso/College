#include <iostream>
#include <typeinfo>

using namespace std;

bool byValue(int);
bool byReference(int&);
bool byPointer(int*);

int main(){
    int m = 0;
    int *ip = &m;
    cout << "By value: "     << byValue(m) ? "true" : "false";
    cout << " Should be: true " << endl;
    cout << "By reference: " << byReference(m) ? "true" : "false";
    cout << " Should be: true " << endl;
    cout << "By pointer: "   << byPointer(ip) ? "true" : "false";
    cout << " Should be: true " << endl;
    return 0;
}

bool byValue(int p){
    return typeid(p).name();
}
bool byReference(int &p){
    return typeid(p).name();
}
bool byPointer(int *p){
    return typeid(p).name();
}
