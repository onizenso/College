# prints out a summary of info from the data file 
# the only parameter is the data filename
# the fields necessary are  Location (field 9) Description (field 10) 

#!/usr/bin/bash
if test $# -eq 0
 then echo "usage: program filename"
 exit
fi

awk '
BEGIN {
   FS = ":";
   restart = 1;
   printf ("\t    Name\t  Occupation\t      Income\n")
}
{
if (restart == 1){
	curlocation = $5;
	restart = 0;
	count = 1;
	}
else

if ($5 == curtype)  {
        count = count + 1;
        }
else

if ($5 != curtype)  
       {printf ("%20s%20s\t%d\n",$1,$2,$3);
        count = 1;
	curlocation = $5;
        }
}
' $1
