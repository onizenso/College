# Makefile: 
# ---------------------------------------------------------------
# the compiler
GCC = gcc 
# compiler flags
CFLAGS = -DPOSIX_4D9 
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
# add suffix .c since it is not a default with make utility 
.SUFFIXES:	.c .o
#
# implicit rule for compilation only:
.c.o:
	${GCC} -c ${CFLAGS} $<

OFILES=		reader_writer.o 

# dependencies 
#
reader_writer:           $(OFILES)
		${GCC} ${CFLAGS} ${LFLAGS} $(OFILES) -o $@

reader_writer.o:		reader_writer.c 

#
clean:
	${RM} *.o
	${RM} core
#
veryclean:	clean
	${RM}  main  
