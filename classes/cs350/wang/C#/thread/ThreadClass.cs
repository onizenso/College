/** ThreadClass.cs show that
 *
 *     A class's member function can be bounded to a thread.
 *
 * */

using System;
using System.Threading;

namespace HWangSpace {

    public class ThreadClass {

	static void Main( String[] args ) {

	     TClass  tc1 = new TClass ( 1, "I AM THE FIRST THREAD"),
	     	     tc2 = new TClass ( 2, "i am the second thread");
	     new Thread ( tc1.Run ).Start();
	     new Thread ( tc2.Run ).Start();

	     Console.WriteLine("I am the main thread, and I am done!");
	    return ;
	}

    }


    public class TClass { 

	static Random rnd = new Random();
	int k; string msg;

	public TClass( int k, string ms ) {
	    this.k = k;  msg = ms;
	}

	public void Run( ) {

	    Console.WriteLine( "{0:G}Thread {1:G}", (k==1 ? "\t" : "\t\t\t"), k ); 	
	    for ( int i = 0; i < msg.Length; i ++ ) {
	       Console.WriteLine( "{0:G}{1:G}", (k==1 ? "\t" : "\t\t\t"), msg[i] ); 	
	       Thread.Sleep(100 + rnd.Next() % 900);
	    }
	}
    }

}
