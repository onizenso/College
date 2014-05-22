-- filename: lab08.adb
-- demonstrate use of selection statement 
-- demonstrate selective waits with guards in concurrent tasks 

with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with text_io; use text_io;
with Ada.Numerics.Discrete_Random;

procedure lab08 is

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
    entry dropoffDog;
    entry pickupDog;
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

             accept dropoffDog do    -- accept a roundevous  
                dog_cnt := dog_cnt + 1;
                ok2pickup := true;
                put("Dropoff dog:");
                put(dog_cnt,3);
                put_line("");
                if dog_cnt = MAX_DOG_CNT then         
                  ok2dropoff:= false;    -- set guard to false
                end if;
             end;
             dirt_level := dirt_level + 1;
             if dirt_level = 20 then         
	              time2clean:= true;
             end if;

          or 

          when ok2pickup =>        
             accept pickupDog; 
             dog_cnt := dog_cnt - 1; 
             if dog_cnt = 0 then
                 ok2pickup := false;
             end if;
             put("Pickup  dog:");
             put(dog_cnt+1,3);
             put_line("");

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
  
begin
    
  Reset(G);                  -- start the random number generator
   
  for x in 0..100 loop

     my_rand := Random(G);

     -- normally you would use guarded commands to generate requests 
     -- in the client task but here it is just done in a loop

     case my_rand mod 3 is 

        when 0 =>
           if (ok2dropoff) then
             petsRus.dropoffDog;
           end if;

        when 1 =>
           if (ok2pickup) then
              petsRus.pickupDog;
           end if;

        when others  =>
           petsRus.treats;   -- everyone gets a treat!

     end case;

  end loop;

  put_line("");
  put_line("Kennel Closed.");
  new_line;

end lab08;
