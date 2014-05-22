#!/usr/bin/perl
#
# CMPS 350 FINAL EXAM PERL                                                /15
# Your job job is to read student scores and info from 'perl.in', compute the 
# grade for each student as a percentage, compute the average grade for
# the class, and write results to an output file 'perl.out'.
# ===============================================
# EMAIL SCRIPT TO ME WHEN COMPLETE
# ===============================================
# The format of the data file is, where fields are separated by space(s):
#
# 999 Anzim, Sandy           5  5  4  3  0  5  4  3  5  3 80 75
# 699 Millersford, Bradford  5  3  1  0  3  5  3  5  2  5 75 73 
#
# There are 10 lab scores (each worth 5) & two exam scores (each worth 100)
# 
# Labs are worth 50% of the final grade and each exam is worth 25%. 
# The formula for Sandy's final grade is: (the sum of her labs is 37)
#
# (.50*(37/50)) + (.25*(80/100)) + (.25*(75/100)) = .7575  = 76% (round up)
#
# Write results to the output file 'perl.out' in this format:
#
#999   Sandy          Anzim           75.8%
#899   Paul           Bezumwat        75.2%
#799   Ned            Cozetsome       86.8%
#699   Bradford       Millersford     69.0%
#599   Valerie        Sandrini        91.5%
#499   Tess           Clifford        68.8%
#399   Yeats          Boots           70.5%
#Class Average:  76.8%
# 
# Some hints:
# See solution to Exam 2 Perl problem.
# You can use split to read a line into individual variables (if you want).
# E.g., this will split $line into 3 fields using one space as the separator
# ($field1,$field2,$field3) = split ' ', $line; 
# Perl supports printf. See link of top of course webpage for printf manpage.
# To left-justify $name in a fixed field of 30 and $sum as a floating
# point number with 1 decimal place to output file specified by OUT:
#
#   printf( OUT "%-30%s %5.1f", $name, $sum);

#1. prompt the user for the input data filename
print "Input filename: ";
$filename = <stdin>;

#2. remove trailing spaces and line feed from the filename
chomp($filename);

#3. open input and output files
open(IN, $filename);
$outfile = "perl.out";
open(OUT, ">".$outfile);

$cnt = 0;
$gradesum = 0.0;

#4. read the data file line by line
while(<IN>){
   $labsum = 0;
   $grade = 0;
   $line = $_;
 
   #5. clean up the input line as necessary
   chomp($line);
   $line =~ s/,/ /;
   $line =~ s/  */ /;

   #6. read all fields, splitting the line by a single space
   ($id,$lname,$fname,$l1,$l2,$l3,$l4,$l5,$l6,$l7,$l8,$l9,$l10,$e1,$e2)
        = split ' ', $line;

   #7. print formatted student information to output file
   printf (OUT "%-6s%-15s%-15s",$id,$fname,$lname);

   #8. compute grade    (5 pts)
   $labsum = $l1 + $l2 + $l3 + $l4 + $l5 + $l6 + $l7 + $l8 + $l9 + $l10;
   $grade = (.50)*($labsum/50.0) + (.25)*($e1/100.0) + (.25)*($e2/100.0); 
   $grade = $grade * 100;

   #9. print formatted grade to output file
   printf (OUT "%5.1f%\n", $grade);
   $gradesum += $grade;
   $cnt++;
}
   #10. print formatted student grade average to output file
   printf (OUT "Class Average: %5.1f%",$gradesum/$cnt);

#11. close files
close(OUT);
close(IN);
