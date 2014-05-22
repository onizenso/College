using System;
using listpack;

public class ListTest {


    static void show<T> ( List<T> lst) {
	Iterator<T> itr = lst.iterator();
	while ( itr.hasNext() )
	    Console.Out.WriteLine( itr.next() );
    }

    public static void Main ( string [] args ) {

	List<int> ilst = new List<int> ();
	Stack<int> istk = new Stack<int> ();

	Random rnd = new Random();
	int    v ;
	for ( int i = 0; i < 5 ; i ++ ) {
	    v = rnd.Next() % 100;
	    ilst.add( v, i );
	    istk.push( v );
	}

	Console.Out.WriteLine("\nOutput from Integer List\n=======================\n");
	show( ilst );

	Console.Out.WriteLine("\n\nOutput from int stack\n=======================\n");
	show( istk ) ;
    }
}

