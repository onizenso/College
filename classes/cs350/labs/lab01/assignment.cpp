#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
  int a = 8;
  const char *c = typeid(a).name();
  cout << "Return from assignment operator: " << c << '\n'; 
  return 0;
}
