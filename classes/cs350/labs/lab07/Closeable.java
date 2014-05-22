import java.awt.event.*;
import javax.swing.*;



public class Closeable extends JFrame
{
    public Closeable()
    {
	super();
	addCloseListener();
    }

    public Closeable (String s)
    {
	super(s);
	addCloseListener(); 
    }

    void addCloseListener()
    {
	addWindowListener(new WindowAdapter()	
	{
		    public void windowClosing(WindowEvent e)
		    {
	    		dispose();
	    		System.exit(0);
		    }
	}
	);
    }
	protected void finalize()throws Throwable
	{
	    try{super.finalize(); }
	    finally {System.exit(-1); }
	}
}
