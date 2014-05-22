CREATE TABLE `CourtAppearance`(
  `caID` number primary key,
  `caseID` number,
  `clientID` number,
  `lawID` number,
  `adLawID` number,
  `dateOn` varchar2(100) default NULL,
  `results` varchar2(255) default NULL,
  PRIMARY KEY (`caID`)
) AUTO_INCREMENT=1;
