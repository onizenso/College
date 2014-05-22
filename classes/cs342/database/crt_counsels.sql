CREATE TABLE `Counsels`(
  `counselsID` number primary key,
  `lawID` number,
  `clientID` number,
  `sDate` varchar2(100) default NULL,
  `eDate` varchar2(100) default NULL,
  `hours` number default NULL,
  `fees` varchar2(100) default NULL,
  PRIMARY KEY (`counselsID`)
) AUTO_INCREMENT=1;
