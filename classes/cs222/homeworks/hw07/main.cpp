


#include "cmps222lib.h"
using namespace std;

ofstream LOGFILE;





#include "animal.h"
#include "vertebrata.h"
#include "reptilia.h"
#include "mammalia.h"




int main()
{
LOGFILE.open("hw07.log",ios::trunc);
if (LOGFILE.is_open())
      LOGFILE << POS_IN_PROGRAM << "start of logging" << endl;
else 
      {
	    cout << "Unable to open file for logging.";
	      return 1;
	        }

// lets create an instance of the animal class
LOGFILE << "\n\n\ntesting animal" ;
animal * animal1 = new animal("Felis","Concolor","Mountain Lion");
cout << "Testing animal class" << endl;
cout << "GetFormattedName() returns " << animal1->GetFormattedName() << endl;
cout << "Move() returns " << animal1->Move() << endl;
cout << "MakeNoise() returns " << animal1->MakeNoise() << endl;
cout << "GetType() returns " << animal1->GetType()<< endl;
cout << "ToString() returns "<< animal1->ToString() << endl;
delete animal1;


LOGFILE << "\n\n\ntesting vertebrata" ;
// now lets try the vertebrata class
vertebrata * vertibrate1 = new vertebrata("Felis","Concolor","Mountain Lion","warm",false,true);

cout << "Testing vertebrata class" << endl;
cout << "GetFormattedName() returns " << vertibrate1->GetFormattedName() << endl;
cout << "Move() returns " << vertibrate1->Move() << endl;
cout << "MakeNoise() returns " << vertibrate1->MakeNoise() << endl;
cout << "GetType() returns " << vertibrate1->GetType()<< endl;
cout << "ToString() returns "<< vertibrate1->ToString() << endl;
delete vertibrate1;






LOGFILE << "\n\n\ntesting mammalia" ;
// now lets try the mammalia class
mammalia  mammalia1("Felis","Concolor","Mountain Lion","run,walk,pounce","purr,snarl,growl");

cout << "Testing mammalia class" << endl;

cout << "GetFormattedName() returns " << mammalia1.GetFormattedName() << endl;
cout << "Move() returns " << mammalia1.Move() << endl;
cout << "MakeNoise() returns " << mammalia1.MakeNoise() << endl;
cout << "GetType() returns " << mammalia1.GetType()<< endl;
cout << "ToString() returns "<< mammalia1.ToString() << endl;






LOGFILE << "\n\n\ntesting reptilia" ;


// now lets try the reptilia class

reptilia reptilia1("Colubridae","Thamnophis","Garter Snake","swims,slithers,climbs","can produce a hissing sound when excited",false,true);

cout << "Testing reptilia class" << endl;




cout << "GetFormattedName() returns " << reptilia1.GetFormattedName() << endl;
cout << "Move() returns " << reptilia1.Move() << endl;
cout << "MakeNoise() returns " << reptilia1.MakeNoise() << endl;
cout << "GetType() returns " << reptilia1.GetType()<< endl;
cout << "ToString() returns "<< reptilia1.ToString() << endl;





LOGFILE.close();

return  0;

}

