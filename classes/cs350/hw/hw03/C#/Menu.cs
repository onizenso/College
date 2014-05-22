/* Nik Ramsey
 * Felicia N'tui
 * CMPS 350: Programming Languages
 * 
 * Contents: menu functions.
 */

using System;
using CS350HW3;

namespace CS350HW3
{
    public class Menu {

	Member [] memArray = new Member[Globals.LIMIT];
	Random r = new Random();
	bool filled = false;

	public string mainMenu() { // Retreive the amount of members to make
	    string input;
	    string menu = 
		    "\n\t+------------------------------------------------+" +
		    "\n\t|                   MAIN MENU                    |" +
		    "\n\t+------------------------------------------------+" +
		    "\n\t| G : Enter number of member instances to create |" +
		    "\n\t| S : Show the current list of members           |" +
		    "\n\t| T : Sort members by ID in ascending order      |" +
		    "\n\t|------------------------------------------------|" +
		    "\n\t| X : Exit                                       |" +
		    "\n\t+------------------------------------------------+" + "\n" +
		    "\n\tSelection: ";
	    Console.Write(menu);
	    input = Console.ReadLine();
	    return input;
	}

	// Sort member array by ID using bubble sort
    public void sort()  
	{
	    if( filled ) {
	    	bool swap = true;
	    	int ctr = 0;
	    	Member tmp;
	    
	    	while ( swap ) 
	    	{
		    swap = false;
		    ctr++;
		    for( int i = 0; i < Globals.COUNT - ctr; i++ )
		    {
		        if ( memArray[i].ID > memArray[i+1].ID )
		        {
			    tmp = memArray[i];
			    memArray[i] = memArray[i+1];
			    memArray[i+1] = tmp;
			    swap = true;
		        }
		    }
		}
		Console.Write("\n\tMember array sorted\n");
	    }
	    else { Console.Write("\n\tMember array not filled\n"); }
	}

	// Display 20 members at a time
    public void show() 
	{
	    if( filled ) {
	    	bool done = false; 
	    	bool valid = false;
	    	string input;
	    	int ctr = 0; 		// counter for display index

		// Continue loop until all members have been displayed
	    	while( !done )
	    	{
		    if( ctr < Globals.COUNT ) 
		    {
	    	    	Console.Write("\n    | Type|    ID      |          Name           |  Other");
	    	    	Console.Write("\n ---+-----+------------+-------------------------+------------------------------------");
	    	    	for( int i=0; i < 20; i++)
			    {
		    	    if( ctr < Globals.COUNT ) {
		            	Console.Write("\n {0:D2} | " + memArray[ctr].ToString(), ctr+1);
		            	ctr++;
		    	    }
		    	}
	    	    	Console.Write("\n ---+-----+------------+-------------------------+------------------------------------\n\n");
		    } else { done = true; }

		    while( !valid && (ctr < Globals.COUNT) )
		    {
		    	Console.Write("\n\tShow more? (Y or N): ");
		    	input = Console.ReadLine();

			switch( input )
			{
			    case "y" : valid = true; break;
			    case "Y" : valid = true; break;
			    case "n" : valid = true; done = true; break;
			    case "N" : valid = true; done = true; break;
			    default : break;
			}
		    }
		    valid = false;
	    	}
	    }
	    else { Console.Write("\n\tMember array not filled\n"); }
	}

    public void populate() // Populate member array with random instances
	{
	    getNumber();
	    for( int i=0; i < Globals.COUNT; i++)
	    {
		switch( r.Next() % 5 )
		{
		    case 0: memArray[i] = new Member(); break;
		    case 1: memArray[i] = new Student(); break;
		    case 2: memArray[i] = new Employee(); break;
		    case 3: memArray[i] = new Faculty(); break;
		    case 4: memArray[i] = new Staff(); break;
		}
	    }
	    Console.Write("\n\tArray filled with {0} members\n", Globals.COUNT);
	    filled = true;
	}

    public void getNumber()
    { // Set global var COUNT by user input
	    string input;
	    bool valid = false;

	    if( filled ) {
		for( int i = 0; i < Globals.LIMIT; i++ )
		    memArray[i] = null;
	    }

	    while( !valid )
	    {
	        Console.Write("\n\tNumber of members to be generated(1-99): ");
	    	input = Console.ReadLine();
		if( Int32.TryParse(input, out Globals.COUNT) ) 
		{
		    if( Globals.COUNT > 0 && Globals.COUNT < Globals.LIMIT )
			valid = true;
		    else { valid = false; }			
		}
	    }
	}
    }
}
