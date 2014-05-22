/*
*  Nik Ramsey
*  CMPS 222
*  Winter 2012
*/
#include "cmps222lib.h"
#include <string.h>
#include <iomanip>
ofstream LOGFILE;

typedef union{
    int age;
    char type[15];
    char name[15];
    char gender;
}pet;
void SetRandomName(char* in, int size)
{
  LOGFILE << POS_IN_PROGRAM << "start of function" << endl;
    char names[][20]={"Archimedes", "Brewknow", "Gryf", "Samael", 
	   	    "Shaitan", "Vishnu", "Destro", "Daemon"};
    int chosen = CreateRandomNumber(1,8);
    strncpy(in, names[chosen], size);
}

void SetRandomType(char * in, int size)
{
  LOGFILE << POS_IN_PROGRAM << "start of function" << endl;
    char animals[][20]={"dog", "dragon", "rattlesnake", "tarantula", "gorgon",
	            "bunny", "frog", "squirrel"};
    int chosen = CreateRandomNumber(1,8); 
    strncpy(in, animals[chosen], size);
}

char GetRandomGender()
{
  LOGFILE << POS_IN_PROGRAM << "start of function" << endl;
    if(CreateRandomNumber(1,10)>5)
	return 'M';
    return 'F';
}

int GetRandomAge()
{
  LOGFILE << POS_IN_PROGRAM << "start of function" << endl;
    return CreateRandomNumber(1,15);
}

void PrintUnionPet ( pet input )
{
  LOGFILE << POS_IN_PROGRAM << "start of function" << endl;
    cout<<"sizeof( pet ) : " << sizeof(input) << endl;
    cout<< setw(15) << setfill(' ') << right
    	<<"age : " << input.age << endl;
    cout<< setw(15) << setfill(' ') << right
	<<"type : " << input.type << endl;
    cout<< setw(15) << setfill(' ') << right
	<<"name : " << input.name << endl;
    cout<< setw(15) << setfill(' ') << right
	<<"gender : " << input.gender << endl;
    cout<<endl;
}
// your functions or file includes


int main()
{
LOGFILE.open("Lab07_Part1.log",ios::trunc);
if (LOGFILE.is_open())
  LOGFILE << POS_IN_PROGRAM << "start of logging" << endl;
else 
  {
  cout << "Unable to open file for logging.";
  return 1;
  }
	
// now all your regular stuff can go here
int length = 15;

pet Dipstick;
PrintUnionPet(Dipstick);

  LOGFILE << POS_IN_PROGRAM << "setting Dipstick.age" << endl;
Dipstick.age = GetRandomAge();
PrintUnionPet(Dipstick);

  LOGFILE << POS_IN_PROGRAM << "setting Dipstick.type" << endl;
SetRandomType(Dipstick.type, length);
PrintUnionPet(Dipstick);

  LOGFILE << POS_IN_PROGRAM << "setting Dipstick.name" << endl;
SetRandomName(Dipstick.name, length);
PrintUnionPet(Dipstick);

  LOGFILE << POS_IN_PROGRAM << "setting Dipstick.gender" << endl;
Dipstick.gender = GetRandomGender();
PrintUnionPet(Dipstick);


// close the logfile and exit
LOGFILE.close();
return 0;
}
