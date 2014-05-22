/** Table class
     The class provides a way of printing data in a tabular way.
The following features are implemented:
	- A table consists of following components:
		-- Table header
		-- column headers
		-- separator: lines separating each row
		-- row data: one row per record with N columns separated
		   by '|'.
	   The following is an example tabular data:

		+-------------------------------------+
		|	Example Table Header for      |   ... table heading
		+--------+--------------+-------------+   ... separator
		| Col 1  |   Col Hdr 2  |  Col Hdr 3  |   ... column headers
		+--------+--------------+-------------+
		|    str1|  This is a   | ............|   ... data row.
		|        |nice dog.     |             | 
		+--------+--------------+-------------+

     The major features provided by table object includes
	- user specified the column lengths with the total length of widths
	  not more than 80.
	- multiple lines for a row data with string longer than specified
	  column width.
	- The wrapping for long columns take place at a non-alphanumberic place.
	- The column data is aligned at either left, middle or right
	  specified by the user. The column header will be aligned in the
	  middle. The continued lines will be always aligned at the left.

*/
import java.util.*;

public class Table {

   public final static int	maxLength = 80; // maximun width of a line.
   public final static int	left = 0;	// alignment of text
   public final static int	middle = 1;
   public final static int	right = 2;
   public final static int	wrap = 10;
   public final static int	nowrap = 11;
   private int			alignment = right;
   private int			minWidthToWrapWord = 5;
   private String	tableHeader[];
   private String	tableTail[];
   private String	columnHeader[];
   private int		columnWidth[];  // for data only not including '|'.
   private int		columnStart[];	// column string's beginning index
					// used to get a substring out.
   private int		rowWidth;	// sum of column widths <= maxLenght.
   private String	separator;	// line separator: +------+----....

   /** Constructor with fully required parameters:
       table header, column headers, column widths, column alingnment.
   */
   public Table(String hdr[], String colHdr[], int colWd[], int align) {
	init(hdr, colHdr, colWd, align);
   }

   public Table(String hdr, String colHdr[], int colWd[], int align) {
	String s[] = { hdr };
	init(s, colHdr, colWd, align);
   }

   /** Constructor with table header, column header, and column widths */
   public Table(String hdr, String colHdr[], int colWd[]) {
	String s[] = { hdr };
	init(s, colHdr, colWd, right);
   }

   public Table(String hdr[], String colHdr[], int colWd[]) {
	init(hdr, colHdr, colWd, right);
   }

   /** Constructor with no parameter, used to test your table class. */
   public Table() { init("Table Contents", 4); }

   /** Constructor with table header as parameter */
   public Table(String hdr) { init( hdr, 4); }

   /** Constructor with number columns as parameter used for testing purpose.*/
   public Table(int cols) { init ( "Table Contents", cols); }

   /** Constructor with table header, and number of column.*/
   public Table(String hdr, int cols ) { init(hdr, cols); }

   /* initialize table class data members: column widther and column header. */
   protected void init(String hdr, int cols) {
	String s[] = { hdr };
	init(s, cols);
   }

   protected void init(String hdr[], int cols) {
	String	colHdr[] = new String[cols];
	int	colWd[] = new int[cols];
	for ( int i = 0; i < cols; i ++ ) {
		colHdr[i] = "Column " + (i+1);
		colWd[i] = (int)(maxLength / cols - 2);
	}
	init(hdr, colHdr, colWd, right);
   }

   /** Major initialization code for initialize the data members, and
       create row leading space string, and line separator, sumarizing
       the total row width and etc.
   */
   private void init (String hdr[], String colHdr[], int colWd[], int align) {
	tableHeader = hdr;
	columnHeader = colHdr;
	columnWidth = colWd;
	columnStart = new int[colWd.length];
	alignment = align;
	int colDataWidth;
	StringBuffer buf = new StringBuffer(maxLength);
	buf.append('+');
	for ( int i = 0; i < columnWidth.length; i++ ) {
		rowWidth += (columnWidth[i] + 1);  // add space for one '|'.
		buf.append(ScreenIO.makeString('-',
				columnWidth[i] )).append('+');
	}
	rowWidth ++;   // last column has 2 vertical bars.
	separator = buf.toString();
   }

   /** Display the table haders, separator, column headers, and separator. */
   public void showHeader() {
	showTableHeader();
	showColumnHeader();
   }

