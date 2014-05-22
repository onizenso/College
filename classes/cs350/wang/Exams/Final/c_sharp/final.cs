/* CMPS 350 Final Exam  - C# 

Everything you need is in /Code/C_sharp/ or /Solutions/lab09. In particular,
look in sample2.cs for new material on generating a random number. Start with 
your solution to lab09 or my solution to lab09: 

    /home/fac/donna/public_html/cs350/Solutions/lab09/solution.cs

All code can be part of the same namespace.

Your job is to add a color value to shapes and write a method in Main that will 
assign it a random color to a shape object. 

Sample output (eliminate all code in Main except this):
I'm a brown rectangle!  I have width 8.75 and height 20.5
I'm a yellow triangle!  I have base 5.5 and height 12.25
I'm a blue Circle!      I have radius 3.5

Details (5 pts each):                                                   /50
#1. Add a private data member m_Color of type string and default value 
    "white" to each derived shape class
#2. Add a Color property to IShape with set and get methods for m_Color
#3. Implement the Color property in each derived class  
#4. Create an array of strings in Main and initialize it with 5 colors: 
    purple, green, blue, yellow, red 
#5. Create an object of type Random in Main  (see sample2.cs)
#6. Create a static method 'setColors' in class Application with no return 
    value and three parameters: an array of strings as IN, a Random object 
    as IN, and a shape object as IN OUT
#7. In setColors generate a random integer from the Random object to act as an 
    index into your color array
#8. In setColors set the shape's color with the Color property  
#9. pass your 3 objects to Application.randomColor() to set a random color
#10.Modify the Display method in each class to display the m_Color 

*/
using System;
namespace Final
{
  public class Application  
  {
     static void Main()
     {
       Random random = new Random();
       string [] my_colors = {"purple", "green", "blue", "yellow", "red"}; 

       double rectWidth = 8.75f, rectHeight = 20.5f;
       IShape shape1 = new Rectangle(rectWidth, rectHeight);

       double triBase = 5.5f, triHeight = 12.25f;
       IShape shape2 = new Triangle(triBase, triHeight);

       double cirRadius = 3.5;
       IShape shape3 = new Circle(cirRadius);
 
       Application.randomColor ( my_colors, random, ref shape1 );
       Application.randomColor ( my_colors, random, ref shape2 );
       Application.randomColor ( my_colors, random, ref shape3 );

       shape1.Display();
       shape2.Display();
       shape3.Display();
    } 

    static void randomColor ( string [] colors, Random r, ref IShape s )
    { 
         int i = Convert.ToInt32(r.NextDouble()*100);  
         i = i % 5;  
         s.Color = colors[i]; 
    } 
  }  // end application

  public interface IShape
  {
     void Display ();
    
     double Area   
     {
       get;  
     }
     string Color
     {   
        get;
        set;
     }  
   } 

  ////////////////////////////////////////////////////////////////////////
  public class Rectangle: IShape
  {
     public Rectangle(double inWidth, double inHeight)
     {
       m_Width = inWidth;
       m_Height = inHeight;
     }
   
     public string Color
     {
        set
        {
           m_Color = value;
        }
        get
        {
           return m_Color;
        }
     } 

     public double Area
     {
       get
       {
         return m_Width * m_Height;
       }
     }

     public void Display() {
         Console.WriteLine(
        "I'm a {2} rectangle!\tI have width {0} and height {1}", 
         m_Width, m_Height, m_Color);
     }

     private double m_Width = 0;
     private double m_Height = 0;
     private string m_Color = "white";
  }
  ////////////////////////////////////////////////////////////////////////
  public class Triangle: IShape
  {
    public Triangle(double inBase, double inHeight)
    {
       m_Base = inBase;
       m_Height = inHeight;
    }
     public string Color
     {
        get
        {
           return m_Color;
        }
        set
        {
           m_Color = value;
        }
     } 

    public double Area
    {
      get
      {
        double area = 0.5f * m_Base * m_Height;
        return area;
      }
    }

    public void Display() {
        Console.WriteLine(
          "I'm a {2} triangle!\tI have base {0} and height {1}", 
           m_Base, m_Height, m_Color);
    }

    private double m_Base = 0;
    private double m_Height = 0;
    private string m_Color = "white";
  }

  ////////////////////////////////////////////////////////////////////////
  public class Circle: IShape
  {
    public Circle(double inRadius)
    {
       m_Radius = inRadius;
    }

    public double Radius 
    {
      get
      {
        return m_Radius;
      }
      set
      {
        m_Radius = value;
      }
    }

     public string Color
     {
        set
        {
           m_Color = value;
        }
        get
        {
           return m_Color;
        }
     } 
    public double Area 
    {
      get
      {
        double area = 3.14 * ( m_Radius * m_Radius);
        return area;
      }
    }

    public void Display() {
        Console.WriteLine("I'm a {1} Circle!\tI have radius {0}", 
           m_Radius, m_Color);
    }

    private double m_Radius = 0;
    private string m_Color = "white";
  }  // end Circle


} // end namespace 
