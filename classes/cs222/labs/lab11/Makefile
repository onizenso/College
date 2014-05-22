# Start of the actual Makefile
# flags for the compiler
 flags = -s -w

# all is the default case so for that we want to create the executable runme
# if you just type "make" it will try to create runme
all: part1 part2 

# clean out all the .o files, other junk and start from scratch
# if you type "make clean" it will remove the file runme, anyfile that ends with ~ , any file that ends in .o and any file named core
clean:
	-rm -f part1 part2 *~ *.o core

# From here down are rules how to make each individual file


# this is the rules to create the part1 file ( the actual executable)
# the first line says to create runme you will need string_stack_main.o and string_stack.o to be created first (if either of them change it will recreate runme)
# to create runme run g++ and create the runme file made from string_stack_main.o and string_stack.o

part1: vector_main.cpp
	g++ -o part1 vector_main.cpp

part2: list_main.cpp
	g++ -o part2 list_main.cpp






# DO NOT DELETE THIS LINE -- make depend depends on it.
