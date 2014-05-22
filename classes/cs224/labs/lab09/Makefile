# Makefile for nasm/yasm assembly code

all:	bare hello inout lab09

bare:	bare.asm
	nasm -f elf64 bare.asm
	ld -o bare  bare.o

hello:	hello.asm
	nasm -f bin -o hello hello.asm
	chmod +x hello

inout:	inout.asm 
	nasm -f elf64 inout.asm
	ld -o inout inout.o

lab09:	lab09.asm 
	yasm -f elf64 -g DWARF2 lab09.asm
	gcc -o lab09  lab09.o

clean:  # for moving to another platform, keeping results
	rm -f *.o
	rm -f hello
	rm -f bare 
	rm -f inout 
	rm -f lab09 
