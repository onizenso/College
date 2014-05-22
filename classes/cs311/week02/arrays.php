<?php

$formOK = true;

$favNum = $_POST['favnum'];

$your_fav = array();
$fav_anim = array();
$your_fav = $_POST['favs'];
$fav_anim = $_POST['animals'];

$favCount = count($your_fav);
$aniCount = count($fav_anim);

if (empty($favNum) || !is_numeric($favNum)){
    $formOK=false;
    echo "Enter your favorite number again. <br/>";
}

if ($favCount < 2){
    $formOK=false;
    echo "You gotta have at least two favorite things to do... Pick more!<br/>";
}

if (empty($fav_anim)){
    $formOK=false;
    echo "What, you don't like animals? Pick a fav mang!<br/>";
}

if ($formOK){
    echo "Your favorite number is $favNum. <br/>";

    $fav_cpy = "";
    for ($i=0; $i < $favCount; $i++){
	if ( $i == $favCount-1 ){
	    $fav_cpy = $fav_cpy . "and $your_fav[$i].";
	}
	else{
	    $fav_cpy = "$your_fav[$i], " . $fav_cpy;
	}
    }
    echo "You like to $fav_cpy<br/>";
    
    $favBeast = "";
    for ($j=0; $j < $aniCount; $j++){
	if ( $j == $aniCount-1 ){
	    $favBeast = $favBeast . "and $fav_anim[$j].";
	}
	else{
	    $favBeast = "$fav_anim[$j], " . $favBeast;
	}
    }
    echo "Your favorite animal(s): $favBeast<br/>";

    for ($k=0; $k < $favCount; $k++)
    {
    	if ($your_fav[$k] == "watch scifi"){
	echo "<img src='space-odyssey.jpg' alt='Greatest SciFi thriller'/>";
    	}
    }

}

?>
