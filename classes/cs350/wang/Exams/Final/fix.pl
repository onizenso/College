#!/usr/bin/perl
#
$filename = "f.txt";
chomp($filename);
open(IN, $filename);
$outfile = "f.out";
open(OUT, ">".$outfile);
$cnt = 1;

while(<IN>){
   $line = $_;
   chomp($line);
   if ($line =~ s/^__/$cnt/) {
      $cnt++;
   }
   printf (OUT "$line\n");
}
# close files
close(OUT);
close(IN);
