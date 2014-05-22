#!/usr/bin/env python

import sys
print sys.argv[0] 

SENDMAIL = "/opt/csw/sbin/exim"             # mailer location
import os
str1 = "Subject: " + sys.argv[1] + "\n"
print str1
str2 = "Your name: " + sys.argv[2] + "\n"
print str2
""" 
p = os.popen("%s -t" % SENDMAIL, "w")
p.write("To: donna@helios.cs.csubak.edu\n")
p.write(str1)
p.write("\n") # blank line separating headers from body
p.write(str2\n")
p.write("some more text\n")
sts = p.close()
if sts != 0:
   print "Exim exit status", sts

""" 
