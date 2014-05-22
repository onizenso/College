// C++ version of 99 Bottles of Beer, object oriented paradigm
// programmer: Tim Robinson timtroyr@ionet.net
// taken from: http://www.99-bottles-of-beer.net

#include <iostream>

using namespace std;

enum Bottle { BeerBottle };

class Shelf {
public:
    Shelf( unsigned bottlesbought )
        : BottlesLeft( bottlesbought )
        {}
    void TakeOneDown()
        {
        if (!BottlesLeft)
            throw BeerBottle;
        BottlesLeft--;
        }
    operator int () { return BottlesLeft; }

private:
    unsigned BottlesLeft;
};

int main( int, char ** )
{
    unsigned ninety_nine = 99;
    Shelf Beer(ninety_nine);
    try {
        for (;;) {
            const char * plural = (int)Beer !=1 ? "s" : "";
            cout << (int)Beer << " bottle" << plural
                 << " of beer on the wall," << endl;
            cout << (int)Beer << " bottle" << plural
                 << " of beer," << endl;
            Beer.TakeOneDown();
            cout << "Take one down, pass it around," << endl;
            plural = (int)Beer !=1 ? "s":"";
            cout << (int)Beer << " bottle" << plural
                 << " of beer on the wall." << endl;
        }
    }
    catch ( Bottle ) {
        cout << "Go to the store and buy some more," << endl;
        cout << "99 bottles of beer on the wall." << endl;
    }
    return 0;
    }
