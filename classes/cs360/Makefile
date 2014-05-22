#
# Standard Makefile for Ultrix 4.x VAX
#                       Ultrix 4.x MIPS
#                       AlphaStation DECUnix 4.0 :
#			RedHat Linux 5.x/6.x on PC: (other Linuxes
#				may require some minor adjustments)
#			Sun/Fujitsu Solaris 7/8 with gcc: (you MUST
#				first put a script /usr/local/bin/machine
#				which, when run, simply echos "sun")
#			PowerbookG4 OSX/Darwin(bsd) with 
#				gcc: (machine returns "ppc7450")
#
# This Makefile assumes each platform has "machine" and "uname"
# commands which return values as in the table below (note: on a 
# Sun machine you may have to add a script /usr/local/bin/machine
# which simply echoes "sun")
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
# 	CFLAGS=`cat TMPFLAGS`		compiler (and debug) flags
# 	LFLAGS=`cat TMPLD`		linker flags
#
# ------------------------------------------------------------------
# architecture-specfic defines: vax alpha sun ppc740 linux
# ------------------------------------------------------------------
#
# MACHINE: mips vax alpha intel ppc ("machine" is not Linux/Sun command,
#	but we assume that on Sun a script /usr/local/bin/machine has
#	been added which simply echos "sun")
MACHINE=`machine`
# OPSYS: ULTRIX OSF Linux SunOS Darwin
OPSYS=`uname`
#
CDEBUG= -DDEBUG -g
#
# set second level of debug (useful for digdnsq.c)
# CDEBUG= -DDEBUG -DDEBUG2 -g
#
# for flags for various Unixes
CFLAGS_mips= -YPOSIX -D_NOPROTO $(CDEBUG)
CC_mips=cc
LD_mips=
CFLAGS_vax =  $(CDEBUG)
CC_vax=cc
LD_vax=
#
CFLAGS_ppc7450= $(CDEBUG) -no-cpp-precomp -Wall -funsigned-char -D__bsd
CC_ppc7450= gcc
LD_ppc7450= -lpthread -lm
#
# -std forces ANSI standard (which sometimes conflicts
# with K+R, unsigned int vs. size_t, etc.)
CFLAGS_alpha= $(CDEBUG)
CC_alpha= cc -w0 -std -pthread
LD_alpha= -lpthread -lexc -lm
CFLAGS_linux= $(CDEBUG) -Wall -funsigned-char -D__linux
CC_linux= cc
LD_linux= -lpthread -lm
#
# Sun has long-standing problems with their fence-sitting
#   System V/BSD posturing (-DBSD_COMP creates more problems
#   than it solves). Also, a new feature is to take "socket"
#   inet_aton and other essential calls out of the "C" libary, hence
#   the "-lsocket -lresolv -lnsl" link flags:
# CFLAGS_sun = $(CDEBUG) -Wall -funsigned-char -D__sunos -DBSD_COMP
CFLAGS_sun = $(CDEBUG) -Wall -funsigned-char -D__sunos 
CC_sun= gcc
LD_sun= -lsocket -lresolv -lnsl -lpthread -lm -lrt
#
CFLAGS=`cat TMPFLAGS`
CC=`cat TMPCC`
LFLAGS=`cat TMPLD`
#
# We now have the virtual machine lib: ./libvm.a 
VMLIBS= -L. -lvm 
# -------------------------------------------------------------------
# The Targets 

default:	tmpfiles 
tmpfiles:	TMPCC

#
# (making TMPCC will automatically also make TMPFLAGS)
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
# -------------------------------------------------------------------

#
vm:		libvm.a vm_batch vm_multi vmiotest vmcputest
#
all:		process startstop message vmcputest libvm.a s_sh \
			vm_batch vm_multi pro_con vmiotest vmlab5 \
			exectest 
# __bsd
# all:		startstop message vmcputest libvm.a s_sh \
# 			vm_batch vm_multi pro_con vmiotest vmlab5

#
# -------------------------------------------------------------------
# C versus C++
# -------------------------------------------------------------------
#

c_diffs.c:	c_diffs.cpp
		grep -v CPP c_diffs.cpp > c_diffs.c

# 
# -------------------------------------------------------------------
#
 
comparison:	a.out a.out_O2 a.out_plus a.out_plus_O2

row_reduce.c:	row_reduce.cpp
		grep -v CPP row_reduce.cpp > row_reduce.c

#
# set "-DDEBUG" only if you want to see LOTS of detail
#
a.out_plus:	row_reduce.cpp
		g++ -g -DCPP row_reduce.cpp -o a.out_plus

a.out_plus_O2:	row_reduce.cpp
		g++ -g -O2 -DCPP row_reduce.cpp -o a.out_plus_O2

a.out:		TMPCC row_reduce.c row_reduce.cpp
		$(CC) -g -lm row_reduce.c 

a.out_O2:	TMPCC row_reduce.c row_reduce.cpp
		$(CC) -g -lm -O2 row_reduce.c -o a.out_O2 

row_reduce_thr:	TMPCC row_reduce_thr.c
		$(CC) -g -lpthread -lm -O2 row_reduce_thr.c -o row_reduce_thr

#
# -------------------------------------------------------------------
#

process:	TMPCC process.c
		$(CC) $(CFLAGS) process.c -o process $(LFLAGS)

startstop:	TMPCC startstop.c
		$(CC) $(CFLAGS) -DDEBUG2 startstop.c -o startstop $(LFLAGS)

