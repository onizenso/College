#!/usr/bin/perl                                    

# NAME:
# CMPS 350 Wtr 2011 Exam 2 PERL                                          / 25 
# filename: perl.pl                                                     

# input file: /home/fac/donna/public_html/cs350/exam_files/poem   

# See: spell_check.pl, test.pl and lab05.pl (solution) for sample code

# Usage: perl.pl -i <infile> -o <outfile>

# Your job is to write a Perl script that parses the command line as shown
# above. The arguments -i <infile> and -o <outfile> can appear in any order
# but you can assume a correct filename will follow the -i and -o. If something
# other than -i or -o or if the number of arguments is not correct, exit 
# with a usage statement. Otherwise, open the file and process as follows.

# The input file (poem) contains a portion of The Raven by Poe. However, to
# read the poem, you must start at the last word and read from right to left 
# up the file to the first word. In other words, the words and the lines are 
# in reverse order. Your job is to read the file and process the words so that 
# you can write the poem in correct order to the output file.

# Hint 1: use the predefined array functions split, join and reverse.
#     @words = split /\s/, $str;     # parses $str into array words
#     @words = reverse @words;       # reverses the array
#     $str = join " ", @words;       # rejoins the words array back into $str 

# Hint 2: You will need to read the entire file into an internal structure
# before you can reverss it. One method is to read each line of the file into 
# a line (a scalar), parse the line into an array of words, and then 
# store each array of words in an array of lines. Then close the input file.
# 
# Open the output file. Traverse your internal data structure in such a way 
# that you can write the words in reverse order to the output file.

#SOLUTION:

use strict;
use warnings;

my $ifname = "";
my $ofname = "";
my $usage = "\nUsage: perl.pl -i <input filename> -o <output filename>\n";

while (@ARGV) {
  if ( $ARGV[0] eq '-i') {
    shift;
    if (@ARGV) {
       $ifname = $ARGV[0];
       shift;
       next;
    }
    else {
       print "$usage";
    }
  }
  elsif ( $ARGV[0] eq '-o') {
    shift;
    if (@ARGV) {
       $ofname = $ARGV[0];
       shift;
       next;
    }
    else {
       print "$usage";
    }
    exit;
  }
  else {
    print "$usage";
    exit;            
  }
}

if ( !($ifname) || !($ofname)) {
    print "$usage";
    exit;            
}

my $inf;
my $outf;
open($inf, '<', $ifname) or die "Can't read input file: $!";
open($outf, '>', $ofname) or die "Can't open output file: $!";

my $line;
my @lines;
my @words;
my @revwords;
my $word;
my $lineno = 0;

while(<$inf>) {
  chomp;                        
  $line = $_;                   
  @words = split /\s/, $line;  
  @words = reverse @words; 
  $line = join " ", @words;
  $lines[$lineno++] = $line;  
}
  
@lines = reverse @lines;  

foreach(@lines)
{
  $line = $_;
  print $outf "$line\n";
}

close($inf);
close($outf);   
