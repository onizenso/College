	.file	"new_custom.cpp"
	.section	".text"
	.align 4
	.type	_Z18__exchange_and_addPVii, #function
	.proc	04
_Z18__exchange_and_addPVii:
.LLFB54:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
.LLCFI0:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	sethi	%hi(_ZN16__Atomicity_lockILi0EE17_S_atomicity_lockE), %g1
	or	%g1, %lo(_ZN16__Atomicity_lockILi0EE17_S_atomicity_lockE), %g1
	1:	ldstub	[%g1], %o5
		cmp	%o5, 0
		bne	1b
		 nop
	mov	%o5, %g1
	st	%g1, [%fp-24]
	ld	[%fp+68], %g1
	ld	[%g1], %g1
	st	%g1, [%fp-20]
	ld	[%fp+68], %i4
	ld	[%fp+68], %g1
	ld	[%g1], %i5
	ld	[%fp+72], %g1
	add	%i5, %g1, %g1
	st	%g1, [%i4]
	sethi	%hi(_ZN16__Atomicity_lockILi0EE17_S_atomicity_lockE), %g1
	or	%g1, %lo(_ZN16__Atomicity_lockILi0EE17_S_atomicity_lockE), %g1
	stb	%g0, [%g1]
	ld	[%fp-20], %g1
	mov	%g1, %i0
	ret
	restore
.LLFE54:
	.size	_Z18__exchange_and_addPVii, .-_Z18__exchange_and_addPVii
	.align 4
	.type	_Z12__atomic_addPVii, #function
	.proc	020
_Z12__atomic_addPVii:
.LLFB56:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
.LLCFI1:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	sethi	%hi(_ZN16__Atomicity_lockILi0EE17_S_atomicity_lockE), %g1
	or	%g1, %lo(_ZN16__Atomicity_lockILi0EE17_S_atomicity_lockE), %g1
	1:	ldstub	[%g1], %o5
		cmp	%o5, 0
		bne	1b
		 nop
	mov	%o5, %g1
	st	%g1, [%fp-20]
	ld	[%fp+68], %i4
	ld	[%fp+68], %g1
	ld	[%g1], %i5
	ld	[%fp+72], %g1
	add	%i5, %g1, %g1
	st	%g1, [%i4]
	sethi	%hi(_ZN16__Atomicity_lockILi0EE17_S_atomicity_lockE), %g1
	or	%g1, %lo(_ZN16__Atomicity_lockILi0EE17_S_atomicity_lockE), %g1
	stb	%g0, [%g1]
	ret
	restore
.LLFE56:
	.size	_Z12__atomic_addPVii, .-_Z12__atomic_addPVii
	.local	_ZSt8__ioinit
	.common	_ZSt8__ioinit,1,1
	.section	".rodata"
	.align 8
.LLC0:
	.asciz	"customNewHandler was called"
	.section	".text"
	.align 4
	.global _Z16customNewHandlerv
	.type	_Z16customNewHandlerv, #function
	.proc	020
_Z16customNewHandlerv:
.LLFB1436:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI2:
	!#PROLOGUE# 1
	sethi	%hi(_ZSt4cerr), %g1
	or	%g1, %lo(_ZSt4cerr), %o0
	sethi	%hi(.LLC0), %g1
	or	%g1, %lo(.LLC0), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	call	abort, 0
	 nop
	nop
.LLFE1436:
	.size	_Z16customNewHandlerv, .-_Z16customNewHandlerv
	.section	".rodata"
	.align 8
.LLC1:
	.asciz	"Allocated 5000000 doubles in ptr[ "
	.align 8
.LLC2:
	.asciz	" ]\n"
	.section	".text"
	.align 4
	.global main
	.type	main, #function
	.proc	04
main:
.LLFB1438:
	!#PROLOGUE# 0
	save	%sp, -320, %sp
.LLCFI3:
	!#PROLOGUE# 1
	sethi	%hi(_Z16customNewHandlerv), %g1
	or	%g1, %lo(_Z16customNewHandlerv), %o0
	call	_ZSt15set_new_handlerPFvvE, 0
	 nop
	st	%g0, [%fp-220]
.LL5:
	ld	[%fp-220], %g1
	cmp	%g1, 49
	ble	.LL8
	nop
	b	.LL6
	 nop
.LL8:
	ld	[%fp-220], %g1
	sll	%g1, 2, %o5
	add	%fp, -16, %g1
	add	%o5, %g1, %l0
	sethi	%hi(39999488), %g1
	or	%g1, 512, %o0
	call	_Znaj, 0
	 nop
	st	%o0, [%l0-200]
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC1), %g1
	or	%g1, %lo(.LLC1), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	ld	[%fp-220], %o1
	call	_ZNSolsEi, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC2), %g1
	or	%g1, %lo(.LLC2), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	ld	[%fp-220], %g1
	add	%g1, 1, %g1
	st	%g1, [%fp-220]
	b	.LL5
	 nop
.LL6:
	mov	0, %g1
	mov	%g1, %i0
	ret
	restore
.LLFE1438:
	.size	main, .-main
	.align 4
	.type	_Z41__static_initialization_and_destruction_0ii, #function
	.proc	020
_Z41__static_initialization_and_destruction_0ii:
.LLFB1444:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI4:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+72], %g1
	sethi	%hi(64512), %o5
	or	%o5, 1023, %o5
	cmp	%g1, %o5
	bne	.LL10
	nop
	ld	[%fp+68], %g1
	cmp	%g1, 1
	bne	.LL10
	nop
	sethi	%hi(_ZSt8__ioinit), %g1
	or	%g1, %lo(_ZSt8__ioinit), %o0
	call	_ZNSt8ios_base4InitC1Ev, 0
	 nop
