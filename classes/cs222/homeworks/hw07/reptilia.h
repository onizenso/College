/*

base class animal


*/
#pragma once
#include "vertebrata.h"




class reptilia: public vertebrata
{
    protected:
	string movement;
	string noise;

    public:
	reptilia();
	reptilia(string in_genus, string in_species, string in_common_name, string in_movement, string in_noise, bool in_egg_layer, bool in_live_birth);
	
	string Move();
	string MakeNoise();
	string ToString();

};
