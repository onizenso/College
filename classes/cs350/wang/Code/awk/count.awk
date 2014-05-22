# an awk script that sums the third field in awk.dat 
awk  '
BEGIN{
      FS=":";
      sum = 0;
      sumb = 0;
      printf ("\n\n")
}

{
  if (sum == 0 ) {
     printf ("A SILLY LITTLE AWK SCRIPT\n");
     printf ("\tIncome\n");
  }
  else 

  if ( sum != 0 )
  {
     printf ("\t%d\n", $3)
   }

   if ( $5 == "Bakersfield" )
     sumb = sumb + 1;

   sum += $3 
  
}

END  { 
print "\t======";
print "Total:  ", sum, "\nAverage:", sum/NR; 
printf ("\n%d People Live in Bakersfield\n", sumb);
}

' $1
