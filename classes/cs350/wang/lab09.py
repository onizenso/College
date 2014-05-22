#!/usr/bin/env python

"""
CS 350 Lab 9:

Execute with:

     ./lab08.py <datafile> 

Assume <datafile> is structured like this:

      10
      15
      20
      0
      17

Add a function 'my_mean' to this program that will take as arguments the 
list read in from the above file and a boolean function B. My_mean will return 
the mean for the values that meet the constraints of the function. E.g.:

           my_mean (lambda x: x > 0, list)

will return the mean for the nonzero numbers in the list. In my_mean you must 
apply the boolean function B to each number in the list; count and sum 
the number of values for which B returns true; and finally return the mean.
(Don't forget to initialize sum and count as real numbers.) My_mean is similar 
in concept to the function my_map provided below.

Add a function 'my_filter' to this program that will take as arguments the 
list read in from the above file and a boolean function. My_filter will return 
the filtered list of values that meet the constraints of the function. E.g.:

           my_filter (lambda x: (x % 2) == 0, list)

will return a list that contains only even numbers.  
"""

from sys import argv

"""  
my_map takes a function and a list, and returns the result of the
function applied to the every element in the list.

For example

    my_map(lambda x: x + 1, [1, 2, 3]) 

returns [2, 3, 4]

"""

def my_map(func, list):
  new_list = []
  for item in list:
    new_list.append(func(item))
  return new_list

if len(argv) < 2:
  print "Usage: %s <filename>" % argv[0]
else:
  input = file(argv[1])
  values = []
  for line in input:
     values.append(int(line))

  print values 
  squared = my_map(lambda x: x * x, values)
  print squared
  successor = my_map(lambda x: x + 1, values)
  print successor
 
