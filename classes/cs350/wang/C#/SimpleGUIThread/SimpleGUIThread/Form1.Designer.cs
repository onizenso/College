using System;
using System.Text;
using System.Windows.Forms;
using System.Threading;

namespace SimpleGUIThread
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.MessageBoard = new System.Windows.Forms.TextBox();
            this.txtBox1 = new System.Windows.Forms.TextBox();
            this.txtBox2 = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // MessageBoard
            // 
            this.MessageBoard.Location = new System.Drawing.Point(61, 46);
            this.MessageBoard.Multiline = true;
            this.MessageBoard.Name = "MessageBoard";
            this.MessageBoard.Size = new System.Drawing.Size(349, 173);
            this.MessageBoard.TabIndex = 0;
            // 
            // txtBox1
            // 
            this.txtBox1.Location = new System.Drawing.Point(21, 260);
            this.txtBox1.Name = "txtBox1";
            this.txtBox1.Size = new System.Drawing.Size(187, 20);
            this.txtBox1.TabIndex = 1;
            this.txtBox1.Text = "ANC";
            // 
            // txBox2
            // 
            this.txtBox2.Location = new System.Drawing.Point(229, 261);
            this.txtBox2.Multiline = true;
            this.txtBox2.Name = "txtBox2";
            this.txtBox2.Size = new System.Drawing.Size(209, 20);
            this.txtBox2.TabIndex = 2;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(483, 379);
            this.Controls.Add(this.txtBox2);
            this.Controls.Add(this.txtBox1);
            this.Controls.Add(this.MessageBoard);
            this.Name = "Form1";
            this.Text = "GUI and Multitheads";
            this.ResumeLayout(false);
            this.PerformLayout();

            Writer wtr = new Writer(txtBox1,MessageBoard, 30, 'A');
           
        }

 

        #endregion

        private System.Windows.Forms.TextBox MessageBoard;
        private System.Windows.Forms.TextBox txtBox1;
        private System.Windows.Forms.TextBox txtBox2;
    }

    public class Writer {
        static Random rnd = new Random();
        private System.Windows.Forms.TextBox tbTxt, tbMsgBrd;
        private int maxLen;
        private char ch;


        public Writer(  TextBox tbTxt,  TextBox tbMsgBrd, int maxLen, char c ) {
           this.tbTxt = tbTxt;  this.tbMsgBrd = tbMsgBrd ;
           this.maxLen = maxLen; ch = c;

           Thread thread = new Thread(new ThreadStart(this.run));
           thread.Start();

        }

        public void run() {
            char [] chars = new char[2];
            string str = null;
            while ( true ) {
                int n = rnd.Next( maxLen ) + 1;
                for ( int i = 0; i < 5; i++ ) {
                        chars[0]= (char ) (ch + rnd.Next(26));
                        str = new string(chars);
                        tbTxt.Text += "H";
                        // tbTxt.Text = str ;
                        // tbMsgBrd.AppendText("" + ((char)(ch + rnd.Next(26)))); 
                        Thread.Sleep(500 + rnd.Next(501));
                }
                //tbMsgBrd.AppendText( tbTxt.Text) ;
                tbTxt.Clear();
            }
        }
    }
}

