# Makefile for nasm/yasm assembly code in examples for week10

all:	myecho  fac lab09 fib fibn

# demonstrate ATT x86-64 syntax 

# implement fib function with ATT x86-64 syntax to demonstrate compiler limits
fib:		fib.c
	gcc -O3 -S fib.c
	gcc -o fib fib.s

fibn:		fib-n.asm
	nasm -f elf64 -g -F dwarf fib-n.asm
	gcc -g -o fibn fib-n.o

myecho:		myecho.asm
	nasm -f elf64 -g -F dwarf myecho.asm
	gcc -o myecho myecho.o -lc

fac:		fac.asm
	nasm -f elf64 -g -F dwarf fac.asm
	gcc -o fac fac.o -lc

lab09:		lab09.asm
	nasm -f elf64 -g -F dwarf lab09.asm
	gcc -o lab09 lab09.o -lc

clean:  
	rm -f *.o
	rm -f myecho fac a.out lab09 fib.s fib fibn
