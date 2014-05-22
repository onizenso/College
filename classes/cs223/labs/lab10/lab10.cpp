#include "quicksort.cpp" 
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char*argv[]){

    ifstream fin;
    fin.open(argv[1]);
    if(fin.fail()){
        cout<< "Crack the code genious." << endl;
        return 1;
    }

    int count(0), i(0);
    int holder[1024];

    while(fin >> i){
        holder[count] = i;
        ++count;
    }

    quicksort(holder, 0, count-1);

    fin.close();
    fin.clear();
    return 0;
}
