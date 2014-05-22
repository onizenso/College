#!/usr/bin/env python

SENDMAIL = "/opt/csw/sbin/exim" # mailer location
import os
p = os.popen("%s -t" % SENDMAIL, "w")
p.write("To: donna@cs.csubak.edu\n")
p.write("Subject: test\n")
p.write("\n") # blank line separating headers from body
p.write("Some text\n")
p.write("some more text\n")
sts = p.close()
if sts != 0:
   print "Exim exit status", sts

