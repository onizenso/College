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
require_once('lib.php');

redirect_if_offline();
/******************************************************
 Write code to grab item ID and quantity GET parameters
 Validate that item and quantity are valid integers
 *****************************************************/
}
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

<table border="0" style="border-collapse:collapse;" summary='products'>
<tr><th>Item</th><th>Qty</th><th>Price</th></tr>
<?php
/******************************************************
 Display a table of items, quantities, and subtotal for
 each item. Output the total cost below.
 *****************************************************/

?>
<tr><td>&nbsp;</td><td>&nbsp;</td><td>&nbsp;</td></tr>
<tr><td>Total</td><td>&nbsp;</td><td>$<?php /*echo the total price here*/ ?></td></tr>
</table>

</div>
</div>
</body>

</html>
