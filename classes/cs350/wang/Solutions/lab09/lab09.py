#!/usr/bin/env python

"""
CS 350 Lab 9: SOLUTION

Execute with:

     ./lab09.py <datafile> 

Assume <datafile> is structured like this:

      10
      15
      20
      0
      17

#1.
Add a function 'my_mean' to this program that will take two arguments: 1) the 
list read in from the above file and 2) a boolean function. My_mean will return 
the mean for the values that meet the constraints of the function. E.g.:

           my_mean (lambda x: x > 0, list)

My_mean will return the mean for the nonzero numbers in the list. This occurs
by applying the boolean function B to each number in the list. Count and sum 
the number of values for which B returns true. Return the mean, which is 
sum/count. (Don't forget to initialize sum and count as real numbers.) My_mean 
is similar in concept to the function my_map provided below.

#2.
Add a function 'my_filter' to this program that will take as arguments the 
list read in from the above file and a boolean function. My_filter will return 
the filtered list of values that meet the constraints of the function. E.g.:

           my_filter (lambda x: (x % 2) == 0, list)

will return a list that contains only even numbers.  
"""

from sys import argv

# returns the result of applying  func to each element in list
def my_map(func, list):
  new_list = []
  for item in list:
    new_list.append(func(item))
  return new_list

print my_map(lambda x: x + 1, [1, 2, 3])  # returns [2, 3, 4]

def my_filter(func, list):
  new_list = []
  for item in list:
    if func(item):
      new_list.append(item)
  return new_list

def my_mean(func, list):
  count=0
  sum=0.0
  for item in list:
    if func(item):
      count = count + 1
      sum = sum+item
  return sum/count 


# main begins here
if len(argv) < 2:
  print "Usage: %s <filename>" % argv[0]
else:
  input = file(argv[1])
  values = []
  for line in input:
     values.append(int(line))

  filtered = my_filter(lambda x: (x % 2) != 0, values)
  mean = my_mean(lambda x: x > 0, values)
  squared = my_map(lambda x: x * x, values)
 
  print "original list: ", values 
  print "odds:   " , filtered 
  print "squared:" , squared
  print "mean:   " , mean 
