/*
*  Nik Ramsey
*  CMPS 222
*  Winter 2012
*/
#include "cmps222lib.h"   
ofstream LOGFILE;


// your functions or file includes

void PrintCharArray (char *input, int cnt)
{
  LOGFILE << POS_IN_PROGRAM << "starting function" << endl;
    int cyc = 0;
    
    do{
    	*(input+cyc);
    	if (isgraph(*(input+cyc))) cout<<*(input+cyc);
	
	else
		cout<<"_";
	cyc++;
    }while(cyc<cnt);

    cout<<" "<<endl;
  LOGFILE << POS_IN_PROGRAM << "ending function" << endl;
}

int main()
{
LOGFILE.open("lab2_part2.log",ios::trunc);
if (LOGFILE.is_open())
  LOGFILE << POS_IN_PROGRAM << "start of logging" << endl;
else 
  {
  cout << "Unable to open file for logging.";
  return 1;
  }


// now all your regular stuff can go here

int total_count = 0;
//counters for printing the arrays sizes
int i(0), j(0), k(0), m(0);

char char_array_one[25] ="I'm the first char array";
char char_array_two[26] ="I'm the second char array";
char char_array_three[25] ="I'm the third char array";
char char_array_four[26] ="I'm the fourth char array";

char *cArrPtr1 = char_array_one;
char *cArrPtr2 = char_array_two;
char *cArrPtr3 = char_array_three;
char *cArrPtr4 = char_array_four;

cout << sizeof(char_array_one) << ", char_array_one ";
	do{
	   cout<< *(char_array_one+i);
	   i++;
	}while(*(char_array_one+i)!= '\0');
cout<< " " << endl;
cout << sizeof(char_array_two) << ", char_array_two ";
	do{
	   cout<< *(char_array_two+j);
	   j++;
	}while(*(char_array_two+j)!= '\0');
cout<< " " << endl;
cout << sizeof(char_array_three) << ", char_array_three ";
	do{
	   cout<< *(char_array_three+k);
	   k++;
	}while(*(char_array_three+k)!= '\0');
cout<< " " << endl;
	
cout << sizeof(char_array_four) << ", char_array_four ";
	do{
	   cout<< *(char_array_four+m);
	   m++;
	}while(*(char_array_four+m)!= '\0');
cout<< " " << endl; 

total_count += sizeof(char_array_one)+sizeof(char_array_two)
    		+sizeof(char_array_three)+sizeof(char_array_four);
cout<< " " << endl; 

/*--Prints out the Total Size
 *--the char_arrays --------- */
cout<< "The total size of all the variables is " 
    << total_count << endl;

cout<< " " << endl; 
cout<< "Start with pointer to char_array_one and print " 
    << total_count+40 << " characters" << endl;
PrintCharArray(cArrPtr1, total_count+40);
cout<< " " << endl;

cout<< "Start with pointer to char_array_two and print " 
    << total_count+40 << " characters" << endl;
PrintCharArray(cArrPtr2, total_count+40);
cout<< " " << endl;

cout<< "Start with pointer to char_array_three and print " 
    << total_count+40 << " characters" << endl;
PrintCharArray(cArrPtr3, total_count+40);
cout<< " " << endl;

cout<< "Start with pointer to char_array_four and print " 
    << total_count+40 << " characters" << endl;
PrintCharArray(cArrPtr4, total_count+40);
cout<< " " << endl;
// close the logfile and exit
LOGFILE.close();
return 0;

}
