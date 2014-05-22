<?php
session_start();
require(dirname(__FILE__).'/lib.php'); redirect_if_offline(); 
?>
<!--
File: store.php
Purpose: Interface to the store. Allow the user to add an item to their cart.
To do's: 
- Check that the item ID from GET is a valid ID.
- Display item name and price.
- Create a form that allows a user to add X amount of the item to their cart.
-->

<html>

<head>
<link rel="stylesheet" type="text/css" href="style.css" />
</head>

<body>
<div id="wrapper">
<?php require_once(dirname(__FILE__)."/left.php"); ?> 
<div id="main">
<h2>The World's Last Supply Depot</h2>
<br />
<?php
/******************************************************
 - Validate the item ID:
 - If there is no item ID specified, display a welcome message.
 - If an item ID is not valid, display an error message.
 - If it is a valid item ID, display the item name and price,
   and provide a form to add items to the cart.
 - hint: your form should use GET, and there needs to be
   a hidden form element with the item ID. Example:
   <input type='hidden' name='item' value='<?php echo $itemID; ?>' />
 *****************************************************/
$itemID = $_GET['item'];

$itemName = array();
$itemPrice = array();

for($i=0;$i<count($items);$i++)//assigns item name to $itemName
    $itemName[$i] = $items[$i][0];

for($p=0;$p<count($items);$p++)//assigns item price to $itemPrice
    $itemPrice[$p]=$items[$p][1];

if(!isset($itemID))
    echo "<h2>Welcome to the Zombie Apocalypse Store!</h2>";


if( $itemID < 0 || $itemID > 14 )
    echo "<p class='warn'><strong>You have entered an invalid product</strong></p>";

if( isset($itemID) )
{
echo "<form method='get' action='cart.php'>";
echo "<h3>".$itemName[$itemID]."-----$".$itemPrice[$itemID]."</h3>";
echo "<label for='quantity'>Quantity: </label>";
echo "<input type='hidden' name='item' value='".$itemID."' />";
echo "<input id='quantity' name='qty' type=text value='1' />";
echo "<input type='submit' value='Add item to cart' />";
echo "</form>";
}
?>
</div>
</div>
</body>

</html>
