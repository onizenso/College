CREATE TABLE `Sets` (
  `setsID` number primary key,
  `staffID` varchar2(100),
  `aptID` varchar2(100),
  `dateSet` varchar2(100) default NULL,
  PRIMARY KEY (`setsID`)
) AUTO_INCREMENT=1;
