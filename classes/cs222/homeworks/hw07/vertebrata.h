/*

class vertebrata derives from animal


*/
#pragma once
#include "animal.h"
#include <string>

using namespace std;

class vertebrata : public animal {
    protected:
        string blood;
        bool egg_layer;
        bool live_birth;

    public:
        //default constructor
        vertebrata();
        
        //constructor
        vertebrata(string, string, string, string, bool, bool);
        string ToString();
};     
