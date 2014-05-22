-- filename: doghouse.adb
-- demonstrate use of selection statement 
-- demonstrate selective waits with guards in concurrent tasks 

with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with text_io; use text_io;
with Ada.Numerics.Discrete_Random;

procedure doghouse is

  -- setup data structure to hold the dog names
  subtype Dog_name is String(1..5);                 -- fixed length dog name
  type Names is array(1..25) of String(1..5);       -- array for dog names
  type RandomNames is array(0..4) of String(1..5);    -- array for random names
  subtype names_index is Integer range 1..25;       -- the index into dog array
  subtype my_index is Integer range 0..4;       -- the index into dog array

  -- setup framework for a discrete random number generator that will allow
  -- you to randomly pickup a dog out of the kennel
  subtype myint is Integer range 1..100;
  package Random_Int is new Ada.Numerics.Discrete_Random (myint);
  use Random_Int;
  G: Generator;                
  my_rand: integer:= 0;     

  -- setup a guard system to control when requests are made and received
  ok2dropoff:   boolean:= true;
  ok2pickup:    boolean:= false;
  MAX_DOG_CNT:  integer:= 100; 
  dog_cnt:      integer:= 0;

  -- setup a task to accept requests only; i.e., a server
  task type Kennel is            
     entry dropoffDog (flag : in Boolean; dogList : in out Names; 
                       name : in Dog_name );
     entry pickupDog ( dogList: in out Names );

     entry treats;
  end Kennel;

  task body Kennel is

    -- setup framework for some internal task cleaning
    time2clean:  boolean:= false;
    dirt_level:  integer:= 0;

  begin
    put_line("Kennel petsRus is open for business.....");

    loop                          -- loop continuously waiting for requests
                                   
       select                      -- a selective wait with guards 

          when ok2dropoff =>           -- ok2dropoff is the guard 

             accept dropoffDog(flag: in Boolean; 
                               dogList: in out Names; name: in Dog_name) do

                 dog_cnt := dog_cnt + 1;
                 dogList(dog_cnt) := name;
                 ok2pickup := true;
                 put("Dropoff ");
                 put_line(dogList(dog_cnt));
                 dirt_level := dirt_level + 1;
                 if dog_cnt = MAX_DOG_CNT then         
                    ok2dropoff:= false;    -- set guard to false
                 end if;
                 if dirt_level = 20 then         
	                  time2clean:= true;
                 end if;
             end dropoffDog;

          or 

          when ok2pickup =>        
             accept pickupDog(dogList: in out Names)  do
                put("Pickup ");
                put_line(dogList(dog_cnt));
                dog_cnt := dog_cnt - 1; 
                if dog_cnt = 0 then
                   ok2pickup := false;
                end if;
             end pickupDog;

           or

          when true =>                -- accept treats at any time 
             accept treats; 
             put("TREAT!");
             put_line("");

           or
              terminate;
           
       end select;

       -- cleanup after every 10 dog tasks 
       if time2clean then      
          put("Time to clean the kennel (");
          put(dog_cnt,3);
          put_line(")");
          time2clean:= false;
          dirt_level:= 0;
       end if;  

    end loop;

    -- code here is never executed

  end Kennel;

  petsRus: Kennel;       -- instantiate a Kennel task
  dogList: Names;
  someNames: RandomNames;  -- an array of random names
  i : My_index := 0; 
 
begin
  
  someNames(0) := "Tiger";
  someNames(1) := "Fidoo";
  someNames(2) := "Fifii";
  someNames(3) := "JoJoo";
  someNames(4) := "Spoty";
 
  Reset(G);                  -- start the random number generator
   
  for x in 0..100 loop

     my_rand := Random(G);

     -- normally you would use guarded commands to generate requests 
     -- in the client task but here it is just done in a loop

     case my_rand mod 3 is 

        when 0 =>
           if (ok2dropoff) then
              petsRus.dropoffDog (true,dogList, someNames(my_rand mod 5));
           end if;

        when 1 =>
           if ( ok2pickup) then

               petsRus.pickupDog (dogList);

           end if;

        when others  =>
           petsRus.treats;   -- everyone gets a treat!

     end case;

  end loop;

  put_line("");
  put_line("Kennel Closed.");
  new_line;

end doghouse;
