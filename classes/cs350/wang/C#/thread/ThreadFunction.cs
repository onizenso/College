/** ThreadFunction.cs show that
 *
 *    1. Create a thread and bound a function to the thread.
 *    2. Start a thread with at most one parameter depending on
 *       whether the function has thread.
 *
 *    Notice that
 *
 *    	1. The function that a thread should 
 *
 *         (1) have void return type
 *    	   (2) have zero or more parameters. Start() can  be used
 *    	       to pass one or no parameter to function and lambda
 *    	       notation can be used to pass one or more paramenters
 *    	       to the function.
 *    	   (3) only the function name is passed to new thread.
 *    	   (4) If the function is not static the function name 
 *    	       must be prefixed with obj name or class name.
 *         (5) If the function is not static, an object name must
 *    	      be used to prefix the function name.
 *
 *	2. The start() function of Thread class
 *	   (1) Take zero or one parameter depending one whether the
 *	       function has parameter or not.
 *	   (2) The start() function pass its parameter to the function
 *	       bounded to the thread.
 *	   (3) Call the function bound to the thread.	       
 *
 *	3. The steps of creating a thread to run a void function:
 *
 *	    (1) Define the function with the format:
 *	    	[static] void FuncName[<T>] ( [T or Object] paraemeter] )
 *	    	{  function-body } 
 *	    (2) Create a thread and bound to the function defined above.
 *	    
 *	    	Thread t = new Thread ( FunctionName ); 
 *	  
 *	    (3) Start the thread:
 *	    	t.start( [ argument ] );
 *
 *	    The step (2) and (3) can be combined to a step:
 *
 *	    	new Thread ( [class. | variable.] FunctionName ).start( [ argument ] ); 
 *
 * */

using System;
using System.Threading;

namespace HWangSpace {

    public class SimpleApplication {

	static void Main( String[] args ) {

	    // SimpleApplication app = new SimpleApplication();	
	    Thread t =  null;
	    
	    // t = new Thread ( app.Go ) ; t.Start( 123 );
	    t = new Thread ( Go ) ; t.Start( 123 );

	        // A shorted method to create and run the thread.
	        new Thread ( Go ).Start( "Thread 2");

		// Use lambda notation to pass multiple arguments to function.
	        new Thread ( () => Go2( 123, "Go2 has  2 paraters" )).Start();

	    return ;
	}

	// void Go<T> ( T obj ) {
	static void Go<T> ( T obj ) {
	    Console.Out.WriteLine("{0:G}", obj);
	}

	static void Go2 ( int v, string s) {
	    Console.Out.WriteLine("par 1: [{0:d}], par 2: [{1:G}]", v, s );
	}
    }
}
