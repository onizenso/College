To compile C source using the GNU C compiler:

    gcc <filename.c>

Some big differences between GNU C and C++:

1. "for loop" variables must be declared outside the loop
2. headers ALWAYS end with .h
3. GNU C is not strict ANSI-C compliant (lets you get away with a few things)

To link in math library:

   gcc -lm <filename.c>

To run the debugger for a C program, compile the program using option -g. 

   gcc -Wall -g prog1.c

then use command

   gdb a.out

to run your program. At the prompt, type "break main" and run to run your 
program. If you stop the program using ctl-C, you can do a debugger command 
backtrace to get a trace of the run-time stack, most recently entered frame 
first. 

Use commands up and down to move up and down in the stack. (Unfortunately, 
up moves down and down moves up because the stack is shown upside-down.) 
You can print the value of a variable x using command print x.

Command break f causes the program to stop each time it starts function f. 
There are other commands as well. Type help to see them.

To exit the debugger, type "quit".

