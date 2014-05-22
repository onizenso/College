/********************************************************************/
/*     Demonstrates parameter passing in Java                       */ 
/*     Uses: Dog.java                                               */
/*                                                                  */
/********************************************************************/

import java.io.*;    
import java.util.List;
import java.util.LinkedList;

public class Functions 
{

   public static void main (String[] args) throws IOException
   {
      Dog x; // you can do this, but x is not an object yet!
      x = new Dog("Xerox");
      Dog b = new Dog("Buster");
      x = b;  // java does not have a reference type - so x now points to b
      b.setName("bowwow");
      System.out.println ("x: " + x.getName() );    
      x.setName("fluffy");
      System.out.println ("b: " + b.getName() );    
 
      Dog c = new Dog("FiDo");  // all objects are allocated from the heap      
      foo(c);                                               // from foo:Fifi
      System.out.println ("mainDog:" + c.getName() );       // mainDog: FiDo
      foo2(c);                                              // foo2:    JoJo
      System.out.println ("mainDog:" + c.getName() );       // mainDog: JoJo
      foo3(c);                                              // foo3:    MoMo
      System.out.println ("mainDog:" + c.getName() );       // mainDog: JoJo
   }   // end main

   public static void foo(Dog d) {
      d = new Dog("Fifi");              // points local d to a new Dog object
      System.out.println ("foo:" + d.getName() );
   }
   public static void foo2(Dog d) {
      d.setName("JoJo");                // changes Dog name in caller
      System.out.println ("foo2:" + d.getName() );
   }
   public static void foo3(Dog d) {
   /* Java "pass-by-reference" behaves like C pointers NOT C++ references */
      Dog e = new Dog("MoMo");
      d = e;                          // points local d to a new Dog object  
      System.out.println ("foo3:" + d.getName() ); // prints 
    }
}
/* used in Functions.java  

public class Dog
{
   private String name;

   public Dog ( String s)
   { name = s; }

   public void setName (String s)
   { name = s; }
   public String getName ()
   { return name; }
}
*/
