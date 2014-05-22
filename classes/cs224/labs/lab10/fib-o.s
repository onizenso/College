	.file	"fib.c"
	.text
	.globl	fib
	.type	fib, @function
fib:
# fib(int n, int val, int prev)
# if(n == 0)
#   return prev 
# if(n == 1)
#   return val
# else
#   return fib(n-1, val+prev, val) 
.LFB0:
	cmpl	$0, %edi
	je	.L3
	cmpl	$1, %edi
	je	.L4
	jmp	.L2
.L2:
        subl    $1, %edi	# n - 1
	movl	%esi, %r10d	# use tmp var 
	addl	%edx, %esi
	movl	%r10d, %edx	# use tmp var 
	call	fib		# fib(n-1, val+prev, val)	
.L3:	
	movl	%edx, %eax	# return prev
	ret
.L4:	
	movl	%esi, %eax	# return val
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
	pushq	%rbp		# push bp to stack
	movq	%rsp, %rbp	# store *stack in *base
	subq	$32, %rsp	# allocate 32 bytes for new stack
	movl	%edi, -20(%rbp)	# store arg count on stack
	movq	%rsi, -32(%rbp)	# store cmdline arg addr on stack
	movq	-32(%rbp), %rax 
	addq	$8, %rax	# char *arg = argv[1]
	movq	(%rax), %rax	 
	movq	%rax, %rdi	# atoi(arg)
	call	atoi
	movl	%eax, -4(%rbp) 	# save atoi ret to stack
	movl	-4(%rbp), %edi	# n = atoi(argv[1])
	addl	$1, %edi
	movl	$1, %esi	# val = 1
	movl	$1, %edx	# val = 1
	call	fib		# fib(n, val, prev)
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %edx	# fib ret -> 3rd arg to printf
	movl	-4(%rbp), %esi	# cmd arg -> 2nd arg to printf
	movl	$.LC0, %edi	# fmt str -> 1st arg to printf
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	ret
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Debian 4.7.2-5) 4.7.2"
	.section	.note.GNU-stack,"",@progbits
