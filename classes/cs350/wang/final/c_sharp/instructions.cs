/* C# final instructions 

Everything you need is in /Code/C_sharp/ or /Solutions/lab09. In particular,
look in sample2.cs for NEW material on generating a random number. Start with 
your solution to lab09 or my solution to lab09: 

   /home/fac/donna/public_html/cs350/Solutions/lab09/solution.cs

Add your code into the same namespace and in the same file.

Your job is to add a color value to shapes and write a method in Main that will 
assign a random color to a shape object. 

Example of output (eliminate all code in Main except this):
I'm a red rectangle!    I have width 8.75 and height 20.5
I'm a yellow triangle!  I have base 5.5 and height 12.25
I'm a blue Circle!      I have radius 3.5

Since output is random, if you execute again it should be different:
I'm a yellow rectangle!  I have width 8.75 and height 20.5
I'm a green triangle!    I have base 5.5 and height 12.25
I'm a purple Circle!     I have radius 3.5

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
#9. pass your 3 objects to Application.setColor() to set a random color
#10.Modify the Display method in each class to display m_Color as shown in
    the sample output above. 

*/
