; myecho.asm
; demonstrate parsing command line arguments
; 
; by convention function args are passed in rdi, rsi, rdx, r10, r8 and r9 
; argc is passed in rdi, argv** is passed in rsi
;
;    $ nasm -f elf64 myecho.asm
;    $ gcc -o myecho myecho.o -g -F dwarf -lc
 
section .rodata
    str_format db "%s",10,0
    num_format db "%ld",10,0

section .text
    global  main, L1, L2  ; L1 and L2 are for debugging
    extern printf

main:
    ; prologue
    push    rbp          ; save base pointer to the stack
    mov     rbp, rsp     ; base pointer = stack pointer 
    sub     rsp, 16      ; make room for two long integers on the stack
    push    rbx           
    push    r12          ; push callee-saved registers onto the stack 
    push    r13          ; OK to use now since callee (main) will restore
    push    r14          ; them just before exiting
    push    r15
    pushfq               ; push register flags onto the stack

    mov    r12, rdi      ; rdi holds number of cmdline args - save it in r12
    mov    r13, rsi      ; rsi is base pointer to char** argv - save to r13

    ; print arg count
    xor    rax, rax
    mov    rsi, r12 
    mov    rdi, dword num_format ; load rdi with address of format string
    call   printf        

L1:
    xor    r15, r15      ; r15 is loop counter and used to compute offset 
                         ; into cmdline arg structure

argLoop:
    cmp    r15, r12       ; stop when i = arg_cnt 
    je     noMoreArgs     

    ; print current cmdline arg 
    lea    r14, [r13+8*r15] ; compute offset - addresses are 8 bytes

L2:
    mov    rsi, [r14]       ; load address to current cmdline arg 
    xor    rax, rax
    mov    rdi, dword str_format 
    call   printf        

    inc    r15            ; increment offset 
    jmp    argLoop        ; jump to argLoop label

noMoreArgs:
    ; epilogue
    popfq
    pop     r15
    pop     r14
    pop     r13
    pop     r12
    pop     rbx
    add     rsp, 16                     ; set back the stack level
    leave
    ret
