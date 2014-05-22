<?php
$param = $_GET['param'];
echo("param is: " . $param . "<br/>\n");
if ($param == "hello") {
    echo "hi there!<br/>\n";
} else {
    $num = $param * 3;
    echo("number:" . $num . "<br/>\n");
}
echo "<br/>";
echo "<img src='lab03_DFD.png'/>";
?>
