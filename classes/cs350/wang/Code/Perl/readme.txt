

o  Perl scripts can be named anything; if an extension is used it will often
   be .pl

o  Perl scripts must be given execute permission to run the script without
   passing it to the perl executable. The default file permission
   is 644. Change permissions with the chmod command:

   chmod 744 test.pl    <= gives yourself execute permission
   chmod 755 test.pl    <= gives everyone execute permission

o to check syntax

   $perl -c <filename>
 
o to execute the script by just typing the script name, put this on the first 
  line of script (shebang followed by the full pathname to perl on your
  system):

   #!/usr/bin/perl

o otherwise you must call perl directly: 

  $perl <filename>

o the convention is to put a usage statement in the script in EBNF form:

  Usage:  lab06.pl [-h] [-f <filename>]

o for Perl documention see:
  http://perldoc.perl.org

o to debug your code:
    $ perl -d myfile.pl
