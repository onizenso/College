#!/usr/bin/perl

use strict;
use warnings;

# spell_check.pl:  spell check input file or a single word; open a dictionary
# file (one word per line) and read into a hash table; flor input file, read 
# file, look up each in the dictionary (one lower case word per line), and 
# output words not found (one word per line) 
#
# Usage:  spell_check.pl [-h] [-f <filename>] 
#

my $dictionary = 'dictionary';             # a very small dictionary file 
my $inf;                                   # input file handle
my $filename = '';
my $a_word;

# open dictionary file and read each word into a local hash table (a map)
open($inf, '<', $dictionary) or die "Can't read dictionary: $!";    
my $word;
my %wordMap;       
                       
# 'while' reads one line at a time into $_
while(<$inf>) {                     
  chomp;                           # remove [CR/LF] 
  next if /^$/;                    # bypass empty lines
  $word = $_;                      # assign $_ in array
  $word =~ s/\s//g;                # remove spaces
  $word =~ tr/A-Z/a-z/;            # convert to lowercase
  $wordMap{$word} = 1;             # default value is 1, add to hash 
}
close($inf);


# here we simmply look up a single word from the command line
# =~ associates string with regex match 
if (@ARGV eq 0) {                       # ARGV is command line arg array 
   print "Enter a word: ";              # prompt the user 
   $a_word = <stdin>;                   # read from stdin
   chomp($a_word);                      # remove trailing stuff
   $a_word =~ tr/A-Z/a-z/;              # translates upper char to lower char 
   if ( ! $wordMap{$a_word} ) { 
      print "misspelled word: ", $a_word, "\n";
   }
   else {
      print "\nword OK \n";
   }
   exit;
}

# if we made it here we need to process the command line args
while (@ARGV) {                         # parse command line arguments 
  if ($ARGV[0] eq '-f') {
    shift;                              # move array elements up 
    $filename = $ARGV[0];
    shift;
    next;                               # jump to start of while loop 
  }
  elsif ( $ARGV[0] eq '-h') {           # display usage 
     print "\nUsage: spell_check.pl [-h] [-f <filename>]\n\n";
     shift;
     if (!@ARGV) {
        exit;
     }
     else {
       next; }
  } 
  else {   
     shift;                             # unknown argument so skip it
     next;
  }
}


# now open the input file for spellchecking 
open($inf, '<', $filename) or die "Can't read input file: $!";    

my @words;
my $line;

while(<$inf>) 
{
   chomp;                        # remove CR LF from $_
   $line = $_;
   $line =~ s/ +/ /g;            # remove extra spaces
   @words = split /\s/,$line;    # split by whitespace - space,TAB,CR,LF
   foreach(@words) 
   {
      $word = $_;
      $word =~ tr/A-Z/a-z/;      # make lowercase
      if ( ! $wordMap{$word} )   # the word is not found in the dictionary
      { 
        print 'misspelled word: ', $_, "\n";
      }
   }
}     
close($inf);
