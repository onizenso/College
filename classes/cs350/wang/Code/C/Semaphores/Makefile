# Makefile: 
# ---------------------------------------------------------------
# the compiler
CPP = gcc 
# compiler flags
# CFLAGS = -L/usr/lib/cmplrs/cxx -DPOSIX_4D9 -w0 -gall
CFLAGS = -DPOSIX_4D9 -g
# linker flags to link in the libraries libm.a and libtask.a
LFLAGS = -lm -lpthread 
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

OFILES=		main.o  semaphore.o

HFILES=		 

# dependencies 
#
main:           $(OFILES)
		${CPP} ${CFLAGS} ${LFLAGS} $(OFILES) -o $@

main.o:		main.c 
semaphore.o:	semaphore.c  semaphore.h

#
clean:
	${RM} *.o
	${RM} core
#
veryclean:	clean
	${RM}  main  

