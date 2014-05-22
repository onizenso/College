#
# Standard Makefile for Ultrix 4.x VAX
#                       AlphaStation DECUnix 4.x:
#			RedHat Linux 5.x/6.x on PC or on AlphaStation: 
#				(other Linuxes may require some 
#				minor adjustments)
#			Sun Solaris 7/8 with gcc: (you MUST first put 
#				a script /usr/local/bin/machine
#				which, when run, simply echos "sun")
#			PowerbookG4 OSX/Darwin(bsd) with 
#				gcc: (machine returns "ppc7450")
#
# for programs which
#
#		1. possibly use timer routines REAL, VIRT, PROF
#		2. possibly require POSIX threads.
#		3. possibly require hardware-specific calls
#
# This Makefile assumes each platform has "machine" and "uname"
# commands which return values as in the table below (note: on a 
# Sun machine you may have to add a script /usr/local/bin/machine
# which simply echoe "sun")
#
# platform	oper_sys	`machine`	`uname`
# ------------------------------------------------------------------
# Vax		Ultrix 4.x	 vax		ULTRIX
# AlphaStation	Tru64Unix	 alpha		OSF1
# Sun		Solaris 7/8	 sun		SunOS
# PowerbookG4	OSX/Darwin(bsd)	 ppc740		Darwin
# IntelPC	Linux		<nothing>	Linux
# AlphaStation	Linux		<nothing>	Linux
# ------------------------------------------------------------------
#
# It stores information for each machine architecture in tmpfiles 
# (of the form "TMP.._$(MACHINE)") then using the "machine" command 
# (via MACHINE=`machine`) it copies the correct tmpfile for the 
# platform and defines the three macros:
#
# 	CC=`cat TMPCC`			C compiler invocation
#	CPP=g++				C++ compiler invocation
# 	CFLAGS=`cat TMPFLAGS`		compiler (and debug) flags
# 	LFLAGS=`cat TMPLD`		linker flags
#
# ------------------------------------------------------------------
# general defines for debugging
# ------------------------------------------------------------------
#
MACHINE=`machine`
OPSYS=`uname`
#
# CDEBUG= -DDEBUG -g
#
# set higher level of debug flag (DEBUG2) for argus.c timer*.c
CDEBUG= -DDEBUG -DDEBUG2 -g
#
# for __bsd
# OPTDFLAGS= -g3 -O3 -DDEBUG2 -D__bsd
# 
OPTDFLAGS= -g3 -O3 -DDEBUG2
#
# ------------------------------------------------------------------
# architecture-specfic defines: vax alpha sun ppc740 linux
# ------------------------------------------------------------------
# Vax
#
CFLAGS_vax= $(CDEBUG)
CC_vax=cc
LD_vax=
#
# ------------------------------------------------------------------
# PowerbookG4
#
CFLAGS_ppc7450= $(CDEBUG) -no-cpp-precomp -Wall -funsigned-char -D__bsd
CC_ppc7450= gcc
LD_ppc7450= -lpthread -lm
#
# ------------------------------------------------------------------
# AlphaStation
#
CFLAGS_alpha = $(CDEBUG)
CC_alpha=cc -w0 -std -pthread
LD_alpha=-lpthread -lmach -lexc -lm
#
# ------------------------------------------------------------------
# Linux on PC or on AlphaStation (the latter may require some
# special handling since (__linux) and (__alpha) are defined
# 
CFLAGS_linux = $(CDEBUG) -Wall -funsigned-char -D__linux
CC_linux=cc
LD_linux= -lpthread -lm
#
# ------------------------------------------------------------------
# Sun has long-standing problems with their fence-sitting
#   System V/BSD posturing (-DBSD_COMP creates MANY more problems
#   than it solves). 
#
CFLAGS_sun = $(CDEBUG) -Wall -funsigned-char -D__sunos 
# CC_sun=gcc -D_POSIX_PTHREAD_SEMANTICS
CC_sun=gcc
# LD_sun=-lsocket -lresolv -lnsl -lpthread -lrt -lm
LD_sun=-lpthread -lrt -lm
#
# ------------------------------------------------------------------
#
# same for ALL (although generally we DON'T want the additional
# 		overhead of objects)
CPP=g++
#
# ------------------------------------------------------------------
# Explanation of macros:
#     $< is any dependent file which is out of date
#     $* is the target's basename (without extension)
#     $@ is the target's fullname
# 
# In general, under Unix ".cpp" (unlike ".c") is not automatically 
# recognized as a reserved suffix, so we have to inform "make" of 
# this fact:
.SUFFIXES:	.cpp .o
# implicit rule for C++ compilation only:
.cpp.o:
	${CPP} -c ${CFLAGS} $<

