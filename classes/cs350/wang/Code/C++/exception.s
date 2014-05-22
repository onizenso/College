	.file	"exception.cpp"
	.section	".text"
	.align 4
	.type	_ZSt17__verify_groupingPKcjRKSs, #function
	.proc	04
_ZSt17__verify_groupingPKcjRKSs:
.LLFB1319:
	!#PROLOGUE# 0
	save	%sp, -144, %sp
.LLCFI0:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	st	%i2, [%fp+76]
	ld	[%fp+76], %o0
	call	_ZNKSs4sizeEv, 0
	 nop
	mov	%o0, %g1
	add	%g1, -1, %g1
	st	%g1, [%fp-20]
	add	%fp, -20, %o5
	ld	[%fp+72], %g1
	add	%g1, -1, %g1
	st	%g1, [%fp-28]
	add	%fp, -28, %g1
	mov	%o5, %o0
	mov	%g1, %o1
	call	_ZSt3minIjERKT_S2_S2_, 0
	 nop
	mov	%o0, %g1
	ld	[%g1], %g1
	st	%g1, [%fp-24]
	ld	[%fp-20], %g1
	st	%g1, [%fp-32]
	mov	1, %g1
	stb	%g1, [%fp-33]
	st	%g0, [%fp-40]
.LL2:
	ld	[%fp-40], %o5
	ld	[%fp-24], %g1
	cmp	%o5, %g1
	bgeu	.LL5
	nop
	ldub	[%fp-33], %g1
	and	%g1, 0xff, %g1
	cmp	%g1, 0
	be	.LL5
	nop
	ld	[%fp+76], %o0
	ld	[%fp-32], %o1
	call	_ZNKSsixEj, 0
	 nop
	mov	%o0, %g1
	ldub	[%g1], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %o4
	ld	[%fp+68], %o5
	ld	[%fp-40], %g1
	add	%o5, %g1, %g1
	ldub	[%g1], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %g1
	xor	%o4, %g1, %g1
	subcc	%g0, %g1, %g0
	subx	%g0, -1, %g1
	stb	%g1, [%fp-33]
	ld	[%fp-32], %g1
	add	%g1, -1, %g1
	st	%g1, [%fp-32]
	ld	[%fp-40], %g1
	add	%g1, 1, %g1
	st	%g1, [%fp-40]
	b	.LL2
	 nop
.LL5:
	ld	[%fp-32], %g1
	cmp	%g1, 0
	be	.LL6
	nop
	ldub	[%fp-33], %g1
	and	%g1, 0xff, %g1
	cmp	%g1, 0
	be	.LL6
	nop
	ld	[%fp+76], %o0
	ld	[%fp-32], %o1
	call	_ZNKSsixEj, 0
	 nop
	mov	%o0, %g1
	ldub	[%g1], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %o4
	ld	[%fp+68], %o5
	ld	[%fp-24], %g1
	add	%o5, %g1, %g1
	ldub	[%g1], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %g1
	xor	%o4, %g1, %g1
	subcc	%g0, %g1, %g0
	subx	%g0, -1, %g1
	stb	%g1, [%fp-33]
	ld	[%fp-32], %g1
	add	%g1, -1, %g1
	st	%g1, [%fp-32]
	b	.LL5
	 nop
.LL6:
	ld	[%fp+76], %o0
	mov	0, %o1
	call	_ZNKSsixEj, 0
	 nop
	mov	%o0, %g1
	ldub	[%g1], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %o4
	ld	[%fp+68], %o5
	ld	[%fp-24], %g1
	add	%o5, %g1, %g1
	ldub	[%g1], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %g1
	cmp	%o4, %g1
	bg	.LL8
	nop
	ldub	[%fp-33], %g1
	and	%g1, 0xff, %g1
	and	%g1, 1, %g1
	stb	%g1, [%fp-41]
	b	.LL9
	 nop
.LL8:
	stb	%g0, [%fp-41]
.LL9:
	ldub	[%fp-41], %g1
	stb	%g1, [%fp-33]
	ldub	[%fp-33], %g1
	and	%g1, 0xff, %g1
	mov	%g1, %i0
	ret
	restore
