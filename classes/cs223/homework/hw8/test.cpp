#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]){
ifstream fin;
ofstream fout;

int i = 0;

fin.open(argv[1]);
fout.open(argv[2]);

while(fin>>i) fout<<i<<"\t";

fin.clear();
fin.close();

fout.clear();
fout.close();
return 0;
}
