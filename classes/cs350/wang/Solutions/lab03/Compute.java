// CMPS 350 LAB 03 Solution   
// note: please stay away from TABs

import java.util.List;
import java.util.LinkedList;
import java.io.*;
import java.util.Formatter;

public class Compute {

    static final int N_COL = 4;  // number of columns in the input file 
    int[] col_counts = null;     // number of items in each column, excluding 0 
    int[] sums = null;           // sums of each column
    int[] means = null;          // means of each column
    BufferedReader in;           // input file
    File file = null;            // output file
    Formatter formatfile = null; // formatted output file

   //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 
     void init() {
   //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 
   
       sums = new int[N_COL]; 
       means = new int[N_COL]; 
       col_counts = new int[N_COL]; 

       for (int i = 0; i < N_COL; i++ ) {
          sums[i] = 0;
          means[i] = 0;
          col_counts[i] = 0;
       }

       file = new File ("out.file");
       if ( file == null ) {
            System.out.println ("Output File not opened"); 
       }
       try {
          formatfile = new Formatter (file);
       }
       catch ( FileNotFoundException e ) { 
       } 
       try {
          in = new BufferedReader(new FileReader("in.file"));
       }
       catch ( Exception e ) {
         e.printStackTrace();
       } 
    }

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
     void header( ) {
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
       String format_str = "%-8s";
 
       System.out.format( format_str, "" );
       formatfile.format( format_str, "" );

       for (int i = 0; i < N_COL; i++) {
          System.out.format( format_str, "Exam" + (i + 1) );
          formatfile.format( format_str, "Exam" + (i + 1) );
       }
       System.out.println( "" );
       formatfile.format("\n");
       System.out.format( format_str, "" );
       formatfile.format( format_str, "" );
       for ( int i = 0; i < N_COL; i++ ) {
           System.out.format( format_str, "=====" );
           formatfile.format( format_str, "=====" );
       }
       System.out.println("");
       formatfile.format("\n\n");
    }  

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
     void footer ( ) {
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
       String format_str = "%-8s";
       // Lines under the values
       System.out.format(format_str, "");
       formatfile.format(format_str, "");
       for (int i = 0; i < N_COL; i++) {
          System.out.format(format_str, "======");
          formatfile.format(format_str, "======");
       }
       System.out.println("");
       formatfile.format("\n");

       System.out.format(format_str, "Mean:");
       formatfile.format(format_str, "Mean:");
       for (int i = 0; i < N_COL; i++) {
           System.out.format(format_str, means[i]);
           formatfile.format(format_str, means[i]);
       }
       System.out.println("");
       formatfile.format("\n");

       // Need to flush the data out of the buffer.
       formatfile.flush ();
       formatfile.close ();
    } 


   //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 
     void process () {
   //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 
         
      // read input file as a linked list of Strings
      List<String> lines = new LinkedList<String>();
      int n_lines = 0;
      try {
          while (true) {
             String line = in.readLine();
             if (line == null) break;
             lines.add(line);
             n_lines++;
          } 
   
          // sum the values 
          String line;
          for (int i=0; i< n_lines; i++) {
             line = lines.get(i);
             line = line.trim();
             String[] line_values = line.split("\\s+");
             // int n_col = line_values[0].length();  <- if you want it dynamic
             System.out.format("\t%-34s", line);
             formatfile.format("\t%-34s", line);
             System.out.println("");
             formatfile.format("\n");

             // perform running sum of the 4 columns excluding 0 values
             for (int j=0; j < N_COL; j++) {
                int tmp = Integer.parseInt(line_values[j]); 
                sums[j] += tmp; 
                if ( tmp > 0 ) {
                    col_counts[j] += 1;
                }  
              } // end for
          } // end for

         // compute means , throwing out zero values
         for (int i=0; i < N_COL; i++) {
            means[i] = sums[i] / col_counts[i];
         }    
       }
       catch ( Exception e ) {
            e.printStackTrace();
       } 
    } 
   //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        public static void main (String[] args) {
   //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
         Compute myInstance = new Compute();  // Java requires this
         myInstance.init();
         myInstance.header();
         myInstance.process();
         myInstance.footer ();
    }
} // end class Compute