# implicit rule for compilation only:
.c.o:
	${CC} -c ${ANSI} ${CFLAGS} $<

#
CFLAGS=`cat TMPFLAGS`
CC=`cat TMPCC`
LFLAGS=`cat TMPLD`
#
# The Targets 

default:	tmpfiles 
tmpfiles:	TMPCC

#
# (making TMPCC will also make TMPFLAGS and TMPLD)
TMPCC:		Makefile
		echo "$(CFLAGS_mips)" > TMPFLAGS_mips
		echo "$(CC_mips)" > TMPCC_mips
		echo "$(LD_mips)" > TMPLD_mips
		echo "$(CFLAGS_vax)" > TMPFLAGS_vax
		echo "$(CC_vax)" > TMPCC_vax
		echo "$(LD_vax)" > TMPLD_vax
		echo "$(CFLAGS_alpha)" > TMPFLAGS_alpha
		echo "$(CC_alpha)" > TMPCC_alpha
		echo "$(LD_alpha)" > TMPLD_alpha
		echo "$(CFLAGS_linux)" > TMPFLAGS_
		echo "$(CC_linux)" > TMPCC_
		echo "$(LD_linux)" > TMPLD_
		echo "$(CFLAGS_sun)" > TMPFLAGS_sun
		echo "$(CC_sun)" > TMPCC_sun
		echo "$(LD_sun)" > TMPLD_sun
		echo "$(CFLAGS_ppc7450)" > TMPFLAGS_ppc7450
		echo "$(CC_ppc7450)" > TMPCC_ppc7450
		echo "$(LD_ppc7450)" > TMPLD_ppc7450
		cat TMPFLAGS_$(MACHINE) > TMPFLAGS
		cat TMPCC_$(MACHINE) > TMPCC
		cat TMPLD_$(MACHINE) > TMPLD
		rm -f TMPCC_*
		rm -f TMPLD_*
		rm -f TMPFLAGS_*
#
# -------------------------------------------------------------------
# *** NOTHING needs to be changed above this line ***
# -------------------------------------------------------------------
#
cs321:		cache cache_info cache_off

# all:		default cs321 device pseudo 
# for __bsd __linux
all:		default cs321 

# remove all *.o's EXCEPT xgks.o xstate.o ximage.o xbitmap.o 
clean:
	rm -f timer02.o timer04.o device.o pager01.o g_stdio.o *.log \
		pseudo.o timing.o queue.o pager02.o cache.o resource.o \
		alarm.o align.o argus.o squared.o buffer.o g_timing.o \
		cache_info.o cache_off.o hello.o hello.m hello_pause.o \
		hello_pause.m petersen.o TMP*

veryclean:	clean
	rm -f timer02 timer04 device pager01 pseudo queue pager02 \
		cache resource alarm align argus squared buffer volatile \
		cache_info cache_off hello hello_pause petersen

#
# ----------------------------------------------------------------
# Semaphore & Queue Routines
# ----------------------------------------------------------------
#

queue:	queue.o 
	${CC} $@.o -o $@ ${LFLAGS} ${LIBS}
queue.o:	tmpfiles queue.c 
	${CC} -c ${CFLAGS} $*.c

#
# ----------------------------------------------------------------
# Sample resource usage program 
# ----------------------------------------------------------------
#

resource:	resource.o timing.o
	${CC} timing.o $@.o -o $@ ${LFLAGS} ${LIBS}
resource.o:	tmpfiles resource.c timing.h
	${CC} -c ${CFLAGS} $*.c

#
#
# ----------------------------------------------------------------
# Sample use of SIGALRM, setjmp, and longjmp 
# ----------------------------------------------------------------
#

alarm:	alarm.o 
	${CC} $@.o -o $@ ${LFLAGS} ${LIBS}
alarm.o:	tmpfiles alarm.c 
	${CC} -c ${CFLAGS} $*.c

#
#
# ----------------------------------------------------------------
# Sample memory bandwidth test programs
# ----------------------------------------------------------------
#

