
public class Precedences {

    public static void main( String ags[] ) {

	System.out.printf( "Since 1 + 2 * 3 = %d\t, mulplication has higher precedence thatn addition\n", 1 + 2 * 3 );

	System.out.printf("\n\nFor the formula :  f(1) + f(2) * f(3) has the following function call sequence:\n");
	int x = f(1) + f(2) + f(3);
	System.out.printf("In java addition has left-right associtivity.\n");


	x = 0;
	System.out.printf(" x + q() = %d\n", x + q() );
	x = 0;
	System.out.printf(" q() + x = %d\n", q() + x );

    }

    static int x = 0;

    static int q () { x ++; return x; }

    static int f ( int i ) {

	System.out.printf("f() is called f(%d)\n", i);
	return i;
    }
}
