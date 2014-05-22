#!/usr/bin/env python

# final exam wtr 2011  - coroutines

"""
For help refer to the solution to the coroutines problem in lab09.

   /home/fac/donna/public_html/cs350/Solutions/lab09/coroutines.py 

Your task is to compute the cartesian product of two sets A and B. Recall
that A x B, for A = {1,2,3} and B = {4,5,6} is the set S of all possible
2-tuples from A and B: 
    S = {(1,4), (1,5), (1,6), (2,4), (2,5), (2,6), (3,4), (3,5), (3,6) }

Start with the function below, which correctly displays S. Your job is to
convert this function into coroutines. I don't care how you do this. One
suggestion is to define A and B in the initiator, pass A and B to the partner
and let the job of the partner be to create the next 2-tuple for S.

You won't need message passing. Each time you pass control to the parter, 
the partner will yield back one 2-tuple in S. Construct and display S in the 
initiator.
"""

def getX( ):
    A = (1,2,3)
    B = (4,5,6)
    Xprod = []
    for e1 in (A):
       for e2 in (B):
          tup = e1,e2
          Xprod.append(tup)
    print Xprod

getX()       

def partner(A, B):
    myList = []
    for e1 in (A):
       for e2 in (B):
          tup = e1,e2
          getRequest = yield tup 
                                
def initiator():
   A = (1,2,3)
   B = (4,5,6)
   size = len(A) * len(B)
   p = partner(A, B)
   Xprod = []
   for i in range(size):
      Xprod.append(p.next())        
   print Xprod

initiator()
