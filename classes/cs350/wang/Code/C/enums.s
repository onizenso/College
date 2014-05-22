	.file	"enums.c"
	.global .div
	.section	".rodata"
	.align 8
.LLC9:
	.asciz	"enum green (-7): %i\n"
	.align 8
.LLC10:
	.asciz	"enum black (15): %i\n"
	.align 8
.LLC11:
	.asciz	"enum white (green+2): %i\n"
	.section	".text"
	.align 4
	.type	test.0, #function
	.proc	020
test.0:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
	!#PROLOGUE# 1
	st	%g2, [%fp-20]
	mov	%i0, %g1
	stb	%g1, [%fp+68]
	sethi	%hi(.LLC9), %g1
	or	%g1, %lo(.LLC9), %o0
	mov	-7, %o1
	call	printf, 0
	 nop
	sethi	%hi(.LLC10), %g1
	or	%g1, %lo(.LLC10), %o0
	mov	15, %o1
	call	printf, 0
	 nop
	sethi	%hi(.LLC11), %g1
	or	%g1, %lo(.LLC11), %o0
	mov	-5, %o1
	call	printf, 0
	 nop
	nop
	ret
	restore
	.size	test.0, .-test.0
	.section	".rodata"
	.align 8
.LLC12:
	.asciz	"const value changed from 3 to 4: %i\n"
	.section	".text"
	.align 4
	.type	test2.1, #function
	.proc	020
test2.1:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
	!#PROLOGUE# 1
	st	%g2, [%fp-20]
	st	%i0, [%fp+68]
	ld	[%fp+68], %o5
	ld	[%fp+68], %g1
	ld	[%g1], %g1
	add	%g1, 1, %g1
	st	%g1, [%o5]
	ld	[%fp+68], %o5
	sethi	%hi(.LLC12), %g1
	or	%g1, %lo(.LLC12), %o0
	ld	[%o5], %o1
	call	printf, 0
	 nop
	nop
	ret
	restore
	.size	test2.1, .-test2.1
	.section	".rodata"
	.align 8
.LLC13:
	.asciz	"c: %i\n"
	.section	".text"
	.align 4
	.type	test3.2, #function
	.proc	020
test3.2:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
	!#PROLOGUE# 1
	st	%g2, [%fp-20]
	st	%i0, [%fp+68]
	sethi	%hi(.LLC13), %g1
	or	%g1, %lo(.LLC13), %o0
	ld	[%fp+68], %o1
	call	printf, 0
	 nop
	nop
	ret
	restore
	.size	test3.2, .-test3.2
	.section	".rodata"
	.align 8
.LLC2:
	.asciz	"10.5: %d \n"
	.align 8
.LLC3:
	.asciz	"float c: %f \n"
	.align 8
.LLC4:
	.asciz	"int a: %d \n"
	.align 8
.LLC5:
	.asciz	"a= a++: %d \n"
	.align 8
.LLC6:
	.asciz	"%d / %d = %f\n"
	.align 8
.LLC7:
	.asciz	"%d / %f = %f\n"
	.align 8
.LLC8:
	.asciz	"%f / %f = %d\n"
	.align 4
.LLC0:
	.long	1093140480
	.align 4
.LLC1:
	.long	1077936128
	.section	".text"
	.align 4
	.global main
	.type	main, #function
	.proc	04
