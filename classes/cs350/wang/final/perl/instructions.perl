Everything you need is in:

  /usr/users/donna/public_html/cs350/Code/Perl/regex.pl
  /usr/users/donna/public_html/cs350/Solutions/lab05/lab05.pl

Your job is to read the input file perl.in, clean it up, calculate some
averages, apply some regular expressions and write results to an output file.  
Sample output (the averages shown are not the actual results):
 
ID  Name                   Average Score
729 Paul Bezumwat          80% 
619 Brawn Millersford      74% 
509 Valerie Sandrini       95% 
491 Tess Clifford          73% 
922 Samantha Boots         82% 
Class Average:  82.8%

5 pts each
#1. Parse the command line arguments for required -f filename. If missing 
    abort with this error: Usage: final.pl -f <filename> 
#2. Open the input file perl.in and output file perl.out
#3. Remove the comma and middle initial from each line
#4. Parse each line into 5 fields
#5. Compute the average exam score for each student
#6. Compute the overall class average exam score
#7. Write a header to the output file as shown above
#8. Write each line that has a 9 somewhere in the ID to the output file in 
    the format shown above.
#9. Write the class average to the output file as shown above
#10.Close files 
  
