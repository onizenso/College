<?php require(dirname(__FILE__).'/lib.php'); redirect_if_offline(); ?>
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
<?php require_once(dirname(__FILE__)."/left.php"); 

  redirect_if_offline();
?>

<div id="main">
<?php print_r(headers_list()); ?>
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
echo '<pre>';
print_r($_SESSION['online']);
echo '</pre>';
if(!isset($_GET['item']))
echo "<h2>Welcome to the Zombie Apocalypse Store!</h2>";

$itemID = $_GET['item'];

if( $itemID < 0 || $itemID > 14 )
echo "<p style='color:red'><strong>You have entered an invalid product</strong></p>";

?>
</div>
</div>
</body>

</html>
