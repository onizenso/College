#!/usr/bin/env python

# demonstrate generators in Python

# generators worked in python prior to 2.5 

"""
first look at a simple generator
generators are limited coroutines 
you can yield and resume control - but you cannot pass parameters 
"""
def generator():
  for ii in range (10):     # range(10) generates 10 indexes from 0 - 9
    yield ii

def test1():
   print "this is a generator: "
   for j in generator():    # generators can return values only
     print j

test1()
