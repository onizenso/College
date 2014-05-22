/*
class mammalia
*/
#pragma once
#include <string>
using namespace std;

#include "vertebrata.h"


class mammalia : public vertebrata
{
    protected:
    string movement;
    string noise;
    
    public:
    mammalia();
    mammalia(string in_genus, string in_species, string in_common_name,string in_movement, string in_noise);
    
    string Move();
    string MakeNoise();
    string ToString();
    
};




