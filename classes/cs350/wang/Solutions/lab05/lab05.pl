#!/usr/bin/perl

use strict;                  # otherwise perl let's you get away with anything 
use warnings;
 
# filename: lab05.pl
# CS 350 lab05 solution 
# run with perl -d lab05.pl for debugging

# read a list of NYSE symbols from an external file 
# no error checking perfomed on input file 

# Usage:  lab05.pl [-h] -f <filename>

if (@ARGV eq 0) {              
  print "\nUsage: lab05.pl [-h] -f <filename>\n\n";
  exit;
}

# parse the command line arguments for -f <filename> or -h
my $filename;
while (@ARGV) {
   if ($ARGV[0] eq '-h')  {
     print "\nUsage: lab05.pl [-h] -f <filename>\n\n";
     exit;
   }
   elsif ($ARGV[0] eq '-f')  {
     shift;  # shift argv[1] to argv[0] and so on...
     if ( $ARGV[0] eq '' ) {
       $ARGV[0] = '-h'; 
     }
     else { 
        $filename = $ARGV[0];
        last;   # jump out of while loop 
     }
   }
   else {   
     next;   # jump to the top of the loop 
  }
}

 
# open data file and read it into the hash
if ( ! open(DATA, $filename) ) {
   print "Error opening input file\n";
   exit;
}

my %hash;                       # a hash table to hold the data from input file
my $line;                       # one line from the file 
my @words;                      # an array of parsed words from the line
 
while(<DATA>) {
  chomp;                        # this removes CR or LF from $_
  $line = $_;                   # $_ is default current line
  $line =~ s/ +/ /g;            # remove extra spaces
  @words = split /\s/,$line;    # split by spaces into an array of two words
  $hash{$words[0]} = $words[1]; # insert key = value
}
close(DATA);                     # close the data file

# display the data in the hash on the screen - mostly for debugging
my @keys = keys %hash;           # grab the keys
my @values = values %hash;       # grab the values 
print "@keys\n";                 # dump keys to screen 
print "@values\n";               # dump values to screen

# 'each' returns a two-element array of key/value pairs for each hash entry
my $key;
my $value;
while ( ($key,$value) = each %hash ) {  
      print "$key = $value\n";
}
print "ABT: $hash{ABT}\n";              # another way to display a value by key 

# prompt the user for a symbol, display value if found
my $symbol;
my $prompt = "Enter a NYSE symbol or q to quit: ";
print $prompt;

while (($symbol = <stdin>) ne "q\n") {
   chomp($symbol);                                # remove trailing stuff
   $symbol =~ tr/a-z/A-Z/;                        # convert to uppercase
   if ( $hash{$symbol} ) {                        # check hash for symbol
      print "$symbol is $hash{$symbol}\n$prompt"; # display a value by key 
   }
   else {
      print "NOT FOUND\n$prompt";
   }
}
