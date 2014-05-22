import java.util.*;

public class TestHashTable {

   static string ttitle[] = {"Implementation of Hash Table", "Assignment 3"};
   static string chr[] = {"Command", "Description"};
   static int 		wd[] = {10, 50};
   static string menu[][]  = {
		{"g G",
			"Prompt for two intergers, the capacity and the" +
			" load factor of a hash table. Create a new hash table," +
			" with 20% as increment percentage, " +
			" generate (capacity * load factor) many mixed Member" +
			" objects and add them to the hash table."
			},
		{"a A",
			"Instanciate a new member object, and the object into" +
			" the hash table. Display the newly added member," +
			" its home address and current address."
			},
		{"r R", "Ask for an ID or hash code of an object. Remove the" +
			" object whose ID matchs the given ID."
			}, 
		{"f F", "Ask for an ID or hash code of an object, find the " +
			"object and display ID, current & home addresses."
			}, 
		{"s S",	"Show contents of hash table in a tabular way." +
			" one object per line and 20 objects per screen." +
			" for each line, the following columns have to be" +
			" displayed: OBject, current address, home address" +
			" and the displacement from home address to its" +
			" current address."
			}, 
		{"t T", "Perform a successful search on each of object in" +
			" the hash table, and 'capacity' many unsuccessful" +
			" searches, list the (1) avareage comparions from" + 
			" all successful searchs, the theoretic susccessful" +
			" search complexity [(11/(1-a))/2]," +
			" the theoretical un-successful search" +
			" time complexity [(1+1/(1-a)**2)/2]."
			}, 
		{"b B",	"Display information on blocks formed by contiguous" +
			" data or empty cells inside table. For each block," +
			" display the type of block (either data or empty)," +
			" the starting and ending addresses, size of block." +
			" At the end of block listing, show the total number " +
			" of blocks, the maximum, the minimum and the average " +
			" block sizes, for each type. Allow quit listing" +
			" the total, maximum, minimum and average must show " +
			" the correct data even if the listing of block ends."
			}, 
		{"p P",	"List the table parameters. The parameters include." +
			"the capacity, size, load factor, increment percentage," +
			"and the actual load factor."
			}, 
		{"h H",	"Show this menu."}, 
		{"q Q",	"Exit the program."}
 	};
   static string prompt = "Eneter a command <G(en), A<dd>, R(mv), F(ind), S(how), T(est), B(lock), P(ar), H(elp), Q(uit))> : ";
   static int val;
   static HashTable<Member> ht = new HashTable<Member>();
   static char choice ;
	
   public static void main(string args[] ) {
	Table	menuTable = new Table(ttitle, chr, wd, Table.middle);

	init();
	while ( true ) {
		choice = Character.toUpperCase(ScreenIO.promptForChar(prompt));
		switch ( choice ) {
			case 'G': generate(); break;
			case 'A': add(); break;
			case 'R': remove(); break;
			case 'F': get(); break;
			case 'S': content(); break;
			case 'T': timeComplexity(); break;
			case 'B': showBlocks(); break;
			case 'P': parameter(); break;
			case 'H': menuTable.show(menu); break;
			case 'Q': System.exit(0); 
		}
	}
   }

   static void generate() {
	int cap = ScreenIO.promptForInt(  "Enter Capacity for the Hash Table: ");
	float ldf = ScreenIO.promptForInt("Enter load factor (e.g. 75)      : ") / 100.0f;
	int cnt = (int)( cap * ldf);
	Member p = null;
	ht = new HashTable<Member>(cap, ldf, 0.2f);
	for ( int i = 0; i < cnt; i ++ ) {
		p = new Member();
		ht.add( p ) ;
	}
   }

   static void add()  {
	ht.add( new Member() ); 
	content();
   }

   static void remove() {
	val = ScreenIO.promptForInt("Enter an integer : ");
	Object c  = ht.remove( val );
	content();
   }

   static void get() {
	val = ScreenIO.promptForInt("Enter an integer : ");
	int k = ht.find( val );
	if ( k < 0 ) {  System.out.printf("\n\t\t\tObject, %s, Not Found!\n\n", val); return ; }

	string tHeader = "Object Found";
	string cHeader[] = {"Object Value", "Current Address", "Home Address",
			"Displacement" };
	int    cWd[] = {30, 7, 7, 7};
	Table conTable = new Table(tHeader, cHeader, cWd, Table.middle);
	conTable.showHeader();
	conTable.show( ht.fields(k), Table.nowrap );
   }

   static void parameter() {
	string cols[] = {"Capacity", "Size", "Increment", "Specified Load Factor", "Actual Load Factor"};
	int	cw[] = {12, 12, 12, 12, 12};
	string s[] = new string[5];
	s[0] = ScreenIO.formatInt(ht.capacity());
	s[1] = ScreenIO.formatInt(ht.size());
	s[2] = ScreenIO.formatFloat(ht.increment(), 2);
	s[3] = ScreenIO.formatFloat(ht.loadFactor(),2);
	s[4] = ScreenIO.formatFloat((float) ht.size()/ht.capacity(), 2);
	Table tb = new Table("Parameters of The Hash Table", cols, cw );
	tb.header();
	tb.show(s);
   }

   static void timeComplexity() {
	string s = "Average Search Time Complexities";
	string cHeader[] = {"Successful Search", "Unsuccessful Search",
				"Theoretic S.S", "Theoretic U.S.S", "Binary Search"};
	int    cWd[] = {12, 12, 12, 12, 12 };
	Table searchTable = new Table(s, cHeader, cWd, Table.middle);
	string sComp[] = ht.searchInfo( ht.size());
	searchTable.showHeader();
	searchTable.showARow( sComp );
   }

   static void showBlocks() {
	string tt = "Information on Data and Blank Blocks";
	string cHeader[] = {"Block Type", "Starting Address",
				"Ending Address", "Size" };
	int    cWd[] = {12, 12, 12, 12 };
	Table blockTable = new Table(tt, cHeader, cWd, Table.middle);
	ht.blockInfo(blockTable);
   }

   static void content() {
	string tHeader = "Contents of Hash Table";
	string cHeader[] = {"Object Value", "Current Address", "Home Address",
			"Displacement" };
	int    cWd[] = {30, 7, 7, 7};
	Table conTable = new Table(tHeader, cHeader, cWd, Table.middle);
	conTable.showHeader();
	for ( int i = 0; i < ht.capacity(); i++ ) {
		conTable.show( ht.fields(i), Table.nowrap );
		if ( (i + 1) % 20 == 0  && (i+1) < ht.capacity() )
		   if (ScreenIO.quit("Q/q to quit ... ", 'q') ) break;
		   else System.out.println();
	}
   }

   static void init() {
	int k;
	Member  p = null;
	for ( int i = 0; i < 6; i ++ ) {
		k = HWUtil.nextInt(2);
		switch ( k ) {
		    case 0: p = new Member(); break;
		    case 1: p = new Student(); break;
		    // case 2: p = new Faculty(); break;
		    //case 3: p = new Staff(); break;
		}
		ht.add(p);
	}
   }
}
