#!/usr/bin/env python

# More examples demonstrating how Python handles functions          
# See test.py for background on data types, and basic structures, etc.

############################################################
#          demonstrate basic parameter passing             #
############################################################

# Python is "call-by-object reference"; actual parameters cannot
# be modified in caller unless they are mutable objects

# the assignment statement demonstrates that Python is similar to 
# Java/C for mutable objects 

def one(mylist):   
    mylist.append(3)          # modifies list in caller
    print "append 3: ", mylist
    mylist = [99]             # reassigning the local pointer to another object
                              # mylist in caller still points to [1,2,3]
    print "mylist: ", mylist
    x = 1
    print x
    two(x)                    # actual parameter x  
    print x    

def two(y):                   # formal/dummy parameter y
    print y
    y = 2
    print y

alist = [1, 2]                # a list is mutable (modifiable)
one(alist)             

# prints 1 1 2 1 
print "what is list now? ", alist 


#################################################################
#       demonstrate use of keyword binding to arguments         #
#################################################################

def keyword_args(arg1, arg2):
  print "Keyword arguments: ", arg1, arg2

# example of a function call using keyword arguments
keyword_args(arg2='b', arg1='a') # prints 'a b'


#################################################################
#           demonstrate use of default arguments                #
#################################################################

def default_args(arg1='a', arg2='b'):
  print "default arguments: ", arg1, arg2


default_args()                # prints 'a b'
default_args('b','c')         # prints 'b c'
stuff = [ 5, 10 ]
default_args(*stuff)          # unpack stuff and pass as parameters  

###################################################################
#          demonstrate variable length parameter lists            #
###################################################################
""" 
In a function definition or function call, one asterisk ('*') followed
by a name denotes a list of additional positional parameters; two asterisks 
('**') followed by a name denote a dictionary (associative array) of 
additional keyword parameters. This is *name or **name syntax. 
"""

# the variable part 'leftovers' is a tuple
def variable_func(arg1, arg2, *leftovers):   # *name syntax
  print arg1, arg2, leftovers

variable_func('a', 'b', 1, 2, 3)             # prints 'a b (1, 2, 3)'

# kwargs is a dictionary (associated array)
def var_keyword_func(**kwargs):              # **name syntax
  print kwargs

var_keyword_func()                           # prints {} 
var_keyword_func(a=1, b=2)                   # prints '{'a': 1, 'b': 2}



#####################################################################
#         Demonstrate use of functions as parameters                #
#####################################################################

"""
Create a function sort(), which will accept as parameters a list and a
comparison function. sort() will use the comparison function to decide in
which order the list should be sorted


Code blocks are defined by : and consistent indentation is MANDATORY

"""

def sort(list, compare_function):            # a simple selection sort
  for first in range(len(list)):
    minimum = first
    for index in range(first,len(list)):
      if compare_function(list[minimum], list[index]):
          minimum = index

    temp = list[first]
    list[first] = list[minimum]
    list[minimum] = temp


alist = [4, 3, 2, 1]
sort(alist, lambda a, b: a > b)    
print alist                         # prints  [1, 2, 3, 4]

"""
Create a function map(), which accepts as parameters a function, an input list 
and a results list. The items in the list may themselves be lists, or they 
might be single values.
"""


def sum(a, b):
  print "Sum: ", a, b
  return a + b

def map(func, args, results):
  for arg in args:                    # iterates through args
    if type(arg) in (list, tuple):    # true if arg is a list or a tuple
      results.append(func(*arg))      # '*' unpacks the argument list 
    else:
      results.append(func(arg))


results = []
map(sum, [ [1, 3], [2, 4], [3, 5]], results)    
print results                                 # prints [4, 6, 8]


#####################################################################
#         Demonstrate use of everything shown above                 #
#####################################################################

"""
this function takes an optional number of argument from a keyword argument
list and passes a default function as one of the arguments to check for
valid parameters
"""

# this function takes an integer x, x >= 0 and returns x ^ x.
def my_exp( x, func = lambda k: k >= 0):
    sum = 1
    if func(x):
       for i in range(x):
          sum = sum * x 
       return sum
    else:
       return False

print my_exp(3)                # should return  3*3*3 = 27

