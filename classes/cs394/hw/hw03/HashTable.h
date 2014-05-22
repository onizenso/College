//	A Hash Table!!!
//


template <class T>
class HTable {
    protected:
	T ** 	table;
	int 	size, cap, pct;
    public:
	HTable( int c=10, int p=80 ) 
	{ cap = c; size = 0; pct = p; table = new T * [cap];
	  // initialize table elements to NULLs
	}
	HTable( const HTable & t ) {
	    cap = t.cap;
	    size = t.size;
	    pct = t.pct;
	    table = new T * [cap];a
		// the following will not work.
	    memcpy( table, t.table, sizeof(T*) * cap ); // This might be bad :(
	}

	~HTable() {
	    // Neet to delete objects in table first.
	    if( table )
		delete [] table;
	}


	// int hash( int & data ) {
	int hash( const T & obj) {
	    return obj.hashCode() %cap; // This may also be really good.
	}

	HTable<T> & insert( const T & v ) {
	    T * data = new T(v);
	    int homeAddy = hash(v);
	    int i=0;
	    // Is expansion needed? If it is, expand array and rehash() 
	    // all objects into new location
	    rehash();
	    while( table[ (homeAddy + i)%cap ] != NULL )
		i++;
	    table[ (homeAddy+i)%cap ] = data;

	    return *this;
	}

	void shift( int empty ) { // NOT GOOD
	    // start with k =  (empty+1) % cap, and end at next NULL element.
	    // 1. Test whether table[k] should be moved to empty.
	    // 2  If it is not needed, k = (k+1) % cal, got step 1.
	    // 3. If object at table[k] needs to move to empty location,
	    //    move it to there and set empty to k, and go to step 1.
	}
	int  search( const T & obj ) {
	   // find home address of obj, compare the obj.keyCode with ...
	   // If found return the index of element.Otherwise -1 
	}

	void erase( T & v ) {
	    int loc = search(v);
	    if ( loc < 0 ) { return; } 
	    delete table[loc];
	    table[loc] == NULL; 
	    shift( loc );
	}

	// Expand the table by 20%.
	void rehash() { 
	    int tCap = (int) ( cap * 1.2 + 1);

	    T ** tmp = new * T[ tCap ] = { NULL };
	    swap(tmp, table);
	    swap(tCap, cap);
	    for ( int i = 0; i < tCap; i++ )
		  if ( tmp[i] != NULL )
		      insert( *tmp[i] );
	  



// ...