.LLFE1319:
	.size	_ZSt17__verify_groupingPKcjRKSs, .-_ZSt17__verify_groupingPKcjRKSs
	.local	_ZSt8__ioinit
	.common	_ZSt8__ioinit,1,1
	.global _Unwind_Resume
	.section	".rodata"
	.align 8
.LLC0:
	.asciz	"Function throwException\n"
	.align 8
.LLC2:
	.asciz	"Exception handled in function throwException\n"
	.align 8
.LLC4:
	.asciz	"This will only print if there is no exception\n"
	.section	".text"
	.align 4
	.global _Z14throwExceptionv
	.type	_Z14throwExceptionv, #function
	.proc	020
_Z14throwExceptionv:
.LLFB1400:
	!#PROLOGUE# 0
	save	%sp, -136, %sp
.LLCFI1:
	!#PROLOGUE# 1
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC0), %g1
	or	%g1, %lo(.LLC0), %o1
.LLEHB0:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	4, %o0
	call	__cxa_allocate_exception, 0
	 nop
	mov	%o0, %g1
	mov	1, %o5
	st	%o5, [%g1]
.LL11:
	mov	%g1, %o0
	sethi	%hi(_ZTIi), %g1
	or	%g1, %lo(_ZTIi), %o1
	mov	0, %o2
	call	__cxa_throw, 0
	 nop
.LLEHE0:
.LL13:
.LL33:
	st	%i0, [%fp-32]
	st	%i1, [%fp-36]
	ld	[%fp-36], %g1
	cmp	%g1, 2
	be	.LL16
	nop
	ld	[%fp-36], %g1
	cmp	%g1, 1
	be	.LL27
	nop
	ld	[%fp-32], %o0
.LLEHB1:
	call	_Unwind_Resume, 0
	 nop
.LLEHE1:
.LL16:
	ld	[%fp-32], %o0
	call	__cxa_begin_catch, 0
	 nop
	mov	%o0, %o5
	add	%fp, -24, %g1
	mov	%g1, %o0
	mov	%o5, %o1
	call	_ZNSt9exceptionC1ERKS_, 0
	 nop
.LL17:
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC2), %g1
	or	%g1, %lo(.LLC2), %o1
.LLEHB2:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	call	__cxa_rethrow, 0
	 nop
.LLEHE2:
.LL31:
	st	%i0, [%fp-32]
.LL19:
	ld	[%fp-32], %l0
	add	%fp, -24, %g1
	mov	%g1, %o0
	call	_ZNSt9exceptionD1Ev, 0
	 nop
	st	%l0, [%fp-32]
.LL21:
.LL32:
.LL23:
	ld	[%fp-32], %l0
	call	__cxa_end_catch, 0
	 nop
	st	%l0, [%fp-32]
.LL25:
	ld	[%fp-32], %o0
.LLEHB3:
	call	_Unwind_Resume, 0
	 nop
.LL27:
	ld	[%fp-32], %o0
	call	__cxa_begin_catch, 0
	 nop
	mov	%o0, %g1
	ld	[%g1], %g1
	st	%g1, [%fp-28]
.LL28:
	call	__cxa_end_catch, 0
	 nop
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC4), %g1
	or	%g1, %lo(.LLC4), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
.LLEHE3:
	nop
	ret
	restore
.LLFE1400:
	.size	_Z14throwExceptionv, .-_Z14throwExceptionv
	.section	".gcc_except_table",#alloc,#write
	.align 4
