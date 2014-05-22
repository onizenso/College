#include <string>
#include <sstream>
using namespace std;

#include "vertebrata.h"

vertebrata::vertebrata()
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;
}


vertebrata::vertebrata(string in_genus, string in_species, string in_common_name, string in_blood, bool in_egg_layer, bool in_live_birth)
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;
    genus = in_genus;
    species = in_species;
    common_name = in_common_name;
    blood = in_blood;
    egg_layer = in_egg_layer;
    live_birth = in_live_birth;

    class_type="vertebrata";
}
	
string vertebrata::ToString()
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;
    ostringstream oss;
    oss << boolalpha << animal::GetFormattedName() << endl;
    oss << "Blood: " << blood << endl;
    oss << "Egg Layer: " << egg_layer << endl;
    oss << "Live Birth: " << live_birth << endl;
    oss << "Noise: " << animal::MakeNoise() << endl; 
    return oss.str();
}
	
