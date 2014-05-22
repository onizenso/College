/** Sckeleton of C#
 *
 *  To compile the program:   mcs skeleton.cs
 *  To Run  the program   :   mono skeleton.exe
 *  To debug the program  :   mcs -debug skeleton.exe
 *  		       or     mdb skeleton.exe
 * */

using System;

namespace HWangSpace {

    public class SimpleApplicaiton {

	static void Main( String[] args ) {

	    if ( args.Length < 1 ) {
		Console.Out.WriteLine( "You have not enterred any command line" +
			" argument" );
		return ;
	    }

	    Console.Out.WriteLine("Command line arguments entered:");
	    for ( int i = 0; i < args.Length; i ++ )
		Console.Out.WriteLine( args[i] );

	    int x = 1, y = 2;

	    (x = y )  = 3;

	     Console.Out.Writeln( "X = " + x);
	    return ;
	}
    }
}