.LL10:
	ld	[%fp+72], %g1
	sethi	%hi(64512), %o5
	or	%o5, 1023, %o5
	cmp	%g1, %o5
	bne	.LL9
	nop
	ld	[%fp+68], %g1
	cmp	%g1, 0
	bne	.LL9
	nop
	sethi	%hi(_ZSt8__ioinit), %g1
	or	%g1, %lo(_ZSt8__ioinit), %o0
	call	_ZNSt8ios_base4InitD1Ev, 0
	 nop
.LL9:
	nop
	ret
	restore
.LLFE1444:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.weak	_ZN16__Atomicity_lockILi0EE17_S_atomicity_lockE
	.section	".gnu.linkonce.d._ZN16__Atomicity_lockILi0EE17_S_atomicity_lockE",#alloc,#write
	.type	_ZN16__Atomicity_lockILi0EE17_S_atomicity_lockE, #object
	.size	_ZN16__Atomicity_lockILi0EE17_S_atomicity_lockE, 1
_ZN16__Atomicity_lockILi0EE17_S_atomicity_lockE:
	.byte	0
	.weak	_ZNSt15basic_streambufIcSt11char_traitsIcEE13_S_pback_sizeE
	.section	".gnu.linkonce.r._ZNSt15basic_streambufIcSt11char_traitsIcEE13_S_pback_sizeE",#alloc
	.align 4
	.type	_ZNSt15basic_streambufIcSt11char_traitsIcEE13_S_pback_sizeE, #object
	.size	_ZNSt15basic_streambufIcSt11char_traitsIcEE13_S_pback_sizeE, 4
_ZNSt15basic_streambufIcSt11char_traitsIcEE13_S_pback_sizeE:
	.long	1
	.section	".text"
	.align 4
	.type	_GLOBAL__I__Z16customNewHandlerv, #function
	.proc	020
_GLOBAL__I__Z16customNewHandlerv:
.LLFB1446:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI5:
	!#PROLOGUE# 1
	mov	1, %o0
	sethi	%hi(64512), %g1
	or	%g1, 1023, %o1
	call	_Z41__static_initialization_and_destruction_0ii, 0
	 nop
	nop
	ret
	restore
.LLFE1446:
	.size	_GLOBAL__I__Z16customNewHandlerv, .-_GLOBAL__I__Z16customNewHandlerv
	.section	".ctors",#alloc,#write
	.align 4
	.long	_GLOBAL__I__Z16customNewHandlerv
	.section	".text"
	.align 4
	.type	_GLOBAL__D__Z16customNewHandlerv, #function
	.proc	020
_GLOBAL__D__Z16customNewHandlerv:
.LLFB1448:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI6:
	!#PROLOGUE# 1
	mov	0, %o0
	sethi	%hi(64512), %g1
	or	%g1, 1023, %o1
	call	_Z41__static_initialization_and_destruction_0ii, 0
	 nop
	nop
	ret
	restore
.LLFE1448:
	.size	_GLOBAL__D__Z16customNewHandlerv, .-_GLOBAL__D__Z16customNewHandlerv
	.section	".dtors",#alloc,#write
	.align 4
	.long	_GLOBAL__D__Z16customNewHandlerv
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
	.asciz	"zP"
	.byte	0x1
	.byte	0x7c
	.byte	0xf
	.byte	0x8
	.byte	0x50
	.align 4
	.long	__gxx_personality_v0
	.byte	0xc
	.byte	0xe
	.byte	0x0
	.align 4
.LLECIE1:
.LLSFDE5:
	.uaword	.LLEFDE5-.LLASFDE5
.LLASFDE5:
	.uaword	.LLASFDE5-.LLframe1
	.uaword	.LLFB1436
	.uaword	.LLFE1436-.LLFB1436
	.byte	0x0
	.byte	0x4
	.uaword	.LLCFI2-.LLFB1436
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE5:
.LLSFDE7:
	.uaword	.LLEFDE7-.LLASFDE7
.LLASFDE7:
	.uaword	.LLASFDE7-.LLframe1
	.uaword	.LLFB1438
	.uaword	.LLFE1438-.LLFB1438
	.byte	0x0
	.byte	0x4
	.uaword	.LLCFI3-.LLFB1438
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE7:
.LLSFDE9:
	.uaword	.LLEFDE9-.LLASFDE9
.LLASFDE9:
	.uaword	.LLASFDE9-.LLframe1
	.uaword	.LLFB1444
	.uaword	.LLFE1444-.LLFB1444
	.byte	0x0
	.byte	0x4
	.uaword	.LLCFI4-.LLFB1444
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE9:
.LLSFDE11:
	.uaword	.LLEFDE11-.LLASFDE11
.LLASFDE11:
	.uaword	.LLASFDE11-.LLframe1
	.uaword	.LLFB1446
	.uaword	.LLFE1446-.LLFB1446
	.byte	0x0
	.byte	0x4
	.uaword	.LLCFI5-.LLFB1446
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
	.uaword	.LLFB1448
	.uaword	.LLFE1448-.LLFB1448
	.byte	0x0
	.byte	0x4
	.uaword	.LLCFI6-.LLFB1448
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE13:
	.ident	"GCC: (GNU) 3.3.3"
