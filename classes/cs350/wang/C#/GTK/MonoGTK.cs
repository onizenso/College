using System;
 using Gtk;
 using System.IO;
 

public partial class MainWindow : Gtk.Window
 {
     public MainWindow () : base(Gtk.WindowType.Toplevel)
     {
         Build ();
     }
     
 
    
 
    protected void OnDeleteEvent (object sender, DeleteEventArgs a)
     {
         Application.Quit ();
         a.RetVal = true;
     }
     
 
    protected virtual void OnButtonClearClicked (object sender, System.EventArgs e)
     {
         //code executed when the Clear button is clicked
         textview1.Buffer.Text="";//clears the buffer displayed by the TextView  
    }
 

    protected virtual void OnButtonUppCaseClicked (object sender, System.EventArgs e)
     {
         //code executed when the Upper Case button is clicked
         textview1.Buffer.Text=textview1.Buffer.Text.ToUpper();
     }
 
    
    protected virtual void OnButtonLowerCaseClicked (object sender, System.EventArgs e)
     {
         //code executed when the Lower Case button is clicked
         textview1.Buffer.Text=textview1.Buffer.Text.ToLower();
     }
     
 
    protected virtual void OnButtonSaveClicked (object sender, System.EventArgs e)
     {
         //code executed when the Copy button is clicked
         StreamWriter sw=new StreamWriter("Test.txt");
         sw.Write(textview1.Buffer.Text); //Write textview1 text to file
         textview1.Buffer.Text="Saved to file !"; //Notify user
         sw.Close(); 
    }
 }