   public void header() { showHeader(); }
   public void tail() { showTableTail(); }
   public void setTail( String tail[] ) { tableTail = tail;}
   public void showTableHeader() {
	oneColumnSeparator('=');
	showAsOneColumn(tableHeader);
	oneColumnSeparator('=');
   }
   public void showTableTail() {
	showAsOneColumn( tableTail );
	oneColumnSeparator('-');
   }

   protected void oneColumnSeparator(char c) {
	System.out.println(  ScreenIO.formatString(
		'+' + ScreenIO.makeString(c, rowWidth-2) + '+',
		maxLength, ScreenIO.middle ));
   }

   protected void showAsOneColumn(String msg[]) {
	String	s = null;
	int	start = 0, len;
	int	ttLen = 0,			// title string length.
		ttWidth =  rowWidth - 2;	// space for table title.

	for ( int i = 0; i < msg.length; i ++ ) {
		start = 0;
		ttLen = msg[i].length();
		while ( start < ttLen)  {
			len = Math.min(ttWidth, ttLen - start);
			len = wrapAt(msg[i], start, len);
			s = msg[i].substring(start, start+len).trim();
			System.out.println( ScreenIO.formatString( '|'
			+ ScreenIO.formatString(s, rowWidth-2, ScreenIO.middle)
			+ '|',
			maxLength, ScreenIO.middle ));
			start += len;
		}
	}
   }

   public void showColumnHeader() {
	int originalAlignment = alignment;
	alignment = middle;
	showARow(columnHeader);
	alignment = originalAlignment;
   }

   /** Display a record as a row, with n columns. A record is passed to here
       as array of strings.
   */ 
   public void show(String col[]) { showARow(col); }
   public void show(String col[], int nowrap) { showARow(col, nowrap); }

   public void showARow(String col[]) { showARow(col, this.wrap); }

   public void showARow(String col[], int nowrap ) {
	StringBuffer buf = new StringBuffer(rowWidth);
	boolean		more;

	for ( int i = 0 ; i < col.length; i ++ ) 
		col[i] = ScreenIO.removeExtraBlanks(col[i]);

	eraseColumnStart();

	while ( (more = makeARow(col, buf) ) ) {
		System.out.println(ScreenIO.formatString(
			buf.toString(), maxLength, ScreenIO.middle));
		if ( nowrap == this.nowrap ) break;
	}
	System.out.println(ScreenIO.formatString(
			separator, maxLength, ScreenIO.middle));
   }

   /** make a line from a column strings, change the starting indices for
       each column data so the wrapped line will start at the right place.
   */ 
   protected boolean makeARow(String col[], StringBuffer buf) {
	int len =0, remainder = 0;
	boolean ok = false;
 	String s = null;
	buf.delete(0, buf.length());
	buf.append('|');
	for ( int i = 0; i < columnWidth.length; i++ ) {
	   if ( i >= col.length || col[i] == null ) s = "";
	   else {
		remainder =  col[i].length() - columnStart[i];
		len = Math.min( remainder, columnWidth[i]) ;
		if ( len <= 0 ) s = "";
		else {
		    // Find proper place to wrap a line.
		    len = wrapAt( col[i], columnStart[i], len);

		    // Eliminate leading and trailing spaces
		    s = col[i].substring(columnStart[i],
				columnStart[i]+len).trim();
		    ok = true; // yes we have something left for the column.
		}
	    	columnStart[i] += len;
	    }
	    buf.append(ScreenIO.formatString(s, columnWidth[i], alignment) );
	    buf.append('|');
	}
	return ok;
   }

   /** If a string needs more than len spaces to display the substring
       between start and start + len -1. A right place in the substring
       must be found so that the substring between start and that place
       will be displyed.
   */
   protected int  wrapAt( String s, int start, int len ) {
	if ( start + len >= s.length() ) return len;
	if ( Character.isWhitespace( s.charAt(start+len) ) ) return len+1;
	int i;
	for ( i = start + len - 1; i > start ; i -- )
	   if ( ! Character.isLetterOrDigit(s.charAt(i)) ) break;
	return i == start ? len : i - start + 1;
   }

   // Initialize the starting indices for columns data to zeros.
   protected void eraseColumnStart() {
	for ( int i = 0; i < columnStart.length; i ++ ) columnStart[i] = 0;
   }

   // Display separator.
   public void separator() {
	System.out.println(
		ScreenIO.formatString(separator, maxLength, ScreenIO.middle));
   }

   // Display separator.
   public void showSeparator() { separator(); }

   public void show(String rows[][]) {
	showHeader();
	for ( int i = 0; i < rows.length; i ++ )
		showARow(rows[i]);
	System.out.println();
   }
}
