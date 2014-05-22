 procedure Bubble_Sort (A : in out Arr) is
  Finished : Boolean;
  Temp     : Element;
 begin
  loop
   Finished := True;
   for J in A'First .. Index'Pred (A'Last) loop
    if A (Index'Succ (J)) < A (J) then
     Finished := False;
     Temp := A (Index'Succ (J));
     A (Index'Succ (J)) := A (J);
     A (J) := Temp;
    end if;
   end loop;
   exit when Finished;
  end loop;
 end Bubble_Sort;
