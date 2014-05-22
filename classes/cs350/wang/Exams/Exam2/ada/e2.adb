-- filename: e2.adb
-- Your job is to take this program which currently has one task and turn it
-- into a typical producer/consumer problem where the Kennel is the controller
-- task and the producer task will generate a dropoffDog request and the
-- consumer task will generate a pickupDog request. The synchronization that
-- the controller must achieve is that a dropoffDog can only occur is dog_cnt
-- is less than 10 and a pickupDog request can only occur if dog_cnt > 0;
-- obviously both tasks cannot occur at the same time.

with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with text_io; use text_io;
with Ada.Numerics.Discrete_Random;

procedure e2 is

  -- setup data structure to hold some random dog names
  subtype Dog_name is String(1..5);                 -- fixed length dog name
  type RandomNames is array(0..4) of String(1..5);  -- array for random names

  type Names is array(1..25) of String(1..5);       -- array for dog names
  subtype names_index is Integer range 1..25;      -- the index into names array
  subtype My_index is Integer range 0..4;          -- the index into name array

  -- setup framework for a discrete random number generator that will allow
  -- you to randomly pickup a dog out of the kennel
  subtype myint is Integer range 1..100;
  package Random_Int is new Ada.Numerics.Discrete_Random (myint);
  use Random_Int;
  G: Generator;                
  subtype binary_type is Integer range 0..1;
  my_rand: integer := 0;
  my_binary: binary_type := 0;     

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

  end Kennel;

  task body Kennel is

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
                 if dog_cnt = MAX_DOG_CNT then         
                    ok2dropoff:= false;    -- set guard to false
                 end if;
             end dropoffDog;

          or 

          when ok2pickup =>        
             accept pickupDog(dogList: in out Names)  do
                put("Pickup  ");
                put_line(dogList(dog_cnt));
                dog_cnt := dog_cnt - 1; 
                if dog_cnt = 0 then
                   ok2pickup := false;
                end if;
             end pickupDog;

           or

              terminate;
           
       end select;

    end loop;

  end Kennel;

  petsRus: Kennel;       -- instantiate a Kennel task
  dogList: Names;
  someNames: RandomNames;  -- an array of random names
  i : My_index := 0; 
 
begin
  
  someNames(0) := "Tiger";
  someNames(1) := "Fidoo";
  someNames(2) := "Fifee";
  someNames(3) := "JoJoo";
  someNames(4) := "Spott";
 
  Reset(G);                  -- start the random number generator
   
  for x in 0..100 loop

     my_rand := Random(G);
     my_binary := my_rand mod 2;
     -- normally you would use guarded commands to generate requests 
     -- in the client task but here it is just done in a loop

     case my_binary is 

        when 0 =>
           if (ok2dropoff) then
              petsRus.dropoffDog (true,dogList, someNames(my_rand mod 5));
           end if;

        when 1 =>
           if ( ok2pickup) then

               petsRus.pickupDog (dogList);

           end if;

     end case;

  end loop;

  put_line("");
  put_line("Kennel Closed.");
  new_line;

end e2;
