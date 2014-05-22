#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    ifstream fin;
    if(argc < 2)
    {
        fin.open("names.list", "r");
        if(fin.fail())
            cerr << "File does not exist" << endl;
        return 1;
    }
    else{
        fin.open(argv[1], "r");
       if(fin.fail())
       {
            cerr << "File does not exist" << endl;
        return 1;

       } 
    }
    return 0;
}
