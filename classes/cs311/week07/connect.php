<?php
  /* define() creates named constants which can be used throughout your scripts
   * without a '$' before the name */ 

  define("USERNAME", "root"); // change sspade to your username
  define("PASSWORD", "H4H4Y3WThoughT");  // do not modify password
  define("DATABASE", "nramsey"); // change sspade to your username
  define("HOST", "localhost");  // do not modify host

   // connect to the mysql server 
   $link = mysql_connect(HOST, USERNAME, PASSWORD);
   if (!$link)
   {
      die('Could not connect: ' . mysql_error());
   }
   echo "made a connection.<br/>";

   // select a database
   mysql_select_db(DATABASE, $link);
   echo "selected a database.<br/>";

   // close the connection in the outer script
   //  mysql_close($link);

?> 
