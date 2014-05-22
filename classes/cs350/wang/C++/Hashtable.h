
/**
 * Name: Huaqing Wang
 * Description:
 *
 * Date:
 * */

#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

template <class T>
class  Hashtable {

  protected:
    T 	**	table ;
    float	ld    ;
    int		cap,size   ;

    void rehash() { }
    int hash( int key ) { return key % cap; }
  public:
   
    Hashtable( ) {
	cap   = 10; size = 0;
    	table = new T* [cap];
    	ld = 0.75;
	for ( int i = 0; i < cap ; i++ ) table[i] = NULL ;
    }

    int add( T * obj ) {

	if ( size >= ld * cap ) rehash();
	int home = hash( obj->hashCode() );

	while ( table[home] != NULL ) home = ( home + 1 ) % cap;
  	table[home] = obj;
        size++;
	return home;
    }
    
    void show() {
	for ( int i = 0; i < cap ; i ++ )
		printf("%5d %s\n", i, ( table[i] == NULL ? "NULL" : table[i]->toString()) );
    }
};
