#
# all is the default case so for that we want to create the executable runme
all:	runme

# clean out all the .o files, other junk  and start from scratch
clean:
	-rm runme *~ *.o core 

# From here down are rules how to make each individual file
# to create run me we need to add the .o files for main.cpp and string_functions.cpp
runme:	hw3_main.cpp string_functions.o
	g++ -s -o runme hw3_main.cpp string_functions.o


string_functions.o:	string_functions.cpp string_functions.h
	g++ -s -c string_functions.cpp


# DO NOT DELETE THIS LINE -- make depend depends on it.




