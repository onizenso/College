using System;

class Hello {

   public static void Main( String [] ags ) {
	int [][] a = null;
	a = initialize();
	fill( a );
	print( a );
   }

   static int [][] initialize( ) {
	int [][] a = new int[5][];
	for ( int i = 0; i < a.Length; i ++ ) a[i] = new int[i+1];
	return a;
   }

   static void fill( int [][] a ) {
	   for ( int i = 0; i < a.Length; i ++ )
		   for ( int j = 0; j < a[i].Length; j++ ) a[i][j] = i + j;
   }

   static void print( int [][] a ) {
	   for ( int i = 0; i < a.Length; i ++ ) {
		   for ( int j = 0; j < a[i].Length; j++ )
			   Console.Out.Write( "{0:d} ", a[i][j] ) ;
		   Console.Out.WriteLine();
	   }
   }
}
