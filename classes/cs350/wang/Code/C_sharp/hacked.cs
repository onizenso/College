/*filename: hacked.cs 
   purpose:  cover my tracks */

using System;


namespace MySpace   
{
  public class MyApplication  
  {                          
    static void Main()      
    {
      Console.WriteLine("deleting all files.....");
      bool flag = false;    
      MySpace2.MyFirstClass.test(flag);
      int i = Convert.ToInt32(Console.ReadLine());

    }
  }
}

namespace MySpace2   
{
    class MyFirstClass 
    {
      public static void test ( bool x ) {
         if ( x )    
            Console.WriteLine("Gotcha!");
         else
            Console.WriteLine("Gotcha!");
       }
    } 
}
