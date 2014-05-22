/* =========================================================================*\
 * Nik Ramsey                                                               |
 * CMPS 223, Spring 2012: MWF 12:20-1:35, T 12:20-2:40                      |
 * HW Assignment 7                                                          |
\* =========================================================================*/

#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

#ifndef ELEMTYPE
#define ELEMTYPE int
#endif

#ifndef MAX_CAPACITY
#define MAX_CAPACITY 1021
#endif

#ifndef EMPTY_VALUE
#define EMPTY_VALUE -1
#endif

#ifndef DELETED_VALUE
#define DELETED_VALUE -2
#endif

struct HashTable{
    ELEMTYPE members[MAX_CAPACITY];
    int count;
};

void centerstring(char *);

void initTable(HashTable *);

bool empty(HashTable *);
bool full(HashTable *);

int hash1(ELEMTYPE);
int hash2(ELEMTYPE);

bool search(HashTable *, ELEMTYPE);
bool insert(HashTable *, ELEMTYPE);
bool remove(HashTable *, ELEMTYPE);

int main(){
    bool ftw = true;
    
    char c;
    char header[50] = {"Hash Table Menu"};
    char test[512];
    int tcount = 0;
    ELEMTYPE entry;

    HashTable hash;

    initTable(&hash);    

    do{
        centerstring(header);
        cout<< setw(50) << setfill('=') << "" << endl;
        cout<< "1. Insert an integer into the table" << endl;
        cout<< "2. Delete an integer from the table" << endl;
        cout<< "3. Search the table for an integer" << endl;
        cout<< "4. Print the primary and secondary keys for an integer" << endl;
        cout<< endl;
        cout<< "0. Exit" << endl;
        cout<< setw(50) << setfill('=') << "" << endl;
        cin >> c;

        switch(c){
            case '1':
                if(full(&hash)){
                    cout<< "You have too much hash, 'delete' some." << endl;
                    break;
                }
                else{
                    entry = 0;
                    ftw = true;
                    tcount = 0;

                    cout<< "Enter a value to turn into hash: ";
                    cin.ignore(512, '\n');
                    cin.getline(test, 511);

                    while(test[tcount]){
                        if(isalpha(test[tcount])){
                            tcount = 0;
                            ftw = false;
                            break;
                        }
                        ++tcount;
                    }

                    if(ftw) entry = atoi(test);

                    if(entry <= 0){
                        cout<< "Invalid entry, no hash for you!" << endl;
                        break;
                    }

                    if(insert(&hash, entry)){
                        cout<< "Item succesfully made into hash." << endl;
                        break;
                    }
                    else{
                        cout<< "Item could not be made into hash,";
                        cout<< " sad day." << endl;
                        break;
                    }
                }

            case '2':
                if(empty(&hash)){
                    cout<< "No values to remove, insert hash first." << endl;
                    break;
                }

                entry = 0;
                ftw = true;
                tcount = 0;

                cout<< "Enter value to remove: " << endl;
                cin.ignore(512, '\n');
                cin.getline(test, 511);

                while(test[tcount]){
                    if(isalpha(test[tcount])){
                        tcount = 0;
                        ftw = false;
                        break;
                    }
                    ++tcount;
                }

                if(ftw) entry = atoi(test);

                if(entry <= 0){
                    cout<< "Invalid entry, we can't remove that shiz!" << endl;
                    break;
                }
                
                if(remove(&hash, entry)){
                    cout<< "Hash successfully removed, hope you enjoy!" << endl;
                    break;
                }
                else{
                    cout<< "Hash not found on the table, ";
                    cout<< "maybe somebody stole it..." << endl;
                    break;
                }

            case '3':
                if(empty(&hash)){
                    cout<< "Table is empty, insert values";
                    cout<< " before searching." <<endl;
                    break;
                }

                entry = 0;
                ftw = true;
                tcount = 0;

                cout<< "Enter a value to search for: ";
                cin.ignore(512, '\n');
                cin.getline(test, 511);

                while(test[tcount]){
                    if(isalpha(test[tcount])){
                        tcount = 0;
                        ftw = false;
                        break;
                    }
                    ++tcount;
                }

                if(ftw) entry = atoi(test);
                if(entry <= 0){
                    cout<< "Invalid entry, can't find hash like that!" << endl;
                    break;
                }

                if(search(&hash, entry)){
                    cout<< entry << " was found in the tree" << endl;
                    break;
                }
                else{
                    cout<< entry << " was not found, try again." << endl;
                    break;
                }

            case '4':
                entry = 0; 
                ftw = true;
                tcount = 0;

                cout<< "Enter a value to generate primary ";
                cout<< "and secondary keys: ";
                cin.ignore(512, '\n');
                cin.getline(test, 511);

                while(test[tcount]){
                    if(isalpha(test[tcount])){
                        tcount = 0;
                        ftw = false;
                        break;
                    }
                    ++tcount;
                }

                if(ftw) entry = atoi(test);
                if(entry <= 0){
                    cout<< "Invalid entry, ";
                    cout<< "can't make hash out of that!" << endl;
                    break;
                }

                cout<< "Hash 1 Key: " << hash1(entry) << endl;
                cout<< "Hash 2 Key: " << hash2(entry) << endl;

                break;
        }
    }while(c != '0');

    return 0;
}

