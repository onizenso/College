# Makefile: 
#           It uses the GNU C++ Compiler with all warnings and 
#           debugging enabled. A single executable will
#           be produced.
# ---------------------------------------------------------------
CPP = g++ 
DFLAGS =  -g
LD = g++ 
LLIBS = -lm 
#
# Linker Flags:
# set "-lm" if we need to use the "math" functions
CLIBS= -lm
RM = rm -f
# ----------------------------------------------------------------
# Explanation of macros:
#     $< is any dependent file which is out of date
#     $* is the target's basename (without extension)
#     $@ is the target's fullname
#
# In general ".cpp" (unlike ".c") is not automatically recognized as a
# reserved suffix, so we should inform "make" in case we use this later:
.SUFFIXES:	.cpp .o
#
# implicit rule for compilation only:
.cpp.o:
	${CPP} -c ${DFLAGS} ${CFLAGS} $<

OFILES=		main.o student.o string.o 

HFILES=		student.h string.h exception.h 

# dependencies 
#
default:	all
all:	        main	
#
main:           $(OFILES)
		${LD} ${CFLAGS} ${LLIBS} $(OFILES) -o $@

main.o:		main.cpp student.h 

student.o:	student.cpp student.h exception.h

string.o:	string.cpp
#
clean:
	${RM} *.o
	${RM} core
	${RM} err
#
veryclean:	clean
	${RM}  main  

