<?php require_once 'connect.php' ?>

<?php
   // demonstrate use of where clause
   echo "display records with state CA:<br />";
   $result = mysql_query("SELECT * FROM Persons WHERE State='CA'");

   while($row = mysql_fetch_array($result))
   {
      echo $row['FirstName'] . " " . $row['LastName'];
      echo "<br />";
   }
   mysql_close($link);
   echo "<br/>closed the connection.<br/>";

?> 
