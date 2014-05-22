<?php require_once(dirname(__FILE__)."/lib.php"); ?>
<!--
File: left.php
Purpose: Display links on the left side of the page
To do's: Generate links to items by using GET parameters.
-->

<div id="left">
<li><a href='store.php'>Home</a><br />
<li><a href="cart.php">View Cart</a></li>
<li><a href="logout.php">Logout</a></li>
<br />
<?php
/******************************************************
 Use a for loop to generate links to each of the items.
 *****************************************************/
for($it=0; $it<count($items); $it++)
{
    $itemID = array();
    $itemID[$it] = $it;
    echo "<li><a href='store.php?item=".$itemID[$it]."'>".$items[$it][0]."</a></li>";
}
?>
</div>
