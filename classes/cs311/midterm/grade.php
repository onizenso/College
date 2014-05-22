<?php

//Opens answers.txt, reads contents to $answers, closes answers.txt
//***************************************************************//
$ansfile = 'answers.txt';
$inf = fopen($ansfile, 'r') or exit ('Unable to read file, epic fail!');
$answers = fread($inf, filesize($ansfile));
fclose($inf);

//Splits contents of answers.txt into individual elements in $gradekey
//******************************************************************//
$gradekey = preg_split('/[\t \n,]+/', $answers, -1, PREG_SPLIT_NO_EMPTY);

$question = array();
$correct = 0;
$total = 5;

if(isset($_REQUEST['submit']))
{
$name = $_REQUEST['name'];
$question = $_REQUEST['q'];
} 

$endf = 'results/results.txt';
$inres = fopen($endf, 'w') or exit("Unable to open file. Holy shit batman!");

$i = 0; //counter variable

if(isset($_REQUEST['submit'])){
    
    while( $i < 5 )
	{
    	if($question[$i] === $gradekey[$i])
		$correct++;

    	$i++;
	}

fwrite( $inres, $name );
fwrite( $inres, "\n" );

foreach($question as $qst)
    fwrite( $inres, $qst."\n" );

fwrite( $inres, $correct."/".$total );
}
fclose( $inres );

$res = "results/results.txt";
$resin = fopen($res, 'r');
$results = fread($resin, filesize($res));

$resFormat = preg_split('/[\t \n,]+/', $results, -1, PREG_SPLIT_NO_EMPTY);
foreach ($resFormat as $htmlres) 
    echo $htmlres."<br/>";
?>


