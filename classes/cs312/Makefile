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
#			MacBook Air OSX/Darwin(bsd) with
#				gcc: (machine returns "i486")
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
# MacBook Air	OSX		i486		Darwin
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
CDEBUG= -DDEBUG -g
#
# option of higher level of debug flag (DEBUG2) for some programs
# CDEBUG= -DDEBUG -DDEBUG2 -g
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
# MacBook Air
#
CFLAGS_i486= $(CDEBUG) -no-cpp-precomp -Wall -funsigned-char -D__bsd
CC_i486=gcc
LD_i486=-lm -lpthread
CPP_i486=g++
CPPFLAGS_i486= $(CDEBUG) -Wall -funsigned-char -D__bsd
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
# same for ALL (although generally we don't always want the additional
# 		overhead of objects when we have long-running algorithms)
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
		echo "$(CFLAGS_i486)" > TMPFLAGS_i486
		echo "$(CC_i486)" > TMPCC_i486
		echo "$(LD_i486)" > TMPLD_i486
		echo "$(CPP_i486)" > TMPCPP_i486
		echo "$(CPPFLAGS_i486)" > TMPCPPFLAGS_i486
		cat TMPFLAGS_$(MACHINE) > TMPFLAGS
		cat TMPCC_$(MACHINE) > TMPCC
		cat TMPLD_$(MACHINE) > TMPLD
		rm -f TMPCC_*
		rm -f TMPCPP_*
		rm -f TMPLD_*
		rm -f TMPFLAGS_*
#
# -------------------------------------------------------------------
# *** NOTHING needs to be changed above this line ***
# -------------------------------------------------------------------
#
cs312:		sorting cache_info cache uniform gcdivisor recursion \
		entropy classes summation ngraph

recursion:	gcd_recurs factor_recurs

classes:	wait_time

all:		cs312 

# remove all *.o's EXCEPT xgks.o xstate.o ximage.o xbitmap.o 
clean:
	rm -f sorting.o timing.o cache_info.o cache.o entropy.o \
		*.log TMP* summation.o ngraph.o

veryclean:	clean removeSYM
	rm -f sorting cache_info cache uniform gcdivisor gcd_recurs \
		factor_recurs entropy wait_time summation ngraph

removeSYM:
	rm -rf *.dSYM

#
# -------------------------------------------------------------------
# gcd/factoring algorithms: 
# -------------------------------------------------------------------
#

gcdivisor:	tmpfiles gcdivisor.cpp 
		${CPP} ${CFLAGS} ${LFLAGS} $@.cpp -o $@

gcd_recurs:	tmpfiles gcd_recurs.cpp 
		${CPP} ${CFLAGS} ${LFLAGS} $@.cpp -o $@

factor_recurs:	factor_recurs.cpp TMPCC
		${CPP} ${CFLAGS} ${LFLAGS} $@.cpp -o $@

#
# -------------------------------------------------------------------
# Sample C++ sorting program: sorting.cpp
#	     time with: /usr/bin/time -p sorting datafile < userinput
# -------------------------------------------------------------------
#

sorting:	tmpfiles sorting.o 
	${CPP} $@.o -o $@ ${LFLAGS} ${LIBS}
sorting.o:	tmpfiles sorting.cpp 
	${CPP} -c ${CFLAGS} $*.cpp

#
# -------------------------------------------------------------------
# generate uniform distributions: uniform 2> datafile.txt
# measure entropy of partially sorted list: entropy datafile.txt
# -------------------------------------------------------------------
#

uniform:	tmpfiles uniform.cpp 
		${CPP} ${CFLAGS} ${LFLAGS} $@.cpp -o $@

entropy:	tmpfiles entropy.o 
	${CC} $@.o -o $@ ${LFLAGS} ${LIBS}
entropy.o:	tmpfiles entropy.c 
	${CC} -c ${CFLAGS} $*.c

#
# -------------------------------------------------------------------
# graph theoretic: max flow, shortest path 
# -------------------------------------------------------------------
#

ngraph:	tmpfiles ngraph.o 
	${CC} $@.o -o $@ ${LFLAGS} ${LIBS}
ngraph.o:	tmpfiles ngraph.c 
	${CC} -c ${CFLAGS} $*.c

#
# -------------------------------------------------------------------
# error issues: 
# -------------------------------------------------------------------
#

summation:	tmpfiles summation.o 
	${CC} $@.o -o $@ ${LFLAGS} ${LIBS}
summation.o:	tmpfiles summation.c 
	${CC} -c ${CFLAGS} $*.c

#
# -------------------------------------------------------------------
# cache routines: 
# -------------------------------------------------------------------
#

cache:	cache.o timing.o
	${CC} timing.o $@.o -o $@ ${LFLAGS} ${LIBS}
cache.o:	tmpfiles cache.c timing.h
	${CC} -c ${CFLAGS} $*.c

cache_info:	cache_info.o
	${CC} $@.o -o $@ ${LFLAGS} ${LIBS}
cache_info.o:	tmpfiles cache_info.c 
	${CC} -c ${CFLAGS} $*.c

#
# -------------------------------------------------------------------
# classes: 
# -------------------------------------------------------------------
#

wait_time:	tmpfiles wait_time.cpp 
		${CPP} ${CFLAGS} ${LFLAGS} $@.cpp -o $@

#
# -------------------------------------------------------------------
# C Timer Routines if you want to embed timing WITHIN the program:
# -------------------------------------------------------------------
#

timing.o:	tmpfiles timing.c 
	${CC} -c ${CFLAGS} $*.c
#	${CC} -c -DDEBUG3 ${CFLAGS} $*.c
#	${CC} -c -DDEBUG3 ${OPTDFLAGS} $*.c
#
# -------------------------------------------------------------------
# 

