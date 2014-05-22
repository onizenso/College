#include <iostream>
int fac (int n);
int fac2 (int n);
using namespace std;

int main()
{
 cout << "17 mod -5: " << 17 % -5 << endl;
 cout << "-17 mod 5: " << -17 % 5 << endl;
 cout << fac(5);
 cout << fac2(5);
 return 0;
}

 int fac (int n){
     int result;
     if ( n == 0 )
        return 1;
     else {
 result = n * fac (n-1);
 return result;
     }
   }

int fac2 (int n){
  int result = 1;
  while ( n >= 1 ) {
    result = result * n;
    n = n-1;
   }
   return result;
}

