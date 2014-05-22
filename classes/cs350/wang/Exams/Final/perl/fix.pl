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


#!/usr/bin/perl                                    

# Usage: fixIt <filename>

if (@ARGV eq 0) {
  print "\nUsage: fixIt <filename>\n";
  exit;
}

$str1 = '<input type="button" value="check" onClick="';
$str2 = 'x=document.getElementById(\'xHERE\'); ';
$str3 = '  if (document.quizform.QHERE[1].checked) {x.innerHTML=\'CORRECT\';}';
$str4 = '  else {x.innerHTML=\'Hint: .\'; } "> ';
$str5 = '<DIV id="xHERE" STYLE="background-color: white"> </DIV> ';
$str6 = "<pre>";

$filename = $ARGV[0];

open(INFILE, $filename);
$i = 0;

while(<INFILE>) {
   chomp;                        
   if ( $_ =~ /A<input/ ) {
      print "</pre>$_";
   }
   elsif ( $_ =~ /^$/ ) {
       $i = $i + 1;
       print $str1;
       $tmp = $str2;
       $tmp =~ s/HERE/$i/;
       print "$tmp";

       $tmp = $str3;
       $tmp =~ s/HERE/$i/;
       print "\n$tmp \n";

       print "$str4 \n";

       $tmp = $str5;
       $tmp =~ s/HERE/$i/;
       print "$tmp \n\n";

       print "$str6 \n";
   }
   else {
       print $_;
       print "\n";   
   }
}
close(INFILE);

