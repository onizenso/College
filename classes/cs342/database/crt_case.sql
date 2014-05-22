CREATE TABLE `Case` (
  `caseID` number primary key,
  `clientID` number,
  `sDate` varchar2(255),
  `eDate` varchar2(255),
  `evidence` BLOB default NULL,
  `category` BLOB default NULL,
  `litigation` BLOB default NULL,
  `notes` BLOB default NULL,
  PRIMARY KEY (`caseID`)
) AUTO_INCREMENT=1;
