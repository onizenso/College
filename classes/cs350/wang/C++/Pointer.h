#ifndef POINTER_H
#define POINTER_H

template <class T>

class Tombstone {

    public:
	int cntPointers, length;  // count of pointers and length of array
	T	* pointer;
	Tombstone( int len ); // set length = len,  cntPointer to 1.
				// pointer = new T[len]
	~Tombstone ( );
	Thombstone ( const Tombstone<T> & p );
	  // copy length to here, set cntPpointer = 1, allocate 
	  // heap dynamic memory. Copy data from p.pointer to new heap
	  // dynamic memory.
	  //
	//operators or function to increment and decrement cntPointer.
};

template <class T>
class Pointer {
   protected:
       Tombstone<T> * pointer;
   public:
       Pointer(int size = 10) ; // set pointer to a new tombstone object
       Pointer( const Pointer<T> & p) ; 
       ~Pointer( );	// decrent tombstone' cntPointer. If the count
       			// equals to 0, delete tombstone object.
	Pointer<T> operator= ( const Pointer<T> v) ;
	// Let this->pointer point at the same tombstone object, and
	// increment cntPointer of the shared tombstone object.
	Pointer<T> & allocate(int size);
	void opeator deallocate(); // decrement count, delete tombstone 
				// object when necessary. 
	// void opeator delete(); // Don't overload delete operatori
	// since it request void*. We want to pass reference of
	// Pointer<T> to the delete operator. Write deallocate(). 
	
	T & operator[] ( int k );
	// check boundary. Return reference to pointer->pointer[k]
	int lengt() ; // number of element in array.
};
