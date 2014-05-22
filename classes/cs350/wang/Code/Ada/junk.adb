with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO;
use Ada.Integer_Text_IO;


Procedure junk is
   X:INTEGER:= 0;
   procedure sub2;
--///////////////////////////
     Procedure SUB1 is
       X:INTEGER:=5;
       BEGIN
          SUB2;
       END;
--///////////////////////////
     Procedure  SUB2 is
     BEGIN
        X := X + 15;
     
     END;
--///////////////////////////
     BEGIN
       SUB2;
       SUB1;
       Put(X);  -- prints 30
     END;

