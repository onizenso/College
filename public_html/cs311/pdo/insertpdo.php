<?php
require_once('connectpdo.php');

try{//try block for inserting rows
    $dbh = pdo_connect($dsn, $userdb, $passdb);
    $item_name = array('Rusty Machete', 'Shotgun', 'Katana');
    $qty = array('1','4','2');
    $item_price = array('2.99','355.99','589.99');
    $sql = $dbh->prepare("INSERT INTO pdo_cart
	(item_nm, quantity, price)
	VALUES
	(:item, :quantity, :price)");
    
    foreach($item_name as $i => $item){
    $sql->bindParam(':item', $item, PDO::PARAM_STR, 13);
    $sql->bindParam(':quantity', $qty[$i], PDO::PARAM_INT, 1);
    $sql->bindParam(':price', $item_price[$i], PDO::PARAM_INT, 4);
     
    $dbh->beginTransaction();
    $ins = $sql->execute();
    $dbh->commit();
    }
} catch (PDOException $x) {
    $dbh->rollBack();
    echo 'Connection failed: ' . $x->getMessage();
}

try{//try block for reading # of rows & closing connnection
    $res = array();
    $sel = $dbh->prepare("SELECT * from pdo_cart");

    $dbh->beginTransaction();
    $sel->execute();
    $res = $sel->fetchAll();
    $dbh->commit();
    
    $dbh = null;
} catch (PDOException $x) {
    $dbh->rollBack();
    echo 'Connection failed: ' . $x->getMessage();
}

if($ins !== false) {
    echo 'Rows added: '. count($res) . '<br/>';
}
else
    echo 'Insert failed <br/>';
?>

