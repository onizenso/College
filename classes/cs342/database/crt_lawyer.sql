CREATE TABLE `Lawyer` (
  `lawID` number primary key,
  `fName` varchar2(255) default NULL,
  `lName` varchar2(255) default NULL,
  `position` varchar2(255) default NULL,
  PRIMARY KEY (`lawID`)
) AUTO_INCREMENT=1;