.LLLSDA1400:
	.byte	0xff
	.byte	0x50
	.byte	0x45
	.byte	0x3
	.byte	0x34
	.uaword	.LLEHB0-.LLFB1400
	.uaword	.LLEHE0-.LLEHB0
	.uaword	.LL33-.LLFB1400
	.byte	0x3
	.uaword	.LLEHB1-.LLFB1400
	.uaword	.LLEHE1-.LLEHB1
	.uaword	0x0
	.byte	0x0
	.uaword	.LLEHB2-.LLFB1400
	.uaword	.LLEHE2-.LLEHB2
	.uaword	.LL31-.LLFB1400
	.byte	0x0
	.uaword	.LLEHB3-.LLFB1400
	.uaword	.LLEHE3-.LLEHB3
	.uaword	0x0
	.byte	0x0
	.byte	0x1
	.byte	0x0
	.byte	0x2
	.byte	0x7d
	.align 4
	.long	_ZTISt9exception
	.long	_ZTIi
	.section	".text"
	.section	".gnu.linkonce.t._ZNSt9exceptionC1ERKS_",#alloc,#execinstr
	.align 4
	.weak	_ZNSt9exceptionC1ERKS_
	.type	_ZNSt9exceptionC1ERKS_, #function
	.proc	020
_ZNSt9exceptionC1ERKS_:
.LLFB1403:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI2:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+68], %g1
	sethi	%hi(_ZTVSt9exception+8), %i5
	or	%i5, %lo(_ZTVSt9exception+8), %i5
	st	%i5, [%g1]
.LL35:
	ret
	restore
.LLFE1403:
	.size	_ZNSt9exceptionC1ERKS_, .-_ZNSt9exceptionC1ERKS_
	.section	".rodata"
	.align 8
.LLC7:
	.asciz	"This should not print\n"
	.align 8
.LLC8:
	.asciz	"Exception handled in main\n"
	.align 8
.LLC9:
	.asciz	"Program control continues after catch in main"
	.align 8
.LLC5:
	.long	1074423398
	.long	1717986918
	.align 8
.LLC6:
	.long	0
	.long	0
	.section	".text"
	.align 4
	.global main
	.type	main, #function
	.proc	04
main:
.LLFB1404:
	!#PROLOGUE# 0
	save	%sp, -144, %sp
.LLCFI3:
	!#PROLOGUE# 1
	sethi	%hi(.LLC5), %g1
	or	%g1, %lo(.LLC5), %g1
	ld	[%g1], %f8
	ld	[%g1+4], %f9
	std	%f8, [%fp-24]
	sethi	%hi(.LLC6), %g1
	or	%g1, %lo(.LLC6), %g1
	ld	[%g1], %f8
	ld	[%g1+4], %f9
	std	%f8, [%fp-32]
	ldd	[%fp-24], %f10
	ldd	[%fp-32], %f8
	fdivd	%f10, %f8, %f8
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	std	%f8, [%fp-16]
	ldd	[%fp-16], %o4
	mov	%o4, %o1
	mov	%o5, %o2
.LLEHB4:
	call	_ZNSolsEd, 0
	 nop
	call	_Z14throwExceptionv, 0
	 nop
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC7), %g1
	or	%g1, %lo(.LLC7), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
.LLEHE4:
	b	.LL38
	 nop
.LL53:
	st	%i0, [%fp-44]
	mov	%i1, %g1
	cmp	%g1, 1
	be	.LL39
	nop
	ld	[%fp-44], %o0
.LLEHB5:
	call	_Unwind_Resume, 0
	 nop
.LLEHE5:
.LL39:
	ld	[%fp-44], %o0
	call	__cxa_begin_catch, 0
	 nop
	mov	%o0, %o5
	add	%fp, -40, %g1
	mov	%g1, %o0
	mov	%o5, %o1
	call	_ZNSt9exceptionC1ERKS_, 0
	 nop
.LL40:
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC8), %g1
	or	%g1, %lo(.LLC8), %o1
.LLEHB6:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
.LLEHE6:
	b	.LL43
	 nop
.LL51:
	st	%i0, [%fp-44]
.LL42:
	ld	[%fp-44], %l0
	add	%fp, -40, %g1
	mov	%g1, %o0
	call	_ZNSt9exceptionD1Ev, 0
	 nop
	st	%l0, [%fp-44]
.LL44:
	b	.LL46
	 nop
.LL43:
	add	%fp, -40, %g1
	mov	%g1, %o0
	call	_ZNSt9exceptionD1Ev, 0
	 nop
	b	.LL47
	 nop
.LL52:
.LL46:
	ld	[%fp-44], %l0
	call	__cxa_end_catch, 0
	 nop
	st	%l0, [%fp-44]
