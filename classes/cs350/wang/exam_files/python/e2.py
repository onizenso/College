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





print exp_2(5)                # call the function

"""
#2. Write a function log_2 that takes as arguments an integer x = 2^k, k >= 0,  
    and returns log base 2 of x. 
"""





print log_2(32)               # call the function

"""
#3. Write a function sq_rt that takes as arguments an integer x = k*k, k >= 1,  
    and returns the square root of x. 
"""






print sq_rt(25)               # call the function

"""
#4. Write a function square that takes as arguments an integer x, x >= 1,  
    and returns x*x. 
"""
 



print square(5)                # call the function

"""
#5. Write a function inverse that takes as arguments two functions f and g and 
    an integer x, x >= 1. Function inverse returns true if f(g(x)) == x. 
"""



print inverse(sq_rt, square, 5 )                # should return true
print inverse(lambda x: x*2, lambda x: x+2, 5)  # should return false


