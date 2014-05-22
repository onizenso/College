 with Ada.Text_IO; use Ada.Text_IO;
 with Bubble_Sort;
 procedure Main is
   type Arr is array (Positive range <>) of Integer;
   procedure Sort is new
   Bubble_Sort
    (Element => Integer,
     Index   => Positive,
     Arr     => Arr);
  A : Arr := (1, 3, 256, 0, 3, 4, -1);
   procedure Test is
      Y : INTEGER := 5;
   begin
      Y := 10;
   ENd;
 begin
  Sort (A);
  for J in A'Range loop
   Put (Integer'Image (A (J)));
  end loop;
  New_Line;
 end Main;
