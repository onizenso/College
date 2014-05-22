#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void reverseFile(ifstream &, ofstream &);

int main(){
    ifstream fin;
    ofstream fout;
    char filename[56];
    char outfile[60];

    do{
        cout<< "Enter the filename of the file you want to reverse: ";
        cin>> setw(56) >> filename;

        if(cin.fail()){
            cout<< "Filename is too long." << endl;
            exit(1);
        }

        fin.open(filename);
        if(fin.fail())
            cout<< "Could not open " << filename << " for reading." << endl;
    }while(fin.fail());

    strcpy(outfile, filename);
    strncat(outfile, ".out", 4);

    fout.open(outfile);
    if(fout.fail())
        cout<< "Could not open " << outfile << " for writing." << endl;
    
    reverseFile(fin, fout);

    fin.clear();
    fin.close();

    fout.clear();
    fout.close();

return 0;
}

void reverseFile(ifstream &input, ofstream &output){
    char c;
    input.get(c);

    if(!input.eof()){
        cout<< "Read " << c << " from file." << endl;
        reverseFile(input, output);
        output << c;
    }    
return;
}
