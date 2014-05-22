<?php
$b = array(1, 2, 3, 17);

$i = 0; /* for illustrative purposes only */

foreach ($b as $v) {
        echo "\$b[$i] => $v.\n<br>";
	$i++;
}
/* foreach example 4: multi-dimensional arrays */
	$a = array();
	$a[0][0] = "a";
	$a[0][1] = "b";
	$a[1][0] = "y";
	$a[1][1] = "z";

	foreach ($a as $v1) {
	        foreach ($v1 as $v2) {
		            echo "$v2\n";
			        }
	}
 
?>
