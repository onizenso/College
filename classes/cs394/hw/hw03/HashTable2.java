public class HashTable2 <T> {

    protected	Object	table[];
    protected   int	count = 0;
    protected	float	loadingFactor = 7.5f,
    			incPCT = 0.2f;

    public	HashTable2() { table = new Object [10]; }

    public	HashTable2(int iniSize, float ldf) {
	table = new T [iniSize];
	loadingFactor = ldf;
    }

    public 	void testNulls() {
	int nullCnt = 0, nonNullCount= 0;
	for ( int i = 0; i < table.length;  i++)
	    if ( table[i] == null ) nullCnt ++;
	    else nonNullCount ++;
	System.out.printf("Nulls = %d, non Nulls = %d\n", nullCnt, nonNullCount);
    }

    protected	int hash ( T obj ) {
	if ( obj == null ) return -1;
	return obj.hashCode() % table.length;
    }

    protected	int inc( int k ) { return  (k + 1) % table.length; }

    protected   HashTable2 rehash() {
   	return this; 
    }

    protected	int distance ( int home, int curLoc ) {
	if ( curLoc >= home ) return (curLoc - home);
	return (curLoc + table.length - home);
    }

    public	HashTable  put( T obj ) {

	int home = hash( obj );
	while ( table [home] != null )  home = inc( home );
	table[home] = obj;
	count ++;
	if ( ((float) count / table.length) > loadingFactor ) rehash();
	return this;
    }

    public	void show() {
	int   home;

	System.out.printf("%36s %10s %10s %10s\n", 
			  "           Object             ", "Home Addr", "Cur. Loc", "Distance");

	for ( int loc = 0; loc < table.length; loc ++ ) {
	    if ( table[loc] == null ) System.out.printf("%58d\n", loc);
	    else {
	    	home = hash(table[loc]);
	    	System.out.printf("%35s %10d %10d %10d\n", 
			table[loc],
			home, loc, distance( home, loc ) );
	    }
	}

    }
}
