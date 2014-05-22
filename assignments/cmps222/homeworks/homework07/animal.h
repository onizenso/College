/*
base class animal
*/
#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

extern ofstream LOGFILE;// LOGFILE is a global that we delcare in main so we need this here so it compiles
#define POS_IN_PROGRAM " file:"<<__FILE__<<" ,function:" << __FUNCTION__<<" ,line:"<<__LINE__<<" "

class animal
{
protected:
string genus,species,common_name;
string class_type;


public:
animal();
animal(string ,string,string);
virtual string GetFormattedName();
virtual string ToString();
virtual string Move();
virtual string MakeNoise();
virtual string GetType();
};
