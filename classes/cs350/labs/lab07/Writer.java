import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.lang.*;

public class Writer implements Runnable{
    static Random rand = new Random();
    JTextField tf;
    JTextArea msg;
    char ch;

    public Writer(JTextField tf, JTextArea msg, char ch)
    {
	this.tf = tf;
	this.msg = msg;
	this.ch = ch;
    }

    public void run(){
	while(true){
	    int strlen=5+rand.nextInt(16);
	    int rnd=rand.nextInt(28)+3;
	    for(int i=0; i<strlen; i++)
	    {
		tf.setText(tf.getText() + (char)(ch+rand.nextInt(26)));
		try{Thread.sleep(rand.nextInt(200)+100);}
		catch(Exception e){}
	    }
	    msg.append(tf.getText() + '\n');
	    tf.setText("");
	}
    }
}
		    


