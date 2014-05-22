public class Test {

    public static void main ( String args[] ) {
	String str = "";
	for ( int i = 0; i < args.length; i ++ )
	    str += args[i] + " ";

	// String str2 = "";
	StringBuffer str3 = new StringBuffer();
	for ( int i = 0; i < Integer.parseInt( args[0] ) ; i++ )
	    //str2= str2 + str;
	    str3.append( str );

	System.out.printf ( "Arguments: %s\n", str3.substring(0) );
    }
}
