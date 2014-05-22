;; file: lab09.asm
;; taken from: http://vikaskumar.org/amd64/nobranch.htm
;;
;; a program that reads two ints from stdin, compares them and displays larger
;; this program uses printf and scanf from glibc 
;;
;; To assemble and link:
;;
;; $ yasm -f elf64 lab09.asm
;; $ gcc -o lab09 lab09.o      # let gcc link
;;
;; OR you could link manually with this:
;; $ ld -dynamic-linker /lib64/ld-linux-x86-64.so.2 /usr/lib64/crt1.o \
;;        /usr/lib64/crti.o lab09.o  /usr/lib64/crtn.o -lc -o lab09

section .rodata
    prompt1 db "Enter an integer:",0
    prompt2 db "Enter another integer:",0
    prompt3 db "The greater of %ld and %ld is %ld.",10,0
    prompt4 db "The sum/difference is %ld.",10,0
    num_format db "%ld",0

section .text
    global main
    extern printf, scanf    ;; from glibc 

    main:
        ; prologue
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16      ; read in two long integers on the stack
        push    rbx
        push    r12
        push    r13
        push    r14
        push    r15
        pushfq

        ; read in input1
        mov     rdi, dword prompt1
        xor     rax, rax
        call    printf
        lea     rsi, [rbp-8]
        mov     rdi, dword num_format
        xor     rax, rax
        call    scanf

        ; read in input2
        mov     rdi, dword prompt2
        xor     rax, rax
        call    printf
        lea     rsi, [rbp-16]
        mov     rdi, dword num_format
        xor     rax, rax
        call    scanf


        ; is input2 > input1 ?
        xor     rbx, rbx      ; RBX = 0x0
        mov     rax, [rbp-16] ; place input2 in RAX
        cmp     rax, [rbp-8]  ; is input2 > input1 ?
                              ; SETG can only set a byte. So BL is used.
        setg    bl            ; RBX = input2 > input1 ? 0x1:0x0 
        neg     rbx           ; RBX = input2 > input1 ? 0xFFFFFFFFFFFFFFFF:0x0
        mov     rcx, rbx      ; RCX = input2 > input1 ? 0xFFFFFFFFFFFFFFFF:0x0
        and     rcx, [rbp-16] ; RCX =(input2 > input1 ? 0xFFFFFFFFFFFFFFFF:0x0)
                              ;                    && input2 ? input2 : 0x0
        not     rbx           ; RBX = input2 > input1 ? 0x0:0xFFFFFFFFFFFFFFFF
        and     rbx, [rbp-8]  ; RBX = (input2> input1 ? 0x0:0xFFFFFFFFFFFFFFFF)
                              ;                     && input1 ? 0x0 : input1
        or      rcx, rbx      ; RCX = input2 > input1 ? input2 || 0x0 : 0x0 || 
                              ;                    input1 = input2 : input1

        ; RCX contains the greater value
        mov     rdx, [rbp-16]
        mov     rsi, [rbp-8]
        mov     rdi, dword prompt3
        xor     rax, rax
        call    printf

	mov	rsi, [rbp-16]
	add	rsi, [rbp-8]
	mov	rdi, dword prompt4
	xor	rax, rax
	call	printf  

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
