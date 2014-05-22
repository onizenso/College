# Start of the actual Makefile
# flags for the compiler
 flags = -s -Wall

# all is the default case so for that we want to create the executable runme
# if you just type "make" it will try to create runme
all: char_runme int_runme person_runme

# clean out all the .o files, other junk and start from scratch
# if you type "make clean" it will remove the file runme, anyfile that ends with ~ , any file that ends in .o and any file named core
clean:
	-rm -f char_runme int_runme person_runme  *~ *.o core 

# From here down are rules how to make each individual file


# this is the rules to create the part1 file ( the actual executable)
# the first line says to create runme you will need person_main.o and person.o to be created first (if either of them change it will recreate runme)
# to create runme run g++ and create the runme file made from person_main.o and person.o
int_runme: int_main.cpp t_stack.h
	g++  -Wall -o int_runme int_main.cpp 

char_runme: char_main.cpp t_stack.h
	g++  -Wall -o char_runme char_main.cpp 

person_runme: person_main.cpp t_stack.h person.o
	g++  -Wall -o person_runme person_main.cpp person.o 



# to create person.o you will need person.cpp and person.h (if either changes person.o will be recreated)
person.o: person.cpp person.h
	g++ -Wall -c person.cpp


# DO NOT DELETE THIS LINE -- make depend depends on it.
