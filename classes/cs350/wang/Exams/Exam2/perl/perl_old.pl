#!/usr/bin/perl                                    

# filename: perl.pl                                                25 pts 
# CMPS 350 Exam 2 PERL
# See: spell_check.pl, test.pl and lab05.pl (solution) for sample code

# Usage: perl.pl [-h] -f <filename>

# Your job is to write a Perl script that parses the command line as shown
# above. If the arguments are not correct, exit with a usage statement.

# To process your words you will
# translate the characters in each word into all uppercase letters;
# write the array words in each line and all the lines in reverse order 
# to your output file. 


# Format of the input file is a comma delimited file:  

#          F3400,A Clockwork Orange,Anthony Burgess,$7.34
 
#  In your input loop - 
#  Parse each line into an array of four substrings.
#  Convert all lowercase letters to uppercase letters in the substrings and 
# display to screen:
            
#            F3400 A CLOCKWORK ORANGE ANTHONY BURGESS $7.34 

#  Finally, write each substring to the output file in reverse order:                    
#           $7.34 Anthony Burgess A Clockwork Orange F3400
#  Close files

#SOLUTION:

use strict;
use warnings;


if (@ARGV eq 0) {
  print "\nUsage: perl.pl [-h] -f <filename>\n\n";
  exit;
}

while (@ARGV) {
  if ($ARGV[0] eq '-f') {
    shift;
    if (@ARGV) {
       $filename = $ARGV[0];
       shift;
       next;
    }
    else {
       print "\nUsage: perl.pl [-h] -f <filename>\n\n";
    }
  }
  elsif
    ($ARGV[0] eq '-h') {
    shift;
    print "\nUsage: perl.pl [-h] -f <filename>\n\n";
    exit;
  }
  else {
    last;            
  }
}

open(INFILE, $filename);

# outfile for writing
$outfile = ">outfile";
open(OUT, $outfile);

while(<INFILE>) {
  chomp;                        
  $line = $_;                   
  @words = split/,/,$line;  
  $word = $words[0];
  foreach(@words) {
      $word = $_;
      $word =~ tr/[a-z]/[A-Z]/;
      print "$word ";   
   }
   print "\n";   
   print OUT "$words[3] ";   
   print OUT "$words[2] ";   
   print OUT "$words[1] ";   
   print OUT "$words[0]\n";   
   
   print "\n";   
}
close(INFILE);
close(OUTFILE);   
