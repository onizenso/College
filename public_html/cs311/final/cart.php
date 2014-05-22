<!-- 
File: cart.php
Purpose: Place items in the shopping cart that the customer wants to purchase.
To do's:
  - Validate that the item and quantity passed as GET parameters are valid input.
  - If the input is valid, put the quantity in your cart array (which is in the 
    $_SESSION array).
  - Output items in the cart in a nicely formatted table. The table needs to 
    the name and subtotal (price * quantity) of each item. See Week 7 insert.php
    for an example of how to use PHP to generate an HTML table..
-->
<?php
session_start();
require_once('lib.php');

//redirect_if_offline();
/******************************************************
 Write code to grab item ID and quantity GET parameters
 Validate that item and quantity are valid integers
 *****************************************************/
$itemIDX = $_GET['item'];
$qty = array();
$qty[$itemIDX] = $_GET['qty'];
$itemName = array();
$itemPrice = array();
$cart = array();

$subtot = array();

for( $i=0; $i<count($items); $i++)//assigns item name to $itemName
    $itemName[$i] = $items[$i][0];

foreach($itemName as $junk=>$good)//assigns item price to $itemPrice
    $itemPrice[$junk] = $items[$junk][1];

if(isset($itemIDX) && isset($qty))
    if($itemIDX>=0 && $itemIDX<=14 && $qty>0)
    {
        $_SESSION['cart'][$itemIDX]=$qty[$itemIDX];
    }

foreach($_SESSION['cart'] as $pick=>$merch)
    $subTot[$pick] = $merch*$itemPrice[$pick];

?>

<html>

<head>
<link rel="stylesheet" type="text/css" href="style.css" />
</head>

<body>
<div id="wrapper">
<?php require_once('left.php'); ?>
<div id="main">
<h2>Your Shopping Cart</h2>
<?php //print_r($subTot); ?>
<table border="0" style="border-collapse:collapse;" summary='products'>
<tr><th>Item</th><th>Qty</th><th>Price</th></tr>
<?php
/******************************************************
 Display a table of items, quantities, and subtotal for
 each item. Output the total cost below.
 *****************************************************/

foreach($_SESSION['cart'] as $key=>$amt){
    echo "<tr><td>".$itemName[$key]."</td><td>".$amt."</td><td>$".$subTot[$key]."</td></tr>";
    $Total += $subTot[$key];
}


?>
<tr><td>&nbsp;</td><td>&nbsp;</td><td>&nbsp;</td></tr>
<tr><td>Total</td><td>&nbsp;</td><td>$<?php echo $Total; ?></td></tr>
</table>

</div>
</div>
</body>

</html>
