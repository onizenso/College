<?php
  $formOK = true;

  echo "<p/> print_r (\$_POST): ";
  print_r ($_POST);
  $my_favs = array();
  $my_favs = $_POST['favs'];
  $fav_cnt = count($my_favs);

  if ( $fav_cnt < 2) {
     $formOK = false;
     echo "<b>You must pick at least two favorite animals!</b>";
  }
  else {
     echo "<p/> print_r (\$my_favs): ";
     print_r ($my_favs);
     echo "<p/>";
     echo "<b>Your $fav_cnt Favorite Animals Are</b>:  <br/>";

     // foreach looping is a quick way of traversing an array
     foreach ( $my_favs as $animal ) {
         echo "$animal <br/>";
     }
     echo "<p/>";

     // this for loop has the same behavior as the above foreach loop
     for ($i = 0; $i < $fav_cnt; $i++) { 
       echo " $my_favs[$i] ";
     }

     echo "<p/>";

     echo "<b>Your $fav_cnt Favorite Animals In Reverse Order</b>:  <br/>";
     // to traverse through the array in reverse you need a for loop! 
     for ($i=$fav_cnt - 1; $i >= 0; $i-- ) {
         echo "$my_favs[$i] <br/>";
     }
  } 
?>
