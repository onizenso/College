CREATE TABLE `Staff` (
  `staffID` number primary key,
  `fName` varchar2(255) default NULL,
  `lName` varchar2(255) default NULL,
  `title` varchar2(255) default NULL,
  PRIMARY KEY (`staffID`)
) AUTO_INCREMENT=1;
