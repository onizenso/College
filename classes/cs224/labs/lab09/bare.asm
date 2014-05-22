; file: bare.asm
; demonstrate bare-bones x86 assembly
; executes and returns a value to the OS
; 
; $ nasm -f elf64 -o bare.o bare.asm
; $ ld -o bare bare.o
; $ ./bare
; $ echo $?

section .data    ; start of data segment
exitcode equ 5   ; this assigns the value 5 to the symbol exitcode 

section .text                ; mark start of text segment 
   global _start             ; you do not need main but you must have _start
   _start:                   ; program entry point
      mov   ax,233           ; load ax register with decimal value 233
      mov   eax, 1           ; load eax register with 1 (syscall 1 is exit)
     
      mov   ebx, exitcode    ; load return value register ebx with exit code 
      int   80h              ; perform syscall (interrupt 80h is a syscall)

