	.file	"fib.c"
	.text
	.p2align 4,,15
	.globl	fib
	.type	fib, @function
fib:
.LFB18:
	.cfi_startproc
	testl	%edi, %edi
	je	.L31
	cmpl	$1, %edi
	je	.L31
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	leal	-1(%rdi), %edx
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$88, %rsp
	.cfi_def_cfa_offset 144
	movl	%edx, 52(%rsp)
	movl	$0, 56(%rsp)
.L3:
	movl	52(%rsp), %eax
	testl	%eax, %eax
	je	.L33
	cmpl	$1, %eax
	je	.L33
	subl	$2, %edi
	movl	$0, 64(%rsp)
	movl	%edi, 8(%rsp)
	movl	%edi, 48(%rsp)
.L5:
	movl	48(%rsp), %edx
	testl	%edx, %edx
	je	.L35
	cmpl	$1, %edx
	je	.L35
	subl	$2, %eax
	movl	$0, 60(%rsp)
	movl	%eax, 12(%rsp)
	movl	%eax, 44(%rsp)
.L7:
	movl	44(%rsp), %eax
	testl	%eax, %eax
	je	.L37
	cmpl	$1, %eax
	je	.L37
	subl	$2, %edx
	movl	$0, 72(%rsp)
	movl	%edx, 16(%rsp)
	movl	%edx, 40(%rsp)
.L9:
	movl	40(%rsp), %edx
	testl	%edx, %edx
	je	.L39
	cmpl	$1, %edx
	je	.L39
	subl	$2, %eax
	movl	$0, 76(%rsp)
	movl	%eax, 24(%rsp)
	movl	%eax, 36(%rsp)
.L11:
	movl	36(%rsp), %ecx
	testl	%ecx, %ecx
	je	.L41
	cmpl	$1, %ecx
	je	.L41
	subl	$2, %edx
	movl	$0, 68(%rsp)
	movl	%edx, 28(%rsp)
	movl	%edx, 32(%rsp)
.L13:
	movl	32(%rsp), %eax
	testl	%eax, %eax
	je	.L43
	cmpl	$1, %eax
	je	.L43
	subl	$2, %ecx
	movl	$0, 4(%rsp)
	movl	%ecx, 20(%rsp)
	movl	%ecx, %r14d
.L15:
	testl	%r14d, %r14d
	movl	%r14d, %r12d
	je	.L45
	cmpl	$1, %r14d
	je	.L45
	subl	$2, %eax
	xorl	%r13d, %r13d
	movl	%eax, (%rsp)
	movl	%eax, %ebp
	.p2align 4,,10
	.p2align 3
.L17:
	testl	%ebp, %ebp
	movl	%ebp, %ebx
	je	.L47
	cmpl	$1, %ebp
	je	.L47
	xorl	%r15d, %r15d
	jmp	.L20
	.p2align 4,,10
	.p2align 3
.L21:
	cmpl	$1, %ebx
	je	.L59
.L20:
	leal	-1(%rbx), %edi
	call	fib
	addl	%eax, %r15d
	subl	$2, %ebx
	jne	.L21
.L59:
	addl	$1, %r15d
.L18:
	addl	%r15d, %r13d
	subl	$2, %r12d
	je	.L60
	subl	$2, %ebp
	cmpl	$1, %r12d
	jne	.L17
.L60:
	movl	(%rsp), %eax
	addl	$1, %r13d
.L16:
	addl	%r13d, 4(%rsp)
	testl	%eax, %eax
	je	.L61
	subl	$2, %r14d
	cmpl	$1, (%rsp)
	jne	.L15
.L61:
	movl	4(%rsp), %eax
	movl	20(%rsp), %ecx
	addl	$1, %eax
.L14:
	addl	%eax, 68(%rsp)
	testl	%ecx, %ecx
	je	.L62
	subl	$2, 32(%rsp)
	cmpl	$1, 20(%rsp)
	jne	.L13
.L62:
	movl	68(%rsp), %eax
	movl	28(%rsp), %edx
	addl	$1, %eax
.L12:
	addl	%eax, 76(%rsp)
	testl	%edx, %edx
	je	.L63
	subl	$2, 36(%rsp)
	cmpl	$1, 28(%rsp)
	jne	.L11
.L63:
	movl	76(%rsp), %edx
	movl	24(%rsp), %eax
	addl	$1, %edx
.L10:
	addl	%edx, 72(%rsp)
	testl	%eax, %eax
	je	.L64
	subl	$2, 40(%rsp)
	cmpl	$1, 24(%rsp)
	jne	.L9
.L64:
	movl	72(%rsp), %eax
	movl	16(%rsp), %edx
	addl	$1, %eax
.L8:
	addl	%eax, 60(%rsp)
	testl	%edx, %edx
	je	.L65
	subl	$2, 44(%rsp)
	cmpl	$1, 16(%rsp)
	jne	.L7
.L65:
	movl	60(%rsp), %edx
	movl	12(%rsp), %eax
	addl	$1, %edx
	jmp	.L6
	.p2align 4,,10
	.p2align 3
.L47:
	movl	$1, %r15d
	jmp	.L18
.L45:
	subl	$2, %eax
	movl	$1, %r13d
	movl	%eax, (%rsp)
	jmp	.L16
.L43:
	subl	$2, %ecx
	movl	$1, %eax
	movl	%ecx, 20(%rsp)
	jmp	.L14
.L41:
	subl	$2, %edx
	movl	$1, %eax
	movl	%edx, 28(%rsp)
	jmp	.L12
.L39:
	subl	$2, %eax
	movl	$1, %edx
	movl	%eax, 24(%rsp)
	jmp	.L10
.L37:
	subl	$2, %edx
	movl	$1, %eax
	movl	%edx, 16(%rsp)
	jmp	.L8
.L33:
	subl	$2, %edi
	movl	$1, %eax
	movl	%edi, 8(%rsp)
.L4:
	addl	%eax, 56(%rsp)
	testl	%edi, %edi
	je	.L67
	subl	$2, 52(%rsp)
	cmpl	$1, 8(%rsp)
	jne	.L3
.L67:
	movl	56(%rsp), %eax
	addq	$88, %rsp
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_restore 3
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_restore 12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_restore 13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_restore 14
	.cfi_def_cfa_offset 16
	addl	$1, %eax
	popq	%r15
	.cfi_restore 15
	.cfi_def_cfa_offset 8
	ret
.L31:
	movl	$1, %eax
	ret
.L35:
	.cfi_def_cfa_offset 144
	.cfi_offset 3, -56
	.cfi_offset 6, -48
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	.cfi_offset 15, -16
	subl	$2, %eax
	movl	$1, %edx
	movl	%eax, 12(%rsp)
.L6:
	addl	%edx, 64(%rsp)
	testl	%eax, %eax
	je	.L66
	subl	$2, 48(%rsp)
	cmpl	$1, 12(%rsp)
	jne	.L5
.L66:
	movl	64(%rsp), %eax
	movl	8(%rsp), %edi
	addl	$1, %eax
	jmp	.L4
	.cfi_endproc
.LFE18:
	.size	fib, .-fib
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"fib %d is %d \n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB19:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	8(%rsi), %rdi
	movl	$10, %edx
	xorl	%esi, %esi
	call	strtol
	movq	%rax, %rbx
	movl	%eax, %edi
	call	fib
	movl	%ebx, %esi
	movl	%eax, %edx
	movl	$.LC0, %edi
	xorl	%eax, %eax
	call	printf
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE19:
	.size	main, .-main
	.ident	"GCC: (Debian 4.7.2-5) 4.7.2"
	.section	.note.GNU-stack,"",@progbits
