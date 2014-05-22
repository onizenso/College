#!/usr/bin/env python

"""
CS 350 FINAL EXAM  PYTHON                                         / 50 

Refer to 

    /home/fac/donna/public_html/cs350/Solutions/lab08/lab08.py

    /home/fac/donna/cs350/Code/Python/test.py 

Email your script to me when complete. Each problem worth 10 pts.

Sample output:
original list:  [11, 0, 15, 20, 25, 30, 21, -5]
Multiples of 3:    [0, 5, 10, 7]
Positive Odds:    [11, 15, 25, 21]
Ident for f(x) = 1*x:  True

#1. Take 'py.in' as an argument from the command line, open py.in and read 
    each line into a list; i.e.,

         ./final.py py.in 

    py.in is structured like this:

      10
      15
      20
      0
      21
      -3

    If the user fails to enter a filename, abort with a usage statement.

#2. Write a function 'final' that takes three arguments: the list read in from 
    py.in, a boolean function B and a function F. B takes an integer and 
    returns a boolean. F takes an integer and returns an integer. Your function 
    'final' will apply B to each element of the list. If B returns true, you 
    apply F to the element and add the result to an output list. The return 
    value of 'final' is the output list.

#3. Write a call to 'final' that will, for each element that is divisable by 3, 
    compute the number of times 3 divides that element and add that result to
    the output list. Display the output list. 

#4. Write a call to 'final' that will print each positive odd element as it is
    encountered in the list. Display the output list. 
 

#5. Write a function 'ident' that takes as an argument a function f and a value
    x. Function ident returns true if f is an identity function, otherwise 
    false. Recall that f: M->M is an identity function if for all x in M, 
    f(x) = x. Test ident with f(x) = 1*x.
              
"""

from sys import argv
