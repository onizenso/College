# flags for the compiler
flags = -s -w

# all is the default case so for that we want to create the executable runme
all:	runme	


# clean out all the .o files, other junk  and start from scratch
clean:
	-rm  -f runme *~ *.o core 

# From here down are rules how to make each individual file
# to create run me we need to add the .o files for main.cpp and main.cpp
runme:	animal.o reptilia.o main.o vertebrata.o mammalia.o
	g++ $(flags) -o runme main.o animal.o reptilia.o vertebrata.o mammalia.o





main.o:	main.cpp
	g++ $(flags) -c  main.cpp 

animal.o:	animal.h animal.cpp
	g++ $(flags) -c animal.cpp

reptilia.o:	reptilia.h reptilia.cpp
	g++ $(flags) -c reptilia.cpp

vertebrata.o:	vertebrata.h vertebrata.cpp
	g++ $(flags) -c vertebrata.cpp
mammalia.o:	mammalia.h mammalia.cpp
	g++ $(flags) -c mammalia.cpp


# DO NOT DELETE THIS LINE -- make depend depends on it.
