<?php
require_once('connectpdo.php');
try{
$dbh = pdo_connect($dsn, $userdb, $passdb);

$prnt = $dbh->prepare("SELECT * from pdo_cart");
$dbh->beginTransaction();
$prnt->execute();
$dbh->commit();

$dbh->beginTransaction();
$res = $prnt->fetchAll();
$dbh->commit();
echo "<table border='1' width='420' summary='Zombie Survival Pruchases'>";
echo "<th>Item ID</th><th>Item Name</th><th>Quantity</th><th>Price</th>";
foreach($res as $r=>$row){
    echo"<tr>
	<td>".$row[item_id]."</td>
	<td>".$row[item_nm]."</td>
	<td>".$row[quantity]."</td>
	<td>".$row[price]."</td>
	</tr>";
}
echo "</table>";
} catch (PDOException $x) {
    $dbh->rollBack();
    echo 'Print failed: ' . $x->getMessage();
}
