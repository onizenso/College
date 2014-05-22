/*

base class animal functions


*/
#include "animal.h"

string animal::GetType()
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;	
return class_type;
}

animal::animal()
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;	
}

animal::animal(string in_genus,string in_species,string in_common_name)
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;	
genus=in_genus;
species=in_species;
common_name=in_common_name;
class_type="animal";
}

string animal::GetFormattedName()
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;	
ostringstream oss;
oss << genus << " " << species << " Common Name:"<<common_name;
return oss.str();
}

string animal::Move()
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;	
return "No Movement";
}

string animal::MakeNoise()
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;	
return "No Noise";
}

string animal::ToString()
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;	
ostringstream oss;
oss << "Name:" << GetFormattedName() << endl;
oss << "Movement: " << Move() << endl;
oss << "Noise: :" <<MakeNoise() << endl;
return oss.str();
}

