#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

int read_input(string, string*);

int main(int argc, char** argv)
{
    string nounname = "nouns.txt", 
	   adjname = "adjectives.txt", 
	   verbname = "verbs.txt";
    string nouns[100], adjs[100], verbs[100];
   
    while(!read_input(nounname, nouns))
    {
	cout<< "Enter a new file name: "<< endl;
	getline(cin, nounname);
    }
    while(!read_input(adjname, adjs))
    {
	cout<< "Enter a new file name: "<< endl;
	getline(cin, adjname);
    }
    while(!read_input(verbname, verbs))
    {
	cout<< "Enter a new file name: "<< endl;
	getline(cin, verbname);
    }
    ofstream outfile;
    outfile.open("altogether.txt");
    if(outfile.fail())
    {    cerr << "Unable to open file for writing\n"; return 1;    }

    int ind = 0;
    outfile << "Nouns: ";
    while(nouns[ind] != "") outfile << nouns[ind++] << " ";
    outfile << endl;

    ind = 0;
    outfile << "Adjectives: ";
    while(adjs[ind] != "") outfile << adjs[ind++] << " ";
    outfile << endl;

    ind = 0;
    outfile << "Verbs: ";
    while(verbs[ind] != "") outfile << verbs[ind++] << " ";
    outfile << endl;
    outfile.close();

    return 0;
}

int read_input(string filename, string items[])
{
    ifstream infile;
    infile.open(filename.c_str());
    
    if(infile.fail())
    {
	cerr << "You entered the wrong fuckin file name!" << endl;
	return 0;
    }

    int count = 0;
    
    while(infile.good()) getline(infile, items[count++], '\n');
    
    infile.close(); 
    return 1;    
}
