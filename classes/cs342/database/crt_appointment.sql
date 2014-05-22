CREATE TABLE `Appointment` (
  `aptID` number primary key,
  `dateOn` varchar2(255),
  `location` varchar2(255) default NULL,
  `description` varchar2(510) default NULL,
  PRIMARY KEY (`aptID`)
) AUTO_INCREMENT=1;
