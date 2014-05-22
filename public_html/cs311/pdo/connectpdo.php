<?php
$dsn    = "mysql:host=localhost;dbname=nramsey";
$userdb = "nramsey";
$passdb = "cs311";

function pdo_connect($dsn, $userdb, $passdb) {
try{    
    $options = array(PDO::ATTR_AUTOCOMMIT=>FALSE);
    $dbh = new PDO($dsn, $userdb, $passdb, $options);
    $dbh->beginTransaction();
    $dbh->exec("SET CHARACTER SET utf8");
    $dbh->commit();
    echo "Connection successful.<br/>\n";
    return $dbh;
} catch (PDOException $x) {
    $dbh->rollBack();
    echo "Connection failed, error: " . $x->getMessage();
}
}
?>
