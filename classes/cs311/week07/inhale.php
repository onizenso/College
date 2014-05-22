<?php require_once 'connect.php' ?>

<?php

function inputCSVtoMySQL ($csv_file, $table, $linemax=60000; )
{
    if($read = fopen($csv_file, 'r') !== FALSE)
    {
	$column = fgetcsv($read, $linemax, ',');
	$insert_query_prefix = "INSERT INTO $table (".implode(",",$column).")\nVALUES";
	while (($data = fgetcsv($handle, $max_line_length, ",")) !== FALSE) {
            while (count($data)<count($columns))
                array_push($data, NULL);
            $query = "$insert_query_prefix (".implode(",",quote_all_array($data)).");";
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
//csv_file_to_mysql_table($tmpfile, "Persons");
inputCSVtoMySQL($tmpfile, "Persons");


   $query = "SELECT * FROM Persons";
   $entry = mysql_query($query);//fix problem with mysql_query
   if (!$entry)
   { 
      die('Error: ' . mysql_error()); 
   }
  
   // display the records in the Persons table
   echo "<table>";
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
