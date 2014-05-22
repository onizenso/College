#!/usr/bin/env python

# demonstrate coroutines in Python 2.5 

"""
lab08: modify the simple scheduler for walking dogs
"""

def printdog(name):                            
   print "%s" %name 

"""
 partner is a coroutine for initiator 
 'yield stuff' passes control back to main with a message in variable stuff 
 when control resumes, a message (it may be empty) is available from the caller
 as the return value from yield
"""

def partner(dogs):
    i = 0

    while len(dogs):

       i = (i + 1) % len(dogs)

       getRequest = yield dogs[i] # yield control back to initiator w/ dog name
                                  # on return get a request or not

       if getRequest:
            request, name = getRequest
            if request == "add":
                print "add: ", name
                dogs.append(name)
                print dogs 
 
            elif request == "remove" and name in dogs:
                print "remove: ", name
                dogs.remove(name)
                print dogs 

            elif request == "walk" and name in dogs:
                print "walk and remove: ", name
                dogs.remove(name)
                print dogs 

            elif request == "walktwo":
                n1,n2 = name   
                print "walk and remove: ", n1, n2 
                dogs.remove(n1)
                dogs.remove(n2)
                print dogs 
   

"""
  the initiator is a coroutine with the partner
 'next' resumes control in the schedule with no message passing
 'send' resumes control in the schedule with a message as the parameter 
"""
def initiator():

   dogs = ["spot", "rusty", "bud", "fluffy", "lassie"] 
   doglist = list(dogs)                  # create a list object

   p = partner(doglist)                  # start the partner  

   print "original list: "
   for i in range(len(doglist)):         # pass control to partner w/o msg
      printdog(p.next())                

   print ("======== Welcome to the Dog House =============")

   p.send(("add", "fifi"))     
   p.send(("remove","fluffy"))       
   p.send(("walk","fifi")) 
   p.send(("add", "fido"))     
   p.send(("walktwo",("fido","rusty"))) 

# all 'main' does is start the initiator 

initiator()

