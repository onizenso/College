/* filename: sample6.cs 
   demonstrate parameter passing in C# 
        $ mcs [filename.cs]            // will produce intermediate code
        $ mono [filename.exe           // will execute intermediate code 
*/

using System;

namespace Functions 
{
  class Application
  {

    // demonstrate pass-by-result "out mode" and "in mode" parameter passing
    // pass by value 'in mode' is the default 
    // Foo (out 5, xin) is a compilation error - 5 is not a modifiable L-value
    // Foo (out xout, xin) would be a compilation error if xin has no value
    static void Foo ( out int xout, int xin)  
    {
       Console.WriteLine ("In function foo...");   

       // int a = xout;  <== compilation error if you try to read xout now 
       xout = 10;  // assignment must occur for method to complete normally
       Console.WriteLine ("set out parameter xout to 10: {0}",xout);   

       xin = xout; // can read xout now - changing y doesn't modify y in caller
       Console.WriteLine ("set in parameter xin to 10: {0}", xin);   
       Console.WriteLine ("Leaving function foo...\n");   
    }

    // demonstrate pass-by-reference "inout mode" parameter passing
    static void Foo2 (ref int xref)
    {     xref = 999;  }   // changes argument in caller

    static void Main()    
    {
      int xout, xin, xref;   
      xin = 5;
      Foo (out xout, xin);    
      Console.WriteLine ("out parameter xout is 10: {0} \n", xout);  
      Console.WriteLine ("in parameter xin is still 5: {0} \n", xin);  
  
      xref = 5; 
      Foo2 (ref xref);
      Console.WriteLine ("ref parameter xref is now 999: {0} \n", xref);   

    } // end Main 

 } // end Application 

} // end Namespace
