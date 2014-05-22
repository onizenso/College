/*
 *  string_map.h
 *
 */
#include "string_map.h"

//---------------------------------------------------------
int     string_map::FindPosition(string key)
{
    for(int l=0; l<position; l++)
	if(element_array[l].s_key == key)
	    return l;
    
    return -1;
}
//---------------------------------------------------------
bool    string_map::Exists(string name)
{
    if (FindPosition(name) != -1)
	return true;
    return false;
}


//---------------------------------------------------------
void    string_map::Clear()
{
    position = 0;
}


//--------------------------------------------------------- 
string  string_map::Get(string name)
{
    int tmp = FindPosition(name);
    
    if(tmp != -1)
	return element_array[tmp].s_val;

    return "";

}


//---------------------------------------------------------
bool    string_map::Set(string name,string val)
{
    
    if( Exists(name) )
	{
	    int tmp = FindPosition(name);
	    element_array[tmp].s_val = val;
	    return true;
	}	

    if (Size() == capacity)
	return false;
    
    element_array[position].s_key = name;
    element_array[position].s_val = val;
    position++;
    return true;
}



//---------------------------------------------------------
int     string_map::Size()
{
    return position;
}


//---------------------------------------------------------
string  string_map::ToString()
{
	ostringstream oss;
	for (int l=0;l< position;l++)
	 oss << "key:" << 	element_array[l].s_key  << "  ---> value:" << element_array[l].s_val << endl;
	return oss.str();	
}


//---------------------------------------------------------
string_map::string_map(int startingsize)
{
    capacity = startingsize;
    position = 0;
    element_array = new sm_element[startingsize];
}


//---------------------------------------------------------
string_map::string_map(string_map & input)
{
	// create a new array of the same size as the one we are trying to copy... 
	LOGFILE << POS_IN_PROGRAM << "create new array" <<endl;
	element_array = new sm_element[input.capacity];
	LOGFILE << POS_IN_PROGRAM << "copy capacity and position"<<endl;
	// copy over the memebers
	capacity = input.capacity;
	position = input.position;
	// to copy a dynamic array we will need to loop through it
	LOGFILE << POS_IN_PROGRAM << "copying the array over" <<endl;
	for (int l=0;l< position;l++)
		{
			element_array[l].s_key= input.element_array[l].s_key;
			element_array[l].s_val= input.element_array[l].s_val;			
		}	
}

//---------------------------------------------------------
string_map::~string_map()
{
    delete [] element_array;
}


      
