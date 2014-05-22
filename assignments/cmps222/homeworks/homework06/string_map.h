/*
 *  string_map.h
 *
 */
#pragma once
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

extern ofstream LOGFILE;// LOGFILE is a global that we delcare in main so we need this here so it compiles


#define POS_IN_PROGRAM " file:"<<__FILE__<<" ,function:" << __FUNCTION__<<" ,line:"<<__LINE__<<" "


using namespace std;

struct sm_element
{
    public:
        string  s_key;
        string  s_val;
};

class string_map
{
    public:
	void    Clear();  
        string  Get(string name);
        bool    Set(string name,string val);
        bool    Exists(string name);
        int     Size();
        string  ToString();
        string_map(int startingsize=10);
        string_map(string_map & input);
        ~string_map();
		
		 
    private:
        int     position; // used to keep the postion in the array we will add to next as well as our size
	int     capacity; // maximum number of elements we should add
        sm_element * element_array; // a pointer to our array of struct sm_element
        int     FindPosition(string key);// look in the array for a sm_element that has a matching key, return its position or -1 if not found
      
};