void centerstring(char *s){
    int len = strlen(s);
    int pos = (int)((50-len)/2);
    for(int i = 0; i < pos; i++)
        cout<< " ";

    cout<< s << endl;
return;
}

void initTable(HashTable *sheesh){
    int i = 0;
    
    while(i++ < MAX_CAPACITY){
        sheesh->members[i] = EMPTY_VALUE;
    }

    sheesh->count = 0;
}

bool empty(HashTable *sheesh){
    return (sheesh->count == 0);
}

bool full(HashTable *sheesh){
    return (sheesh->count == MAX_CAPACITY);
}

int hash1(ELEMTYPE key){
    int index = key % MAX_CAPACITY;
    return index;
}

int hash2(ELEMTYPE key){
    int index = 997 - (key % 997);
    return index;
}

bool search(HashTable *sheesh, ELEMTYPE val){
    if(val == EMPTY_VALUE || val == DELETED_VALUE){
        cout<< "You did too much hash, get";
        cout<< " out of here with that nonsense!" <<endl;
        return false;
    }
    int i = 0;
    int key = hash1(val);
    int key2 = hash2(val);
    int slot = key;

    while(sheesh->members[slot] != EMPTY_VALUE && 
          sheesh->members[slot] != val){
         ++i;
         if(i == MAX_CAPACITY)
             return false;
         slot = (key + (i*key2)) % MAX_CAPACITY;
    }

    return (sheesh->members[slot] == val);
}

bool insert(HashTable *sheesh, ELEMTYPE val){
    if(val == EMPTY_VALUE || val == DELETED_VALUE){
        cout<< "You did too much hash, get";
        cout<< " out of here with that nonsense!" <<endl;
        return false;
    }

    int i = 0;
    int key = hash1(val);
    int key2 = hash2(val);
    int slot = key;

    while(sheesh->members[slot] != EMPTY_VALUE && 
          sheesh->members[slot] != DELETED_VALUE){
         ++i;
         if(i == MAX_CAPACITY)
             return false;
         slot = (key + (i*key2)) % MAX_CAPACITY;
    }

    sheesh->members[slot] = val;
    ++sheesh->count;
    return true;
}

bool remove(HashTable *sheesh, ELEMTYPE val){
    if(val == EMPTY_VALUE || val == DELETED_VALUE){
        cout<< "You did too much hash, ";
        cout<< " get out of here with that nonsense!" <<endl;
        return false;
    }
    
    int i = 0;
    int key = hash1(val);
    int key2 = hash2(val);
    int slot = key;

    while(sheesh->members[slot] != EMPTY_VALUE && 
          sheesh->members[slot] != DELETED_VALUE){
         ++i;
         if(i == MAX_CAPACITY)
             return false;
         slot = (key + (i*key2)) % MAX_CAPACITY;
    }

    if(sheesh->members[slot] == val){
        sheesh->members[slot] = DELETED_VALUE;
        --sheesh->count;
        return true;
    }   

    return false;
}
