
public class JavaEquals {

    public static void main ( String args[] ) {
	Integer i = new Integer(100), j = null; // new Integer(100) ;

	j = i; 
	System.out.printf ( "i =  %s, j = %s, i.equals(j) = %b, i == j = %1B\n",
		i, j, i.equals(j), i == j );

	j = new Integer(100); 
	System.out.printf ( "i =  %s, j = %s, i.equals(j) = %b, i == j = %B\n",
		i, j, i.equals(j), i == j );
    }
}
