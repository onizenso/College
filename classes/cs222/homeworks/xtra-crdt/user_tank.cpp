//


#include "internalstuff\top_half.h"

// place your functions here
//-------------------------------------------------------------------------------------------------------------------


int CanGo(int direction)
{
if ( Ping(direction) >=35)
	return 1;
else 
	return 0;
}

int CanTurnClockwise()
{
int dir = Compass();
return CanGo(dir + 2);
}

int CanTurnCounterClockwise()
{
int dir = Compass();
return CanGo(dir - 2);
}

void TurnTo(int dir)
{
while ( Compass() != dir)
  TurnCW();
}

void GoForwardToWall()
{
int dir = Compass();
while( (Ping(dir) >=20) )

  Forward(5);
}
// here is a usefull define for you where ever you place 'PRINT_INFO' it will print out debugging info

#define PRINT_INFO   NonOp(5),printf( " at line %d, tank x,y position  %d,%d\n",__LINE__,GetX(),GetY());


//-------------------------------------------------------------------------------------------------------------------
// END place your functions here
#include "internalstuff\middle.h"





printf (" start of RUN() in %s \n",  __FILE__);
//-------------------------------------------------------------------------------------------------------------------
// START STUDENT CODE

int myDir = Compass();

PRINT_INFO
TurnTo(E);
GoForwardToWall();


PRINT_INFO
TurnTo(N);
GoForwardToWall();

PRINT_INFO
TurnTo(E);
Forward(120);

while(CanTurnClockwise() != 1){
Forward();
}

do{
Forward();
if(CanTurnClockwise() == 1){
PRINT_INFO
TurnTo(S);
while(CanGo(S) == 1){
GoForwardToWall();
}
}
else if (CanTurnCounterClockwise() == 1){
PRINT_INFO
TurnTo(E);
GoForwardToWall();
TurnTo(S);
GoForwardToWall();
TurnTo(W);
}
}while(CanGo(E) == 1);

while( CanTurnCounterClockwise() != 1){
PRINT_INFO
if(CanGo(W)){
Forward();
}
else{
PRINT_INFO
	TurnTo(N);
	GoForwardToWall();
	TurnTo(W);
	GoForwardToWall();
	TurnTo(S);
	GoForwardToWall();
	TurnTo(W);
}
}

TurnTo(S);

PRINT_INFO
if(CanGo(S)==1)
	GoForwardToWall();

while(CanTurnClockwise() == 0){
if (CanTurnCounterClockwise() == 1){
	PRINT_INFO
	TurnCCW(2);
	GoForwardToWall();
}	
}

PRINT_INFO
TurnTo(E);
GoForwardToWall();

PRINT_INFO
TurnTo(S);
GoForwardToWall();

PRINT_INFO
TurnTo(E);
GoForwardToWall();

PRINT_INFO
TurnTo(S);
GoForwardToWall();

NonOp(5000);

// END STUDENT CODE
// Dont edit anything past here
//------------------------------------------------------------------------------------------------------------------------




#include "internalstuff\bottom_half.h"

