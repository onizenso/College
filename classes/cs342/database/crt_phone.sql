CREATE TABLE `Case` (
  `phoneID` number primary key,
  `home` varchar2(100) default NULL,
  `cell` varchar2(100) default NULL,
  `business` varchar2(100) default NULL,
  PRIMARY KEY (`phoneID`)
) AUTO_INCREMENT=1;
