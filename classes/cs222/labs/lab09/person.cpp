#include "person.h"



// here is a function you will want to use to check your phone number
bool is_number(string str)
{
LOGFILE<<  POS_IN_PROGRAM << "start of function is_number" << endl;
	for (int i = 0; i < str.length(); i++) {
		if (! isdigit(str[i]))
		return false;
		}

	return true;
}


person::person()
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;
// you are always going to need a constructor 
// even if it dont do anything at all
}

 // put the rest of the function bodies here
 //


bool person::SetFName(string in)
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;	
if ( (in.length() > 30) ||  (in.find(":") != string::npos)    )
return false;
f_name = in;
return true;
}

bool person::SetMInitial(string in)
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;	
if ( (in.length() > 1) ||  (in.find(":") != string::npos)    )
return false;
l_name = in;
return true;
}

bool person::SetLName(string in)
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;	
if ( (in.length() > 30) ||  (in.find(":") != string::npos)    )
return false;
l_name = in;
return true;
}

bool person::SetPhone(string in)
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;	
   if(in.find('(') != string::npos)
   	in.erase(in.find('('),1);
   if(in.find(')') != string::npos)
   	in.erase(in.find(')'),1);
   if(in.find('-') != string::npos)
   	in.erase(in.find('-'),1);
   
   if(in.length()!=10)
      return false;
   if(!is_number(in))
      return false;
   else
      phone = in; 
}

bool person::SetAddress1(string in)
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;	
if ( (in.length() > 50) ||  (in.find(":") != string::npos)    )
return false;
address1 = in;
return true;
}

bool person::SetAddress2(string in)
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;	
if ( (in.length() > 50) ||  (in.find(":") != string::npos)    )
return false;
address2 = in;
return true;
}

bool person::SetCity(string in)
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;	
if ( (in.length() > 30) ||  (in.find(":") != string::npos)    )
return false;
city = in;
return true;
}

bool person::SetState(string in)
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;	
if ( (in.length() > 2) ||  (in.find(":") != string::npos)    )
return false;
state = in;
return true;
}

bool person::SetZip(string in)
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;	

if( in.find('-') != string::npos )
    in.erase(in.find('-'),1);

if ( (in.length() != 5) && (in.length() != 9) )
    return false;

if ( in.length() == 5 )
    in.append("0000");

if ( !is_number(in))
    return false;

    zip = in;
    return true;
}

string person::FormattedName()
{
    ostringstream oss;
    oss << f_name << " " << m_initial << ". " << l_name << endl;
    return oss.str();
}

string person::ToString()
{
	stringstream oss;
        oss << endl <<f_name << " " << m_initial  << " " << l_name << endl
            << "(" << phone.substr(0,3) << ") " << phone.substr(3,3) 
	    << "-" << phone.substr(6,4) << endl
            << address1 << endl << address2 << endl << city << " " 
	    << state << " " << zip
            << endl << endl;

        return oss.str();
}

string person::ToColonDelimited()
{
    stringstream oss;
    oss << f_name << ":" << m_initial << ":" << l_name << ":" << phone 
	<< ":" << address1 << ":" << address2 << ":" << city << ":" 
	<< state << ":" << zip << endl << endl;

    return oss.str();
}

void person::operator = ( person & input )
{
    f_name = input.f_name;
    m_initial = input.m_initial;
    l_name = input.l_name;
    phone = input.phone;
    address1 = input.address1;
    address2 = input.address2;
    city =  input.city;
    state = input.state;
    zip = input.zip;
}


bool person::operator > ( person & input )
{
    LOGFILE << POS_IN_PROGRAM << endl;
    LOGFILE << " some biznitch is attempting to compare two persons using < operator " << endl;
    LOGFILE << " this function is a member of the class on the left side of the < operator, the input parameter is the person object on the right side." << endl;
    LOGFILE << "my FormattedName() returns " << FormattedName() << endl;
    LOGFILE << " The lone parameter to this function is the address reference of the person object, its FormattedName() returns " << input.FormattedName() <<endl;
    LOGFILE << "Question is, will " << FormattedName() << " > " <<input.FormattedName() << boolalpha << endl;

    bool result;
    if( l_name==input.l_name && f_name==input.f_name )
    {
	result = ( m_initial > input.m_initial );
	LOGFILE << "I'm gonna return this shiz " << result << endl << endl << endl;
	return result;
    }
    if( l_name == input.l_name )
    {
	result = ( f_name > input.f_name );
	LOGFILE << "I'm gonna return this shiz " << result << endl << endl << endl;
	return result;
    }
    result = ( l_name > input.l_name );
	LOGFILE << "I'm gonna return this shiz " << result << endl << endl << endl;

}

bool person::operator < ( person & input )
{
    LOGFILE << POS_IN_PROGRAM << endl;
    LOGFILE << " some biznitch is attempting to compare two persons using < operator " << endl;
    LOGFILE << " this function is a member of the class on the left side of the < operator, the input parameter is the person object on the right side." << endl;
    LOGFILE << "my FormattedName() returns " << FormattedName() << endl;
    LOGFILE << " The lone parameter to this function is the address reference of the person object, its FormattedName() returns " << input.FormattedName() <<endl;
    LOGFILE << "Question is, will " << FormattedName() << " < " <<input.FormattedName() << boolalpha << endl;

    bool result;
    if( l_name==input.l_name && f_name==input.f_name )
    {
	result = ( m_initial < input.m_initial );
	LOGFILE << "I'm gonna return this shiz " << result << endl << endl << endl;
	return result;
    }
    if( l_name == input.l_name )
    {
	result = ( f_name < input.f_name );
	LOGFILE << "I'm gonna return this shiz " << result << endl << endl << endl;
	return result;
    }
    result = ( l_name < input.l_name );
	LOGFILE << "I'm gonna return this shiz " << result << endl << endl << endl;

}
