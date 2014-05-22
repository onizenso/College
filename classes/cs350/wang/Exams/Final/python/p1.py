#!/usr/bin/env python

"""
CS 350 FINAL EXAM  - python part I                                 / 25 

Refer to 

    /home/fac/donna/public_html/cs350/Solutions/lab09/lab09.py
    /home/fac/donna/cs350/Code/Python/test.py 

Email your script to me when complete. 

#1.
5 pts. Read the filename ('data') as a command line argument :

         ./p1.py data    

   The file 'data' is structured like this (the values may vary when I run it):

      10
      15
      20
      0
      21
      -3

    If the user fails to enter a filename, abort with a usage statement.
    Open 'data' and read each line into a list.

#2.
5 pts. Define a function foo that returns a list and takes 3 arguments: 
    a list, a boolean function (takes an int returns a bool), and an integer 
    function (takes an int and returns an int). The specifications for the
    two functions are given below. 

    Function foo will apply the boolean function to each item of the list. 
    If true, foo will apply the integer function to the current int and then
    append the result to the list that foo returns.

#3.
5 pts. Call foo. Pass the list you read in from the file. In this call the
    boolean function tests whether the current integer n has a factor of 3. 
    The int function returns n/3, where n is the current integer and / is 
    integer division. You can either define the functions or use lambda.

    Upon completion display the output list.

#4.
5 pts. Call foo again. In this call the boolean function tests whether the
    current item is a positive odd integer. If so, apply the integer function.
    The integer function takes the current integer, multiplies it by 2 and
    appends it to the output list. You can either define the functions or use
    lambda.
    
    Display the output list. 

#5.
5 pts. Write a function 'ident' that takes as an argument a function f and a 
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

def display (x):
   print x
   return x

def odd_pos( x ):
  return (( x % 2 != 0) and (x > 0))
 
def final(bool, func, list):
  new_list = []
  for item in list:
    if (bool(item)):
        new_list.append(func(item))
  return new_list

def ident(func, x):
  return func(x) == x

if len(argv) < 2:
  print "Usage: %s <filename>" % argv[0]
else:
  input = file(argv[1])
  values = []
  for line in input:
    values.append(int(line))

  print "original list: ", values 
  mult3 = final(lambda x: (x % 3) == 0, lambda x: x / 3, values)
  print "Multiples of 3:   " , mult3 
  odds = final(lambda x: (x % 2) != 0 and (x >= 0), lambda x: x*2, values)
  print "Positive Odds:   " , odds 

  print "Ident for f(x) = 1*x: ", ident(lambda x: x*1,5) 
