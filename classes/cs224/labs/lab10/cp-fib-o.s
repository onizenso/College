	.file	"fib.c"
	.text
	.globl	fib
	.type	fib, @function
fib:
# if(arg <= 1)
#   return arg
# else
#   return arg + fib(arg-1)
.LFB0:
	cmpl	$0, %edi	# recurse on arg != 0
	je	.L5
	jmp	.L2
.L2:
	cmpl	$1, %edi	# recurse on arg != 1
	je	.L5
	jmp	.L4
.L4:
	.cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        pushq   %rbx
        subq    $24, %rsp
        .cfi_offset 3, -24
        movl    %edi, -20(%rbp)
	movl	-20(%rbp), %eax
	subl	$1, %eax	# arg -= 1
	movl	%eax, %edi	
	call	fib		# recurse
	movl	%eax, %ebx	# store ret in ebx
	movl	-20(%rbp), %eax	# load arg from stack
	subl	$2, %eax	# arg -= 2
	movl	%eax, %edi
	call	fib		# recurse
	addl	%ebx, %eax	# arg += fib(arg-1)
.L3:	
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.L5:
	movl	$1, %eax	# ret = 1, jmp to exit
	ret
.LFE0:
	.size	fib, .-fib
	.section	.rodata
.LC0:
	.string	"fib %d is %d \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp		# push bp to stack
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	# store *stack in *base
	.cfi_def_cfa_register 6
	subq	$32, %rsp	# allocate 32 bytes for new stack
	movl	%edi, -20(%rbp)	# store arg count on stack
	movq	%rsi, -32(%rbp)	# store cmdline arg addr on stack
	movq	-32(%rbp), %rax 
	addq	$8, %rax	# char *arg = argv[1]
	movq	(%rax), %rax	 
	movq	%rax, %rdi	# atoi(arg)
	call	atoi
	movl	%eax, -4(%rbp) 	# save atoi ret to stack
	movl	-4(%rbp), %edi	# pass arg to fib
	call	fib
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %edx	# fib ret -> 3rd arg to printf
	movl	-4(%rbp), %esi	# cmd arg -> 2nd arg to printf
	movl	$.LC0, %edi	# fmt str -> 1st arg to printf
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Debian 4.7.2-5) 4.7.2"
	.section	.note.GNU-stack,"",@progbits
