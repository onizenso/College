 CREATE TABLE `AdverseLawyer` (
  `adLawID` number primary key,
  `fName` varchar2(255) default NULL,
  `lName` varchar2(255) default NULL,
  `address` varchar2(255) default NULL,
  `email` varchar2(255) default NULL,
  `phone` varchar2(100) default NULL,
  PRIMARY KEY (`adLawID`)
) AUTO_INCREMENT=1;
