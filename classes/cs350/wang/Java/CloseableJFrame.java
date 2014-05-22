import java.awt.event.* ;
import javax.swing.* ;

public class CloseableJFrame extends JFrame 
{  public CloseableJFrame() { super() ; addCloseListener(); }
   public CloseableJFrame (String s) { super(s) ; addCloseListener(); }
   void addCloseListener() { addWindowListener(new WindowAdapter() {
	public void windowClosing(WindowEvent e) { dispose(); System.exit(0); } } ); }
   protected void finalize() throws Throwable  {
	try { super.finalize(); } finally { System.exit(-1); } }
}
