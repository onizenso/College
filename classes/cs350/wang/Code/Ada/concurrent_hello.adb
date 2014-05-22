with Ada.Text_IO; use Ada.Text_IO;
with Ada.Numerics.Float_Random; use Ada.Numerics.Float_Random;
 
procedure Concurrent_Hello is
   task type Writer (Message : access String);
   task body Writer is
      Seed : Generator;
   begin
      Reset (Seed);
      delay Duration (Random (Seed));
      Put_Line (Message.all);
   end Writer;
 
   S1 : aliased String := "Enjoy";
   S2 : aliased String := "Rosetta";
   S3 : aliased String := "Code";
   T1 : Writer (S1'Access);
   T2 : Writer (S2'Access);
   T3 : Writer (S3'Access);
begin
   null;
end Concurrent_Hello;
