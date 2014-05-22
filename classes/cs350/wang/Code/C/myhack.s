	.file	"myhack.c"
	.section	".rodata"
	.align 8
.LLC0:
	.asciz	"From good code: %d"
	.section	".text"
	.align 4
	.global good_code
	.type	good_code, #function
	.proc	020
good_code:
	save	%sp, -120, %sp
	mov	10, %g1
	st	%g1, [%fp-20]
	sethi	%hi(.LLC0), %g1
	or	%g1, %lo(.LLC0), %o0
	ld	[%fp-20], %o1
	call	printf, 0
	 nop
	return	%i7+8
	 nop
	.size	good_code, .-good_code
	.section	".rodata"
	.align 8
.LLC1:
	.asciz	"From bad code: %d"
	.section	".text"
	.align 4
	.global bad_code
	.type	bad_code, #function
	.proc	020
bad_code:
	save	%sp, -120, %sp
	mov	99, %g1
	st	%g1, [%fp-20]
	sethi	%hi(.LLC1), %g1
	or	%g1, %lo(.LLC1), %o0
	ld	[%fp-20], %o1
	call	printf, 0
	 nop
	return	%i7+8
	 nop
	.size	bad_code, .-bad_code
	.section	".rodata"
	.align 8
.LLC2:
	.asciz	"From main: %d"
	.section	".text"
	.align 4
	.global main
	.type	main, #function
	.proc	04
main:
	save	%sp, -120, %sp
	mov	5, %g1
	st	%g1, [%fp-20]
	sethi	%hi(.LLC2), %g1
	or	%g1, %lo(.LLC2), %o0
	ld	[%fp-20], %o1
	call	printf, 0
	 nop
	call	good_code, 0
	 nop
	mov	0, %g1
	mov	%g1, %i0
	return	%i7+8
	 nop
	.size	main, .-main
	.ident	"GCC: (GNU) 4.0.2"
