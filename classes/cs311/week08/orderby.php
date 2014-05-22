<?php require_once 'connect.php' ?>
<?php
   // demonstrate use of order by keyword 
  /* echo "<p>display records by state:<p/>";
   $result = mysql_query("SELECT * FROM Persons ORDER BY State='CA'");
   while($row = mysql_fetch_array($result))
   {
       echo "<table>";
       foreach($row as $key=>$rows)
       {
     echo "<tr><td>" . $row[$key] . "</td></tr>";
       }
       echo "</table>";
   }*/
  
   echo "<p>display records by last name and age order:<p/>";
   $result = mysql_query("SELECT Distinct * FROM Persons WHERE State='CA' 
    	ORDER BY LastName, FirstName");

   while($row = mysql_fetch_array($result))
   {
       echo "<table>";
      // foreach($row as $key=>$rows)
      // {
	   echo "<tr>";
	   echo "<td>" . $row[0] . $row[1] . $row[2] . $row[3]. $row[4] . $row[5] . "</td>";
	   echo "</tr>";
     echo "<br />";
      // }
   }
      mysql_close($link);
   echo "<br/>closed the connection.<br/>";
?> 
