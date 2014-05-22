The prolog interpreter on helios is GNU Prolog 1.2.16 (gprolog)

GNU prolog has an interactive interpreter that uses a read-execute-write loop
and a compiler that produces byte code.

To start the interpreter:

> prolog

Once in Prolog:

o all statements must be terminated by .

o Prolog variables must begin with uppercase letters 

o Predicate names CANNOT have dashes

o the up arrow will recall previous commands

o TAB completes commands

o a prolog program consists of facts, rules or queries

o facts and rules are usually read in from a file (although can be typed in)

o queries are generally entered interactively 

o to compile and load test.pl (do not type the .pl extension): 

     > [test]. 

o you can trace a program with
  
    |-? trace.

o you can turn off tracing with

    |-? notrace.

o you can get a listing of the database with

    |-? listing. 

o Hit ; to continue query or RETURN to end query.
o Hit CTRL-D or halt to exit. 
o Hit ESC- for escape code.
o hit TAB for listing of all available queries (TAB 'a' will list commands
  beginning with 'a'.

