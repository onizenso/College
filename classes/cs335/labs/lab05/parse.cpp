#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc<2)
    { cout << "Use ./parse <fileToRead>" << endl; exit(EXIT_FAILURE); }
    
    long int wordCount = 0;
    char* word;
    char* tmpFile;
    const int maxLength = 30;

    if(sizeof(argv[1])<15)
    {
         tmpFile = new char[sizeof(argv[1])];
         strncpy(argv[1], tmpFile, sizeof(argv[1]));
    }
    else
    { cout << "File name too long." << endl; exit(EXIT_FAILURE); }

    std::fstream fs;
    fs.open(tmpFile, std::fstream::in);
    
    if(fs.bad())
    { cout << "Failed to open file." << endl; exit(EXIT_FAILURE); }

    else
    {
        while(!fs.eof())
        {
            fs.get(word, 35, '\n'); 
            wordCount++;
        }
        cout << "There are " << wordCount << " words in the file." << endl;
    }

    delete [] tmpFile;
    fs.close(); 
    return 0;
}
