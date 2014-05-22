#!/usr/bin/env python

# demonstrate coroutines in Python

# coroutines require python 2.5 

"""
this simple example is a scheduler for walking dogs
the scheduler subroutine and main() act as coroutines 
yield hands off control, next() and send() resumes control 
"""

def printdog(name):                             # auxilliary print function
   print "It's %s's turn to go for a walk." % name 

"""
this is the scheduler coroutine 
'yield stuff' passes control back to main with a message in variable stuff 
when control resumes, a message (it may be empty) is available from the caller
as the return value from yield
"""
def scheduler(dogs):
    doglist = list(dogs)                       # create a list object of dogs
    current = 0
    while len(doglist):
        # yield passes control back to caller with a dog name
        getRequest = yield doglist[current]    # on resume, get a request 
        current = (current + 1) % len(doglist) # circular traversal of the list
        if getRequest:
            request, name = getRequest
            if request == "add":
                doglist.append(name)
            elif request == "remove" and name in doglist:
                doglist.remove(name)

"""
the code below acts as a coroutine with the scheduler
next resumes control in the schedule with no message passing
send resumes control in the schedule with a message as the parameter 
"""
if __name__ == "__main__":                     # initialize once from main only
   dogs = ["spot", "rusty", "bud", "fluffy", "lassie"] 
   s = scheduler(dogs)                  # start the scheduler s 
   for i in range(5): 
      printdog(s.next())                # next resumes control in s w/ no msg 
   printdog(s.send(("add", "fifi")))    # send resumes control and passes msg
   for i in range(6): 
      printdog(s.next())                 # resume control in s 

   printdog(s.send(("remove","fluffy")))  # send remove request to s 

   for i in range(6): 
      printdog(s.next())
