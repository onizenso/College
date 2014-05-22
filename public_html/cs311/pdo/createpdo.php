<?php
require_once('connectpdo.php');
try {
  $dbh = pdo_connect($dsn, $userdb, $passdb);  
  $sql = "CREATE TABLE IF NOT EXISTS pdo_cart (
      item_id int(8) NOT NULL AUTO_INCREMENT PRIMARY KEY,
      item_nm varchar(80) NOT NULL DEFAULT '',
      quantity int(9) ,
      price varchar(10)
  )CHARACTER SET utf8 COLLATE utf8_general_ci";
  
  if($dbh->exec($sql) !== false) 
      echo "Table \'pdo_cart\' has been created.<br/>\n";
  
  $dbh = null;
} catch (PDOException $x) {
    echo $x->getMessage();
}
?>
