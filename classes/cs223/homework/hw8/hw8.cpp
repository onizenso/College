/* =========================================================================*\
 * Nik Ramsey                                                               |
 * CMPS 223, Spring 2012: MWF 12:20-1:35, T 12:20-2:40                      |
 * HW Assignment 7                                                          |
\* =========================================================================*/

#include <cctype>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

void split(char *, char *, char *);
int merge(char *, char *, char *);

int main(int argc,char *argv[]){
    if(argc < 3){
        cout<< "Usage: " << argv[0] << " <input_filename> <output_filename>\n";
        return 1;
    }

    cout<< "Input filename " << argv[1] << endl;
    cout<< "Output filename " << argv[2] << endl;
    
    char tmp1[strlen(argv[1])+8];
    char tmp2[strlen(argv[2])+8];
    int fd, fd2;

    int runs = 0;

    ifstream fin;
    ofstream fout;

    fin.open(argv[1]);
    fout.open(argv[2]);

    int i = 0;

    while(fin >> i) fout<<i<<"\t";

    fin.clear();
    fin.close();

    fout.clear();
    fout.close();
    
    strcpy(tmp1, argv[1]);
    strcat(tmp1, "XXXXXXX");
    fd = mkstemp(tmp1);
    close(fd);

    strcpy(tmp2, argv[2]);
    strcat(tmp2, "XXXXXXX");
    fd2 = mkstemp(tmp2);
    close(fd2);

    cout<< "First random filename: " << tmp1 << endl;
    cout<< "Second random filename: " << tmp2 << endl;

    do{
        split(argv[2], tmp1, tmp2);
        runs = merge(tmp1, tmp2, argv[2]);
    }while(runs > 1);

    return 0;
}

void split(char *out, char *rnd1, char *rnd2){
    ifstream fin;

    fin.open(out);
    if(fin.fail()){
        cout<< "Program has failed to open file.\n";
        exit(1);
    }
    
    ofstream file1;
    file1.open(rnd1);
    if(file1.fail()){
        cout<< "Program has failed to open file.\n";
        exit(1);
    }

    ofstream file2;
    file2.open(rnd2);
    if(file2.fail()){
        cout<< "Program has failed to open file.\n";
        exit(1);
    }

    bool flag = true;
    int temp, prev(-4);

    while(fin >> temp){
        if(temp < prev)
            flag = !flag;

        if(flag)
            file1 << temp << "\t";
        else
            file2 << temp << "\t";
        
        prev = temp;
    }    

    fin.clear();
    fin.close();

    file1.clear();
    file1.close();

    file2.clear();
    file2.close();
}

int merge(char *rnd1, char *rnd2, char *out){
    ifstream file1, file2;
    ofstream fout;

    file1.open(rnd1);
    if(file1.fail()){
        cout<< "Program has failed to open file.\n";
        exit(1);
    }

    file2.open(rnd2);
    if(file2.fail()){
        cout<< "Program has failed to open file.\n";
        exit(1);
    }

    fout.open(out);
    if(fout.fail()){
        cout<< "Program has failed to open file.\n";
        exit(1);
    }

    int runs = 0;
    int temp1, temp2, last1(-3), last2(-3);
    bool live1, live2;

    live1 = (file1 >> temp1);
    live2 = (file2 >> temp2);

    if(!live1){
        cout<< "Unable to input to file.1" << endl;
        exit(1);
    }
    if(!live2){
        cout<< "Unable to input to file.2" << endl;
        exit(1);
    }

    while(live1 && live2){
        if(temp1 < temp2){
            fout << temp1 << "\t";
            last1 = temp1;
            live1 = (file1 >> temp1);
            if(!live1 || temp1 < last1){
                do{
                    fout << temp2 << "\t";
                    last2 = temp2;
                    live2 = (file2 >> temp2);
                }while(live2 && temp2 > last2);
                ++runs;
            }
        }
        else{
            fout << temp2 << "\t";
            last2 = temp2;
            live2 = (file2 >> temp2);
            if(!live2 || temp2 < last2){
                do{
                    fout << temp1 << "\t";
                    last1 = temp1; 
                    live1 = (file1 >> temp1);
                }while(live1 && temp1 > last1);
                ++runs;
            }
        }
    }
    
    while(live1){
        fout << temp1 << "\t";
        live1 = (file1 >> temp1);
        if(!live1)
            ++runs;
    }

    fout.clear();
    fout.close();

    file1.clear();
    file1.close();

    file2.clear();
    file2.close();
    return runs;
}
