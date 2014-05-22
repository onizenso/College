using System;

public class MemberTest {

    Member [] ms = new Member[30];

    Random   rnd = new Random();

    public static void Main( String [] args ) {

	MemberTest app = new MemberTest();

	app.fill();
	app.show();
    }

    void fill ( ) {

	for ( int i = 0; i < ms.Length; i ++ ) {

	    switch ( rnd.Next()  % 2 ) {
	    	case 0 : ms[i] = new Member(); break;
		case 1 : ms[i] = new Student(); break;
		default : ms[i] = null; break;
	    }
	}
	Array.Sort( ms );
    }

    void show ( ) {

	printTitle(true);
	for ( int i = 0; i < ms.Length; i ++ ) {
	    Console.WriteLine( ms[i] );
	    if ( (i + 1) % 20 == 0 ) {
		Console.Read(); 
		printTitle(true);
	    }
	}
    }
   
    public void printTitle( bool lab )
   { 
	Console.WriteLine( String.Format( "\n{0}{1,10}{2}{3} {4}",
	      	               ( lab? "Type " : ""), "   ID     ", "  First Name  ",  " Last Name ", "   Other Fields"));
	Console.WriteLine( String.Format( "{0}{1}{2}{3} {4}",
	      	               ( lab? "==== " : ""),  "=========== ",  "============ ", "============", " ===========================")) ;
   }
}

