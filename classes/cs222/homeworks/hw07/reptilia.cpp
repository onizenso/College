/*

base class animal


*/
#include "reptilia.h"

reptilia::reptilia(string in_genus, string in_species, string in_common_name, 
			string in_movement, string in_noise, bool in_egg_layer,
			bool in_live_birth) 
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;
    genus = in_genus;
    species = in_species;
    common_name = in_common_name;
    
    movement = in_movement;
    noise = in_noise;
    egg_layer = in_egg_layer;
    in_live_birth = in_live_birth;

    class_type="reptilia";
    blood = "cold";
}

string reptilia::Move()
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;
    return movement;
}

string reptilia::MakeNoise()
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;
    return noise;
}

string reptilia::ToString()
{
LOGFILE << POS_IN_PROGRAM << "start of function" << endl;
    ostringstream oss;
    oss<< boolalpha << animal::GetFormattedName() << endl;
    oss<< "Blood: " << blood << endl;
    oss<< "Egg Layer: " << egg_layer << endl;
    oss<< "Live Birth: " << live_birth << endl;
    oss<< "Movement: " << Move() << endl;
    oss << "Noise: " << MakeNoise() << endl;
    return oss.str();
}
