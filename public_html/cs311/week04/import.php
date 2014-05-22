<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
<title>CMPS 311 - Week Four - Importing Data  </title>
</head>
<body>
<hr />
<h2>Importing a CSV File </h2>

<a href="contacts.csv">view original csv file</a>
<?
$filename = "contacts.csv";
$infile = fopen ($filename, "r") or exit("Unable to open data file.");


echo "<h3>Display as a Table of Records and Fields:</h3>";

$my_data = array();
$count = 0;
while ( ( $record = fgetcsv($infile) ) !== FALSE) {
  $my_data[$count] =  array();
  $my_data[$count] =  $record;
  $count++;
}
fclose ($infile);

echo "<pre>";
print_r ($my_data); 
echo "</pre>";

/*
echo "<h3>Filter for state AK</h3>";

foreach ( $my_data as $record )
{
  if ( $record[4] == 'AK' ) {
    echo "<pre>";
    print_r ( $record );
    echo "</pre>";
  }
} */

echo "<h3>Filter for state CA or zip 60267</h3>";

foreach ( $my_data as $record )
{
  if ( $record[4] == 'CA' || $record[5] == '60267' ) {
    echo "<pre>";
    print_r ( $record );
    echo "</pre>";
  }
}

?>

<hr />

<h2>Reading an Unstructured File into an Array</h2>

To make the infile invisible to everyone but you:<pre>
     $ chmod 700 'filename'</pre> 
<a href="./data.txt">original file is invisible but PHP can read it...</a>

<?php
// lines are not meaningful so just read the entire file
$filename = "data.txt";
$inf = fopen ($filename, "r") or exit("Unable to open data file.");

$data = fread ($inf, filesize($filename) );  
fclose ($inf);
$tokens = preg_split('/[\t \n,]+/', $data, -1, PREG_SPLIT_NO_EMPTY);
$count = 0;

echo "<h3>Dump Array Contents:</h3>";
print_r ($tokens);
echo "<h3>Split Array into Elements:</h3>";

foreach ( $tokens as $tk  )
{
  $count++;
  echo "<b>$count: </b> $tk<br>";
}

sort($tokens);

echo "<h3>Smallest Value:</h3>";

echo "$tokens[0]";

echo "<h3>Largest Value:</h3>";

echo "$tokens[11]";

echo "<h3>Array Average:</h3>";

$sum = array_sum($tokens);
$elements = count($tokens);
$avg = $sum/$elements;

echo "$avg";
?>

<?php
echo "<br>";
echo "<h3>The Raven Poem</h3>";

$poem = "poem.txt";
$inpoem = fopen($poem, "r") or exit("Unable to open the file.");
$stanza = fread($inpoem, filesize($poem));
fclose($inpoem);

$lines = explode(" ", $stanza);
$lines = array_reverse($lines);

//foreach($lines as &$words)
   // $words = explode(" ", $lines);

//foreach($words as &$phrase)
  //  $phrase=array_reverse($words);

foreach($lines as $words)
{
    echo $words . " ";
}  

?>
