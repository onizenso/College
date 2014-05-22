#include "string_functions.h"
#include <cctype>
#include <cstring>

string Trim(string input)
{
    return(FrontTrim(BackTrim(input)));
}

string FrontTrim(string input)
{
    while(input[0]==' ' || input[0]=='\t')
	input.erase(0,1);

    return input;
}

string BackTrim(string input)
{
    int s = input.length();
    while(input[s-1]==' ' || input[s-1]=='\t')
    {
	input.erase(s-1,1);
	s--;
    }
    return input;
}

string ReplaceFirst(string phrase, string sought, string replacement)
{
    int pos = phrase.find(sought);
    	if(pos==string::npos)
	    return phrase;

	int size = sought.length();

	phrase.replace(pos, size, replacement);

	return phrase;
}

string ReplaceLast(string phrase, string sought, string replacement)
{
    int pos = phrase.rfind(sought);
    	if(pos==string::npos)
	    return phrase;

	int size = sought.length();

	phrase.replace(pos, size, replacement);

	return phrase;
}

bool Contains(string phrase, string sought) 
{
	bool found = false;

	size_t foundPtr = phrase.find(sought, 0);

	if(foundPtr!=string::npos)
	    found=true;

	return found;
}

string ToLowerCase(string input)
{
    int i = 0;
    while( i < input.length())
    {
	if(isalpha(input[i]))
		input[i]=tolower(input[i]);	
	i++;
	}
    return input;
}