.LL48:
	ld	[%fp-44], %o0
.LLEHB7:
	call	_Unwind_Resume, 0
	 nop
.LL47:
	call	__cxa_end_catch, 0
	 nop
.LL38:
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC9), %g1
	or	%g1, %lo(.LLC9), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_), %g1
	or	%g1, %lo(_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_), %o1
	call	_ZNSolsEPFRSoS_E, 0
	 nop
.LLEHE7:
	mov	0, %g1
	mov	%g1, %i0
	ret
	restore
.LLFE1404:
	.size	main, .-main
	.section	".gcc_except_table",#alloc,#write
	.align 4
.LLLSDA1404:
	.byte	0xff
	.byte	0x50
	.byte	0x3d
	.byte	0x3
	.byte	0x34
	.uaword	.LLEHB4-.LLFB1404
	.uaword	.LLEHE4-.LLEHB4
	.uaword	.LL53-.LLFB1404
	.byte	0x1
	.uaword	.LLEHB5-.LLFB1404
	.uaword	.LLEHE5-.LLEHB5
	.uaword	0x0
	.byte	0x0
	.uaword	.LLEHB6-.LLFB1404
	.uaword	.LLEHE6-.LLEHB6
	.uaword	.LL51-.LLFB1404
	.byte	0x0
	.uaword	.LLEHB7-.LLFB1404
	.uaword	.LLEHE7-.LLEHB7
	.uaword	0x0
	.byte	0x0
	.byte	0x1
	.byte	0x0
	.align 4
	.long	_ZTISt9exception
	.section	".text"
	.section	".gnu.linkonce.t._ZSt3minIjERKT_S2_S2_",#alloc,#execinstr
	.align 4
	.weak	_ZSt3minIjERKT_S2_S2_
	.type	_ZSt3minIjERKT_S2_S2_, #function
	.proc	0116
_ZSt3minIjERKT_S2_S2_:
.LLFB1405:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
.LLCFI4:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+72], %g1
	ld	[%fp+68], %i5
	ld	[%g1], %i4
	ld	[%i5], %g1
	cmp	%i4, %g1
	bgeu	.LL55
	nop
	ld	[%fp+72], %g1
	st	%g1, [%fp-20]
	b	.LL54
	 nop
.LL55:
	ld	[%fp+68], %g1
	st	%g1, [%fp-20]
.LL54:
	ld	[%fp-20], %i0
	ret
	restore
.LLFE1405:
	.size	_ZSt3minIjERKT_S2_S2_, .-_ZSt3minIjERKT_S2_S2_
	.section	".text"
	.align 4
	.type	_Z41__static_initialization_and_destruction_0ii, #function
	.proc	020
_Z41__static_initialization_and_destruction_0ii:
.LLFB1412:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI5:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+72], %g1
	sethi	%hi(64512), %o5
	or	%o5, 1023, %o5
	cmp	%g1, %o5
	bne	.LL57
	nop
	ld	[%fp+68], %g1
	cmp	%g1, 1
	bne	.LL57
	nop
	sethi	%hi(_ZSt8__ioinit), %g1
	or	%g1, %lo(_ZSt8__ioinit), %o0
	call	_ZNSt8ios_base4InitC1Ev, 0
	 nop
.LL57:
	ld	[%fp+72], %g1
	sethi	%hi(64512), %o5
	or	%o5, 1023, %o5
	cmp	%g1, %o5
	bne	.LL56
	nop
	ld	[%fp+68], %g1
	cmp	%g1, 0
	bne	.LL56
	nop
	sethi	%hi(_ZSt8__ioinit), %g1
	or	%g1, %lo(_ZSt8__ioinit), %o0
	call	_ZNSt8ios_base4InitD1Ev, 0
	 nop
.LL56:
	nop
	ret
	restore
.LLFE1412:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.align 4
	.type	_GLOBAL__I__Z14throwExceptionv, #function
	.proc	020