main:
	!#PROLOGUE# 0
	save	%sp, -152, %sp
	!#PROLOGUE# 1
	mov	10, %g1
	st	%g1, [%fp-24]
	sethi	%hi(.LLC0), %g1
	or	%g1, %lo(.LLC0), %g1
	ld	[%g1], %f8
	st	%f8, [%fp-28]
	sethi	%hi(.LLC1), %g1
	or	%g1, %lo(.LLC1), %g1
	ld	[%g1], %f8
	st	%f8, [%fp-32]
	mov	97, %g1
	stb	%g1, [%fp-33]
	add	%fp, -44, %g1
	st	%g1, [%fp-48]
	ld	[%fp-28], %f8
	fstoi	%f8, %f8
	st	%f8, [%fp-20]
	sethi	%hi(.LLC2), %g1
	or	%g1, %lo(.LLC2), %o0
	ld	[%fp-20], %o1
	call	printf, 0
	 nop
	ld	[%fp-20], %f8
	fitos	%f8, %f8
	st	%f8, [%fp-28]
	ld	[%fp-28], %f8
	fstod	%f8, %f8
	sethi	%hi(.LLC3), %g1
	or	%g1, %lo(.LLC3), %o0
	std	%f8, [%fp-16]
	ldd	[%fp-16], %o4
	mov	%o4, %o1
	mov	%o5, %o2
	call	printf, 0
	 nop
	ldub	[%fp-33], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %g1
	st	%g1, [%fp-20]
	sethi	%hi(.LLC4), %g1
	or	%g1, %lo(.LLC4), %o0
	ld	[%fp-20], %o1
	call	printf, 0
	 nop
	add	%fp, -20, %o5
	ld	[%o5], %g1
	mov	%g1, %o4
	add	%g1, 1, %g1
	st	%g1, [%o5]
	st	%o4, [%fp-20]
	sethi	%hi(.LLC5), %g1
	or	%g1, %lo(.LLC5), %o0
	ld	[%fp-20], %o1
	call	printf, 0
	 nop
	ld	[%fp-20], %o0
	ld	[%fp-24], %o1
	call	.div, 0
	 nop
	mov	%o0, %g1
	st	%g1, [%fp-16]
	ld	[%fp-16], %f9
	fitos	%f9, %f8
	st	%f8, [%fp-40]
	ld	[%fp-40], %f8
	fstod	%f8, %f8
	sethi	%hi(.LLC6), %g1
	or	%g1, %lo(.LLC6), %o0
	ld	[%fp-20], %o1
	ld	[%fp-24], %o2
	std	%f8, [%fp-16]
	ldd	[%fp-16], %l0
	mov	%l0, %o3
	mov	%l1, %o4
	call	printf, 0
	 nop
	ld	[%fp-20], %f8
	fitos	%f8, %f9
	ld	[%fp-28], %f8
	fdivs	%f9, %f8, %f8
	st	%f8, [%fp-40]
	ld	[%fp-28], %f8
	fstod	%f8, %f10
	ld	[%fp-40], %f8
	fstod	%f8, %f8
	sethi	%hi(.LLC7), %g1
	or	%g1, %lo(.LLC7), %o0
	ld	[%fp-20], %o1
	std	%f10, [%fp-16]
	ldd	[%fp-16], %o2
	std	%f8, [%fp-16]
	ldd	[%fp-16], %o4
	call	printf, 0
	 nop
	ld	[%fp-28], %f9
	ld	[%fp-32], %f8
	fdivs	%f9, %f8, %f8
	fstoi	%f8, %f8
	st	%f8, [%fp-44]
	ld	[%fp-28], %f8
	fstod	%f8, %f10
	ld	[%fp-32], %f8
	fstod	%f8, %f8
	sethi	%hi(.LLC8), %g1
	or	%g1, %lo(.LLC8), %o0
	std	%f10, [%fp-16]
	ldd	[%fp-16], %o4
	mov	%o4, %o1
	mov	%o5, %o2
	std	%f8, [%fp-16]
	ldd	[%fp-16], %l0
	mov	%l0, %o3
	mov	%l1, %o4
	ld	[%fp-44], %o5
	call	printf, 0
	 nop
	st	%g0, [%fp-52]
	st	%g0, [%fp-56]
	add	%fp, -16, %g2
	mov	15, %o0
	call	test.0, 0
	 nop
	add	%fp, -16, %g2
	ld	[%fp-48], %o0
	call	test2.1, 0
	 nop
	add	%fp, -16, %g2
	mov	15, %o0
	call	test3.2, 0
	 nop
	mov	0, %g1
	mov	%g1, %i0
	ret
	restore
	.size	main, .-main
	.ident	"GCC: (GNU) 3.4.5"
