<?php
  // scriptname: week01.php
  $formOK = true;
  $fname = $_POST['fname']; 
  $lname = $_POST['lname'];
  $room = $_POST['room'];
  $entree = $_POST['entree'];
  $message = $_POST['message'];


  if ( empty($fname) || empty($lname) || empty($room) || empty($entree) ) {
     $formOK = false; 
     echo "You forgot your first name, last name, entree, or your room.<br>";
     echo "<p><a href='javascript:history.go(-1)' >&laquo; Go fix it</a></p>";
  }
  if ($formOK) {
     echo "<b>Menu ordered by</b>: $fname $lname<br>";
     echo "<b>Deliver to Room:</b>: $room<br>";
     echo "<b>Entree Selection</b>: $entree <br>";
     echo "<b>Special instructions</b>: $message <br>";
     
  } 
?>
