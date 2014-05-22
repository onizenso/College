/*
*  Nik Ramsey
*  CMPS 222
*  Winter 2012
*/
#include "cmps222lib.h"   
#include <iomanip>
#include <string>
ofstream LOGFILE;


// your functions or file includes
void SortAscending (string target[], int count)
{
  LOGFILE << POS_IN_PROGRAM << "start of SortAscending()" << endl;
    string temp[count];

    for(int loop2=0; loop2<count; loop2++)
    {
        for(int loop1=0; loop1<count-1; loop1++)
        {
                if(*(target+loop1)>*(target+loop1+1))
                {
                LOGFILE << POS_IN_PROGRAM << "swapping positions "
                << loop1 << " and " << loop1+1 << endl;
                swap(*(temp+loop1),*(target+loop1));
                swap(*(target+loop1),*(target+loop1+1));
                swap(*(target+loop1+1),*(temp+loop1));
                }
        }
    }
  LOGFILE << POS_IN_PROGRAM << "end of SortAscending()" << endl;
}

int main()
{
LOGFILE.open("lab05.log",ios::trunc);
if (LOGFILE.is_open())
  LOGFILE << POS_IN_PROGRAM << "start of logging" << endl;
else 
  {
  cout << "Unable to open file for logging.";
  return 1;
  }
	
// now all your regular stuff can go here

//const int and strName array used for recursive loops involving string names
const int STRING_NUM = 7;
string strName[STRING_NUM]={"one","two","three","four","five","six","seven"};

  LOGFILE << POS_IN_PROGRAM << "defining strings" << endl;
string one ("So, so you think you can tell");
string two ("Heaven from Hell,");
string three ("Blue skys from pain.");
string four ("Can you tell a green field");
string five ("From a cold steel rail?");
string six ("A smile from a veil?");
string seven ("Do you think you can tell?");
  LOGFILE << POS_IN_PROGRAM << "end string definition" << endl;

cout<<"creating the strings"<<endl;

  LOGFILE << POS_IN_PROGRAM << "printing strings" << endl;
cout<< setw(13) << setfill(' ') << left <<"string one "<<">" << one << endl;
cout<< setw(13) << setfill(' ') << left <<"string two "<<">" << two << endl;
cout<< setw(13) << setfill(' ') << left <<"string three "<<">" << three << endl;
cout<< setw(13) << setfill(' ') << left <<"string four "<<">" << four << endl;
cout<< setw(13) << setfill(' ') << left <<"string five "<<">" << five << endl;
cout<< setw(13) << setfill(' ') << left <<"string six "<<">" << six << endl;
cout<< setw(13) << setfill(' ') << left <<"string seven "<<">" << seven << endl;
  LOGFILE << POS_IN_PROGRAM << "end printing strings" << endl;
cout<<endl <<endl;

int length1 = one.length();
int length2 = two.length();
int length3 = three.length();
int length4 = four.length();
int length5 = five.length();
int length6 = six.length();
int length7 = seven.length();

cout<<"using the length function"<<endl;

  LOGFILE << POS_IN_PROGRAM << "string length " << one << endl;
cout<< setw(15) << setfill(' ') << left <<"string \"one\" "
    << "has a length of " << length1 << endl;
  LOGFILE << POS_IN_PROGRAM << "string length " << two << endl;
cout<< setw(15) << setfill(' ') << left <<"string \"two\" "
    << "has a length of " << length2 << endl;
  LOGFILE << POS_IN_PROGRAM << "string length " << three << endl;
cout<< setw(15) << setfill(' ') << left <<"string \"three\" "
    << "has a length of " << length3 << endl;
  LOGFILE << POS_IN_PROGRAM << "string length " << four << endl;
cout<< setw(15) << setfill(' ') << left <<"string \"four\" "
    << "has a length of " << length4 << endl;
  LOGFILE << POS_IN_PROGRAM << "string length " << five << endl;
cout<< setw(15) << setfill(' ') << left <<"string \"five\" "
    << "has a length of " << length5 << endl;
  LOGFILE << POS_IN_PROGRAM << "string length " << six << endl;
cout<< setw(15) << setfill(' ') << left <<"string \"six\" "
    << "has a length of " << length6 << endl;
  LOGFILE << POS_IN_PROGRAM << "string length " << seven << endl;
cout<< setw(15) << setfill(' ') << left <<"string \"seven\" "
    << "has a length of " << length7 << endl;

cout<<endl <<endl;

cout<<"using the erase function"<<endl
    <<"removing 5 chars from string five starting at postion 7"<<endl;
cout<<setw(19)<<setfill(' ')<<left<<"string five before"<<">"<< five <<endl;
five.erase(7,5);
cout<<setw(19)<<setfill(' ')<<left<<"string five after"<<">"<< five <<endl;

cout<<"now erasing the word \"rail\" from string five"<<endl;
cout<<setw(19)<<setfill(' ')<<left<<"string five before"<<">"<< five <<endl;
five.erase(13,4);
cout<<setw(19)<<setfill(' ')<<left<<"string five after"<<">"<< five <<endl;

cout<<endl <<endl;

cout<<"using the insert function"<<endl
    <<"put \"cold\" back into string five"<<endl;
cout<<setw(19)<<setfill(' ')<<left<<"string five before"<<">"<< five <<endl;
five.insert(7,"cold ");
cout<<setw(19)<<setfill(' ')<<left<<"string five after"<<">"<< five <<endl;

cout<<endl <<endl;

cout<<"now put \"rail\" back into string five"<<endl;
cout<<setw(19)<<setfill(' ')<<left<<"string five before"<<">"<< five <<endl;
five.insert(18,"rail");
cout<<setw(19)<<setfill(' ')<<left<<"string five after"<<">"<< five <<endl;

cout<<endl<<endl;

cout<<"using the compare function"<<endl
    <<"test two equivalent strings"<<endl;
cout<<setw(40)<<setfill(' ')<<left<<"what is the output of one.compare(one)"
    <<":"<< one.compare(one) << endl;
cout<<"test two disparate strings"<<endl;
cout<<setw(40)<<setfill(' ')<<left<<"what is the output of one.compare(two)"
    <<":"<< one.compare(two) <<endl;

cout<<endl<<endl;

cout<<"using the == operator"<<endl
    <<"test two equivalent strings"<<endl;
cout<<setw(37)<<setfill(' ')<<left<<"what is the output of (one == one)"
    <<":"<< (one == one) << endl;
cout<<"test two disparate strings"<<endl;
cout<<setw(37)<<setfill(' ')<<left<<"what is the output of (one == two)"
    <<":"<< (one == two) <<endl;
cout<<setw(37)<<setfill(' ')<<left<<"what is the output of \"aaa\" == \"bbb\""
    <<":"<< ("aaa" == "bbb") <<endl;
cout<<setw(37)<<setfill(' ')<<left<<"what is the output of \"bbb\" == \"aaa\""
    <<":"<< ("bbb" == "aaa") <<endl;

cout<<endl<<endl;

cout<<"using the < operator"<<endl
    <<"test two equivalent strings"<<endl;
cout<<setw(36)<<setfill(' ')<<left<<"what is the output of (one < one)"
    <<":"<< (one < one) << endl;
cout<<"test two disparate strings"<<endl;
cout<<setw(36)<<setfill(' ')<<left<<"what is the output of (one < two)"
    <<":"<< (one < two) <<endl;
cout<<setw(36)<<setfill(' ')<<left<<"what is the output of \"aaa\" < \"bbb\""
    <<":"<< ("aaa" < "bbb") <<endl;
cout<<setw(36)<<setfill(' ')<<left<<"what is the output of \"bbb\" < \"aaa\""
    <<":"<< ("bbb" < "aaa") <<endl;

cout<<endl<<endl;

cout<<"using the < operator"<<endl
    <<"test two equivalent strings"<<endl;
cout<<setw(36)<<setfill(' ')<<left<<"what is the output of (one > one)"
    <<":"<< (one > one) << endl;
cout<<"test two disparate strings"<<endl;
cout<<setw(36)<<setfill(' ')<<left<<"what is the output of (one > two)"
    <<":"<< (one > two) <<endl;
cout<<setw(36)<<setfill(' ')<<left<<"what is the output of \"aaa\" > \"bbb\""
    <<":"<< ("aaa" > "bbb") <<endl;
cout<<setw(36)<<setfill(' ')<<left<<"what is the output of \"bbb\" > \"aaa\""
    <<":"<< ("bbb" > "aaa") <<endl;

cout<<endl<<endl;

cout<<"what is the ouput of \"cout << one+two+three+four+five+six+seven" 
    <<" << endl;\""<<endl;

cout<<one+two+three+four+five+six+seven<<endl;
cout<<endl<<endl;

cout<<"it seems as if the operators ==, <, >, =, and + seems to work much " 
    <<"the same as with an integer or char"<<endl;
cout<<endl<<endl;

cout<<"make an array of 7 strings, asign them with the values from" 
    <<"one, two, three, four, five, six and  seven"<<endl; 
cout<<"use a for loop to print them out"<<endl;

string myarray[STRING_NUM] = {one, two, three, four, five, six, seven};

for(int g=0; g<STRING_NUM; g++)
{
    cout<<"myarray["<<g<<"]=\""<<myarray[g]<<"\""<<endl;
}

cout<<endl<<endl;

cout<<"sort em!!";

SortAscending(myarray, STRING_NUM);

cout<<endl<<endl;

for(int j=0; j<STRING_NUM; j++)
{
    cout<<"myarray["<<j<<"]=\""<<myarray[j]<<"\""<<endl;
}

// close the logfile and exit
LOGFILE.close();
return 0;
}
