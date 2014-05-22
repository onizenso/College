<?php
  $formOK = true;
  $file = fopen("results/results.txt", "w");
  $Q1=$_POST['Q1'];
  $Q2=$_POST['Q2'];
  $Q3=$_POST['Q3'];
  $Q4=$_POST['Q4'];
  $quiz_no=$_POST['quiz_no'];
  $fname = $_POST['fname'];
  $lname = $_POST['lname'];
  if ( empty($fname) || empty($lname) ) {
     $formOK = false; 
     echo "You forgot your first name or your last name.<br>";
     echo "<p><a href='javascript:history.go(-1)' >&laquo; Go fix it</a></p>";
  }
  $question_cnt = 4;
  $score = 0;
  echo "<p>$fname $lname Quiz#$quiz_no</p>";
  if ($formOK) {
     // grade question #1
     if ( (count($Q1) == 2) && ($Q1[0] == 'B') && ($Q1[1] == 'C') ) {
        $score++; 
     }
     else {
	 echo "<p>You missed question #1</p>";
	 fwrite($file, "You missed question #1\n");
     }

     // grade question #2
     if ((count($Q2) == 2) && ($Q2[0] == 'B') && ($Q2[1] == 'D')){
	 $score++;
     }
     else {
        echo "<p>You missed question #2</p>"; 
	 fwrite($file, "You missed question #2\n");
     }
     
     // grade question #3
     if ((count($Q3) == 2) && ($Q3[0] == 'B') && ($Q3[1] == 'D')){
	 $score++;
     }
     else {
        echo "<p>You missed question #3</p>"; 
	 fwrite($file, "You missed question #3\n");
     }
     
     // grade question #4
     if ((count($Q4) == 1) && ($Q4[0] == 'D')){
	 $score++;
     }
     else {
        echo "<p>You missed question #4</p>"; 
	 fwrite($file, "You missed question #4\n");
     }

     echo "<p>Results: $score / $question_cnt";
     fwrite($file, "Results: $score / $question_cnt");
     fclose($file);

  } 
?>
