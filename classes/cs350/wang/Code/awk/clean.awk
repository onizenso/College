#!/usr/bin/bash
# 
# This awk script converts a Snort-IDMEF plugin alert log into a single 
# IDMEF-Message by stripping off the xml headers and IDMEF-Message tags.

if test $# -eq 0
  then echo "usage: clean <filename>"
  exit
fi

awk '

# print the opening tag
BEGIN { print "<IDMEF-Message>" }

# print all lines but xml headers and IDMEF-Message tags
{ if ($0 !~ /(IDMEF-Message|\?xml)/) print $0 }

# print the closing tag 
END { print "</IDMEF-Message>" } 

' $1
