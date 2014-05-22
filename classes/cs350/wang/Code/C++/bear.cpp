/* filename: bear.cpp
   purpose:  demonstrates static scoping rules and 
   the use/misuse of implicit/explicit casting
*/

#include <iostream>
using namespace std;


class Mommabear {
   public: 
     static int count;   // count has Mommabear class scope
     Mommabear(float w = 200 ) { weight=w; } 
     float getWeight() { return weight;} 
   protected:
     float weight;    // make mommabear's weight visable to Babybear
};

class Babybear : public Mommabear {
   public: 
     Babybear(float w = 20 ) { weight = w; } 
     float getWeight() { return weight;} 
//     void setWeight( int w) { weight = w;} 
     void display() { cout << "Baby: " << weight << " Momma: " << Mommabear::weight << endl; }
   private:
     float weight;   
  };

int Mommabear::count = 10;

int main() {

     // a static variable with class scope exists before any object is created
     cout <<  "Count: " << Mommabear::count << endl;
     Mommabear::count++;
     cout <<  "Count: " << Mommabear::count << endl;

     // create a derived object
     Babybear baby;  

     // display the babybear and mommabear's weight
     cout << "Baby: ";
     baby.display();
     cout << endl;


     cout << "point a base and a derived pointer to the derived object \n";
     Babybear * dPtr = &baby;    // dPtr for derived and bPtr for base 
     Mommabear * bPtr = dPtr;   // implicit downcasting of derived to base  
     
     cout << "Baby: " <<  dPtr->getWeight() << endl;
     cout << "Momma: " << bPtr->getWeight() << endl;
//     bPtr->display();   //<== WHY IS THIS A COMPILER ERROR?

 
     cout << "create a base object by static allocation \n";
     Mommabear mommy;
     bPtr = &mommy;
//     dPtr =  bPtr;  // cannot downcast from base to derived!!

     cout << "force an explicit cast from base to derived \n";
     dPtr =  static_cast<Babybear *>(bPtr);
     cout << "\nHow much do I weight? " << dPtr->getWeight() << endl; 

     cout << "create a base object by dynamic allocation \n";
     bPtr = new Mommabear;

//   bPtr =  mommy;  <== WHY IS THIS A COMPILER ERROR?
     /* force an explicit cast from base to derived */
     dPtr =  static_cast<Babybear *>(bPtr);
 //    dPtr->display();   
     cout << "\nHow much do I weight? " << dPtr->getWeight() << endl; 

     // const type qualifier is enforced by C++, so this won't compile:
      const Babybear * cptr = new Babybear;

     // this will work
     //Babybear * cptr = new Babybear;
 //    cptr->setWeight(25);

     delete bPtr;   // every new must have a delete

     return 0;
 }
