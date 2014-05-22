
-- CMPS 350 Exam 2 ADA                                                  25 pts

-- filename: exam.adb                                          
-- input file: data.ada
-- output file: outfile 

-- See: test.adb for everything you need 
-- the only thing new from the lab is how to declare string:
--   s : STRING(1..50);             -- a string of 50 characters
  
-- Your job is to write an Ada program of one or more procedures that 
-- 1) opens an input file named data.ada and reads each line
-- 2) parses the first 3 fields into an array of strings
-- 3) parses the last field into an array of float 
-- 4) displays each line to the screen with a sum for the last field 
-- 5) writes each line with the fields in reverse order to an output file

-- Each item worth 5 pts.

-- The format of data.ada is fixed width columns:  
--   7     20                   20              float
--  F3400 A Clockwork Orange   Anthony,Burgess  7.34
 

with Ada.Text_IO; use Ada.Text_IO;          
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;

procedure exam is

  package Flt_IO is new Ada.Text_IO.Float_IO(FLOAT);  
  use Flt_IO;

   -- declare input string types 
   type FIELD1 is array(1..15) of STRING(1..7);
   type FIELD2 is array(1..15) of STRING(1..20);
   type FIELD3 is array(1..15) of STRING(1..20);
   type FIELD4 is array(1..15) of FLOAT; 
   ids    : FIELD1;
   titles : FIELD2;
   authors: FIELD3;
   prices : FIELD4; 
 
   inf : FILE_TYPE;   
   outf : FILE_TYPE;  

   sum : INTEGER := 0;
    
   begin 
        Open(inf, In_File, "data.ada"); 
        Create(outf, Out_File, "ada.out");  -- open file for writing
        
        for j in 1..15 loop
           Get(inf, ids(j));
           Put(ids(j));
           Put(" ");
           Get(inf, titles(j));
           Put(titles(j));
           Put(" ");
           Get(inf, authors(j));
           Get(inf, prices(j));
           Put(prices(j),6,2,0);
           New_line; 
        end loop;
        
        Close(inf) ;

        Set_Output(outf);   -- set this for formatted output
        for j in 1..15 loop
             Put(ids(j));
             Put(titles(j));
             Put(authors(j));
             Put(prices(j),6,2,0);
             New_line; 
        end loop;
        Set_Output(Standard_Output);
        close(outf) ;
end exam;
