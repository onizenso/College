 CREATE TABLE `Client` (
  `clientID` number primary key,
  `fName` varchar2(255) default NULL,
  `lName` varchar2(255) default NULL,
  `busName` varchar2(255),
  `email` varchar2(255) default NULL,
  `address` varchar2(255) default NULL,
  `dob` varchar2(255),
  PRIMARY KEY (`clientID`)
) AUTO_INCREMENT=1;
