/*
class mammalia
*/

#include "mammalia.h"



mammalia::mammalia()
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;	
}

mammalia::mammalia(string in_genus, string in_species, string in_common_name,string in_movement, string in_noise)
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;	
genus=in_genus;
species=in_species;
common_name=in_common_name;
movement=in_movement;
noise=in_noise;


blood="warm";
egg_layer=false;
live_birth=true;

class_type="mammalia";
}



string mammalia::Move()
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;	
return movement;
}

string mammalia::MakeNoise()
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;	
return noise;
}


string mammalia::ToString()
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;	
ostringstream oss;
oss << boolalpha <<  animal::GetFormattedName() << endl;
oss <<  "Blood:"       << blood << endl;
oss <<  "Egg Layer:"   << egg_layer << endl;
oss <<  "Live Birth:"  << live_birth << endl;
oss << "Movement: " << Move() << endl;
oss << "Noise: " <<MakeNoise() << endl;
return oss.str();
}