_GLOBAL__I__Z14throwExceptionv:
.LLFB1413:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI6:
	!#PROLOGUE# 1
	mov	1, %o0
	sethi	%hi(64512), %g1
	or	%g1, 1023, %o1
	call	_Z41__static_initialization_and_destruction_0ii, 0
	 nop
	nop
	ret
	restore
.LLFE1413:
	.size	_GLOBAL__I__Z14throwExceptionv, .-_GLOBAL__I__Z14throwExceptionv
	.section	".ctors",#alloc,#write
	.align 4
	.long	_GLOBAL__I__Z14throwExceptionv
	.section	".text"
	.align 4
	.type	_GLOBAL__D__Z14throwExceptionv, #function
	.proc	020
_GLOBAL__D__Z14throwExceptionv:
.LLFB1414:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI7:
	!#PROLOGUE# 1
	mov	0, %o0
	sethi	%hi(64512), %g1
	or	%g1, 1023, %o1
	call	_Z41__static_initialization_and_destruction_0ii, 0
	 nop
	nop
	ret
	restore
.LLFE1414:
	.size	_GLOBAL__D__Z14throwExceptionv, .-_GLOBAL__D__Z14throwExceptionv
	.section	".dtors",#alloc,#write
	.align 4
	.long	_GLOBAL__D__Z14throwExceptionv
	.weak	pthread_mutex_unlock
	.weak	pthread_mutex_trylock
	.weak	pthread_mutex_lock
	.weak	pthread_create
	.weak	pthread_setspecific
	.weak	pthread_getspecific
	.weak	pthread_key_delete
	.weak	pthread_key_create
	.weak	pthread_once
	.section	".eh_frame",#alloc,#write
.LLframe1:
	.uaword	.LLECIE1-.LLSCIE1
.LLSCIE1:
	.uaword	0x0
	.byte	0x1
	.asciz	"zPL"
	.byte	0x1
	.byte	0x7c
	.byte	0xf
	.byte	0x8
	.byte	0x50
	.align 4
	.long	__gxx_personality_v0
	.byte	0x0
	.byte	0xc
	.byte	0xe
	.byte	0x0
	.align 4
.LLECIE1:
.LLSFDE1:
	.uaword	.LLEFDE1-.LLASFDE1
.LLASFDE1:
	.uaword	.LLASFDE1-.LLframe1
	.uaword	.LLFB1319
	.uaword	.LLFE1319-.LLFB1319
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI0-.LLFB1319
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE1:
.LLSFDE3:
	.uaword	.LLEFDE3-.LLASFDE3
.LLASFDE3:
	.uaword	.LLASFDE3-.LLframe1
	.uaword	.LLFB1400
	.uaword	.LLFE1400-.LLFB1400
	.byte	0x4
	.uaword	.LLLSDA1400
	.byte	0x4
	.uaword	.LLCFI1-.LLFB1400
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE3:
.LLSFDE7:
	.uaword	.LLEFDE7-.LLASFDE7
.LLASFDE7:
	.uaword	.LLASFDE7-.LLframe1
	.uaword	.LLFB1404
	.uaword	.LLFE1404-.LLFB1404
	.byte	0x4
	.uaword	.LLLSDA1404
	.byte	0x4
	.uaword	.LLCFI3-.LLFB1404
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE7:
.LLSFDE11:
	.uaword	.LLEFDE11-.LLASFDE11
.LLASFDE11:
	.uaword	.LLASFDE11-.LLframe1
	.uaword	.LLFB1412
	.uaword	.LLFE1412-.LLFB1412
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI5-.LLFB1412
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE11:
.LLSFDE13:
	.uaword	.LLEFDE13-.LLASFDE13
.LLASFDE13:
	.uaword	.LLASFDE13-.LLframe1
	.uaword	.LLFB1413
	.uaword	.LLFE1413-.LLFB1413
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI6-.LLFB1413
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE13:
.LLSFDE15:
	.uaword	.LLEFDE15-.LLASFDE15
.LLASFDE15:
	.uaword	.LLASFDE15-.LLframe1
	.uaword	.LLFB1414
	.uaword	.LLFE1414-.LLFB1414
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI7-.LLFB1414
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE15:
	.ident	"GCC: (GNU) 3.4.5"
