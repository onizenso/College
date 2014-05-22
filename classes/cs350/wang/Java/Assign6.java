/** The example show how to create Java Swing fram with JFrame class.
*/

import javax.swing.*;
import java.awt.*;
import java.util.*;

class Assign6 extends CloseableJFrame {
    public final static long serialVersionUID = 1L;

    JTextArea	msg = new JTextArea(40, 40);
    JTextField	tb1 = new JTextField(30), 
		tb2 = new JTextField(30);

    // Constructor:
    public Assign6 () {}
    public Assign6 (String title) {
	    super(title);
	    Container c = getContentPane();
	    c.setLayout( new BorderLayout() );
	    // c.setBackground( new Color(0, 0, 0) );
	    c.setLayout( new BorderLayout(10,10) );
	    c.add( tb1, "North");
	    c.add( tb2, "South");
	    c.add( msg, "Center");
	    setSize(300, 800); setVisible(true);
    }

    public static void main(String argv[] ) {
	Assign6 app = new Assign6("GUI with Two Threads") ;
	
	// Create and start two threads which carry two runnable objeacts that
	// will generate random character sequence stored in JTextField and
	// then copies it to JTextArea object.
    }
}

