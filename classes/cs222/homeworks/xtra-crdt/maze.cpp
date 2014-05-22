#include <iostream>


#include <stdlib.h>
#include <string.h>


using namespace std;
int speed = 100;



char MAZE[25][51] =	{
			"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
			"X X                                              X",
			"X X XX XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX X",
			"X   XX XXXXXXXXXXXXXXXXX      XXX   XX         X X",
			"XXX XX              XXXXXXXXX     X    XXXXXXXXX X",
			"XXX XXXXXXXXXXXXXXX XXXXXXXXXXXXXXXXXX XXXX    X X",
			"XXX XXXXXXXXXX                  XXXXXX      XX X X",
			"X   XXXX       XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX X X",
			"X XXXXXXXXXXXXXXX                              X X",
			"X X           XXX XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX X",
			"X X XXXXXXXXX XXX                                X",
			"X XXXXXXXXXXX XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
			"X XX          XXXXXXXXXX       XXXXXXXXXXXXXXXXXXX",
			"X  X XXXXXXXXXXXXXXXXXXX XXXXX XXXX      XXXXXXXXX",
			"XX X   XXXXXXXXXXXXXXXXX XXXXX      XXXX XXXXX   X",
			"XX XXX                XX XXXXXXXXXXXXXXX XXXXXXX X",
			"XX XXXXXXXXXXXXXXXXXX    XXXXXXXXXXXXXXX         X",
			"XX                    XXXXXXXFXXXXXXXXXXXXXXXXXX X",
			"XXXXX XXXXXXXXXXXXXXXXXXXXXXX XXXXXXXXXXXXXXXXXX X",
			"XXXXX XXXX            XXXXXXX                    X",
			"XXXXX XXXXXXXXXXXXXXX    XXXXXXXXXXXXXXXXXXXXXXXXX",
			"XXXXX XXXXXXXXXXXXXXXXXX                    XXXXXX",
			"XXXXX XXXXXXXXXXXXX      XXXXXXXXXXXXXXXXXX XXXXXX",
			"XXXXX               XXXXXXXXX               XXXXXX",
			"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
			};

void printMaze();
int Step(int x, int y, int level);


int main()
{

	cout << " What delay do you want between moves... 1-99:   ";
	
	cin >> speed;

if (speed < 1 )
	speed = 1;
	
	if (speed >99)
		speed =100;
printMaze();

Step(1,1,1);

return 0;
}




void Sleep(int input)
{
if ( input < 1)
	input =1;
	
while (input >0)
	{
	for (int loop=0;loop<1000;loop++)
		for (int loop2=0;loop2<1000;loop2++);
	
		input --;
	}
}


//--------------------------------------------------------------------

void printMaze()
{
system("clear");// system ("cls") on Windows
int loop;
for(loop=0;loop < 25;loop++)
cout << MAZE[loop] << endl;

cout <<"\n";
}




//---------------------------------------------------------------------

int Step(int x, int y, int level)
{ 
/* are we at the finish */
if (MAZE[x][y] =='F')
	{
cout << "Finish found at "<<x<<","<<y<<endl;
	return 1;
	}

if (MAZE[x][y] !=' ')return 0;

/* set the current position to '.' then call printMaze()  */
MAZE[x][y] = '.';
printMaze();


/* print some debugging info, mine prints current location and how many levels deep we are */
cout << "currently at "<<x<<","<<y<<endl;
cout << level << " levels deep\n";

Sleep(speed);										

/* try to go up */
	if (Step(x-1,y,level+1))
	return 1;

/* try to go left */
	if (Step(x,y+1,level+1))
		return 1;

/* try to go down */
	if ( Step(x+1,y,level+1) )
	return 1;

/* try to go right */
	if ( Step(x,y-1,level+1)  )
	return 1;

/* no end found set the space back to blank and return a 0 */
MAZE[x][y]=' ';
return 0;
}


