# Makefile: 
#        It uses the GNU C++ Compiler with debugging
#        will create a single executable called 'main'
# ---------------------------------------------------------------
# the compiler
CPP = g++ 
# compiler flags
CFLAGS = -L/usr/lib/cmplrs/cxx -DPOSIX_4D9   -w -g
# this linker flag will link in the math library libm.a 
LFLAGS = -lm
#
RM = rm -f
# ----------------------------------------------------------------
# Explanation of macros:
#     $< is any dependent file which is out of file1
#     $* is the target's basename (without extension)
#     $@ is the target's fullname
#
# add suffix .cpp since it is not a default with make utility 
.SUFFIXES:	.cpp .o
#
# implicit rule for compilation only:
.cpp.o:
	${CPP} -c ${CFLAGS} $<

OFILES=		main.o

# make sure you include list.h as a dependency since it is a template class
HFILES=		list.h range_error.h 

# dependencies 
#
default:	main	
#
main:           $(OFILES)
		${CPP} ${CFLAGS} ${LFLAGS} $(OFILES) -o $@

main.o:		main.cpp $(HFILES)
	g++ -c -g main.cpp
#
clean:
	${RM} *.o
	${RM} core
#
veryclean:	clean
	${RM}  main  

