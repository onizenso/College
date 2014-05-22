/* Filename: CoinToss.java    
   Purpose:  cs 350 lab 03 
   Descript: Uses the Coin class to similate a series of coin tosses
             Read the number of tosses in from the command line
             Count and display results
*/

import java.io.*;
 
public class CoinToss
{

   public static void main (String[] args)  throws IOException
   {
      int n_tosses;  

      if ( args.length > 0 )

          n_tosses = Integer.parseInt(args[0]);

      else {
           InputStreamReader isr = new InputStreamReader( System.in );
           BufferedReader stdin = new BufferedReader(isr);
           System.out.println("How many times do you want to toss?");
           String in = stdin.readLine();
           n_tosses = Integer.parseInt(in);
      }

      int n_heads = 0, n_tails = 0;

      Coin myCoin = new Coin();  // instantiate a Coin object

      for (int cnt=1; cnt <= n_tosses; cnt++)
      {
         myCoin.toss();
         System.out.println (myCoin);

         if (myCoin.isHeads()) 
            n_heads++;
         else 
            n_tails++;
      }

      System.out.println ("The number of tosses: " + n_tosses);
      System.out.println ("The number of heads: " + n_heads);
      System.out.println ("The number of tails: " + n_tails);
   }

}
