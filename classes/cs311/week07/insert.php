<?php require_once 'connect.php' ?>

<?php

   // construct a SQL statement to insert one record
   $sql="INSERT INTO Persons (FirstName, LastName, Street, City, State, Zip)
         VALUES
         ('Looney','Fucker','Crazy Street', 'FunkyTown', 'CA', '66600')";

   // execute SQL statement and grab return code
   if (!mysql_query($sql,$link))
   { 
      die('Error: ' . mysql_error()); 
   }
   echo "1st record added<br>";

   $entry = fopen("contacs.csv", "r");
   $record = fgetcsv('$entry',strlen($entry), ",");

   // construct an SQL statement to insert a record using variables
   $first = "$record[0]"; 
   $last = "$record[1]"; 
   $street = "$record[2]";
   $city = "$record[3]";
   $state = "$record[4]";
   $zip = "$record[5]";

   // note the use of parens around the variable name 
   $sql="INSERT INTO Persons (FirstName, LastName, Street, City, State, Zip)
         VALUES
         ('$first','$last','$street','$city','$state','$zip')";

   if (!mysql_query($sql,$link))
   { 
      die('Error: ' . mysql_error()); 
   }
   echo "2nd record added<br>";

   // list the records you just inserted 
   $sql = "SHOW TABLES FROM " . DATABASE;
   $result = mysql_query($sql);
   while ($row = mysql_fetch_row($result)) {
       echo "Table: $row[0]\n";
   }

   // close the connection
   mysql_close($link);

?> 
