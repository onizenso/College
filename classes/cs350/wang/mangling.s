	.file	"mangling.cpp"
	.global .umul
	.section	".text"
	.align 4
	.global _Z6squarei
	.type	_Z6squarei, #function
	.proc	04
_Z6squarei:
.LLFB3:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI0:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	ld	[%fp+68], %o0
	ld	[%fp+68], %o1
	call	.umul, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %i0
	ret
	restore
.LLFE3:
	.size	_Z6squarei, .-_Z6squarei
	.align 4
	.global _Z6squared
	.type	_Z6squared, #function
	.proc	07
_Z6squared:
.LLFB5:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
.LLCFI1:
	!#PROLOGUE# 1
	std	%i0, [%fp-24]
	ldd	[%fp-24], %f10
	ldd	[%fp-24], %f8
	fmuld	%f10, %f8, %f8
	fmovs	%f8, %f0
	fmovs	%f9, %f1
	ret
	restore
.LLFE5:
	.size	_Z6squared, .-_Z6squared
	.align 4
	.global _Z7nothingifcPi
	.type	_Z7nothingifcPi, #function
	.proc	020
_Z7nothingifcPi:
.LLFB7:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
.LLCFI2:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	mov	%i2, %g1
	st	%i3, [%fp+80]
	stb	%g1, [%fp-17]
	ret
	restore
.LLFE7:
	.size	_Z7nothingifcPi, .-_Z7nothingifcPi
	.align 4
	.global _Z7nothingciPfPd
	.type	_Z7nothingciPfPd, #function
	.proc	0102
_Z7nothingciPfPd:
.LLFB9:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
.LLCFI3:
	!#PROLOGUE# 1
	mov	%i0, %g1
	st	%i1, [%fp+72]
	st	%i2, [%fp+76]
	st	%i3, [%fp+80]
	stb	%g1, [%fp-17]
	mov	0, %g1
	mov	%g1, %i0
	ret
	restore
.LLFE9:
	.size	_Z7nothingciPfPd, .-_Z7nothingciPfPd
	.section	".rodata"
	.align 8
.LLC0:
	.long	1074528256
	.long	0
	.section	".text"
	.align 4
	.global main
	.type	main, #function
	.proc	04
main:
.LLFB11:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
.LLCFI4:
	!#PROLOGUE# 1
	sethi	%hi(.LLC0), %g1
	or	%g1, %lo(.LLC0), %g1
	ld	[%g1], %f8
	ld	[%g1+4], %f9
	std	%f8, [%fp-24]
	ldd	[%fp-24], %o0
	call	_Z6squared, 0
	 nop
	mov	3, %o0
	call	_Z6squarei, 0
	 nop
	mov	0, %g1
	mov	%g1, %i0
	ret
	restore
.LLFE11:
	.size	main, .-main
	.ident	"GCC: (GNU) 3.3.3"
