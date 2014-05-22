#!/usr/bin/env python

"""
CS 350 FINAL EXAM  - PROBLEM 1                                        30 / 50 

Refer to 

    /home/fac/donna/public_html/cs350/Solutions/lab09/lab09.py
    /home/fac/donna/cs350/Code/Python/test.py 

Email your script to me when complete. 

#1. 6 pts. Read the filename ('data') as a command line argument :

         ./p1.py data    

   The file 'data' is structured like this:

      10
      15
      20
      0
      21
      -3

    If the user fails to enter a filename, abort with a usage statement.
    Open 'data' and read each line into a list.

#2. 6 pts. Define a function map that returns a list and takes 3 arguments: 
    a list, a boolean function (takes int returns bool), and an integer 
    function (takes int and returns int). The specifications for the
    two functions are given below. 

    Function map will apply the boolean function to each item of the list. 
    If true, map will apply the integer function to the current int and then
    append the result to the list that map returns.

#3. 6 pts. Call map. Pass the list you read in from the file. In this call the
    boolean function tests whether the current integer n is divisable by 3. 
    The int function returns n/3, where n is the current integer and / is 
    integer division. You can either define the functions or use lambda.

    Upon completion display the output list.

#4. 6 pts. Call map again. In this call the boolean function tests whether the
    current item is a positive odd integer. If so, apply the integer function.
    The integer function takes the current integer, multiplies it by 2 and
    appends it to the output list. You can either define the functions or use
    lambda.
    
    Display the output list. 

#5. 6 pts. Write a function 'ident' that takes as an argument function f and  
    value x. Ident returns true if f is an identity function, otherwise 
    false. Recall that f: M->M is an identity function if for all x in M, 
    f(x) = x. Test ident with f(x) = 1*x.
              
Sample output:

original list:  [11, 0, 15, 20, 25, 30, 21, -5]
Multiples of 3:    [0, 5, 10, 7]
Positive Odds*2:   [22, 30, 50, 42]
Ident for f(x) = 1*x:  True

"""

from sys import argv
