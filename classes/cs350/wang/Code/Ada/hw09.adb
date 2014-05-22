-- filename: hw09.adb
-- compile only:            $ gcc -c test.adb
-- compile and link with :  $ gnatmake test.adb
-- execute:                 test

-- purpose: Demonstrate Ada's parameter passing mechanisms

with Ada.Text_IO; use Ada.Text_IO;  
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;


procedure hw09 is          

  package Flt_IO is new Ada.Text_IO.Float_IO(FLOAT); 
  use Flt_IO;


  B : BOOLEAN := true;
  Z : FLOAT := 3.5;
  I : INTEGER := 10;        
  
procedure demo(X: out FLOAT; flag: in BOOLEAN; N: in out INTEGER) is
  begin
     
     Put( "From demo: " );
     Put( "N: " ); 
     Put(N,6);   
     Put( " X: "); 
     Put(X,6,2,0); -- the value of out parameters is always 0 to begin with     
     New_Line;

     IF flag = true THEN
        --flag := false;   -- modification to 'in' parameter not allowed 
        N := 99;      -- inout mode parameters are bound to address in caller 
        X := 99.99;     -- 'out' parameter modifies back in calling routine
     END IF;

     Put( "From demo: " );
     Put( "N: " ); 
     Put(N,6);   
     Put( " X: "); 
     Put(X,6,2,0);       
     New_Line;
end demo;
 

  begin

    New_Line;                       
    Put( "From main: " ); 
    Put("i: "); 
    Put(i,6);                
    Put(" z: "); 
    Put(z,6,2,0);
    New_Line;                       


    demo(z,b,i);    -- z is OUT mode; b is IN mode; i is IN OUT mode        

    Put( "From main: " ); 
    Put("i: "); 
    Put(i,6);                
    Put(" z: "); 
    Put(z,6,2,0);
    New_Line;                       

end hw09; 
