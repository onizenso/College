#!/usr/bin/env python

"""
Exam 2: SOLUTION                                                      /25

For syntax help see:

  cs350/Code/Python/test.py 
  cs350/Solutions/lab08/lab08.py

  Note: Leave existing code in - your job is to add the
  function definitions as specified - you CANNOT call existing functions in
  the python math library

"""

from sys import argv

"""
#1. Write a function exp_2 that takes as arguments an integer x, x >= 0 and
    returns 2^x. 
"""
def exp_2( x, func = lambda k: k >= 0):
    sum = 1
    if func(x):
	for i in range(x):
	    sum = sum * 2
	return sum
    else:
       return False




print exp_2(5)                # call the function
print exp_2(10)

"""
#2. Write a function log_2 that takes as arguments an integer x = 2^k, k >= 0,  
    and returns log base 2 of x. 
"""

def log_2(x, func = lambda k: k >= 0):
    count = x
    expon = 0
    for i in range(20):
	if exp_2(expon) == x and func(expon):
	    return expon
	count = count / 2
	expon = expon + 1
    return False




print log_2(32)               # call the function
print log_2(1024)
"""
#3. Write a function sq_rt that takes as arguments an integer x = k*k, k >= 1,  
    and returns the square root of x. 
"""
def sq_rt( x, func = lambda k: k >= 1 ):
    if func(x):
	for i in range(x/2):
	    if i*i == x:
		return i
    else:
	return False





print sq_rt(25)               # call the function
print sq_rt(256)
"""
#4. Write a function square that takes as arguments an integer x, x >= 1,  
    and returns x*x. 
"""
def square(x, func = lambda k: k >= 1):
    if func(x):
	return x*x
    else:
	return False



print square(5)                # call the function
print square(16)
"""
#5. Write a function inverse that takes as arguments two functions f and g and 
    an integer x, x >= 1. Function inverse returns true if f(g(x)) == x. 
"""
def inverse(func1, func2, x):
    if func1(func2(x)) == x:
	return True
    else:
	return False


print inverse(sq_rt, square, 5 )                # should return true
print inverse(lambda x: x*2, lambda x: x+2, 5)  # should return false


