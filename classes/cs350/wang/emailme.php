<?php



$message = $_POST['name'];
$percentage = $_POST['percentage'];
$subject = $_POST['subject'];
$to = "donna@cs.csub.edu"; 

$from = "nobody@cs.csub.edu";
$headers = "From: $from";
mail($to,$subject,$message,$headers);
echo "Mail Sent.";
?> 
