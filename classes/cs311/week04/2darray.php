<?php
$data = array();
for ($i=0; $i<10; $i++) {
  $data[$i] = array();
  for ($j=0; $j<5; $j++) {
    $data[$i][$j] = $i + $j * 5;
    echo $data[$i][$j] . " ";
  }
  echo "<br />";
}
?>
