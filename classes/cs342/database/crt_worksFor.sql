CREATE TABLE `WorksFor` (
  `workID` number primary key,
  `staffID` number,
  `lawID` number,
  `sDate` varchar2(100) default NULL,
  `eDate` varchar2(100) default NULL,
  `salary` varchar2(100) default NULL,
  `salary` number default NULL,
  PRIMARY KEY (`workID`)
) AUTO_INCREMENT=1;
