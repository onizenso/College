#pragma once
#include <string>
#include <iostream>
#include <sstream>


using namespace std;

//Erases leading and trailing spaces
string Trim( string in );

//Erases leading spaces
string FrontTrim( string in );

//Erases trailing spaces
string BackTrim( string in );

//Searches for first occurence string 'sought' 
//replaces with string 'replacement'
string ReplaceFirst( string phrase, string sought, std::string replacement);

//Searches for last occurence of string 'sought'
//replaces with string 'replacement'
string ReplaceLast( string phrase, string sought, std::string replacement );

//Searches for all occurences of string 'sought'
//replaces with string replacement
string ReplaceAll( string phrase, string sought, std::string replacement );

//Used to test if string 'sought' is substring of string 'phrase'
//Returns true if found, false if no match
bool Contains(string phrase, string sought);

//Converts string 'input' to lowercase
string ToLowerCase( string input );



