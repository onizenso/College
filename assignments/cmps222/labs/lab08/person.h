#include <iostream>
#include <string>
#include <sstream>
#include <ostream>

using namespace std;



// create struct type addr
struct addr {
   string number, street, city, state;
   int zip; 
};

// create person class
class person
{
public:
    string f_name, m_initial, l_name, phone;
    int ssn;
    struct addr address;

    //person();
    //~person();

    string ToString()
    {
	ostringstream oss;
	oss << endl <<f_name << " " << m_initial  << " " << l_name 
	    << " (" << ssn << ") \n" << "(" << phone.substr(0,3) << ") " 
	    << phone.substr(3,3) << "-" << phone.substr(6,4) << endl
	    << address.number << " " << address.street << ", "
	    << address.city << " " << address.state << " " << address.zip
	    << endl;

	return oss.str();
    }
  };



