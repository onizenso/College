<?php require_once 'connect.php' ?>
<?php

   // grab all the data in the persons table into an associated array
   $result = mysql_query("SELECT * FROM Persons");

   echo "<br/>Note: by default, data is displayed in record entry order.<br/>";

   echo "<br/>Display the unformatted associated array to the screen:<br/>";
   while($row = mysql_fetch_array($result))
   {
     echo $row['FirstName']." ".$row['LastName']." ".$row['Age'];
     echo "<br />";
   }


   echo "<br/>Display the associated array in an HTML table:<br/>";
   $result = mysql_query("SELECT * FROM Persons");
   echo "<table border='1'><tr><th>Firstname</th><th>Lastname</th><th>Age</th></tr>";

   while($row = mysql_fetch_array($result))
   {
     echo "<tr>";
     echo "<td>" . $row['FirstName'] . "</td>";
     echo "<td>" . $row['LastName'] . "</td>";
     echo "<td>" . $row['Age'] . "</td>";
     echo "</tr>";
   }
   echo "</table>";

   echo "<br/>closed the connection.<br/>";
   mysql_close($link);
?> 
