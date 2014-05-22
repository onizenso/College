#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;

string type(const char *);

int main()
{
  int a = 8;
  const char* c;
  c = typeid(a).name();
  cout << "Primitive: " << type( typeid(char).name() )  << '\n'; 
  cout << "Primitive: " << type( typeid(float).name() )  << '\n'; 
  cout << "Primitive: " << type( typeid(double).name() )  << '\n'; 
  cout << "Return from assignment operator: " << type( typeid(a).name() )  << '\n'; 
  return 0;
}

string type(const char *t){
    char ch = *t;
    switch(ch){
        case 'f':
            return "Floating Point";
        case 'd':
            return "Double Floating Point";
        case 'i':
            return "Integer";
        case 'c':
            return "Character";
        default:
            return "\n";
    }
}
