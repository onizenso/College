/** Sckeleton of C#
 *
 *  To compile the program:   mcs skeleton.cs
 *  To Run  the program   :   mono skeleton.exe
 *  To debug the program  :   mcs -debug skeleton.exe
 *  		       or     mdb skeleton.exe
 * */

using System;

namespace HWangSpace {

    public class TesstReference {

	static void Main( String[] args ) {

	    int i = 1;

	    Console.Out.WriteLine( "Before call ByRef( ref int): i = {0:d}\n", i);
	    
	    ByRef ( ref i );  // correct call

	    Console.Out.WriteLine( "After call ByRef( ref int): i = {0:d}\n", i);

	    
	    return ;
	}

	static void ByRef ( ref int k ) {
	    k = 2;
	}


	/** static ref in ReturnRef( ref int k ) cannot pass the comilation.

	static ref int ReturnRef ( ref in k  ) {
	    return k; // return ref k;
	}
	*/
    }
}
