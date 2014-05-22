<?php
// 2D array of items in the store. Modify if you like, but keep the same structure.
$items = array(
   array("42in LED TV", 549.99),
   array("Optical Wireless Mouse", 28.99),
   array("1.5TB 7200RPM HDD", 139.99),
   array("Wireless-N Router", 39.99),
   array("6-core 3.4GHz CPU", 169.99),
   array("2x4GB DDR3 1600 RAM", 42.99),
   array("2GB Mem. Video Card", 249.99),
   array("Office PC", 379.99),
   array("Gaming Laptop", 1499.99),
   array("USB Keyboard", 8.99),
   array("Two-barrel Shotgun", 449.99),
   array("Zombie Repellent", 34.99),
   array("Terpentine", 4.99),
   array("Durable Trainers", 69.99),
   array("Apocalypse Z: Zombie Survival Guide", 19.99)
  );
    
// sets cookie to HTTP-Only
ini_set("session.cookie_httponly", 1);

// This function will redirect to the login page if the user is already logged in.
// You should not need to modify this function
function redirect_if_offline() {
    session_start();

    // Destroy session and redirect to login page if not logged in
    if (!isset($_SESSION['online']))
    {
      setcookie(session_name(),"",-1,"/");
      $_SESSION = array();
      session_destroy();
      header("Location: login.php");
    }
}
?>
<!-- 
File: lib.php
Purpose: Set of variables and functions used by multiple scripts (library)
To do's: Nothing (you may add/modify/remove items if you like though)
-->
