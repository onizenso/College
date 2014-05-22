/** Dynamic Array based implementation of List, Stack, Queue and Sorted Queue.
 */

#ifndef DLIST_H
#define DLIST_H
#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;

template <typename T>
class DList {

   protected:
	T	*element;
	int	iSize, iCapacity;
   public:
	DList( int cap = 10 ): iCapacity(cap), iSize(0) {
	   assert( cap > 0 );
    	   element = new T[iCapacity];
        }
	DList(const DList<T> &list) : iCapacity(list.iCapacity),
				iSize(list.iSize) {
           element = new T[iCapacity];
           for ( int i = 0 ; i < list.length(); i ++ )
		element[i] = list.element[i];
	}

	const DList & operator = ( const DList & list ) {
   	   if ( this == &list ) return *this;
	   iSize = list.iSize;
	   iCapacity = list.iCapacity;
	   delete element;
	   element = new T[iCapacity];
	   for ( int i = 0 ; i < list.length(); i ++ )
		element[i] = list.element[i];
	   return *this;
	}


	virtual ~DList () {
  	   if ( element != 0 ) delete element;
	}

	/** DList.h: A list class declaration based on a dynamic array.
 	*/
	void  clear() { iSize = 0; }

	bool  empty() const { return iSize <= 0 ; }

	int   length() const { return iSize; }

	int   size() const { return length(); }	
	void  insert( const T & item, int pos = 0 ) {
	   assert( pos >= 0 && pos <= iSize);
	   if ( iSize == iCapacity ) { // list is full already, expand the list
		iCapacity *= 2;
		T * tmp = new T[iCapacity] ;
		for ( int i = 0; i < iSize; i ++ )
		tmp[i] = element[i];
		delete [] element;
		element = tmp;
   	   }
   	   for ( int i = iSize; i > pos; i -- ) element[i] = element[i-1];
	   element[pos] = item;
	   iSize ++;
	}

	void  remove( int pos = 0 );


	const T &   get( int pos ) const { return element[pos]; }

	T &         operator[] ( int pos ) { return element[pos]; }

   template <typename C>
   friend ostream & operator << ( ostream & out, const DList<C> & list );
};
 
template <typename T>
void  DList<T>::remove( int pos )
 {
	   assert( pos >= 0 && pos < DList<T>::iSize);
	   for ( int i = pos; i < (DList<T>::iSize - 1); i++ ) element[i] = 
          element[i+1];
	   DList<T>::iSize --;
	}

template <typename T>
ostream & operator << ( ostream & out, const DList<T> & list ) {
   out << "( ";
   for ( int i = 0; i < list.length(); i++ )
	out << (i == 0 ? "" : ", ") << list.element[i];
   out << " )";
   return out;
}

template <typename T>
class DStack : public DList<T>  {
  public:
	DStack(int cap = 10 ) : DList<T>(cap) { }
	DStack( const DStack<T>& stk) : DList<T>( stk ) {}
	~DStack( ) { delete [] DList<T>::element; }
	const T &	top() { return DList<T>::get( DList<T>::iSize - 1 ) ; }
	void 		push(const T & itm) { insert(itm, DList<T>::iSize) ; }
	void 		pop () { remove( DList<T>::iSize - 1); }
};

template <typename T>
class DQueue : public DList<T>  {
  public:
	DQueue(int cap = 10 ) : DList<T>(cap) { }
	DQueue( const DQueue<T>& que) : DList<T>( que) {}
	~DQueue( ) { delete [] DList<T>::element; }
	const T &	front() { return DList<T>::get( 0 ) ; }
	void 		enqueue (const T & itm) { insert(itm, DList<T>::iSize) ; }
	void 		dequeue();
};

template <typename T>
void DQueue<T>::dequeue()
{ remove( 0 ); }

template <typename T>
class DSQueue : public DList<T>  {
  public:
	DSQueue(int cap = 10 ) : DList<T>(cap) { }
	DSQueue( const DSQueue<T>& que) : DList<T>( que) {}
	~DSQueue( ) { delete [] DList<T>::element; }

	void	enqueue (const T & itm, int pos) {
		insert(itm, pos);
	}
	int	enqueue (const T & itm) {
	    int k; 
	    if ( DList<T>::empty() || itm <= (*this)[0] ) {
		insert(itm, 0); k = 0;
	    }
	    else if ( itm >= (*this)[DList<T>::iSize - 1] ) {
			k = DList<T>::iSize;	
			insert(itm, DList<T>::iSize);
	          }  else {
			int i = 1;
			while ( itm > (*this)[i] ) i++;
			insert(itm, i);
			k = i;
		  }
	    return k;
	}

	void	dequeue( int pos ) { DList<T>::remove( pos ); }

	void	dequeue( const T & itm ) { 
	    int i = find(itm);
	    if ( i == -1 ) return;
	    DList<T>::remove(i);
	}

	int	find ( const T & itm ) {
	    if ( DList<T>::iSize < 1 ) return - 1;
	    int lb = 0, ub = DList<T>::iSize - 1, mid;
	    while ( lb <= ub ) {
		mid = ( lb + ub ) / 2;
		if ( itm == (*this)[mid] ) return mid;
		else if ( itm < (*this)[mid] ) ub = mid - 1;
		     else lb = mid + 1;
	    }
 	    return - 1;
	}
};

#endif
