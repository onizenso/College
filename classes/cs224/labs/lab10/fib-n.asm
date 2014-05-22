%macro prologue 0
        push    rbp
        mov     rbp,rsp
        push    rbp
        push    r12
        push    r13
        push    r14
        push    r15
        pushfq 
%endmacro
%macro epilogue 0
        popfq
        pop     r15
        pop     r14
        pop     r13
        pop     r12
        pop     rbp
        leave
        ret
%endmacro

section .text

section .rodata
	fmtstr	db	'fib %i is %i', 0xA, 0

section .text
extern 	printf
extern 	atoi
global	main
main:
	prologue
	sub	rsp, 32		        ; allocate 32 bytes for new stack
	mov	r12, rdi	        ; store arg count on stack
	mov	r13, rsi          ; store cmdine arg addr on stack
	lea	rdi, [r13+8]
	mov 	rdi, [rdi]
	xor	rax, rax
	call	atoi
	mov	r14, rax 	        ; save atoi ret to stack
	mov	rdi, r14     	    ; n = atoi(argv[1])
	add	rdi, 1
	mov	rsi, 1		        ; val = 1
	mov	rdx, 1		        ; val = 1
	xor	rax, rax
	call	fib 		          ; fib(n, val, prev)
	mov	rdx, rax	        ; fib ret -> 3rd arg to printf
	mov	rsi, r14     	    ; cmd arg -> 2nd arg to printf
	mov	rdi, dword fmtstr	; fmt str -> 1st arg to printf
	xor 	rax, rax
	call	printf
	mov	rax, 0
	add	rsp, 32
	epilogue

global	fib
fib:
	cmp	rdi, 0
	je    	L3
	cmp	rdi, 1
	je	L4
	jmp	L2
L2:
  	sub	rdi, 1		  ; n - 1
	mov	r15, rsi    ; use tmp var 
	add	rsi, rdx
	mov	rdx, r15    ; use tmp var 
	call	fib         ; fib(n-1, val+prev, val)	
L3:	
	mov	rax, rdx	  ; return prev
	ret
L4:	
	mov	rax, rsi	  ; return val
	ret

; fib(int n, int val, int prev)
; if(n == 0)
;   return prev 
; if(n == 1)
;   return val
; else
;   return fib(n-1, val+prev, val) 
