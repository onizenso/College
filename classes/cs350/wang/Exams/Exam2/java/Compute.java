// CMPS 350 Exam 2    NAME: 
/* Find the count, max, min, and mean of a list of positive integers and write 
   results to an output file. Read the integers from 

        /home/fac/donna/public_html/donna/cs350/Exam2/in.file 

   Hints:
   In the interest of time, you may do everything in main(). For sample code, 
   see /home/fac/donna/public_html/cs350/Code/Java/Test.java and your solution
   to lab03.

   Write the mean as a float with 2 decimal precision - others as integers. 
   Sample output file:

   Exam 2 Solution 
   Count:    20 Mean:  72.00 Max:    100 Min:     45
*/

import java.util.List;
import java.util.LinkedList;
import java.io.*;
import java.util.Formatter;

public class Compute {

  public static void main (String[] args) throws IOException
  { 
    int sum = 0;         
    int max = 0;
    int min = 1000;
    double mean = 0.0;         

    BufferedReader inf;             // input file
    File outfile = null;            // output file
    BufferedReader infile = null;   // input file
    Formatter formatfile = null;    // formatted output file

    outfile = new File ("out.file");
    if ( outfile == null ) {
         System.out.println ("Output File not opened"); 
    }
    try {
          formatfile = new Formatter (outfile);
    }
    catch ( FileNotFoundException e ) { 
    } 
    try {
        infile = new BufferedReader(new FileReader("in.file"));
    }
    catch ( Exception e ) {
       e.printStackTrace();
    } 

    formatfile.format( "Exam 2 Solution \n");

    int n_lines = 0;
    try {
        String inline = infile.readLine();
        while ( inline != null) {
          n_lines++;
          int num = Integer.parseInt(inline); 
          sum += num;
          if ( num > max ) {
                max = num;
          } 
          if ( num < min ) {
               min = num;
          } 
          inline = infile.readLine();
       } 
    } 
    catch ( Exception e ) {
       e.printStackTrace();
    } 
    mean =  sum/n_lines;
   
    //  display output 
    String format_str = "%-8s%4d";
    formatfile.format(format_str, "Count:",n_lines);
    formatfile.format("%-8s%4.2f", " Mean: ",mean);
    formatfile.format(format_str, " Max: ",max);
    formatfile.format(format_str, " Min: ",min);
    formatfile.format("\n");
    formatfile.flush ();
    formatfile.close ();
   }
} // end class Compute
