// test String class in STL of C++
// must include <string> from STL

#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  string r;
  cout << "enter a string: " ;
  getline(cin,s);
  cout << "\nThe length of your string " << s << " is "  << s.length() << endl;
  cout << "enter a new string: ";
  getline(cin,r);
  if ( s < r )
     cout << r << " comes before " << s << endl;
  else
     cout << s << " comes before " << r << endl;
  s = "goodbye now";
  cout << "\nassigning literal string to your string: ";
  cout << "\nThe length of this string " << s << " is "  << s.length() << endl;
  cout << s << endl;

return 0;
}