align:	align.o timing.o
	${CC} timing.o $@.o -o $@ ${LFLAGS} ${LIBS}
align.o:	tmpfiles align.c timing.h
	${CC} -c ${CFLAGS} $*.c

cache:	cache.o timing.o
	${CC} timing.o $@.o -o $@ ${LFLAGS} ${LIBS}
cache.o:	tmpfiles cache.c timing.h
	${CC} -c ${CFLAGS} $*.c

cache_info:	cache_info.o
	${CC} $@.o -o $@ ${LFLAGS} ${LIBS}
cache_info.o:	tmpfiles cache_info.c 
	${CC} -c ${CFLAGS} $*.c

cache_off:	cache_off.o timing.o
	${CC} timing.o $@.o -o $@ ${LFLAGS} ${LIBS}
cache_off.o:	tmpfiles cache_off.c timing.h
	${CC} -c ${CFLAGS} $*.c
#
# ----------------------------------------------------------------
# Timer Routines (timer01 timer02 and timer03 are *** OBSOLETE ***)
# ----------------------------------------------------------------
#

timing.o:	tmpfiles timing.c 
	${CC} -c ${CFLAGS} $*.c
#	${CC} -c -DDEBUG3 ${CFLAGS} $*.c
#	${CC} -c -DDEBUG3 ${OPTDFLAGS} $*.c

argus:		argus.o timing.o
	${CC} timing.o $@.o -o $@ ${LFLAGS} ${LIBS}
argus.o:	tmpfiles argus.c timing.h
	${CC} -c ${CFLAGS} $*.c

squared:	squared.o timing.o
	${CC} ${OPTDFLAGS} timing.o $@.o -o $@ ${LFLAGS} ${LIBS}
squared.o:	tmpfiles squared.c timing.h
	${CC} -c ${OPTDFLAGS} $*.c

petersen:	petersen.o 
	${CC} ${OPTDFLAGS} $@.o -o $@ ${LFLAGS} ${LIBS}
petersen.o:	tmpfiles petersen.c 
	${CC} -c ${OPTDFLAGS} $*.c

timer04:	timer04.o timing.o
	${CC} timing.o $@.o -o $@ ${LFLAGS} ${LIBS}
timer04.o:	tmpfiles timer04.c timing.h
	${CC} -c ${CFLAGS} $*.c

#
# ----------------------------------------------------------------
# Memory and Paging Routines (pager01 is *** OBSOLETE ***)
# ----------------------------------------------------------------
#

pager01:	pager01.o 
	${CC} $@.o -o $@ ${LFLAGS} ${LIBS}
pager01.o:	tmpfiles pager01.c 
	${CC} -c ${CFLAGS} $*.c

pager02:	pager02.o timing.o
	${CC} timing.o $@.o -o $@ ${LFLAGS} ${LIBS}
pager02.o:	tmpfiles pager02.c timing.h
	${CC} -c ${DFLAGS} ${CFLAGS} $*.c

#
# ----------------------------------------------------------------
# Primes and Pseudo Primes (only on Alpha):
# ----------------------------------------------------------------
#

pseudo:		pseudo.o timing.o
	${CC} ${OPTDFLAGS} timing.o $@.o -o $@ ${LFLAGS} ${LIBS}
pseudo.o:	tmpfiles pseudo.c timing.h
	${CC} -c ${OPTDFLAGS} $*.c

#
# ----------------------------------------------------------------
# Directory and Hardware Device Routines (only on Alpha)
# ----------------------------------------------------------------
#

g_stdio.o:	tmpfiles g_stdio.c g_stdio.h 
	${CC} -c ${CFLAGS} $*.c 

device:		device.o g_stdio.o
	${CC} ${DFLAGS} $@.o g_stdio.o -o $@ ${LFLAGS} ${LIBS}
device.o:	tmpfiles device.c g_stdio.h 
	${CC} -c ${DFLAGS} ${CFLAGS} $*.c

g_timing.o:	tmpfiles g_timing.c 
	${CC} -c ${CFLAGS} $*.c

buffer:		buffer.o g_stdio.o g_timing.o
	${CC} ${DFLAGS} $@.o g_stdio.o g_timing.o -o $@ ${LFLAGS} ${LIBS}
buffer.o:	tmpfiles buffer.c g_stdio.h g_timing.h
	${CC} -c ${DFLAGS} ${CFLAGS} $*.c


