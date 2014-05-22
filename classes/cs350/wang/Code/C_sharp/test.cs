/* filename: test.css
   purpose:  demonstrate essential components of a C# program   

  Compile into MSIL(Microsoft Intermediate Language) code and then execute:
     $ mcs filename
     $ mono filename.exe     
  Like Java, MSIL code can be ported to any platform; e.g., from cmd prompt in 
  any Windows OS with .Net framework just type executable name.          */


using System;                 // using replaces #include directives


// everything in C# must exist inside namespaces
namespace MySpace   
{
  public class MyApplication  // everything must also exist inside a class 
  {                           // can be public or not it doesn't matter
    static void Main()        // Main is always the first method called  
    {
      Console.WriteLine("hello world");
      bool flag = false;     // everything must be initialized before use
      MySpace2.MyFirstClass.test(flag);
    }
  }
}

namespace MySpace2    // create another namespace in the same compilation unit
{
    class MyFirstClass 
    {
      public static void test ( bool x ) {
         if ( x )       // conditions must evaluate to type bool 
            Console.WriteLine("hello world from MySpace2");
         else
            Console.WriteLine("hello world from MySpace2");

         // demonstrate switch statement
         int k = 1;   
         switch (k)
         { 
         case 1:
            Console.WriteLine("made it to case 1");
             break;    // the break is required - no fall through allowed
         case 2:
            Console.WriteLine("made it to case 2");
            break;
         default:
            Console.WriteLine("made it to default case");
            
        } 
       }
    } 
}