message:	TMPCC message.c
		$(CC) $(CFLAGS) -DDEBUG2 message.c -o message $(LFLAGS)

mem_prot:	TMPCC mem_prot.c
		$(CC) $(CFLAGS) -DDEBUG2 mem_prot.c -o mem_prot $(LFLAGS)

mslab3:		TMPCC mslab3.c
		$(CC) $(CFLAGS) -DDEBUG2 mslab3.c -o mslab3 $(LFLAGS)

exectest:	TMPCC exectest.c
		$(CC) $(CFLAGS) exectest.c -o exectest $(LFLAGS)

strtoktest:	TMPCC strtoktest.c
		$(CC) $(CFLAGS) strtoktest.c -o strtoktest $(LFLAGS)

strtoktestR:	TMPCC strtoktest.c
		$(CC) $(CFLAGS) -D_REENTRANT strtoktest.c -o strtoktest $(LFLAGS)

pro_con:	TMPCC pro_con.c
		$(CC) $(CFLAGS) -DDEBUG2 pro_con.c -o pro_con $(LFLAGS)

#
# -------------------------------------------------------------------
#
# requires root privileges to run:
#

findmsg:	TMPCC findmsg.c
		$(CC) $(CFLAGS) -DDEBUG2 findmsg.c -o findmsg $(LFLAGS)

#
# -------------------------------------------------------------------
#
# s_sh:		TMPCC s_sh.c  \
#			header.h startup.h startup.c cleanup.c
s_sh:		TMPCC s_sh.c 
	$(CC) $(CFLAGS) s_sh.c -o s_sh $(LFLAGS)

#
# making vmcputest with "virtual" library libvm.a (so it will have 
# to be run via "vm_batch [options] vmcputest [start_primes]")
#
vmcputest:	TMPCC vmcputest.c libvm.a
	rm -f vmcputest
	$(CC) $(CFLAGS) vmcputest.c -o vmcputest $(VMLIBS) $(LFLAGS)

#
# making vmcputest with "actual" C Run Time Interface:
#
vmcputestC:	TMPCC vmcputest.c  
	rm -f vmcputest
	$(CC) $(CFLAGS) vmcputest.c -o vmcputest $(LFLAGS)

# making vmiotest with "virtual" library libvm.a (so it will have 
# to be run via "vm_batch [options] vmiotest [random_numbers]")
#
vmiotest:	TMPCC vmiotest.c libvm.a
	rm -f vmiotest
	$(CC) $(CFLAGS) vmiotest.c -o vmiotest $(VMLIBS) $(LFLAGS)

#
# making vmiotest with "actual" C Run Time Interface:
#
vmiotestC:	TMPCC vmiotest.c  
	rm -f vmiotest
	$(CC) $(CFLAGS) vmiotest.c -o vmiotest $(LFLAGS)


# making vmlab5 with "virtual" library libvm.a (so it will have 
# to be run via "vm_batch [options] vmlab5 [int_param]")
#
vmlab5:	TMPCC vmlab5.c libvm.a
	rm -f vmlab5
	$(CC) $(CFLAGS) vmlab5.c -o vmlab5 $(VMLIBS) $(LFLAGS)

#
# making vmlab5 with "actual" C Run Time Interface:
#
vmlab5C:	TMPCC vmlab5.c  
	rm -f vmlab5
	$(CC) $(CFLAGS) vmlab5.c -o vmlab5 $(LFLAGS)

#
# -------------------------------------------------------------------
#

libvm.o:	TMPCC libvm.c libvm.h
		$(CC) -c $(CFLAGS) libvm.c

libvm.a:	libvm.o
		rm -f libvm.a
		ar -r libvm.a libvm.o
		ar -t libvm.a
		ranlib libvm.a

vm_batch:	TMPCC vm_ops.c libvm.a libvm.h
		$(CC) $(CFLAGS) -DVM_BATCH vm_ops.c -o vm_batch $(LFLAGS)

vm_vbatch:	TMPCC vm_ops.c libvm.a libvm.h
		$(CC) $(CFLAGS) -DVM_BATCH vm_ops.c -o vm_vbatch $(VMLIBS) \
			$(LFLAGS)

vm_multi:	TMPCC vm_ops.c libvm.a libvm.h
		$(CC) $(CFLAGS) -DVM_MULTI vm_ops.c -o vm_multi $(LFLAGS)

vm_vmulti:	TMPCC vm_ops.c libvm.a libvm.h
		$(CC) $(CFLAGS) -DVM_MULTI vm_ops.c -o vm_vmulti $(VMLIBS) \
			$(LFLAGS)

#
# Note: kernel requires the POSIX timers which may be 
# unavailable on BSD and early Linux systems. It must
# be linked with the real-time libraries
#
kernel:		TMPCC kernel.c
		$(CC) $(CFLAGS) kernel.c -o kernel -lrt

#
# -------------------------------------------------------------------
#

clean:
		rm -f	*.o
		rm -f	*.log
		rm -f	*.dmp
		rm -f	TMP*

veryclean:	clean
		rm -f	process startstop vmcputest libvm.a s_sh vm_batch \
			vm_vbatch message findmsg vm_ops pro_con vmiotest \
			vm_multi vm_vmulti mslab3 vmlab5 kernel exectest \
			strtoktest a.out* row_reduce.c mem_prot row_reduce_thr

