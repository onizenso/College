#!/usr/bin/env python

"""
filename: test.py
purpose:  demonstrate basic python data types and control structures 
see:      http://www.python.org/


Three quotes denote a multiline string, also known as a "docstring"
It may contain newlines and single or double quotes (three single quotes also
denotes a multiline string comment
"""

'strings are also comments' "and may start with either quote character"

# orange = yellow              illegal since yellow is undefined 

an_int = 1                     # an integer is an immutable scalar
an_int = 2                     # bind an_int to a new value
print an_int                   # python is case sensitive 

a_float = 1.5                  # a float is an immutable scalar 
print a_float
empty_tuple = ()               # a tuple is an unindexed immutable scalar 
example_tuple = (1, 2, 3)      # this tuple contains 3 elements 
single_value_tuple = (1,)      # use a trailing comma to distinguish a single
                               # value tuple from an expression

flag = True                    # a boolean is an immutable scalar     

ex_list = [1, 2, 3]            # a list is a mutable structure
ex_list = []                   # bind ex_list to an empty list
print "Type: ", type(ex_list)  # prints <type 'list'>

                               # a dictionary is a mutable object
example_dictionary = {         # a dictionary is an associative array  
  'a': 1,                      # assign some key-value pairs
  'b': 2 
}
example_dictionary['a'] == 2   # just modified it 


def keyword_function(y, x):
  print "Keyword arguments: ", y, x 

# example of a function call using keyword arguments
keyword_function(x="hello ", y="goodbye") 


# Use of asterisk for variable length parameter lists

"""
 In a function definition or function call, one asterisk (*) denotes a list of 
 additional positional parameters; two asterisks (**) denotes a dictionary of 
 additional keyword parameters. Examples:
"""

def variable_func(arg1, arg2, *leftovers):      # leftovers is a tuple
  print arg1, arg2, leftovers
variable_func('a', 'b', 1, 2, 3)                # prints 'a b (1, 2, 3)'


# Ex. function with a variable number of keyword arguments with **name syntax
# var_keyword_func(a=1, b=2) => prints '{'a': 1, 'b': 2}
# kwargs is a dictionary

def var_keyword_func(**kwargs):
  print kwargs

# Example of *args and **kwargs syntax to call functions
# Arguments to *arg syntax may be any sequence
variable_func( *['var1', 42])       # Prints 'var1 42 ()'

# Prints 'a 2 ()', because dictionaries are sequenced by their keys
variable_func(*example_dictionary)

# To use this, every key in the dictionary must be a string
# This line prints {'a': 1, 'b': 2, 'c': 3}
var_keyword_func(
  **{'a': 1, 'b': 2}
)

# The if statement and use of boolean operators
if 'a' == 'b' or 'a' != 'b':
  print 'Time paradox!'

# The elif statement is available to avoid too much nesting
elif 'a' == 'a' and 'a' == 'a':
  # Because Python blocks are delimited using whitespace, 'pass' must be used
  # for empty blocks
  pass

# else is optional, and is only here for completeness
else:
  print 'a != a!?'


# for loop
for char in 'example string':
  print 'char =',char

# while loop
x = 5
while x > 0:
  print x
  x = x - 1

# enumerate() can be used if the index of an item is needed
for index,value in enumerate('abcd'):
  print 'index =',index, 'value =',value

# Dictionaries are indexed by key
for key in {'a': 1, 'b': 2, 'c': 3}:
  print 'key =',key

# To access both items of a dictionary:
for key,value in {'a': 1, 'b': 2, 'c': 3}.items():
  print 'key =',key, 'value =',value

# Automatic unpacking of values
# This can also be used like:
#   pair = x, y
#   x, y = pair
#   x, y = 5, 10
#   x, y = (5, 10)
#   x, y = [5, 10]

for first, second in (('a', 1), ('b', 2), ('c', 3)):
  print 'first =',first, 'second =',second

# String formatting
# Generally using %s will just 'do the right thing', but you may want to look
# at http://docs.python.org/lib/typesseq-strings.html for special operations
# (such as forcing an unusual output style)

# Formatting a single value is easy:
print 'String formatting, 5 = %s' % 5

# Multiple values must be passed in a list or tuple
print 'More formatting, 5 = %s, 10 = %s' % (5, 10)

# Dictionary keys may be used, or re-used
print 'Dictionary formatting: %(first)s %(second)s %(first)s' % {
  'first': 1, 'second': 2
}

# Python uses dynamic duck typing but is also strongly typed
def fun1(argument):
  result = argument + 5        
  print result

fun1(5)              # this is OK 
# fun1('a')          # this is not OK - unlike JavaScript, python is strongly 
                     # typed and won't give you enough rope to hang yourself


"""
function sort will accept as parameters a list and a comparison function. sort 
will use the comparison function to decide in which order the list should be 
sorted
"""

def sort(list, compare_function):
  for first in range(len(list)):       # Simple selection sort
    minimum = first
    for index in range(0, len(list)):
      if compare_function(list[minimum], list[index]):
        minimum = index

    temp = list[first]
    list[first] = list[minimum]
    list[minimum] = temp

sort([4, 3, 2, 1], lambda a, b: a > b)    # example of use

"""
function map accepts as parameters a function and list. The items in the list 
may themselves be lists, or they might be single values.
"""


def mod(a, b):
  return a % b


def map(func, args):
  results = []
  for arg in args:
    if type(arg) in (list, tuple):
      results.append(func(arg))
    else:
      results.append(func(arg))

sums = map(sum, [[1, 1], [2, 2], [3, 3]])   # Sums will equal [2, 4, 6]

"""
you can pass a function to pass to another function 
"""


def run_if(condition, function1, function2, *args, **kwargs):
  if condition:
    function1(function2, *args, **kwargs)

myList = [[1, 1], [2, 2], [3, 3]]
out = run_if(lambda x: x > 5, map, sum, myList)
print out
  
"""
Showing how to replace a switch statement or if/else if list with a dictionary
"""
def switch_dict():
  """
  Equivilent of:

  std::string function_name = "first";
  if (function_name == "first") {
    function_1();
  }

  else if (function_name == "second") {
    function_2();
  }
  """
  def function_1():
    print 'Function 1'

  def function_2():
    print 'Function 2'

  functions = {
    'first': function_1,
    'second': function_2
  }

  function_name = 'first';
  functions[function_name]()

# Importing a library 
# This line imports the date module from the datetime package
from datetime import date
print date.today()              # Prints the current date

# Other ways to import modules and packages:
import datetime                  # Import the entire package
# print datetime.date.today()
# Import only datetime.date
# Note that due to no from statement, the name is not modified
# print datetime.date.today()
import datetime

# Imports may be renamed
from datetime import date as my_date


# Exception handling - Unlike C++, only subclasses of Exception may be raised
# there are no user-defined exception classes
try:
  raise Exception('Example exception')
except:
  print 'Caught an exception'
try:
  raise Exception('Example exception')
except Exception, e:
  print 'Caught an exception of type Exception:',e
else:
  print 'This code will be called if no exception was thrown'
