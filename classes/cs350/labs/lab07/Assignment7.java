import javax.swing.*;
import java.awt.*;
import java.util.*;

class Assignment7 extends Closeable
{
    public final static long serialVersionUID = 1L;

    JTextArea msg= new JTextArea(40,40);
    JTextField tb1 = new JTextField(30);
    JTextField tb2 = new JTextField(30);


    public Assignment7() {}
    public Assignment7(String title)
    {
	super(title);
	Container c=getContentPane();
	c.setLayout(new BorderLayout() );
	c.setLayout(new BorderLayout(10,10) );
	c.add(tb1, "North");
	c.add(tb2, "South");
	c.add(msg, "Center");
	setSize(300,800);
	setVisible(true);
    }

    public static void main(String argv[]) 
    {
	Assignment7 app = new Assignment7("Gui with Two Threads");

	Thread t1 = new Thread(new Writer(app.tb1, app.msg, 'A'));
	Thread t2 = new Thread(new Writer(app.tb2, app.msg, 'a'));
	t1.start();
	t2.start();
    }
}
