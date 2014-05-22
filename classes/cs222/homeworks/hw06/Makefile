# Start of the actual Makefile
# flags for the compiler
 flags = -s -Wal

# all is the default case so for that we want to create the executable runme
# if you just type "make" it will try to create runme
all: runme 

# clean out all the .o files, other junk and start from scratch
# if you type "make clean" it will remove the file runme, anyfile that ends with ~ , any file that ends in .o and any file named core
clean:
	-rm -f runme  *~ *.o core

# From here down are rules how to make each individual file


# this is the rules to create the part1 file ( the actual executable)
# the first line says to create runme you will need string_map_main.o and string_map.o to be created first (if either of them change it will recreate runme)
# to create runme run g++ and create the runme file made from string_map_main.o and string_map.o
runme: hw06.o string_map.o
	g++ -o runme hw06.o string_map.o


# to create main.o you will need to have main.cpp 
main.o: hw06.cpp
	g++ -c hw06.cpp

# to create string_map.o you will need string_map.cpp and string_map.h (if either changes string_map.o will be recreated)
string_map.o: string_map.cpp string_map.h
	g++ -c string_map.cpp


# DO NOT DELETE THIS LINE -- make depend depends on it.
