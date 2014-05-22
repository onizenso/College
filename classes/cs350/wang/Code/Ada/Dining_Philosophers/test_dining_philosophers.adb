with Ada.Exceptions;             use Ada.Exceptions;
with Ada.Numerics.Float_Random;  use Ada.Numerics.Float_Random;
with Ada.Text_IO;                use Ada.Text_IO;

with Test_Dining_Philosophers_Forks;
use  Test_Dining_Philosophers_Forks;

procedure Test_Dining_Philosophers is
   use Test_Dining_Philosophers_Forks.Forks;

   Forks : aliased Mutexes_Array; -- Forks for hungry philosophers
   --
   -- Left_Of -- The fork left to the given one
   --
   function Left_Of (Fork : Philosopher) return Philosopher is
   begin
      if Fork = Philosopher'First then
         return Philosopher'Last;
      else
         return Philosopher'Pred (Fork);
      end if;
   end Left_Of;
   --
   -- Person -- A task running some philosopher
   --
   -- ID - The philosopher ID
   --
   task type Person (ID : Philosopher);
   task body Person is
      Cutlery : aliased Mutexes_Set := ID or Left_Of (ID);
      Dice    : Generator;
   begin
      Reset (Dice);
      for Life_Cycle in 1..50 loop
         -- In his life a philosopher eats 50 times
         Put_Line (Philosopher'Image (ID) & " is thinking");
         delay Duration (Random (Dice) * 0.100);
         Put_Line (Philosopher'Image (ID) & " is hungry");
         declare
            Lock : Set_Holder (Forks'Access, Cutlery'Access);
         begin
            Put_Line (Philosopher'Image (ID) & " is eating");
            delay Duration (Random (Dice) * 0.100);
         end;
      end loop;
      Put_Line (Philosopher'Image (ID) & " is leaving");
   exception
      when Error: others =>
         Put_Line
         (  Philosopher'Image (ID)
         &  " caused "
         &  Exception_Information (Error)
         );
   end Person;

   T1 : Person (Aristotle); -- Start philosophers
   T2 : Person (Kant);
   T3 : Person (Spinoza);
   T4 : Person (Marx);
   T5 : Person (Russel);
begin
   null; -- Nothing to do in the main task, just sit and behold
end Test_Dining_Philosophers;
