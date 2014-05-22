<?php require_once 'connect.php' ?>

<?php

function csv_file_to_mysql_table($source_file, $target_table, $max_line_length=10000) {
    if (($handle = fopen("$source_file", "r")) !== FALSE) {
        $columns = fgetcsv($handle, $max_line_length, ",");
        
        $insert_query_prefix = "INSERT INTO $target_table (".join(",",$columns).")\nVALUES";
        while (($data = fgetcsv($handle, $max_line_length, ",")) !== FALSE) {

            $query = "$insert_query_prefix (".join(",",quote_all_array($data)).");";
            mysql_query($query);
        }
        fclose($handle);
    }
}

function quote_all_array($values) {
    foreach ($values as $key=>$value)
        if (is_array($value))
            $values[$key] = quote_all_array($value);
        else
            $values[$key] = quote_all($value);
    return $values;
}

function quote_all($value) {
    if (is_null($value))
        return "NULL";

    $value = "'" . mysql_real_escape_string($value) . "'";
    return $value;
} 


$tmpfile = "contacts.csv";
csv_file_to_mysql_table($tmpfile, "Persons");

   $query = "SELECT * FROM Persons";
   $entry = mysql_query($query);//fix problem with mysql_query
   if (!$entry)
   { 
      die('Error: ' . mysql_error()); 
   }
  
   // display the records in the Persons table
   echo "<table>";
   echo "<tr><th>Firstname</th><th>Lastname</th><th>Street</th><th>City</th><th>State</th><th>Zip</th></tr>";
   while ($record = mysql_fetch_row($entry)) {
     echo "<tr>";
     foreach ($record as $field) {
       echo "<td>$field</td>";
     }
     echo "</tr>";
   }
   echo "</table>";
   mysql_close($link);
   
   
?> 
