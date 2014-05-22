CREATE TABLE `Litigates`(
  `litID` number primary key,
  `adLawID` number,
  `caseID` number,
  `sDate` varchar2(100) default NULL,
  `eDate` varchar2(100) default NULL,
  `results` varchar2(255) default NULL,
  PRIMARY KEY (`litID`)
) AUTO_INCREMENT=1;
