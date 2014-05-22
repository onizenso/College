; fac.asm
; compute factorial
;
; vikaskumar.org/amd64/factorial.htm

section .rodata
    prompt1 db  "Enter a positive number:",0
    num_fmt db  "%lu",0
    prompt2 db  "The factorial of %lu is %lu ",10,0

section .text
    global  main, factorial
    extern  printf, scanf

    main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 8
        pushfq
        push    rbx
        push    r12
        push    r13
        push    r14
        push    r15
        
        ; Read in a number
        mov     rdi, dword prompt1
        xor     rax, rax           ; zero out the return value register
        call    printf
        mov     rdi, dword num_fmt
        lea     rsi, [rbp-8]
        xor     rax,rax
        call    scanf

        ; Calculate Factorial. Result returned in RDX:RAX
        mov     rdi, [rbp-8]   ; save current value of n on the satck
        xor     rax, rax
        call    factorial
 
        ; print result as 32-bit unsigned int
        mov     rdx, rax       ; return value is in rax
        mov     rsi, [rbp-8]   ; value of n
        mov     rdi, dword prompt2
        xor     rax, rax
        call    printf
 
        pop     r15
        pop     r14
        pop     r13
        pop     r12
        pop     rbx
        popfq
        mov     rsp, rbp
        pop     rbp
        ret

    factorial:
        push    rbp
        mov     rbp, rsp
        ; Check if the number in RDI is 0. 
        ; If yes, return with value 1 in RAX as factorial(0). 
        mov     rax, 1
        xor     rdx,rdx
        cmp     rdi, 0
        je      return_here
        ; If value in RDI > 0, push on stack for multiplication,
        ; decrement and call factorial again.
        push    rdi
        dec     rdi
        xor     rax, rax
        call    factorial
        ; Eventually when factorial returns, it will have RAX = 1 when RDI = 0.
       ; So we pop the stack and do unsigned multiply with RAX and return that value in RDX:RAX.
        pop     rsi
        mul     rsi
    return_here:
        mov     rsp, rbp
        pop     rbp
        ret
				
