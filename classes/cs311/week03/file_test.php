<?php
 $num = 5.5;
 $file = fopen("test.txt","w");
 fwrite($file,"Hello World. Testing!\n");
 fwrite($file,$num);
 fwrite($file,$num." Hi");  // this is concatenation
 fclose($file);
 echo "I just opened a file and wrote stuff to it";
?>
