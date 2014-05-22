/** List sturcures Package
 *
 *  To compile the program:   mcs skeleton.cs
 *  To Run  the program   :   mono skeleton.exe
 *  To debug the program  :   mcs -debug skeleton.exe
 *  		       or     mdb skeleton.exe
 
   public class SortedQueue<T> : List<T>
		where : T IComparable<T>, new() {
	// Similar to java's 
	// 	public class SortedQueue<T extends Comparable> {}
	// The new() meas T must have a default constructor and the
	// SortedQueue class will create T object using the default constructor
   }
 
 * */

using System;

namespace listpack {

    public interface Iterator<T> {
	bool hasNext() ;
	T next ();
    }

    // A generic general list structure.
    public class List<T> { 

	// Inner node class for list
	class Node {
    		public T	data;
    		public Node	next, previous;

	    public Node( T dt ) { data = dt; next = previous = null; }
	}

	// Data Members List:
	
	Node	 front, rear;
	int	cnt;


	public List() {	
		cnt = 0; front = rear = null;
	}

	public List<T> add( T itm, int pos = 0 ) {

	   Node nn = new Node( itm ) ;
	   if  ( cnt < 1 ) {
	       front = rear = nn; cnt ++; return this;
	   }

	   if ( pos < 1 ) {
	       nn.next = front; front = nn; cnt ++; return this;
	   }

	   if ( pos >= cnt ) {
	       nn.previous = rear; rear.next = nn; rear = nn;
	      cnt++; return this;

	    }

	    // find out right place to put the new node in. 
	   return this;
	}

	class ListIterator : Iterator<T> {

	    Node cur = null;

	    public ListIterator(  Node front ) { cur = front; }

	    public bool hasNext() { return cur != null; }

	    public T    next() {
		T obj = cur.data; cur = cur.next;
		return obj;
	    }
	}

	public Iterator<T> iterator() { return new ListIterator( front ) ; }

    }

    public class Stack<T> : List<T> {

	public Stack(): base() { }

	public Stack<T> push( T itm ) {
    		add( itm, 0 );
    		return this;
	}		

    }	
}
