<html>
<head>
<title> Final Exam PHP SOLUTION</title>
</head>
<body>
<?php
// uncomment to dump all elements in $_POST for debugging
// foreach($_POST as $key => $value)
//{
//   printf("%s = %s<br>", $key, $value);
//}
  $name = $_POST['name'];
  $year = $_POST['year'];
  $track = $_POST['track'];
  $C1=$_POST['C1'];
  $C2=$_POST['C2'];
  $C3=$_POST['C3'];
  $C4=$_POST['C4'];
  $C5=$_POST['C5'];
  $C6=$_POST['C6'];
  if ( empty($name) ){
     print "You must include your name!";
  }
  else {
     $lacking = 0;
     $list = "";
     if ($C1 != "on"){
        $list .= " Operating Systems<br>" ; 
        $lacking++;
     }
     if ( $C2 != "on")  {
        $list .= " Networking<br>"; 
        $lacking++;
     }
     if ($C3 != "on") {
        $list .= " Architecture <br>"; 
        $lacking++;
     }
     if ($C4 != "on") {
         $list .= " Discrete Structures<br>"; 
         $lacking++; 
     }
     if ($C5 != "on") {
         $list .=  " Databases<br>"; 
         $lacking++; 
     }
     if ($C6 != "on") {
         $list .= " Senior Seminar<br>"; 
         $lacking++; 
     }
     print "<b>SURVEY RESULTS</b><p>";
     print "Name: $name</b><p>";
     print "Year: $year</b><p>";
     print "Track: $track</b><p>";
     print "You have the following ".$lacking." course(s) remaining:<p>";
     print $list;
  } 
?>
</body>
</html>
