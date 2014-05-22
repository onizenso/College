	.file	"DListTest.cpp"
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
	.section	".rodata"
	.align 8
.LLC0:
	.asciz	"+====================================+"
	.align 8
.LLC1:
	.asciz	"|      Test of Linked List           |"
	.align 8
.LLC2:
	.asciz	"|         Class Template             |"
	.align 8
.LLC3:
	.asciz	"| L/l: Display items of two  list    |"
	.align 8
.LLC4:
	.asciz	"+------------------------------------+"
	.align 8
.LLC5:
	.asciz	"| I/i: Insert 1 item at each list at |"
	.align 8
.LLC6:
	.asciz	"|      a random possition            |"
	.align 8
.LLC7:
	.asciz	"| D/d: Delete an item from each list |"
	.align 8
.LLC8:
	.asciz	"|      at random position            |"
	.align 8
.LLC9:
	.asciz	"| C/=: Test copy constructor and     |"
	.align 8
.LLC10:
	.asciz	"|      assignment operator           |"
	.align 8
.LLC11:
	.asciz	"| S/s: Test Stack, a derived class   |"
	.align 8
.LLC12:
	.asciz	"|      template from DList           |"
	.align 8
.LLC13:
	.asciz	"| U/u: Test Queue, a derived class   |"
	.align 8
.LLC14:
	.asciz	"| O/o: Test Sorted Queue, a derived  |"
	.align 8
.LLC15:
	.asciz	"|      class template from DList     |"
	.align 8
.LLC16:
	.asciz	"| H/?: Show this menu                |"
	.align 8
.LLC17:
	.asciz	"| X/x: Exit                          |"
	.global menuItems
	.section	".data"
	.align 4
	.type	menuItems, #object
	.size	menuItems, 116
menuItems:
	.long	.LLC0
	.long	.LLC1
	.long	.LLC2
	.long	.LLC0
	.long	.LLC3
	.long	.LLC4
	.long	.LLC5
	.long	.LLC6
	.long	.LLC4
	.long	.LLC7
	.long	.LLC8
	.long	.LLC4
	.long	.LLC9
	.long	.LLC10
	.long	.LLC4
	.long	.LLC11
	.long	.LLC12
	.long	.LLC4
	.long	.LLC13
	.long	.LLC12
	.long	.LLC4
	.long	.LLC14
	.long	.LLC15
	.long	.LLC4
	.long	.LLC16
	.long	.LLC4
	.long	.LLC17
	.long	.LLC4
	.long	0
	.global .rem
	.global _Unwind_Resume
	.section	".rodata"
	.align 8
.LLC18:
	.asciz	"\n\tA Stack<char> object is created, a random number"
	.align 8
.LLC19:
	.asciz	"\n\tbetween 0 and 10 of objects are generated and\n"
	.align 8
.LLC20:
	.asciz	"\n\tpushed into stack. Then, they are pop out.\t"
	.align 8
.LLC21:
	.asciz	"\n\t("
	.align 8
.LLC22:
	.asciz	"-"
	.align 8
.LLC23:
	.asciz	" "
	.align 8
.LLC24:
	.asciz	") -- Items pushed into stack\n"
	.align 8
.LLC25:
	.asciz	") -- Items popped out of stack\n"
	.section	".text"
	.align 4
	.global _Z9testStackv
	.type	_Z9testStackv, #function
	.proc	020
_Z9testStackv:
.LLFB1490:
	!#PROLOGUE# 0
	save	%sp, -144, %sp
.LLCFI1:
	!#PROLOGUE# 1
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC18), %g1
	or	%g1, %lo(.LLC18), %o1
.LLEHB0:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC19), %g1
	or	%g1, %lo(.LLC19), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC20), %g1
	or	%g1, %lo(.LLC20), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	add	%fp, -32, %g1
	mov	%g1, %o0
	mov	10, %o1
	call	_ZN6DStackIcEC1Ei, 0
	 nop
.LLEHE0:
	call	rand, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	mov	10, %o1
	call	.rem, 0
	 nop
	mov	%o0, %g1
	st	%g1, [%fp-40]
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC21), %g1
	or	%g1, %lo(.LLC21), %o1
.LLEHB1:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	1, %g1
	st	%g1, [%fp-44]
.LL11:
	ld	[%fp-44], %o5
	ld	[%fp-40], %g1
	cmp	%o5, %g1
	bg	.LL12
	nop
	mov	65, %o0
	mov	90, %o1
	call	_Z12generateItemIcET_S0_S0_, 0
	 nop
	mov	%o0, %g1
	stb	%g1, [%fp-33]
	add	%fp, -32, %g1
	add	%fp, -33, %o5
	mov	%g1, %o0
	mov	%o5, %o1
	call	_ZN6DStackIcE4pushERKc, 0
	 nop
	ldub	[%fp-33], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %o5
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	mov	%o5, %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC22), %g1
	or	%g1, %lo(.LLC22), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	ld	[%fp-44], %o1
	call	_ZNSolsEi, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC23), %g1
	or	%g1, %lo(.LLC23), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	ld	[%fp-44], %g1
	add	%g1, 1, %g1
	st	%g1, [%fp-44]
	b	.LL11
	 nop
.LL12:
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC24), %g1
	or	%g1, %lo(.LLC24), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC21), %g1
	or	%g1, %lo(.LLC21), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	1, %g1
	st	%g1, [%fp-44]
.LL14:
	add	%fp, -32, %g1
	mov	%g1, %o0
	call	_ZNK5DListIcE5emptyEv, 0
	 nop
	mov	%o0, %g1
	and	%g1, 0xff, %g1
	cmp	%g1, 0
	bne	.LL15
	nop
	add	%fp, -32, %g1
	mov	%g1, %o0
	call	_ZN6DStackIcE3topEv, 0
	 nop
	mov	%o0, %g1
	ldub	[%g1], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %o5
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	mov	%o5, %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	mov	45, %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	ld	[%fp-44], %o1
	call	_ZNSolsEi, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC23), %g1
	or	%g1, %lo(.LLC23), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	add	%fp, -32, %g1
	mov	%g1, %o0
	call	_ZN6DStackIcE3popEv, 0
	 nop
	ld	[%fp-44], %g1
	add	%g1, 1, %g1
	st	%g1, [%fp-44]
	b	.LL14
	 nop
.LL15:
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC25), %g1
	or	%g1, %lo(.LLC25), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
.LLEHE1:
	b	.LL18
	 nop
.LL21:
	st	%i0, [%fp-48]
.LL17:
	ld	[%fp-48], %l0
	add	%fp, -32, %g1
	mov	%g1, %o0
	call	_ZN6DStackIcED1Ev, 0
	 nop
	st	%l0, [%fp-48]
.LL19:
	ld	[%fp-48], %o0
.LLEHB2:
	call	_Unwind_Resume, 0
	 nop
.LL18:
	add	%fp, -32, %g1
	mov	%g1, %o0
	call	_ZN6DStackIcED1Ev, 0
	 nop
.LLEHE2:
	nop
	ret
	restore
.LLFE1490:
	.size	_Z9testStackv, .-_Z9testStackv
	.section	".gcc_except_table",#alloc,#write
.LLLSDA1490:
	.byte	0xff
	.byte	0xff
	.byte	0x3
	.byte	0x27
	.uaword	.LLEHB0-.LLFB1490
	.uaword	.LLEHE0-.LLEHB0
	.uaword	0x0
	.byte	0x0
	.uaword	.LLEHB1-.LLFB1490
	.uaword	.LLEHE1-.LLEHB1
	.uaword	.LL21-.LLFB1490
	.byte	0x0
	.uaword	.LLEHB2-.LLFB1490
	.uaword	.LLEHE2-.LLEHB2
	.uaword	0x0
	.byte	0x0
	.section	".text"
	.section	".rodata"
	.align 8
.LLC26:
	.asciz	"\n\tA DQueue<char> object is created, a random number"
	.align 8
.LLC27:
	.asciz	") -- Items added to queue\n"
	.align 8
.LLC28:
	.asciz	") -- Items removed out of queue\n"
	.section	".text"
	.align 4
	.global _Z9testQueuev
	.type	_Z9testQueuev, #function
	.proc	020
_Z9testQueuev:
.LLFB1491:
	!#PROLOGUE# 0
	save	%sp, -144, %sp
.LLCFI2:
	!#PROLOGUE# 1
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC26), %g1
	or	%g1, %lo(.LLC26), %o1
.LLEHB3:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC19), %g1
	or	%g1, %lo(.LLC19), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC20), %g1
	or	%g1, %lo(.LLC20), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	add	%fp, -32, %g1
	mov	%g1, %o0
	mov	10, %o1
	call	_ZN6DQueueIcEC1Ei, 0
	 nop
.LLEHE3:
	call	rand, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	mov	10, %o1
	call	.rem, 0
	 nop
	mov	%o0, %g1
	st	%g1, [%fp-40]
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC21), %g1
	or	%g1, %lo(.LLC21), %o1
.LLEHB4:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	1, %g1
	st	%g1, [%fp-44]
.LL23:
	ld	[%fp-44], %o5
	ld	[%fp-40], %g1
	cmp	%o5, %g1
	bg	.LL24
	nop
	mov	65, %o0
	mov	90, %o1
	call	_Z12generateItemIcET_S0_S0_, 0
	 nop
	mov	%o0, %g1
	stb	%g1, [%fp-33]
	add	%fp, -32, %g1
	add	%fp, -33, %o5
	mov	%g1, %o0
	mov	%o5, %o1
	call	_ZN6DQueueIcE7enqueueERKc, 0
	 nop
	ldub	[%fp-33], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %o5
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	mov	%o5, %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC23), %g1
	or	%g1, %lo(.LLC23), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	ld	[%fp-44], %g1
	add	%g1, 1, %g1
	st	%g1, [%fp-44]
	b	.LL23
	 nop
.LL24:
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC27), %g1
	or	%g1, %lo(.LLC27), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC21), %g1
	or	%g1, %lo(.LLC21), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	st	%g0, [%fp-44]
.LL26:
	add	%fp, -32, %g1
	mov	%g1, %o0
	call	_ZNK5DListIcE5emptyEv, 0
	 nop
	mov	%o0, %g1
	and	%g1, 0xff, %g1
	cmp	%g1, 0
	bne	.LL27
	nop
	ld	[%fp-44], %g1
	add	%g1, 1, %g1
	st	%g1, [%fp-44]
	add	%fp, -32, %g1
	mov	%g1, %o0
	call	_ZN6DQueueIcE5frontEv, 0
	 nop
	mov	%o0, %g1
	ldub	[%g1], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %o5
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	mov	%o5, %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC23), %g1
	or	%g1, %lo(.LLC23), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	add	%fp, -32, %g1
	mov	%g1, %o0
	call	_ZN6DQueueIcE7dequeueEv, 0
	 nop
	b	.LL26
	 nop
.LL27:
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC28), %g1
	or	%g1, %lo(.LLC28), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
.LLEHE4:
	b	.LL29
	 nop
.LL32:
	st	%i0, [%fp-48]
.LL28:
	ld	[%fp-48], %l0
	add	%fp, -32, %g1
	mov	%g1, %o0
	call	_ZN6DQueueIcED1Ev, 0
	 nop
	st	%l0, [%fp-48]
.LL30:
	ld	[%fp-48], %o0
.LLEHB5:
	call	_Unwind_Resume, 0
	 nop
.LL29:
	add	%fp, -32, %g1
	mov	%g1, %o0
	call	_ZN6DQueueIcED1Ev, 0
	 nop
.LLEHE5:
	nop
	ret
	restore
.LLFE1491:
	.size	_Z9testQueuev, .-_Z9testQueuev
	.section	".gcc_except_table",#alloc,#write
.LLLSDA1491:
	.byte	0xff
	.byte	0xff
	.byte	0x3
	.byte	0x27
	.uaword	.LLEHB3-.LLFB1491
	.uaword	.LLEHE3-.LLEHB3
	.uaword	0x0
	.byte	0x0
	.uaword	.LLEHB4-.LLFB1491
	.uaword	.LLEHE4-.LLEHB4
	.uaword	.LL32-.LLFB1491
	.byte	0x0
	.uaword	.LLEHB5-.LLFB1491
	.uaword	.LLEHE5-.LLEHB5
	.uaword	0x0
	.byte	0x0
	.section	".text"
	.section	".rodata"
	.align 8
.LLC29:
	.asciz	"\n\tA DSQueue<char> object is created, a random number"
	.align 8
.LLC30:
	.asciz	" -- items in sorted queueu"
	.align 8
.LLC31:
	.asciz	"\n\tEnter a character to delete : "
	.align 8
.LLC32:
	.asciz	" -- after one removal"
	.section	".text"
	.align 4
	.global _Z15testSortedQueuev
	.type	_Z15testSortedQueuev, #function
	.proc	020
_Z15testSortedQueuev:
.LLFB1492:
	!#PROLOGUE# 0
	save	%sp, -176, %sp
.LLCFI3:
	!#PROLOGUE# 1
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC29), %g1
	or	%g1, %lo(.LLC29), %o1
.LLEHB6:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC19), %g1
	or	%g1, %lo(.LLC19), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC20), %g1
	or	%g1, %lo(.LLC20), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	add	%fp, -32, %g1
	mov	%g1, %o0
	mov	10, %o1
	call	_ZN7DSQueueIcEC1Ei, 0
	 nop
.LLEHE6:
	call	rand, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	mov	10, %o1
	call	.rem, 0
	 nop
	mov	%o0, %g1
	st	%g1, [%fp-52]
	mov	1, %g1
	st	%g1, [%fp-56]
.LL34:
	ld	[%fp-56], %o5
	ld	[%fp-52], %g1
	cmp	%o5, %g1
	bg	.LL35
	nop
	mov	65, %o0
	mov	90, %o1
.LLEHB7:
	call	_Z12generateItemIcET_S0_S0_, 0
	 nop
	mov	%o0, %g1
	stb	%g1, [%fp-33]
	add	%fp, -32, %g1
	add	%fp, -33, %o5
	mov	%g1, %o0
	mov	%o5, %o1
	call	_ZN7DSQueueIcE7enqueueERKc, 0
	 nop
.LLEHE7:
	ld	[%fp-56], %g1
	add	%g1, 1, %g1
	st	%g1, [%fp-56]
	b	.LL34
	 nop
.LL35:
	add	%fp, -72, %g1
	mov	%g1, %o0
	call	_ZNSaIcEC1Ev, 0
	 nop
	add	%fp, -72, %o5
	add	%fp, -64, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC30), %g1
	or	%g1, %lo(.LLC30), %o1
	mov	%o5, %o2
.LLEHB8:
	call	_ZNSsC1EPKcRKSaIcE, 0
	 nop
.LLEHE8:
	add	%fp, -64, %g1
	add	%fp, -32, %o5
	mov	%g1, %o0
	mov	%o5, %o1
.LLEHB9:
	call	_Z8showListIcEvRKSsR5DListIT_E, 0
	 nop
.LLEHE9:
	b	.LL38
	 nop
.LL59:
	st	%i0, [%fp-80]
.LL37:
	ld	[%fp-80], %l0
	add	%fp, -64, %g1
	mov	%g1, %o0
	call	_ZNSsD1Ev, 0
	 nop
	st	%l0, [%fp-80]
.LL39:
	b	.LL41
	 nop
.LL38:
	add	%fp, -64, %g1
	mov	%g1, %o0
.LLEHB10:
	call	_ZNSsD1Ev, 0
	 nop
.LLEHE10:
	b	.LL42
	 nop
.LL60:
	st	%i0, [%fp-80]
.LL41:
	ld	[%fp-80], %l0
	add	%fp, -72, %g1
	mov	%g1, %o0
	call	_ZNSaIcED1Ev, 0
	 nop
	st	%l0, [%fp-80]
.LL43:
	b	.LL53
	 nop
.LL42:
	add	%fp, -72, %g1
	mov	%g1, %o0
	call	_ZNSaIcED1Ev, 0
	 nop
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC31), %g1
	or	%g1, %lo(.LLC31), %o1
.LLEHB11:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	add	%fp, -48, %o5
	sethi	%hi(_ZSt3cin), %g1
	or	%g1, %lo(_ZSt3cin), %o0
	mov	%o5, %o1
	mov	5, %o2
	call	_ZNSi7getlineEPci, 0
	 nop
	add	%fp, -32, %g1
	ldub	[%fp-48], %o5
	stb	%o5, [%fp-73]
	add	%fp, -73, %o5
	mov	%g1, %o0
	mov	%o5, %o1
	call	_ZN7DSQueueIcE7dequeueERKc, 0
	 nop
.LLEHE11:
	add	%fp, -64, %g1
	mov	%g1, %o0
	call	_ZNSaIcEC1Ev, 0
	 nop
	add	%fp, -64, %o5
	add	%fp, -72, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC32), %g1
	or	%g1, %lo(.LLC32), %o1
	mov	%o5, %o2
.LLEHB12:
	call	_ZNSsC1EPKcRKSaIcE, 0
	 nop
.LLEHE12:
	add	%fp, -72, %g1
	add	%fp, -32, %o5
	mov	%g1, %o0
	mov	%o5, %o1
.LLEHB13:
	call	_Z8showListIcEvRKSsR5DListIT_E, 0
	 nop
.LLEHE13:
	b	.LL46
	 nop
.LL57:
	st	%i0, [%fp-80]
.LL45:
	ld	[%fp-80], %l0
	add	%fp, -72, %g1
	mov	%g1, %o0
	call	_ZNSsD1Ev, 0
	 nop
	st	%l0, [%fp-80]
.LL47:
	b	.LL49
	 nop
.LL46:
	add	%fp, -72, %g1
	mov	%g1, %o0
.LLEHB14:
	call	_ZNSsD1Ev, 0
	 nop
.LLEHE14:
	b	.LL50
	 nop
.LL58:
	st	%i0, [%fp-80]
.LL49:
	ld	[%fp-80], %l0
	add	%fp, -64, %g1
	mov	%g1, %o0
	call	_ZNSaIcED1Ev, 0
	 nop
	st	%l0, [%fp-80]
.LL51:
	b	.LL53
	 nop
.LL50:
	add	%fp, -64, %g1
	mov	%g1, %o0
	call	_ZNSaIcED1Ev, 0
	 nop
	b	.LL54
	 nop
.LL61:
	st	%i0, [%fp-80]
.LL53:
	ld	[%fp-80], %l0
	add	%fp, -32, %g1
	mov	%g1, %o0
	call	_ZN7DSQueueIcED1Ev, 0
	 nop
	st	%l0, [%fp-80]
.LL55:
	ld	[%fp-80], %o0
.LLEHB15:
	call	_Unwind_Resume, 0
	 nop
.LL54:
	add	%fp, -32, %g1
	mov	%g1, %o0
	call	_ZN7DSQueueIcED1Ev, 0
	 nop
.LLEHE15:
	nop
	ret
	restore
.LLFE1492:
	.size	_Z15testSortedQueuev, .-_Z15testSortedQueuev
	.section	".gcc_except_table",#alloc,#write
.LLLSDA1492:
	.byte	0xff
	.byte	0xff
	.byte	0x3
	.byte	0x82,0x1
	.uaword	.LLEHB6-.LLFB1492
	.uaword	.LLEHE6-.LLEHB6
	.uaword	0x0
	.byte	0x0
	.uaword	.LLEHB7-.LLFB1492
	.uaword	.LLEHE7-.LLEHB7
	.uaword	.LL61-.LLFB1492
	.byte	0x0
	.uaword	.LLEHB8-.LLFB1492
	.uaword	.LLEHE8-.LLEHB8
	.uaword	.LL60-.LLFB1492
	.byte	0x0
	.uaword	.LLEHB9-.LLFB1492
	.uaword	.LLEHE9-.LLEHB9
	.uaword	.LL59-.LLFB1492
	.byte	0x0
	.uaword	.LLEHB10-.LLFB1492
	.uaword	.LLEHE10-.LLEHB10
	.uaword	.LL60-.LLFB1492
	.byte	0x0
	.uaword	.LLEHB11-.LLFB1492
	.uaword	.LLEHE11-.LLEHB11
	.uaword	.LL61-.LLFB1492
	.byte	0x0
	.uaword	.LLEHB12-.LLFB1492
	.uaword	.LLEHE12-.LLEHB12
	.uaword	.LL58-.LLFB1492
	.byte	0x0
	.uaword	.LLEHB13-.LLFB1492
	.uaword	.LLEHE13-.LLEHB13
	.uaword	.LL57-.LLFB1492
	.byte	0x0
	.uaword	.LLEHB14-.LLFB1492
	.uaword	.LLEHE14-.LLEHB14
	.uaword	.LL58-.LLFB1492
	.byte	0x0
	.uaword	.LLEHB15-.LLFB1492
	.uaword	.LLEHE15-.LLEHB15
	.uaword	0x0
	.byte	0x0
	.section	".text"
	.section	".rodata"
	.align 8
.LLC33:
	.asciz	"cList"
	.align 8
.LLC34:
	.asciz	"iList"
	.align 8
.LLC35:
	.asciz	"\tIllegal action!\n"
	.section	".text"
	.align 4
	.global main
	.type	main, #function
	.proc	04
main:
.LLFB1493:
	!#PROLOGUE# 0
	save	%sp, -176, %sp
.LLCFI4:
	!#PROLOGUE# 1
	mov	0, %o0
	call	time, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	call	srand, 0
	 nop
	add	%fp, -32, %g1
	mov	%g1, %o0
	mov	10, %o1
.LLEHB16:
	call	_ZN5DListIcEC1Ei, 0
	 nop
.LLEHE16:
	add	%fp, -48, %g1
	mov	%g1, %o0
	mov	10, %o1
.LLEHB17:
	call	_ZN5DListIiEC1Ei, 0
	 nop
.LLEHE17:
.LL63:
.LLEHB18:
	call	_ZN4Menu6promptEv, 0
	 nop
.LLEHE18:
	mov	%o0, %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %g1
	mov	%g1, %o0
	call	toupper, 0
	 nop
	mov	%o0, %g1
	stb	%g1, [%fp-49]
	ldub	[%fp-49], %g1
	add	%g1, -61, %g1
	st	%g1, [%fp-80]
	ld	[%fp-80], %o5
	and	%o5, 0xff, %g1
	cmp	%g1, 24
	bgu	.LL93
	nop
	ld	[%fp-80], %o5
	and	%o5, 0xff, %g1
	sll	%g1, 2, %o5
	sethi	%hi(.LL94), %g1
	or	%g1, %lo(.LL94), %g1
	ld	[%o5+%g1], %g1
	jmp	%g1
	 nop
.LL66:
	add	%fp, -72, %g1
	mov	%g1, %o0
	call	_ZNSaIcEC1Ev, 0
	 nop
	add	%fp, -72, %o5
	add	%fp, -64, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC33), %g1
	or	%g1, %lo(.LLC33), %o1
	mov	%o5, %o2
.LLEHB19:
	call	_ZNSsC1EPKcRKSaIcE, 0
	 nop
.LLEHE19:
	add	%fp, -64, %g1
	add	%fp, -32, %o5
	mov	%g1, %o0
	mov	%o5, %o1
.LLEHB20:
	call	_Z8showListIcEvRKSsR5DListIT_E, 0
	 nop
.LLEHE20:
	b	.LL68
	 nop
.LL105:
	st	%i0, [%fp-76]
.LL67:
	ld	[%fp-76], %l0
	add	%fp, -64, %g1
	mov	%g1, %o0
	call	_ZNSsD1Ev, 0
	 nop
	st	%l0, [%fp-76]
.LL69:
	b	.LL71
	 nop
.LL68:
	add	%fp, -64, %g1
	mov	%g1, %o0
.LLEHB21:
	call	_ZNSsD1Ev, 0
	 nop
.LLEHE21:
	b	.LL72
	 nop
.LL106:
	st	%i0, [%fp-76]
.LL71:
	ld	[%fp-76], %l0
	add	%fp, -72, %g1
	mov	%g1, %o0
	call	_ZNSaIcED1Ev, 0
	 nop
	st	%l0, [%fp-76]
.LL73:
	b	.LL95
	 nop
.LL72:
	add	%fp, -72, %g1
	mov	%g1, %o0
	call	_ZNSaIcED1Ev, 0
	 nop
	add	%fp, -64, %g1
	mov	%g1, %o0
	call	_ZNSaIcEC1Ev, 0
	 nop
	add	%fp, -64, %o5
	add	%fp, -72, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC34), %g1
	or	%g1, %lo(.LLC34), %o1
	mov	%o5, %o2
.LLEHB22:
	call	_ZNSsC1EPKcRKSaIcE, 0
	 nop
.LLEHE22:
	add	%fp, -72, %g1
	add	%fp, -48, %o5
	mov	%g1, %o0
	mov	%o5, %o1
.LLEHB23:
	call	_Z8showListIiEvRKSsR5DListIT_E, 0
	 nop
.LLEHE23:
	b	.LL76
	 nop
.LL103:
	st	%i0, [%fp-76]
.LL75:
	ld	[%fp-76], %l0
	add	%fp, -72, %g1
	mov	%g1, %o0
	call	_ZNSsD1Ev, 0
	 nop
	st	%l0, [%fp-76]
.LL77:
	b	.LL79
	 nop
.LL76:
	add	%fp, -72, %g1
	mov	%g1, %o0
.LLEHB24:
	call	_ZNSsD1Ev, 0
	 nop
.LLEHE24:
	b	.LL80
	 nop
.LL104:
	st	%i0, [%fp-76]
.LL79:
	ld	[%fp-76], %l0
	add	%fp, -64, %g1
	mov	%g1, %o0
	call	_ZNSaIcED1Ev, 0
	 nop
	st	%l0, [%fp-76]
.LL81:
	b	.LL95
	 nop
.LL80:
	add	%fp, -64, %g1
	mov	%g1, %o0
	call	_ZNSaIcED1Ev, 0
	 nop
	b	.LL63
	 nop
.LL83:
	add	%fp, -32, %g1
	mov	%g1, %o0
	mov	65, %o1
	mov	90, %o2
.LLEHB25:
	call	_Z6insertIcEvR5DListIT_ES1_S1_, 0
	 nop
	add	%fp, -48, %g1
	mov	%g1, %o0
	mov	0, %o1
	mov	99, %o2
	call	_Z6insertIiEvR5DListIT_ES1_S1_, 0
	 nop
	b	.LL63
	 nop
.LL84:
	add	%fp, -32, %g1
	mov	%g1, %o0
	call	_Z6removeIcEvR5DListIT_E, 0
	 nop
	add	%fp, -48, %g1
	mov	%g1, %o0
	call	_Z6removeIiEvR5DListIT_E, 0
	 nop
	b	.LL63
	 nop
.LL85:
	add	%fp, -32, %g1
	mov	%g1, %o0
	call	_Z19testCopyConstructorIcEvR5DListIT_E, 0
	 nop
	b	.LL63
	 nop
.LL86:
	add	%fp, -48, %g1
	mov	%g1, %o0
	call	_Z12testAssignOpIiEvR5DListIT_E, 0
	 nop
	b	.LL63
	 nop
.LL87:
	call	_Z9testStackv, 0
	 nop
	b	.LL63
	 nop
.LL88:
	call	_Z9testQueuev, 0
	 nop
	b	.LL63
	 nop
.LL89:
	call	_Z15testSortedQueuev, 0
	 nop
	b	.LL63
	 nop
.LL91:
	call	_ZN4Menu4showEv, 0
	 nop
	b	.LL63
	 nop
.LL92:
	mov	0, %o0
	call	exit, 0
	 nop
.LL93:
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC35), %g1
	or	%g1, %lo(.LLC35), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
.LLEHE25:
	b	.LL63
	 nop
.LL107:
	st	%i0, [%fp-76]
.LL95:
	ld	[%fp-76], %l0
	add	%fp, -48, %g1
	mov	%g1, %o0
	call	_ZN5DListIiED1Ev, 0
	 nop
	st	%l0, [%fp-76]
.LL97:
	b	.LL99
	 nop
.LL108:
	st	%i0, [%fp-76]
.LL99:
	ld	[%fp-76], %l0
	add	%fp, -32, %g1
	mov	%g1, %o0
	call	_ZN5DListIcED1Ev, 0
	 nop
	st	%l0, [%fp-76]
.LL101:
	ld	[%fp-76], %o0
.LLEHB26:
	call	_Unwind_Resume, 0
	 nop
.LLEHE26:
	nop
	.align 4
	.align 4
.LL94:
	.word	.LL86
	.word	.LL93
	.word	.LL91
	.word	.LL93
	.word	.LL93
	.word	.LL93
	.word	.LL85
	.word	.LL84
	.word	.LL93
	.word	.LL93
	.word	.LL93
	.word	.LL91
	.word	.LL83
	.word	.LL93
	.word	.LL93
	.word	.LL66
	.word	.LL93
	.word	.LL93
	.word	.LL89
	.word	.LL93
	.word	.LL92
	.word	.LL93
	.word	.LL87
	.word	.LL93
	.word	.LL88
.LLFE1493:
	.size	main, .-main
	.section	".gcc_except_table",#alloc,#write
.LLLSDA1493:
	.byte	0xff
	.byte	0xff
	.byte	0x3
	.byte	0x8f,0x1
	.uaword	.LLEHB16-.LLFB1493
	.uaword	.LLEHE16-.LLEHB16
	.uaword	0x0
	.byte	0x0
	.uaword	.LLEHB17-.LLFB1493
	.uaword	.LLEHE17-.LLEHB17
	.uaword	.LL108-.LLFB1493
	.byte	0x0
	.uaword	.LLEHB18-.LLFB1493
	.uaword	.LLEHE18-.LLEHB18
	.uaword	.LL107-.LLFB1493
	.byte	0x0
	.uaword	.LLEHB19-.LLFB1493
	.uaword	.LLEHE19-.LLEHB19
	.uaword	.LL106-.LLFB1493
	.byte	0x0
	.uaword	.LLEHB20-.LLFB1493
	.uaword	.LLEHE20-.LLEHB20
	.uaword	.LL105-.LLFB1493
	.byte	0x0
	.uaword	.LLEHB21-.LLFB1493
	.uaword	.LLEHE21-.LLEHB21
	.uaword	.LL106-.LLFB1493
	.byte	0x0
	.uaword	.LLEHB22-.LLFB1493
	.uaword	.LLEHE22-.LLEHB22
	.uaword	.LL104-.LLFB1493
	.byte	0x0
	.uaword	.LLEHB23-.LLFB1493
	.uaword	.LLEHE23-.LLEHB23
	.uaword	.LL103-.LLFB1493
	.byte	0x0
	.uaword	.LLEHB24-.LLFB1493
	.uaword	.LLEHE24-.LLEHB24
	.uaword	.LL104-.LLFB1493
	.byte	0x0
	.uaword	.LLEHB25-.LLFB1493
	.uaword	.LLEHE25-.LLEHB25
	.uaword	.LL107-.LLFB1493
	.byte	0x0
	.uaword	.LLEHB26-.LLFB1493
	.uaword	.LLEHE26-.LLEHB26
	.uaword	0x0
	.byte	0x0
	.section	".text"
	.section	".rodata"
	.align 8
.LLC36:
	.asciz	"\t"
	.section	".gnu.linkonce.t._ZN4Menu4showEv",#alloc,#execinstr
	.align 4
	.weak	_ZN4Menu4showEv
	.type	_ZN4Menu4showEv, #function
	.proc	020
_ZN4Menu4showEv:
.LLFB1482:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
.LLCFI5:
	!#PROLOGUE# 1
	st	%g0, [%fp-20]
.LL110:
	sethi	%hi(menuItems), %g1
	or	%g1, %lo(menuItems), %o5
	ld	[%fp-20], %g1
	sll	%g1, 2, %g1
	ld	[%o5+%g1], %g1
	cmp	%g1, 0
	be	.LL109
	nop
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC36), %g1
	or	%g1, %lo(.LLC36), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %o4
	sethi	%hi(menuItems), %g1
	or	%g1, %lo(menuItems), %o5
	ld	[%fp-20], %g1
	sll	%g1, 2, %g1
	mov	%o4, %o0
	ld	[%o5+%g1], %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	mov	10, %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c, 0
	 nop
	ld	[%fp-20], %g1
	add	%g1, 1, %g1
	st	%g1, [%fp-20]
	b	.LL110
	 nop
.LL109:
	ret
	restore
.LLFE1482:
	.size	_ZN4Menu4showEv, .-_ZN4Menu4showEv
	.section	".rodata"
	.align 8
.LLC37:
	.asciz	"\n\n\tSelect 'H' for menu, 'Q' to quit, or other command : "
	.section	".gnu.linkonce.t._ZN4Menu6promptEv",#alloc,#execinstr
	.align 4
	.weak	_ZN4Menu6promptEv
	.type	_ZN4Menu6promptEv, #function
	.proc	04
_ZN4Menu6promptEv:
.LLFB1483:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
.LLCFI6:
	!#PROLOGUE# 1
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC37), %g1
	or	%g1, %lo(.LLC37), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	add	%fp, -17, %o5
	sethi	%hi(_ZSt3cin), %g1
	or	%g1, %lo(_ZSt3cin), %o0
	mov	%o5, %o1
	call	_ZStrsIcSt11char_traitsIcEERSt13basic_istreamIT_T0_ES6_RS3_, 0
	 nop
	sethi	%hi(_ZSt3cin), %g1
	or	%g1, %lo(_ZSt3cin), %o0
	call	_ZNSi3getEv, 0
	 nop
	ldub	[%fp-17], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %g1
	mov	%g1, %i0
	ret
	restore
.LLFE1483:
	.size	_ZN4Menu6promptEv, .-_ZN4Menu6promptEv
	.section	".gnu.linkonce.t._ZSt3minIjERKT_S2_S2_",#alloc,#execinstr
	.align 4
	.weak	_ZSt3minIjERKT_S2_S2_
	.type	_ZSt3minIjERKT_S2_S2_, #function
	.proc	0116
_ZSt3minIjERKT_S2_S2_:
.LLFB1494:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
.LLCFI7:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+72], %g1
	ld	[%fp+68], %i5
	ld	[%g1], %i4
	ld	[%i5], %g1
	cmp	%i4, %g1
	bgeu	.LL115
	nop
	ld	[%fp+72], %g1
	st	%g1, [%fp-20]
	b	.LL114
	 nop
.LL115:
	ld	[%fp+68], %g1
	st	%g1, [%fp-20]
.LL114:
	ld	[%fp-20], %i0
	ret
	restore
.LLFE1494:
	.size	_ZSt3minIjERKT_S2_S2_, .-_ZSt3minIjERKT_S2_S2_
	.section	".gnu.linkonce.t._ZN6DStackIcEC1Ei",#alloc,#execinstr
	.align 4
	.weak	_ZN6DStackIcEC1Ei
	.type	_ZN6DStackIcEC1Ei, #function
	.proc	020
_ZN6DStackIcEC1Ei:
.LLFB1500:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI8:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+68], %o0
	ld	[%fp+72], %o1
	call	_ZN5DListIcEC2Ei, 0
	 nop
	ld	[%fp+68], %g1
	sethi	%hi(_ZTV6DStackIcE+8), %o5
	or	%o5, %lo(_ZTV6DStackIcE+8), %o5
	st	%o5, [%g1]
.LL117:
	ret
	restore
.LLFE1500:
	.size	_ZN6DStackIcEC1Ei, .-_ZN6DStackIcEC1Ei
	.section	".gnu.linkonce.t._ZN6DStackIcED1Ev",#alloc,#execinstr
	.align 4
	.weak	_ZN6DStackIcED1Ev
	.type	_ZN6DStackIcED1Ev, #function
	.proc	020
_ZN6DStackIcED1Ev:
.LLFB1503:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI9:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	ld	[%fp+68], %o5
	sethi	%hi(_ZTV6DStackIcE+8), %g1
	or	%g1, %lo(_ZTV6DStackIcE+8), %g1
	st	%g1, [%o5]
	ld	[%fp+68], %g1
	ld	[%g1+4], %g1
	cmp	%g1, 0
	be	.LL124
	nop
	ld	[%fp+68], %g1
	ld	[%g1+4], %o0
	call	_ZdaPv, 0
	 nop
.LL123:
.LL124:
	ld	[%fp+68], %o0
	call	_ZN5DListIcED2Ev, 0
	 nop
	mov	1, %o5
	and	%o5, 2, %g1
	and	%g1, 0xff, %g1
	cmp	%g1, 0
	be	.LL119
	nop
	ld	[%fp+68], %o0
	call	_ZdlPv, 0
	 nop
.LL119:
	nop
	ret
	restore
.LLFE1503:
	.size	_ZN6DStackIcED1Ev, .-_ZN6DStackIcED1Ev
	.section	".gnu.linkonce.t._Z12generateItemIcET_S0_S0_",#alloc,#execinstr
	.align 4
	.weak	_Z12generateItemIcET_S0_S0_
	.type	_Z12generateItemIcET_S0_S0_, #function
	.proc	04
_Z12generateItemIcET_S0_S0_:
.LLFB1505:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI10:
	!#PROLOGUE# 1
	mov	%i0, %g1
	mov	%i1, %o5
	stb	%g1, [%fp+68]
	stb	%o5, [%fp+72]
	call	rand, 0
	 nop
	mov	%o0, %o4
	ldub	[%fp+72], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %o5
	ldub	[%fp+68], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %g1
	sub	%o5, %g1, %g1
	add	%g1, 1, %g1
	mov	%o4, %o0
	mov	%g1, %o1
	call	.rem, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o5
	ldub	[%fp+68], %g1
	add	%o5, %g1, %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %g1
	mov	%g1, %i0
	ret
	restore
.LLFE1505:
	.size	_Z12generateItemIcET_S0_S0_, .-_Z12generateItemIcET_S0_S0_
	.section	".gnu.linkonce.t._ZN6DStackIcE4pushERKc",#alloc,#execinstr
	.align 4
	.weak	_ZN6DStackIcE4pushERKc
	.type	_ZN6DStackIcE4pushERKc, #function
	.proc	020
_ZN6DStackIcE4pushERKc:
.LLFB1506:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI11:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+68], %g1
	ld	[%fp+68], %o0
	ld	[%fp+72], %o1
	ld	[%g1+8], %o2
	call	_ZN5DListIcE6insertERKci, 0
	 nop
	nop
	ret
	restore
.LLFE1506:
	.size	_ZN6DStackIcE4pushERKc, .-_ZN6DStackIcE4pushERKc
	.section	".gnu.linkonce.t._ZNK5DListIcE5emptyEv",#alloc,#execinstr
	.align 4
	.weak	_ZNK5DListIcE5emptyEv
	.type	_ZNK5DListIcE5emptyEv, #function
	.proc	04
_ZNK5DListIcE5emptyEv:
.LLFB1508:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI12:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	ld	[%fp+68], %i5
	ld	[%i5+8], %g1
	add	%g1, -1, %g1
	ld	[%i5+8], %i5
	or	%g1, %i5, %g1
	srl	%g1, 31, %g1
	mov	%g1, %i0
	ret
	restore
.LLFE1508:
	.size	_ZNK5DListIcE5emptyEv, .-_ZNK5DListIcE5emptyEv
	.section	".gnu.linkonce.t._ZN6DStackIcE3topEv",#alloc,#execinstr
	.align 4
	.weak	_ZN6DStackIcE3topEv
	.type	_ZN6DStackIcE3topEv, #function
	.proc	0102
_ZN6DStackIcE3topEv:
.LLFB1509:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI13:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	ld	[%fp+68], %g1
	ld	[%g1+8], %g1
	add	%g1, -1, %g1
	ld	[%fp+68], %o0
	mov	%g1, %o1
	call	_ZNK5DListIcE3getEi, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %i0
	ret
	restore
.LLFE1509:
	.size	_ZN6DStackIcE3topEv, .-_ZN6DStackIcE3topEv
	.section	".gnu.linkonce.t._ZN6DStackIcE3popEv",#alloc,#execinstr
	.align 4
	.weak	_ZN6DStackIcE3popEv
	.type	_ZN6DStackIcE3popEv, #function
	.proc	020
_ZN6DStackIcE3popEv:
.LLFB1510:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI14:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	ld	[%fp+68], %g1
	ld	[%g1+8], %g1
	add	%g1, -1, %g1
	ld	[%fp+68], %o0
	mov	%g1, %o1
	call	_ZN5DListIcE6removeEi, 0
	 nop
	nop
	ret
	restore
.LLFE1510:
	.size	_ZN6DStackIcE3popEv, .-_ZN6DStackIcE3popEv
	.section	".gnu.linkonce.t._ZN6DQueueIcEC1Ei",#alloc,#execinstr
	.align 4
	.weak	_ZN6DQueueIcEC1Ei
	.type	_ZN6DQueueIcEC1Ei, #function
	.proc	020
_ZN6DQueueIcEC1Ei:
.LLFB1513:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI15:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+68], %o0
	ld	[%fp+72], %o1
	call	_ZN5DListIcEC2Ei, 0
	 nop
	ld	[%fp+68], %g1
	sethi	%hi(_ZTV6DQueueIcE+8), %o5
	or	%o5, %lo(_ZTV6DQueueIcE+8), %o5
	st	%o5, [%g1]
.LL133:
	ret
	restore
.LLFE1513:
	.size	_ZN6DQueueIcEC1Ei, .-_ZN6DQueueIcEC1Ei
	.section	".gnu.linkonce.t._ZN6DQueueIcED1Ev",#alloc,#execinstr
	.align 4
	.weak	_ZN6DQueueIcED1Ev
	.type	_ZN6DQueueIcED1Ev, #function
	.proc	020
_ZN6DQueueIcED1Ev:
.LLFB1516:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI16:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	ld	[%fp+68], %o5
	sethi	%hi(_ZTV6DQueueIcE+8), %g1
	or	%g1, %lo(_ZTV6DQueueIcE+8), %g1
	st	%g1, [%o5]
	ld	[%fp+68], %g1
	ld	[%g1+4], %g1
	cmp	%g1, 0
	be	.LL140
	nop
	ld	[%fp+68], %g1
	ld	[%g1+4], %o0
	call	_ZdaPv, 0
	 nop
.LL139:
.LL140:
	ld	[%fp+68], %o0
	call	_ZN5DListIcED2Ev, 0
	 nop
	mov	1, %o5
	and	%o5, 2, %g1
	and	%g1, 0xff, %g1
	cmp	%g1, 0
	be	.LL135
	nop
	ld	[%fp+68], %o0
	call	_ZdlPv, 0
	 nop
.LL135:
	nop
	ret
	restore
.LLFE1516:
	.size	_ZN6DQueueIcED1Ev, .-_ZN6DQueueIcED1Ev
	.section	".gnu.linkonce.t._ZN6DQueueIcE7enqueueERKc",#alloc,#execinstr
	.align 4
	.weak	_ZN6DQueueIcE7enqueueERKc
	.type	_ZN6DQueueIcE7enqueueERKc, #function
	.proc	020
_ZN6DQueueIcE7enqueueERKc:
.LLFB1518:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI17:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+68], %g1
	ld	[%fp+68], %o0
	ld	[%fp+72], %o1
	ld	[%g1+8], %o2
	call	_ZN5DListIcE6insertERKci, 0
	 nop
	nop
	ret
	restore
.LLFE1518:
	.size	_ZN6DQueueIcE7enqueueERKc, .-_ZN6DQueueIcE7enqueueERKc
	.section	".gnu.linkonce.t._ZN6DQueueIcE5frontEv",#alloc,#execinstr
	.align 4
	.weak	_ZN6DQueueIcE5frontEv
	.type	_ZN6DQueueIcE5frontEv, #function
	.proc	0102
_ZN6DQueueIcE5frontEv:
.LLFB1519:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI18:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	ld	[%fp+68], %o0
	mov	0, %o1
	call	_ZNK5DListIcE3getEi, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %i0
	ret
	restore
.LLFE1519:
	.size	_ZN6DQueueIcE5frontEv, .-_ZN6DQueueIcE5frontEv
	.section	".gnu.linkonce.t._ZN6DQueueIcE7dequeueEv",#alloc,#execinstr
	.align 4
	.weak	_ZN6DQueueIcE7dequeueEv
	.type	_ZN6DQueueIcE7dequeueEv, #function
	.proc	020
_ZN6DQueueIcE7dequeueEv:
.LLFB1520:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI19:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	mov	0, %o0
	call	remove, 0
	 nop
	nop
	ret
	restore
.LLFE1520:
	.size	_ZN6DQueueIcE7dequeueEv, .-_ZN6DQueueIcE7dequeueEv
	.section	".gnu.linkonce.t._ZN7DSQueueIcEC1Ei",#alloc,#execinstr
	.align 4
	.weak	_ZN7DSQueueIcEC1Ei
	.type	_ZN7DSQueueIcEC1Ei, #function
	.proc	020
_ZN7DSQueueIcEC1Ei:
.LLFB1523:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI20:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+68], %o0
	ld	[%fp+72], %o1
	call	_ZN5DListIcEC2Ei, 0
	 nop
	ld	[%fp+68], %g1
	sethi	%hi(_ZTV7DSQueueIcE+8), %o5
	or	%o5, %lo(_ZTV7DSQueueIcE+8), %o5
	st	%o5, [%g1]
.LL147:
	ret
	restore
.LLFE1523:
	.size	_ZN7DSQueueIcEC1Ei, .-_ZN7DSQueueIcEC1Ei
	.section	".gnu.linkonce.t._ZN7DSQueueIcED1Ev",#alloc,#execinstr
	.align 4
	.weak	_ZN7DSQueueIcED1Ev
	.type	_ZN7DSQueueIcED1Ev, #function
	.proc	020
_ZN7DSQueueIcED1Ev:
.LLFB1526:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI21:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	ld	[%fp+68], %o5
	sethi	%hi(_ZTV7DSQueueIcE+8), %g1
	or	%g1, %lo(_ZTV7DSQueueIcE+8), %g1
	st	%g1, [%o5]
	ld	[%fp+68], %g1
	ld	[%g1+4], %g1
	cmp	%g1, 0
	be	.LL154
	nop
	ld	[%fp+68], %g1
	ld	[%g1+4], %o0
	call	_ZdaPv, 0
	 nop
.LL153:
.LL154:
	ld	[%fp+68], %o0
	call	_ZN5DListIcED2Ev, 0
	 nop
	mov	1, %o5
	and	%o5, 2, %g1
	and	%g1, 0xff, %g1
	cmp	%g1, 0
	be	.LL149
	nop
	ld	[%fp+68], %o0
	call	_ZdlPv, 0
	 nop
.LL149:
	nop
	ret
	restore
.LLFE1526:
	.size	_ZN7DSQueueIcED1Ev, .-_ZN7DSQueueIcED1Ev
	.section	".gnu.linkonce.t._ZN7DSQueueIcE7enqueueERKc",#alloc,#execinstr
	.align 4
	.weak	_ZN7DSQueueIcE7enqueueERKc
	.type	_ZN7DSQueueIcE7enqueueERKc, #function
	.proc	04
_ZN7DSQueueIcE7enqueueERKc:
.LLFB1528:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
.LLCFI22:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+68], %o0
	call	_ZNK5DListIcE5emptyEv, 0
	 nop
	mov	%o0, %g1
	and	%g1, 0xff, %g1
	cmp	%g1, 0
	bne	.LL159
	nop
	ld	[%fp+72], %g1
	ldub	[%g1], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %l0
	ld	[%fp+68], %o0
	mov	0, %o1
	call	_ZN5DListIcEixEi, 0
	 nop
	mov	%o0, %g1
	ldub	[%g1], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %g1
	cmp	%l0, %g1
	ble	.LL159
	nop
	b	.LL158
	 nop
.LL159:
	ld	[%fp+68], %o0
	ld	[%fp+72], %o1
	mov	0, %o2
	call	_ZN5DListIcE6insertERKci, 0
	 nop
	st	%g0, [%fp-20]
	b	.LL160
	 nop
.LL158:
	ld	[%fp+72], %g1
	ldub	[%g1], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %l0
	ld	[%fp+68], %g1
	ld	[%g1+8], %g1
	add	%g1, -1, %g1
	ld	[%fp+68], %o0
	mov	%g1, %o1
	call	_ZN5DListIcEixEi, 0
	 nop
	mov	%o0, %g1
	ldub	[%g1], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %g1
	cmp	%l0, %g1
	bl	.LL161
	nop
	ld	[%fp+68], %g1
	ld	[%g1+8], %g1
	st	%g1, [%fp-20]
	ld	[%fp+68], %g1
	ld	[%fp+68], %o0
	ld	[%fp+72], %o1
	ld	[%g1+8], %o2
	call	_ZN5DListIcE6insertERKci, 0
	 nop
	b	.LL160
	 nop
.LL161:
	mov	1, %g1
	st	%g1, [%fp-24]
.LL163:
	ld	[%fp+72], %g1
	ldub	[%g1], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %l0
	ld	[%fp+68], %o0
	ld	[%fp-24], %o1
	call	_ZN5DListIcEixEi, 0
	 nop
	mov	%o0, %g1
	ldub	[%g1], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %g1
	cmp	%l0, %g1
	ble	.LL164
	nop
	ld	[%fp-24], %g1
	add	%g1, 1, %g1
	st	%g1, [%fp-24]
	b	.LL163
	 nop
.LL164:
	ld	[%fp+68], %o0
	ld	[%fp+72], %o1
	ld	[%fp-24], %o2
	call	_ZN5DListIcE6insertERKci, 0
	 nop
	ld	[%fp-24], %g1
	st	%g1, [%fp-20]
.LL160:
	ld	[%fp-20], %g1
	mov	%g1, %i0
	ret
	restore
.LLFE1528:
	.size	_ZN7DSQueueIcE7enqueueERKc, .-_ZN7DSQueueIcE7enqueueERKc
	.section	".rodata"
	.align 8
.LLC38:
	.asciz	"\n\t"
	.align 8
.LLC39:
	.asciz	" - "
	.align 8
.LLC40:
	.asciz	" : "
	.section	".gnu.linkonce.t._Z8showListIcEvRKSsR5DListIT_E",#alloc,#execinstr
	.align 4
	.weak	_Z8showListIcEvRKSsR5DListIT_E
	.type	_Z8showListIcEvRKSsR5DListIT_E, #function
	.proc	020
_Z8showListIcEvRKSsR5DListIT_E:
.LLFB1544:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI23:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC38), %g1
	or	%g1, %lo(.LLC38), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	ld	[%fp+72], %o1
	call	_ZlsIcERSoS0_RK5DListIT_E, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC39), %g1
	or	%g1, %lo(.LLC39), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %l0
	ld	[%fp+72], %o0
	call	_ZNK5DListIcE6lengthEv, 0
	 nop
	mov	%o0, %g1
	mov	%l0, %o0
	mov	%g1, %o1
	call	_ZNSolsEi, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC40), %g1
	or	%g1, %lo(.LLC40), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	ld	[%fp+68], %o1
	call	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E, 0
	 nop
	nop
	ret
	restore
.LLFE1544:
	.size	_Z8showListIcEvRKSsR5DListIT_E, .-_Z8showListIcEvRKSsR5DListIT_E
	.section	".gnu.linkonce.t._ZN7DSQueueIcE7dequeueERKc",#alloc,#execinstr
	.align 4
	.weak	_ZN7DSQueueIcE7dequeueERKc
	.type	_ZN7DSQueueIcE7dequeueERKc, #function
	.proc	020
_ZN7DSQueueIcE7dequeueERKc:
.LLFB1546:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
.LLCFI24:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+68], %o0
	ld	[%fp+72], %o1
	call	_ZN7DSQueueIcE4findERKc, 0
	 nop
	mov	%o0, %g1
	st	%g1, [%fp-20]
	ld	[%fp-20], %g1
	cmp	%g1, -1
	bne	.LL167
	nop
	b	.LL166
	 nop
.LL167:
	ld	[%fp+68], %o0
	ld	[%fp-20], %o1
	call	_ZN5DListIcE6removeEi, 0
	 nop
.LL166:
	nop
	ret
	restore
.LLFE1546:
	.size	_ZN7DSQueueIcE7dequeueERKc, .-_ZN7DSQueueIcE7dequeueERKc
	.section	".rodata"
	.align 8
.LLC41:
	.asciz	"cap > 0"
	.align 8
.LLC42:
	.asciz	"DList.h"
	.section	".gnu.linkonce.t._ZN5DListIcEC2Ei",#alloc,#execinstr
	.align 4
	.weak	_ZN5DListIcEC2Ei
	.type	_ZN5DListIcEC2Ei, #function
	.proc	020
_ZN5DListIcEC2Ei:
.LLFB1548:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI25:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+68], %o5
	sethi	%hi(_ZTV5DListIcE+8), %g1
	or	%g1, %lo(_ZTV5DListIcE+8), %g1
	st	%g1, [%o5]
	ld	[%fp+68], %g1
	st	%g0, [%g1+8]
	ld	[%fp+68], %o5
	ld	[%fp+72], %g1
	st	%g1, [%o5+12]
	ld	[%fp+72], %g1
	cmp	%g1, 0
	bg	.LL169
	nop
	sethi	%hi(.LLC41), %g1
	or	%g1, %lo(.LLC41), %o0
	sethi	%hi(.LLC42), %g1
	or	%g1, %lo(.LLC42), %o1
	mov	19, %o2
	call	__assert, 0
	 nop
.LL169:
	ld	[%fp+68], %l0
	ld	[%fp+68], %g1
	ld	[%g1+12], %g1
	mov	%g1, %o0
	call	_Znaj, 0
	 nop
	st	%o0, [%l0+4]
	ret
	restore
.LLFE1548:
	.size	_ZN5DListIcEC2Ei, .-_ZN5DListIcEC2Ei
	.section	".gnu.linkonce.t._ZN5DListIcEC1Ei",#alloc,#execinstr
	.align 4
	.weak	_ZN5DListIcEC1Ei
	.type	_ZN5DListIcEC1Ei, #function
	.proc	020
_ZN5DListIcEC1Ei:
.LLFB1549:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI26:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+68], %o5
	sethi	%hi(_ZTV5DListIcE+8), %g1
	or	%g1, %lo(_ZTV5DListIcE+8), %g1
	st	%g1, [%o5]
	ld	[%fp+68], %g1
	st	%g0, [%g1+8]
	ld	[%fp+68], %o5
	ld	[%fp+72], %g1
	st	%g1, [%o5+12]
	ld	[%fp+72], %g1
	cmp	%g1, 0
	bg	.LL172
	nop
	sethi	%hi(.LLC41), %g1
	or	%g1, %lo(.LLC41), %o0
	sethi	%hi(.LLC42), %g1
	or	%g1, %lo(.LLC42), %o1
	mov	19, %o2
	call	__assert, 0
	 nop
.LL172:
	ld	[%fp+68], %l0
	ld	[%fp+68], %g1
	ld	[%g1+12], %g1
	mov	%g1, %o0
	call	_Znaj, 0
	 nop
	st	%o0, [%l0+4]
	ret
	restore
.LLFE1549:
	.size	_ZN5DListIcEC1Ei, .-_ZN5DListIcEC1Ei
	.section	".gnu.linkonce.t._ZN5DListIcED2Ev",#alloc,#execinstr
	.align 4
	.weak	_ZN5DListIcED2Ev
	.type	_ZN5DListIcED2Ev, #function
	.proc	020
_ZN5DListIcED2Ev:
.LLFB1551:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI27:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	ld	[%fp+68], %o5
	sethi	%hi(_ZTV5DListIcE+8), %g1
	or	%g1, %lo(_ZTV5DListIcE+8), %g1
	st	%g1, [%o5]
	ld	[%fp+68], %g1
	ld	[%g1+4], %g1
	cmp	%g1, 0
	be	.LL177
	nop
	ld	[%fp+68], %g1
	ld	[%g1+4], %o0
	call	_ZdlPv, 0
	 nop
.LL177:
	mov	1, %o5
	and	%o5, 0, %g1
	and	%g1, 0xff, %g1
	cmp	%g1, 0
	be	.LL174
	nop
	ld	[%fp+68], %o0
	call	_ZdlPv, 0
	 nop
.LL174:
	nop
	ret
	restore
.LLFE1551:
	.size	_ZN5DListIcED2Ev, .-_ZN5DListIcED2Ev
	.section	".gnu.linkonce.t._ZN5DListIcED1Ev",#alloc,#execinstr
	.align 4
	.weak	_ZN5DListIcED1Ev
	.type	_ZN5DListIcED1Ev, #function
	.proc	020
_ZN5DListIcED1Ev:
.LLFB1552:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI28:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	ld	[%fp+68], %o5
	sethi	%hi(_ZTV5DListIcE+8), %g1
	or	%g1, %lo(_ZTV5DListIcE+8), %g1
	st	%g1, [%o5]
	ld	[%fp+68], %g1
	ld	[%g1+4], %g1
	cmp	%g1, 0
	be	.LL182
	nop
	ld	[%fp+68], %g1
	ld	[%g1+4], %o0
	call	_ZdlPv, 0
	 nop
.LL182:
	mov	1, %o5
	and	%o5, 2, %g1
	and	%g1, 0xff, %g1
	cmp	%g1, 0
	be	.LL179
	nop
	ld	[%fp+68], %o0
	call	_ZdlPv, 0
	 nop
.LL179:
	nop
	ret
	restore
.LLFE1552:
	.size	_ZN5DListIcED1Ev, .-_ZN5DListIcED1Ev
	.section	".gnu.linkonce.t._ZN5DListIiEC1Ei",#alloc,#execinstr
	.align 4
	.weak	_ZN5DListIiEC1Ei
	.type	_ZN5DListIiEC1Ei, #function
	.proc	020
_ZN5DListIiEC1Ei:
.LLFB1556:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI29:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+68], %o5
	sethi	%hi(_ZTV5DListIiE+8), %g1
	or	%g1, %lo(_ZTV5DListIiE+8), %g1
	st	%g1, [%o5]
	ld	[%fp+68], %g1
	st	%g0, [%g1+8]
	ld	[%fp+68], %o5
	ld	[%fp+72], %g1
	st	%g1, [%o5+12]
	ld	[%fp+72], %g1
	cmp	%g1, 0
	bg	.LL185
	nop
	sethi	%hi(.LLC41), %g1
	or	%g1, %lo(.LLC41), %o0
	sethi	%hi(.LLC42), %g1
	or	%g1, %lo(.LLC42), %o1
	mov	19, %o2
	call	__assert, 0
	 nop
.LL185:
	ld	[%fp+68], %l0
	ld	[%fp+68], %g1
	ld	[%g1+12], %g1
	sll	%g1, 2, %g1
	mov	%g1, %o0
	call	_Znaj, 0
	 nop
	st	%o0, [%l0+4]
	ret
	restore
.LLFE1556:
	.size	_ZN5DListIiEC1Ei, .-_ZN5DListIiEC1Ei
	.section	".gnu.linkonce.t._ZN5DListIiED1Ev",#alloc,#execinstr
	.align 4
	.weak	_ZN5DListIiED1Ev
	.type	_ZN5DListIiED1Ev, #function
	.proc	020
_ZN5DListIiED1Ev:
.LLFB1559:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI30:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	ld	[%fp+68], %o5
	sethi	%hi(_ZTV5DListIiE+8), %g1
	or	%g1, %lo(_ZTV5DListIiE+8), %g1
	st	%g1, [%o5]
	ld	[%fp+68], %g1
	ld	[%g1+4], %g1
	cmp	%g1, 0
	be	.LL190
	nop
	ld	[%fp+68], %g1
	ld	[%g1+4], %o0
	call	_ZdlPv, 0
	 nop
.LL190:
	mov	1, %o5
	and	%o5, 2, %g1
	and	%g1, 0xff, %g1
	cmp	%g1, 0
	be	.LL187
	nop
	ld	[%fp+68], %o0
	call	_ZdlPv, 0
	 nop
.LL187:
	nop
	ret
	restore
.LLFE1559:
	.size	_ZN5DListIiED1Ev, .-_ZN5DListIiED1Ev
	.section	".gnu.linkonce.t._Z8showListIiEvRKSsR5DListIT_E",#alloc,#execinstr
	.align 4
	.weak	_Z8showListIiEvRKSsR5DListIT_E
	.type	_Z8showListIiEvRKSsR5DListIT_E, #function
	.proc	020
_Z8showListIiEvRKSsR5DListIT_E:
.LLFB1561:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI31:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC38), %g1
	or	%g1, %lo(.LLC38), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	ld	[%fp+72], %o1
	call	_ZlsIiERSoS0_RK5DListIT_E, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC39), %g1
	or	%g1, %lo(.LLC39), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %l0
	ld	[%fp+72], %o0
	call	_ZNK5DListIiE6lengthEv, 0
	 nop
	mov	%o0, %g1
	mov	%l0, %o0
	mov	%g1, %o1
	call	_ZNSolsEi, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC40), %g1
	or	%g1, %lo(.LLC40), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	ld	[%fp+68], %o1
	call	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E, 0
	 nop
	nop
	ret
	restore
.LLFE1561:
	.size	_Z8showListIiEvRKSsR5DListIT_E, .-_Z8showListIiEvRKSsR5DListIT_E
	.section	".rodata"
	.align 8
.LLC43:
	.asciz	" + "
	.align 8
.LLC44:
	.asciz	"["
	.align 8
.LLC45:
	.asciz	"] = "
	.section	".gnu.linkonce.t._Z6insertIcEvR5DListIT_ES1_S1_",#alloc,#execinstr
	.align 4
	.weak	_Z6insertIcEvR5DListIT_ES1_S1_
	.type	_Z6insertIcEvR5DListIT_ES1_S1_, #function
	.proc	020
_Z6insertIcEvR5DListIT_ES1_S1_:
.LLFB1562:
	!#PROLOGUE# 0
	save	%sp, -128, %sp
.LLCFI32:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	mov	%i1, %g1
	mov	%i2, %o5
	stb	%g1, [%fp+72]
	stb	%o5, [%fp+76]
	call	rand, 0
	 nop
	mov	%o0, %l0
	ld	[%fp+68], %o0
	call	_ZNK5DListIcE6lengthEv, 0
	 nop
	mov	%o0, %g1
	add	%g1, 1, %g1
	mov	%l0, %o0
	mov	%g1, %o1
	call	.rem, 0
	 nop
	mov	%o0, %g1
	st	%g1, [%fp-20]
	ldub	[%fp+72], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %o5
	ldub	[%fp+76], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %g1
	mov	%o5, %o0
	mov	%g1, %o1
	call	_Z12generateItemIcET_S0_S0_, 0
	 nop
	mov	%o0, %g1
	stb	%g1, [%fp-21]
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	mov	9, %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	ld	[%fp+68], %o1
	call	_ZlsIcERSoS0_RK5DListIT_E, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC43), %g1
	or	%g1, %lo(.LLC43), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %l0
	add	%fp, -28, %g1
	st	%g1, [%sp+64]
	mov	2, %o0
	call	_ZSt4setwi, 0
	nop
	unimp	4
	add	%fp, -28, %g1
	mov	%l0, %o0
	mov	%g1, %o1
	call	_ZStlsIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_St5_Setw, 0
	 nop
	mov	%o0, %o5
	ldub	[%fp-21], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %g1
	mov	%o5, %o0
	mov	%g1, %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC44), %g1
	or	%g1, %lo(.LLC44), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	ld	[%fp-20], %o1
	call	_ZNSolsEi, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC45), %g1
	or	%g1, %lo(.LLC45), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	add	%fp, -21, %g1
	ld	[%fp+68], %o0
	mov	%g1, %o1
	ld	[%fp-20], %o2
	call	_ZN5DListIcE6insertERKci, 0
	 nop
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	ld	[%fp+68], %o1
	call	_ZlsIcERSoS0_RK5DListIT_E, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_), %g1
	or	%g1, %lo(_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_), %o1
	call	_ZNSolsEPFRSoS_E, 0
	 nop
	nop
	ret
	restore
.LLFE1562:
	.size	_Z6insertIcEvR5DListIT_ES1_S1_, .-_Z6insertIcEvR5DListIT_ES1_S1_
	.section	".gnu.linkonce.t._ZSt4setwi",#alloc,#execinstr
	.align 4
	.weak	_ZSt4setwi
	.type	_ZSt4setwi, #function
	.proc	010
_ZSt4setwi:
.LLFB1446:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI33:
	!#PROLOGUE# 1
	ld	[%fp+64], %i5
	st	%i0, [%fp+68]
	ld	[%fp+68], %g1
	st	%g1, [%i5]
	mov	%i5, %i0
	jmp	%i7+12
	restore
.LLFE1446:
	.size	_ZSt4setwi, .-_ZSt4setwi
	.section	".gnu.linkonce.t._Z6insertIiEvR5DListIT_ES1_S1_",#alloc,#execinstr
	.align 4
	.weak	_Z6insertIiEvR5DListIT_ES1_S1_
	.type	_Z6insertIiEvR5DListIT_ES1_S1_, #function
	.proc	020
_Z6insertIiEvR5DListIT_ES1_S1_:
.LLFB1563:
	!#PROLOGUE# 0
	save	%sp, -128, %sp
.LLCFI34:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	st	%i2, [%fp+76]
	call	rand, 0
	 nop
	mov	%o0, %l0
	ld	[%fp+68], %o0
	call	_ZNK5DListIiE6lengthEv, 0
	 nop
	mov	%o0, %g1
	add	%g1, 1, %g1
	mov	%l0, %o0
	mov	%g1, %o1
	call	.rem, 0
	 nop
	mov	%o0, %g1
	st	%g1, [%fp-20]
	ld	[%fp+72], %o0
	ld	[%fp+76], %o1
	call	_Z12generateItemIiET_S0_S0_, 0
	 nop
	mov	%o0, %g1
	st	%g1, [%fp-24]
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	mov	9, %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	ld	[%fp+68], %o1
	call	_ZlsIiERSoS0_RK5DListIT_E, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC43), %g1
	or	%g1, %lo(.LLC43), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %l0
	add	%fp, -28, %g1
	st	%g1, [%sp+64]
	mov	2, %o0
	call	_ZSt4setwi, 0
	nop
	unimp	4
	add	%fp, -28, %g1
	mov	%l0, %o0
	mov	%g1, %o1
	call	_ZStlsIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_St5_Setw, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	ld	[%fp-24], %o1
	call	_ZNSolsEi, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC44), %g1
	or	%g1, %lo(.LLC44), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	ld	[%fp-20], %o1
	call	_ZNSolsEi, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC45), %g1
	or	%g1, %lo(.LLC45), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	add	%fp, -24, %g1
	ld	[%fp+68], %o0
	mov	%g1, %o1
	ld	[%fp-20], %o2
	call	_ZN5DListIiE6insertERKii, 0
	 nop
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	ld	[%fp+68], %o1
	call	_ZlsIiERSoS0_RK5DListIT_E, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_), %g1
	or	%g1, %lo(_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_), %o1
	call	_ZNSolsEPFRSoS_E, 0
	 nop
	nop
	ret
	restore
.LLFE1563:
	.size	_Z6insertIiEvR5DListIT_ES1_S1_, .-_Z6insertIiEvR5DListIT_ES1_S1_
	.section	".gnu.linkonce.t._Z6removeIcEvR5DListIT_E",#alloc,#execinstr
	.align 4
	.weak	_Z6removeIcEvR5DListIT_E
	.type	_Z6removeIcEvR5DListIT_E, #function
	.proc	020
_Z6removeIcEvR5DListIT_E:
.LLFB1564:
	!#PROLOGUE# 0
	save	%sp, -128, %sp
.LLCFI35:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	ld	[%fp+68], %o0
	call	_ZNK5DListIcE6lengthEv, 0
	 nop
	mov	%o0, %g1
	cmp	%g1, 0
	bg	.LL197
	nop
	b	.LL196
	 nop
.LL197:
	call	rand, 0
	 nop
	mov	%o0, %l0
	ld	[%fp+68], %o0
	call	_ZNK5DListIcE6lengthEv, 0
	 nop
	mov	%o0, %g1
	mov	%l0, %o0
	mov	%g1, %o1
	call	.rem, 0
	 nop
	mov	%o0, %g1
	st	%g1, [%fp-20]
	ld	[%fp+68], %o0
	ld	[%fp-20], %o1
	call	_ZN5DListIcEixEi, 0
	 nop
	mov	%o0, %g1
	ldub	[%g1], %g1
	stb	%g1, [%fp-21]
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC38), %g1
	or	%g1, %lo(.LLC38), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	ld	[%fp+68], %o1
	call	_ZlsIcERSoS0_RK5DListIT_E, 0
	 nop
	ld	[%fp+68], %o0
	ld	[%fp-20], %o1
	call	_ZN5DListIcE6removeEi, 0
	 nop
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC39), %g1
	or	%g1, %lo(.LLC39), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %l0
	add	%fp, -28, %g1
	st	%g1, [%sp+64]
	mov	2, %o0
	call	_ZSt4setwi, 0
	nop
	unimp	4
	add	%fp, -28, %g1
	mov	%l0, %o0
	mov	%g1, %o1
	call	_ZStlsIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_St5_Setw, 0
	 nop
	mov	%o0, %o5
	ldub	[%fp-21], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %g1
	mov	%o5, %o0
	mov	%g1, %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC44), %g1
	or	%g1, %lo(.LLC44), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	ld	[%fp-20], %o1
	call	_ZNSolsEi, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC45), %g1
	or	%g1, %lo(.LLC45), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	ld	[%fp+68], %o1
	call	_ZlsIcERSoS0_RK5DListIT_E, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_), %g1
	or	%g1, %lo(_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_), %o1
	call	_ZNSolsEPFRSoS_E, 0
	 nop
.LL196:
	nop
	ret
	restore
.LLFE1564:
	.size	_Z6removeIcEvR5DListIT_E, .-_Z6removeIcEvR5DListIT_E
	.section	".gnu.linkonce.t._Z6removeIiEvR5DListIT_E",#alloc,#execinstr
	.align 4
	.weak	_Z6removeIiEvR5DListIT_E
	.type	_Z6removeIiEvR5DListIT_E, #function
	.proc	020
_Z6removeIiEvR5DListIT_E:
.LLFB1565:
	!#PROLOGUE# 0
	save	%sp, -128, %sp
.LLCFI36:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	ld	[%fp+68], %o0
	call	_ZNK5DListIiE6lengthEv, 0
	 nop
	mov	%o0, %g1
	cmp	%g1, 0
	bg	.LL199
	nop
	b	.LL198
	 nop
.LL199:
	call	rand, 0
	 nop
	mov	%o0, %l0
	ld	[%fp+68], %o0
	call	_ZNK5DListIiE6lengthEv, 0
	 nop
	mov	%o0, %g1
	mov	%l0, %o0
	mov	%g1, %o1
	call	.rem, 0
	 nop
	mov	%o0, %g1
	st	%g1, [%fp-20]
	ld	[%fp+68], %o0
	ld	[%fp-20], %o1
	call	_ZN5DListIiEixEi, 0
	 nop
	mov	%o0, %g1
	ld	[%g1], %g1
	st	%g1, [%fp-24]
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC38), %g1
	or	%g1, %lo(.LLC38), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	ld	[%fp+68], %o1
	call	_ZlsIiERSoS0_RK5DListIT_E, 0
	 nop
	ld	[%fp+68], %o0
	ld	[%fp-20], %o1
	call	_ZN5DListIiE6removeEi, 0
	 nop
	sethi	%hi(_ZSt4cout), %g1
	or	%g1, %lo(_ZSt4cout), %o0
	sethi	%hi(.LLC39), %g1
	or	%g1, %lo(.LLC39), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %l0
	add	%fp, -28, %g1
	st	%g1, [%sp+64]
	mov	2, %o0
	call	_ZSt4setwi, 0
	nop
	unimp	4
	add	%fp, -28, %g1
	mov	%l0, %o0
	mov	%g1, %o1
	call	_ZStlsIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_St5_Setw, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	ld	[%fp-24], %o1
	call	_ZNSolsEi, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC44), %g1
	or	%g1, %lo(.LLC44), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	ld	[%fp-20], %o1
	call	_ZNSolsEi, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC45), %g1
	or	%g1, %lo(.LLC45), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	ld	[%fp+68], %o1
	call	_ZlsIiERSoS0_RK5DListIT_E, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	sethi	%hi(_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_), %g1
	or	%g1, %lo(_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_), %o1
	call	_ZNSolsEPFRSoS_E, 0
	 nop
.LL198:
	nop
	ret
	restore
.LLFE1565:
	.size	_Z6removeIiEvR5DListIT_E, .-_Z6removeIiEvR5DListIT_E
	.section	".rodata"
	.align 8
.LLC46:
	.asciz	" -- Parameter list"
	.align 8
.LLC47:
	.asciz	" -- List Made by CC"
	.align 8
.LLC48:
	.asciz	" -- List to CC after 1 removal"
	.align 8
.LLC49:
	.asciz	" -- Parameter List"
	.section	".gnu.linkonce.t._Z19testCopyConstructorIcEvR5DListIT_E",#alloc,#execinstr
	.align 4
	.weak	_Z19testCopyConstructorIcEvR5DListIT_E
	.type	_Z19testCopyConstructorIcEvR5DListIT_E, #function
	.proc	020
_Z19testCopyConstructorIcEvR5DListIT_E:
.LLFB1566:
	!#PROLOGUE# 0
	save	%sp, -152, %sp
.LLCFI37:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	add	%fp, -32, %g1
	mov	%g1, %o0
	ld	[%fp+68], %o1
.LLEHB27:
	call	_ZN5DListIcEC1ERKS0_, 0
	 nop
.LLEHE27:
	add	%fp, -48, %g1
	mov	%g1, %o0
	call	_ZNSaIcEC1Ev, 0
	 nop
	add	%fp, -48, %o5
	add	%fp, -40, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC46), %g1
	or	%g1, %lo(.LLC46), %o1
	mov	%o5, %o2
.LLEHB28:
	call	_ZNSsC1EPKcRKSaIcE, 0
	 nop
.LLEHE28:
	add	%fp, -40, %g1
	mov	%g1, %o0
	ld	[%fp+68], %o1
.LLEHB29:
	call	_Z8showListIcEvRKSsR5DListIT_E, 0
	 nop
.LLEHE29:
	b	.LL202
	 nop
.LL243:
	st	%i0, [%fp-52]
.LL201:
	ld	[%fp-52], %l0
	add	%fp, -40, %g1
	mov	%g1, %o0
	call	_ZNSsD1Ev, 0
	 nop
	st	%l0, [%fp-52]
.LL203:
	b	.LL205
	 nop
.LL202:
	add	%fp, -40, %g1
	mov	%g1, %o0
.LLEHB30:
	call	_ZNSsD1Ev, 0
	 nop
.LLEHE30:
	b	.LL206
	 nop
.LL244:
	st	%i0, [%fp-52]
.LL205:
	ld	[%fp-52], %l0
	add	%fp, -48, %g1
	mov	%g1, %o0
	call	_ZNSaIcED1Ev, 0
	 nop
	st	%l0, [%fp-52]
.LL207:
	b	.LL233
	 nop
.LL206:
	add	%fp, -48, %g1
	mov	%g1, %o0
	call	_ZNSaIcED1Ev, 0
	 nop
	add	%fp, -40, %g1
	mov	%g1, %o0
	call	_ZNSaIcEC1Ev, 0
	 nop
	add	%fp, -40, %o5
	add	%fp, -48, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC47), %g1
	or	%g1, %lo(.LLC47), %o1
	mov	%o5, %o2
.LLEHB31:
	call	_ZNSsC1EPKcRKSaIcE, 0
	 nop
.LLEHE31:
	add	%fp, -48, %g1
	add	%fp, -32, %o5
	mov	%g1, %o0
	mov	%o5, %o1
.LLEHB32:
	call	_Z8showListIcEvRKSsR5DListIT_E, 0
	 nop
.LLEHE32:
	b	.LL210
	 nop
.LL241:
	st	%i0, [%fp-52]
.LL209:
	ld	[%fp-52], %l0
	add	%fp, -48, %g1
	mov	%g1, %o0
	call	_ZNSsD1Ev, 0
	 nop
	st	%l0, [%fp-52]
.LL211:
	b	.LL213
	 nop
.LL210:
	add	%fp, -48, %g1
	mov	%g1, %o0
.LLEHB33:
	call	_ZNSsD1Ev, 0
	 nop
.LLEHE33:
	b	.LL214
	 nop
.LL242:
	st	%i0, [%fp-52]
.LL213:
	ld	[%fp-52], %l0
	add	%fp, -40, %g1
	mov	%g1, %o0
	call	_ZNSaIcED1Ev, 0
	 nop
	st	%l0, [%fp-52]
.LL215:
	b	.LL233
	 nop
.LL214:
	add	%fp, -40, %g1
	mov	%g1, %o0
	call	_ZNSaIcED1Ev, 0
	 nop
	add	%fp, -32, %g1
	mov	%g1, %o0
.LLEHB34:
	call	_Z6removeIcEvR5DListIT_E, 0
	 nop
.LLEHE34:
	add	%fp, -40, %g1
	mov	%g1, %o0
	call	_ZNSaIcEC1Ev, 0
	 nop
	add	%fp, -40, %o5
	add	%fp, -48, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC48), %g1
	or	%g1, %lo(.LLC48), %o1
	mov	%o5, %o2
.LLEHB35:
	call	_ZNSsC1EPKcRKSaIcE, 0
	 nop
.LLEHE35:
	add	%fp, -48, %g1
	add	%fp, -32, %o5
	mov	%g1, %o0
	mov	%o5, %o1
.LLEHB36:
	call	_Z8showListIcEvRKSsR5DListIT_E, 0
	 nop
.LLEHE36:
	b	.LL218
	 nop
.LL239:
	st	%i0, [%fp-52]
.LL217:
	ld	[%fp-52], %l0
	add	%fp, -48, %g1
	mov	%g1, %o0
	call	_ZNSsD1Ev, 0
	 nop
	st	%l0, [%fp-52]
.LL219:
	b	.LL221
	 nop
.LL218:
	add	%fp, -48, %g1
	mov	%g1, %o0
.LLEHB37:
	call	_ZNSsD1Ev, 0
	 nop
.LLEHE37:
	b	.LL222
	 nop
.LL240:
	st	%i0, [%fp-52]
.LL221:
	ld	[%fp-52], %l0
	add	%fp, -40, %g1
	mov	%g1, %o0
	call	_ZNSaIcED1Ev, 0
	 nop
	st	%l0, [%fp-52]
.LL223:
	b	.LL233
	 nop
.LL222:
	add	%fp, -40, %g1
	mov	%g1, %o0
	call	_ZNSaIcED1Ev, 0
	 nop
	add	%fp, -40, %g1
	mov	%g1, %o0
	call	_ZNSaIcEC1Ev, 0
	 nop
	add	%fp, -40, %o5
	add	%fp, -48, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC49), %g1
	or	%g1, %lo(.LLC49), %o1
	mov	%o5, %o2
.LLEHB38:
	call	_ZNSsC1EPKcRKSaIcE, 0
	 nop
.LLEHE38:
	add	%fp, -48, %g1
	mov	%g1, %o0
	ld	[%fp+68], %o1
.LLEHB39:
	call	_Z8showListIcEvRKSsR5DListIT_E, 0
	 nop
.LLEHE39:
	b	.LL226
	 nop
.LL237:
	st	%i0, [%fp-52]
.LL225:
	ld	[%fp-52], %l0
	add	%fp, -48, %g1
	mov	%g1, %o0
	call	_ZNSsD1Ev, 0
	 nop
	st	%l0, [%fp-52]
.LL227:
	b	.LL229
	 nop
.LL226:
	add	%fp, -48, %g1
	mov	%g1, %o0
.LLEHB40:
	call	_ZNSsD1Ev, 0
	 nop
.LLEHE40:
	b	.LL230
	 nop
.LL238:
	st	%i0, [%fp-52]
.LL229:
	ld	[%fp-52], %l0
	add	%fp, -40, %g1
	mov	%g1, %o0
	call	_ZNSaIcED1Ev, 0
	 nop
	st	%l0, [%fp-52]
.LL231:
	b	.LL233
	 nop
.LL230:
	add	%fp, -40, %g1
	mov	%g1, %o0
	call	_ZNSaIcED1Ev, 0
	 nop
	b	.LL234
	 nop
.LL245:
	st	%i0, [%fp-52]
.LL233:
	ld	[%fp-52], %l0
	add	%fp, -32, %g1
	mov	%g1, %o0
	call	_ZN5DListIcED1Ev, 0
	 nop
	st	%l0, [%fp-52]
.LL235:
	ld	[%fp-52], %o0
.LLEHB41:
	call	_Unwind_Resume, 0
	 nop
.LLEHE41:
.LL234:
	add	%fp, -32, %g1
	mov	%g1, %o0
	call	_ZN5DListIcED1Ev, 0
	 nop
	nop
	ret
	restore
.LLFE1566:
	.size	_Z19testCopyConstructorIcEvR5DListIT_E, .-_Z19testCopyConstructorIcEvR5DListIT_E
	.section	".gcc_except_table",#alloc,#write
.LLLSDA1566:
	.byte	0xff
	.byte	0xff
	.byte	0x3
	.byte	0xc3,0x1
	.uaword	.LLEHB27-.LLFB1566
	.uaword	.LLEHE27-.LLEHB27
	.uaword	0x0
	.byte	0x0
	.uaword	.LLEHB28-.LLFB1566
	.uaword	.LLEHE28-.LLEHB28
	.uaword	.LL244-.LLFB1566
	.byte	0x0
	.uaword	.LLEHB29-.LLFB1566
	.uaword	.LLEHE29-.LLEHB29
	.uaword	.LL243-.LLFB1566
	.byte	0x0
	.uaword	.LLEHB30-.LLFB1566
	.uaword	.LLEHE30-.LLEHB30
	.uaword	.LL244-.LLFB1566
	.byte	0x0
	.uaword	.LLEHB31-.LLFB1566
	.uaword	.LLEHE31-.LLEHB31
	.uaword	.LL242-.LLFB1566
	.byte	0x0
	.uaword	.LLEHB32-.LLFB1566
	.uaword	.LLEHE32-.LLEHB32
	.uaword	.LL241-.LLFB1566
	.byte	0x0
	.uaword	.LLEHB33-.LLFB1566
	.uaword	.LLEHE33-.LLEHB33
	.uaword	.LL242-.LLFB1566
	.byte	0x0
	.uaword	.LLEHB34-.LLFB1566
	.uaword	.LLEHE34-.LLEHB34
	.uaword	.LL245-.LLFB1566
	.byte	0x0
	.uaword	.LLEHB35-.LLFB1566
	.uaword	.LLEHE35-.LLEHB35
	.uaword	.LL240-.LLFB1566
	.byte	0x0
	.uaword	.LLEHB36-.LLFB1566
	.uaword	.LLEHE36-.LLEHB36
	.uaword	.LL239-.LLFB1566
	.byte	0x0
	.uaword	.LLEHB37-.LLFB1566
	.uaword	.LLEHE37-.LLEHB37
	.uaword	.LL240-.LLFB1566
	.byte	0x0
	.uaword	.LLEHB38-.LLFB1566
	.uaword	.LLEHE38-.LLEHB38
	.uaword	.LL238-.LLFB1566
	.byte	0x0
	.uaword	.LLEHB39-.LLFB1566
	.uaword	.LLEHE39-.LLEHB39
	.uaword	.LL237-.LLFB1566
	.byte	0x0
	.uaword	.LLEHB40-.LLFB1566
	.uaword	.LLEHE40-.LLEHB40
	.uaword	.LL238-.LLFB1566
	.byte	0x0
	.uaword	.LLEHB41-.LLFB1566
	.uaword	.LLEHE41-.LLEHB41
	.uaword	0x0
	.byte	0x0
	.section	".gnu.linkonce.t._Z19testCopyConstructorIcEvR5DListIT_E",#alloc,#execinstr
	.section	".rodata"
	.align 8
.LLC50:
	.asciz	"-- list on right of ="
	.align 8
.LLC51:
	.asciz	"-- list on left of ="
	.align 8
.LLC52:
	.asciz	"-- left list after one removed"
	.align 8
.LLC53:
	.asciz	"-- right list with/o change"
	.section	".gnu.linkonce.t._Z12testAssignOpIiEvR5DListIT_E",#alloc,#execinstr
	.align 4
	.weak	_Z12testAssignOpIiEvR5DListIT_E
	.type	_Z12testAssignOpIiEvR5DListIT_E, #function
	.proc	020
_Z12testAssignOpIiEvR5DListIT_E:
.LLFB1567:
	!#PROLOGUE# 0
	save	%sp, -152, %sp
.LLCFI38:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	add	%fp, -32, %g1
	mov	%g1, %o0
	mov	10, %o1
.LLEHB42:
	call	_ZN5DListIiEC1Ei, 0
	 nop
.LLEHE42:
	add	%fp, -32, %g1
	mov	%g1, %o0
	ld	[%fp+68], %o1
.LLEHB43:
	call	_ZN5DListIiEaSERKS0_, 0
	 nop
.LLEHE43:
	add	%fp, -48, %g1
	mov	%g1, %o0
	call	_ZNSaIcEC1Ev, 0
	 nop
	add	%fp, -48, %o5
	add	%fp, -40, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC50), %g1
	or	%g1, %lo(.LLC50), %o1
	mov	%o5, %o2
.LLEHB44:
	call	_ZNSsC1EPKcRKSaIcE, 0
	 nop
.LLEHE44:
	add	%fp, -40, %g1
	mov	%g1, %o0
	ld	[%fp+68], %o1
.LLEHB45:
	call	_Z8showListIiEvRKSsR5DListIT_E, 0
	 nop
.LLEHE45:
	b	.LL248
	 nop
.LL289:
	st	%i0, [%fp-52]
.LL247:
	ld	[%fp-52], %l0
	add	%fp, -40, %g1
	mov	%g1, %o0
	call	_ZNSsD1Ev, 0
	 nop
	st	%l0, [%fp-52]
.LL249:
	b	.LL251
	 nop
.LL248:
	add	%fp, -40, %g1
	mov	%g1, %o0
.LLEHB46:
	call	_ZNSsD1Ev, 0
	 nop
.LLEHE46:
	b	.LL252
	 nop
.LL290:
	st	%i0, [%fp-52]
.LL251:
	ld	[%fp-52], %l0
	add	%fp, -48, %g1
	mov	%g1, %o0
	call	_ZNSaIcED1Ev, 0
	 nop
	st	%l0, [%fp-52]
.LL253:
	b	.LL279
	 nop
.LL252:
	add	%fp, -48, %g1
	mov	%g1, %o0
	call	_ZNSaIcED1Ev, 0
	 nop
	add	%fp, -40, %g1
	mov	%g1, %o0
	call	_ZNSaIcEC1Ev, 0
	 nop
	add	%fp, -40, %o5
	add	%fp, -48, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC51), %g1
	or	%g1, %lo(.LLC51), %o1
	mov	%o5, %o2
.LLEHB47:
	call	_ZNSsC1EPKcRKSaIcE, 0
	 nop
.LLEHE47:
	add	%fp, -48, %g1
	add	%fp, -32, %o5
	mov	%g1, %o0
	mov	%o5, %o1
.LLEHB48:
	call	_Z8showListIiEvRKSsR5DListIT_E, 0
	 nop
.LLEHE48:
	b	.LL256
	 nop
.LL287:
	st	%i0, [%fp-52]
.LL255:
	ld	[%fp-52], %l0
	add	%fp, -48, %g1
	mov	%g1, %o0
	call	_ZNSsD1Ev, 0
	 nop
	st	%l0, [%fp-52]
.LL257:
	b	.LL259
	 nop
.LL256:
	add	%fp, -48, %g1
	mov	%g1, %o0
.LLEHB49:
	call	_ZNSsD1Ev, 0
	 nop
.LLEHE49:
	b	.LL260
	 nop
.LL288:
	st	%i0, [%fp-52]
.LL259:
	ld	[%fp-52], %l0
	add	%fp, -40, %g1
	mov	%g1, %o0
	call	_ZNSaIcED1Ev, 0
	 nop
	st	%l0, [%fp-52]
.LL261:
	b	.LL279
	 nop
.LL260:
	add	%fp, -40, %g1
	mov	%g1, %o0
	call	_ZNSaIcED1Ev, 0
	 nop
	add	%fp, -32, %g1
	mov	%g1, %o0
.LLEHB50:
	call	_Z6removeIiEvR5DListIT_E, 0
	 nop
.LLEHE50:
	add	%fp, -40, %g1
	mov	%g1, %o0
	call	_ZNSaIcEC1Ev, 0
	 nop
	add	%fp, -40, %o5
	add	%fp, -48, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC52), %g1
	or	%g1, %lo(.LLC52), %o1
	mov	%o5, %o2
.LLEHB51:
	call	_ZNSsC1EPKcRKSaIcE, 0
	 nop
.LLEHE51:
	add	%fp, -48, %g1
	add	%fp, -32, %o5
	mov	%g1, %o0
	mov	%o5, %o1
.LLEHB52:
	call	_Z8showListIiEvRKSsR5DListIT_E, 0
	 nop
.LLEHE52:
	b	.LL264
	 nop
.LL285:
	st	%i0, [%fp-52]
.LL263:
	ld	[%fp-52], %l0
	add	%fp, -48, %g1
	mov	%g1, %o0
	call	_ZNSsD1Ev, 0
	 nop
	st	%l0, [%fp-52]
.LL265:
	b	.LL267
	 nop
.LL264:
	add	%fp, -48, %g1
	mov	%g1, %o0
.LLEHB53:
	call	_ZNSsD1Ev, 0
	 nop
.LLEHE53:
	b	.LL268
	 nop
.LL286:
	st	%i0, [%fp-52]
.LL267:
	ld	[%fp-52], %l0
	add	%fp, -40, %g1
	mov	%g1, %o0
	call	_ZNSaIcED1Ev, 0
	 nop
	st	%l0, [%fp-52]
.LL269:
	b	.LL279
	 nop
.LL268:
	add	%fp, -40, %g1
	mov	%g1, %o0
	call	_ZNSaIcED1Ev, 0
	 nop
	add	%fp, -40, %g1
	mov	%g1, %o0
	call	_ZNSaIcEC1Ev, 0
	 nop
	add	%fp, -40, %o5
	add	%fp, -48, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC53), %g1
	or	%g1, %lo(.LLC53), %o1
	mov	%o5, %o2
.LLEHB54:
	call	_ZNSsC1EPKcRKSaIcE, 0
	 nop
.LLEHE54:
	add	%fp, -48, %g1
	mov	%g1, %o0
	ld	[%fp+68], %o1
.LLEHB55:
	call	_Z8showListIiEvRKSsR5DListIT_E, 0
	 nop
.LLEHE55:
	b	.LL272
	 nop
.LL283:
	st	%i0, [%fp-52]
.LL271:
	ld	[%fp-52], %l0
	add	%fp, -48, %g1
	mov	%g1, %o0
	call	_ZNSsD1Ev, 0
	 nop
	st	%l0, [%fp-52]
.LL273:
	b	.LL275
	 nop
.LL272:
	add	%fp, -48, %g1
	mov	%g1, %o0
.LLEHB56:
	call	_ZNSsD1Ev, 0
	 nop
.LLEHE56:
	b	.LL276
	 nop
.LL284:
	st	%i0, [%fp-52]
.LL275:
	ld	[%fp-52], %l0
	add	%fp, -40, %g1
	mov	%g1, %o0
	call	_ZNSaIcED1Ev, 0
	 nop
	st	%l0, [%fp-52]
.LL277:
	b	.LL279
	 nop
.LL276:
	add	%fp, -40, %g1
	mov	%g1, %o0
	call	_ZNSaIcED1Ev, 0
	 nop
	b	.LL280
	 nop
.LL291:
	st	%i0, [%fp-52]
.LL279:
	ld	[%fp-52], %l0
	add	%fp, -32, %g1
	mov	%g1, %o0
	call	_ZN5DListIiED1Ev, 0
	 nop
	st	%l0, [%fp-52]
.LL281:
	ld	[%fp-52], %o0
.LLEHB57:
	call	_Unwind_Resume, 0
	 nop
.LLEHE57:
.LL280:
	add	%fp, -32, %g1
	mov	%g1, %o0
	call	_ZN5DListIiED1Ev, 0
	 nop
	nop
	ret
	restore
.LLFE1567:
	.size	_Z12testAssignOpIiEvR5DListIT_E, .-_Z12testAssignOpIiEvR5DListIT_E
	.section	".gcc_except_table",#alloc,#write
.LLLSDA1567:
	.byte	0xff
	.byte	0xff
	.byte	0x3
	.byte	0xd0,0x1
	.uaword	.LLEHB42-.LLFB1567
	.uaword	.LLEHE42-.LLEHB42
	.uaword	0x0
	.byte	0x0
	.uaword	.LLEHB43-.LLFB1567
	.uaword	.LLEHE43-.LLEHB43
	.uaword	.LL291-.LLFB1567
	.byte	0x0
	.uaword	.LLEHB44-.LLFB1567
	.uaword	.LLEHE44-.LLEHB44
	.uaword	.LL290-.LLFB1567
	.byte	0x0
	.uaword	.LLEHB45-.LLFB1567
	.uaword	.LLEHE45-.LLEHB45
	.uaword	.LL289-.LLFB1567
	.byte	0x0
	.uaword	.LLEHB46-.LLFB1567
	.uaword	.LLEHE46-.LLEHB46
	.uaword	.LL290-.LLFB1567
	.byte	0x0
	.uaword	.LLEHB47-.LLFB1567
	.uaword	.LLEHE47-.LLEHB47
	.uaword	.LL288-.LLFB1567
	.byte	0x0
	.uaword	.LLEHB48-.LLFB1567
	.uaword	.LLEHE48-.LLEHB48
	.uaword	.LL287-.LLFB1567
	.byte	0x0
	.uaword	.LLEHB49-.LLFB1567
	.uaword	.LLEHE49-.LLEHB49
	.uaword	.LL288-.LLFB1567
	.byte	0x0
	.uaword	.LLEHB50-.LLFB1567
	.uaword	.LLEHE50-.LLEHB50
	.uaword	.LL291-.LLFB1567
	.byte	0x0
	.uaword	.LLEHB51-.LLFB1567
	.uaword	.LLEHE51-.LLEHB51
	.uaword	.LL286-.LLFB1567
	.byte	0x0
	.uaword	.LLEHB52-.LLFB1567
	.uaword	.LLEHE52-.LLEHB52
	.uaword	.LL285-.LLFB1567
	.byte	0x0
	.uaword	.LLEHB53-.LLFB1567
	.uaword	.LLEHE53-.LLEHB53
	.uaword	.LL286-.LLFB1567
	.byte	0x0
	.uaword	.LLEHB54-.LLFB1567
	.uaword	.LLEHE54-.LLEHB54
	.uaword	.LL284-.LLFB1567
	.byte	0x0
	.uaword	.LLEHB55-.LLFB1567
	.uaword	.LLEHE55-.LLEHB55
	.uaword	.LL283-.LLFB1567
	.byte	0x0
	.uaword	.LLEHB56-.LLFB1567
	.uaword	.LLEHE56-.LLEHB56
	.uaword	.LL284-.LLFB1567
	.byte	0x0
	.uaword	.LLEHB57-.LLFB1567
	.uaword	.LLEHE57-.LLEHB57
	.uaword	0x0
	.byte	0x0
	.section	".gnu.linkonce.t._Z12testAssignOpIiEvR5DListIT_E",#alloc,#execinstr
	.section	".rodata"
	.align 8
.LLC54:
	.asciz	"pos >= 0 && pos <= iSize"
	.section	".gnu.linkonce.t._ZN5DListIcE6insertERKci",#alloc,#execinstr
	.align 4
	.weak	_ZN5DListIcE6insertERKci
	.type	_ZN5DListIcE6insertERKci, #function
	.proc	020
_ZN5DListIcE6insertERKci:
.LLFB1570:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
.LLCFI39:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	st	%i2, [%fp+76]
	ld	[%fp+76], %g1
	cmp	%g1, 0
	bl	.LL295
	nop
	ld	[%fp+68], %g1
	ld	[%g1+8], %o5
	ld	[%fp+76], %g1
	cmp	%o5, %g1
	bge	.LL293
	nop
.LL295:
	sethi	%hi(.LLC54), %g1
	or	%g1, %lo(.LLC54), %o0
	sethi	%hi(.LLC42), %g1
	or	%g1, %lo(.LLC42), %o1
	mov	55, %o2
	call	__assert, 0
	 nop
.LL293:
	ld	[%fp+68], %g1
	ld	[%fp+68], %o5
	ld	[%g1+8], %o4
	ld	[%o5+12], %g1
	cmp	%o4, %g1
	bne	.LL296
	nop
	ld	[%fp+68], %o5
	ld	[%fp+68], %g1
	ld	[%g1+12], %g1
	add	%g1, %g1, %g1
	st	%g1, [%o5+12]
	ld	[%fp+68], %g1
	ld	[%g1+12], %g1
	mov	%g1, %o0
	call	_Znaj, 0
	 nop
	st	%o0, [%fp-20]
	st	%g0, [%fp-24]
.LL297:
	ld	[%fp+68], %g1
	ld	[%g1+8], %o5
	ld	[%fp-24], %g1
	cmp	%o5, %g1
	ble	.LL298
	nop
	ld	[%fp-20], %o5
	ld	[%fp-24], %g1
	add	%o5, %g1, %o4
	ld	[%fp+68], %g1
	ld	[%g1+4], %o5
	ld	[%fp-24], %g1
	add	%o5, %g1, %g1
	ldub	[%g1], %g1
	stb	%g1, [%o4]
	ld	[%fp-24], %g1
	add	%g1, 1, %g1
	st	%g1, [%fp-24]
	b	.LL297
	 nop
.LL298:
	ld	[%fp+68], %g1
	ld	[%g1+4], %g1
	cmp	%g1, 0
	be	.LL301
	nop
	ld	[%fp+68], %g1
	ld	[%g1+4], %o0
	call	_ZdaPv, 0
	 nop
.LL301:
	ld	[%fp+68], %o5
	ld	[%fp-20], %g1
	st	%g1, [%o5+4]
.LL296:
	ld	[%fp+68], %g1
	ld	[%g1+8], %g1
	st	%g1, [%fp-24]
.LL302:
	ld	[%fp-24], %o5
	ld	[%fp+76], %g1
	cmp	%o5, %g1
	ble	.LL303
	nop
	ld	[%fp+68], %g1
	ld	[%g1+4], %o5
	ld	[%fp-24], %g1
	add	%o5, %g1, %o4
	ld	[%fp+68], %g1
	ld	[%g1+4], %o5
	ld	[%fp-24], %g1
	add	%o5, %g1, %g1
	ldub	[%g1-1], %g1
	stb	%g1, [%o4]
	ld	[%fp-24], %g1
	add	%g1, -1, %g1
	st	%g1, [%fp-24]
	b	.LL302
	 nop
.LL303:
	ld	[%fp+68], %g1
	ld	[%g1+4], %o5
	ld	[%fp+76], %g1
	add	%o5, %g1, %o5
	ld	[%fp+72], %g1
	ldub	[%g1], %g1
	stb	%g1, [%o5]
	ld	[%fp+68], %o5
	ld	[%fp+68], %g1
	ld	[%g1+8], %g1
	add	%g1, 1, %g1
	st	%g1, [%o5+8]
	ret
	restore
.LLFE1570:
	.size	_ZN5DListIcE6insertERKci, .-_ZN5DListIcE6insertERKci
	.section	".gnu.linkonce.t._ZNK5DListIcE3getEi",#alloc,#execinstr
	.align 4
	.weak	_ZNK5DListIcE3getEi
	.type	_ZNK5DListIcE3getEi, #function
	.proc	0102
_ZNK5DListIcE3getEi:
.LLFB1571:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI40:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+68], %g1
	ld	[%g1+4], %i5
	ld	[%fp+72], %g1
	add	%i5, %g1, %g1
	mov	%g1, %i0
	ret
	restore
.LLFE1571:
	.size	_ZNK5DListIcE3getEi, .-_ZNK5DListIcE3getEi
	.section	".rodata"
	.align 8
.LLC55:
	.asciz	"pos >= 0 && pos < DList<T>::iSize"
	.section	".gnu.linkonce.t._ZN5DListIcE6removeEi",#alloc,#execinstr
	.align 4
	.weak	_ZN5DListIcE6removeEi
	.type	_ZN5DListIcE6removeEi, #function
	.proc	020
_ZN5DListIcE6removeEi:
.LLFB1572:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
.LLCFI41:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+72], %g1
	cmp	%g1, 0
	bl	.LL309
	nop
	ld	[%fp+68], %g1
	ld	[%g1+8], %o5
	ld	[%fp+72], %g1
	cmp	%o5, %g1
	bg	.LL307
	nop
.LL309:
	sethi	%hi(.LLC55), %g1
	or	%g1, %lo(.LLC55), %o0
	sethi	%hi(.LLC42), %g1
	or	%g1, %lo(.LLC42), %o1
	mov	83, %o2
	call	__assert, 0
	 nop
.LL307:
	ld	[%fp+72], %g1
	st	%g1, [%fp-20]
.LL310:
	ld	[%fp+68], %g1
	ld	[%g1+8], %g1
	add	%g1, -1, %o5
	ld	[%fp-20], %g1
	cmp	%o5, %g1
	ble	.LL311
	nop
	ld	[%fp+68], %g1
	ld	[%g1+4], %o5
	ld	[%fp-20], %g1
	add	%o5, %g1, %o4
	ld	[%fp+68], %g1
	ld	[%g1+4], %o5
	ld	[%fp-20], %g1
	add	%o5, %g1, %g1
	ldub	[%g1+1], %g1
	stb	%g1, [%o4]
	ld	[%fp-20], %g1
	add	%g1, 1, %g1
	st	%g1, [%fp-20]
	b	.LL310
	 nop
.LL311:
	ld	[%fp+68], %o5
	ld	[%fp+68], %g1
	ld	[%g1+8], %g1
	add	%g1, -1, %g1
	st	%g1, [%o5+8]
	ret
	restore
.LLFE1572:
	.size	_ZN5DListIcE6removeEi, .-_ZN5DListIcE6removeEi
	.section	".gnu.linkonce.t._ZN5DListIcEixEi",#alloc,#execinstr
	.align 4
	.weak	_ZN5DListIcEixEi
	.type	_ZN5DListIcEixEi, #function
	.proc	0102
_ZN5DListIcEixEi:
.LLFB1573:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI42:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+68], %g1
	ld	[%g1+4], %i5
	ld	[%fp+72], %g1
	add	%i5, %g1, %g1
	mov	%g1, %i0
	ret
	restore
.LLFE1573:
	.size	_ZN5DListIcEixEi, .-_ZN5DListIcEixEi
	.section	".rodata"
	.align 8
.LLC56:
	.asciz	"( "
	.align 8
.LLC57:
	.asciz	""
	.align 8
.LLC58:
	.asciz	", "
	.align 8
.LLC59:
	.asciz	" )"
	.section	".gnu.linkonce.t._ZlsIcERSoS0_RK5DListIT_E",#alloc,#execinstr
	.align 4
	.weak	_ZlsIcERSoS0_RK5DListIT_E
	.type	_ZlsIcERSoS0_RK5DListIT_E, #function
	.proc	0110
_ZlsIcERSoS0_RK5DListIT_E:
.LLFB1585:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
.LLCFI43:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+68], %o0
	sethi	%hi(.LLC56), %g1
	or	%g1, %lo(.LLC56), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	st	%g0, [%fp-20]
.LL315:
	ld	[%fp+72], %o0
	call	_ZNK5DListIcE6lengthEv, 0
	 nop
	mov	%o0, %o5
	ld	[%fp-20], %g1
	cmp	%o5, %g1
	ble	.LL316
	nop
	ld	[%fp-20], %g1
	cmp	%g1, 0
	bne	.LL318
	nop
	sethi	%hi(.LLC57), %g1
	or	%g1, %lo(.LLC57), %g1
	st	%g1, [%fp-24]
	b	.LL319
	 nop
.LL318:
	sethi	%hi(.LLC58), %g1
	or	%g1, %lo(.LLC58), %g1
	st	%g1, [%fp-24]
.LL319:
	ld	[%fp+68], %o0
	ld	[%fp-24], %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %o4
	ld	[%fp+72], %g1
	ld	[%g1+4], %o5
	ld	[%fp-20], %g1
	add	%o5, %g1, %g1
	ldub	[%g1], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %g1
	mov	%o4, %o0
	mov	%g1, %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c, 0
	 nop
	ld	[%fp-20], %g1
	add	%g1, 1, %g1
	st	%g1, [%fp-20]
	b	.LL315
	 nop
.LL316:
	ld	[%fp+68], %o0
	sethi	%hi(.LLC59), %g1
	or	%g1, %lo(.LLC59), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	ld	[%fp+68], %g1
	mov	%g1, %i0
	ret
	restore
.LLFE1585:
	.size	_ZlsIcERSoS0_RK5DListIT_E, .-_ZlsIcERSoS0_RK5DListIT_E
	.section	".gnu.linkonce.t._ZNK5DListIcE6lengthEv",#alloc,#execinstr
	.align 4
	.weak	_ZNK5DListIcE6lengthEv
	.type	_ZNK5DListIcE6lengthEv, #function
	.proc	04
_ZNK5DListIcE6lengthEv:
.LLFB1586:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI44:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	ld	[%fp+68], %g1
	ld	[%g1+8], %g1
	mov	%g1, %i0
	ret
	restore
.LLFE1586:
	.size	_ZNK5DListIcE6lengthEv, .-_ZNK5DListIcE6lengthEv
	.section	".gnu.linkonce.t._ZN7DSQueueIcE4findERKc",#alloc,#execinstr
	.align 4
	.weak	_ZN7DSQueueIcE4findERKc
	.type	_ZN7DSQueueIcE4findERKc, #function
	.proc	04
_ZN7DSQueueIcE4findERKc:
.LLFB1587:
	!#PROLOGUE# 0
	save	%sp, -128, %sp
.LLCFI45:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+68], %g1
	ld	[%g1+8], %g1
	cmp	%g1, 0
	bg	.LL322
	nop
	mov	-1, %g1
	st	%g1, [%fp-32]
	b	.LL321
	 nop
.LL322:
	st	%g0, [%fp-20]
	ld	[%fp+68], %g1
	ld	[%g1+8], %g1
	add	%g1, -1, %g1
	st	%g1, [%fp-24]
.LL323:
	ld	[%fp-20], %o5
	ld	[%fp-24], %g1
	cmp	%o5, %g1
	bg	.LL324
	nop
	ld	[%fp-20], %o5
	ld	[%fp-24], %g1
	add	%o5, %g1, %o5
	sra	%o5, 31, %g1
	srl	%g1, 31, %g1
	add	%o5, %g1, %g1
	sra	%g1, 1, %g1
	st	%g1, [%fp-28]
	ld	[%fp+72], %g1
	ldub	[%g1], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %l0
	ld	[%fp+68], %o0
	ld	[%fp-28], %o1
	call	_ZN5DListIcEixEi, 0
	 nop
	mov	%o0, %g1
	ldub	[%g1], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %g1
	cmp	%l0, %g1
	bne	.LL325
	nop
	ld	[%fp-28], %g1
	st	%g1, [%fp-32]
	b	.LL321
	 nop
.LL325:
	ld	[%fp+72], %g1
	ldub	[%g1], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %l0
	ld	[%fp+68], %o0
	ld	[%fp-28], %o1
	call	_ZN5DListIcEixEi, 0
	 nop
	mov	%o0, %g1
	ldub	[%g1], %g1
	sll	%g1, 24, %g1
	sra	%g1, 24, %g1
	cmp	%l0, %g1
	bge	.LL327
	nop
	ld	[%fp-28], %g1
	add	%g1, -1, %g1
	st	%g1, [%fp-24]
	b	.LL323
	 nop
.LL327:
	ld	[%fp-28], %g1
	add	%g1, 1, %g1
	st	%g1, [%fp-20]
	b	.LL323
	 nop
.LL324:
	mov	-1, %g1
	st	%g1, [%fp-32]
.LL321:
	ld	[%fp-32], %i0
	ret
	restore
.LLFE1587:
	.size	_ZN7DSQueueIcE4findERKc, .-_ZN7DSQueueIcE4findERKc
	.section	".gnu.linkonce.t._ZlsIiERSoS0_RK5DListIT_E",#alloc,#execinstr
	.align 4
	.weak	_ZlsIiERSoS0_RK5DListIT_E
	.type	_ZlsIiERSoS0_RK5DListIT_E, #function
	.proc	0110
_ZlsIiERSoS0_RK5DListIT_E:
.LLFB1588:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
.LLCFI46:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+68], %o0
	sethi	%hi(.LLC56), %g1
	or	%g1, %lo(.LLC56), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	st	%g0, [%fp-20]
.LL330:
	ld	[%fp+72], %o0
	call	_ZNK5DListIiE6lengthEv, 0
	 nop
	mov	%o0, %o5
	ld	[%fp-20], %g1
	cmp	%o5, %g1
	ble	.LL331
	nop
	ld	[%fp-20], %g1
	cmp	%g1, 0
	bne	.LL333
	nop
	sethi	%hi(.LLC57), %g1
	or	%g1, %lo(.LLC57), %g1
	st	%g1, [%fp-24]
	b	.LL334
	 nop
.LL333:
	sethi	%hi(.LLC58), %g1
	or	%g1, %lo(.LLC58), %g1
	st	%g1, [%fp-24]
.LL334:
	ld	[%fp+68], %o0
	ld	[%fp-24], %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	mov	%o0, %o3
	ld	[%fp+72], %o4
	ld	[%fp-20], %g1
	sll	%g1, 2, %o5
	ld	[%o4+4], %g1
	add	%o5, %g1, %g1
	mov	%o3, %o0
	ld	[%g1], %o1
	call	_ZNSolsEi, 0
	 nop
	ld	[%fp-20], %g1
	add	%g1, 1, %g1
	st	%g1, [%fp-20]
	b	.LL330
	 nop
.LL331:
	ld	[%fp+68], %o0
	sethi	%hi(.LLC59), %g1
	or	%g1, %lo(.LLC59), %o1
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc, 0
	 nop
	ld	[%fp+68], %g1
	mov	%g1, %i0
	ret
	restore
.LLFE1588:
	.size	_ZlsIiERSoS0_RK5DListIT_E, .-_ZlsIiERSoS0_RK5DListIT_E
	.section	".gnu.linkonce.t._ZNK5DListIiE6lengthEv",#alloc,#execinstr
	.align 4
	.weak	_ZNK5DListIiE6lengthEv
	.type	_ZNK5DListIiE6lengthEv, #function
	.proc	04
_ZNK5DListIiE6lengthEv:
.LLFB1589:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI47:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	ld	[%fp+68], %g1
	ld	[%g1+8], %g1
	mov	%g1, %i0
	ret
	restore
.LLFE1589:
	.size	_ZNK5DListIiE6lengthEv, .-_ZNK5DListIiE6lengthEv
	.section	".gnu.linkonce.t._Z12generateItemIiET_S0_S0_",#alloc,#execinstr
	.align 4
	.weak	_Z12generateItemIiET_S0_S0_
	.type	_Z12generateItemIiET_S0_S0_, #function
	.proc	04
_Z12generateItemIiET_S0_S0_:
.LLFB1592:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
.LLCFI48:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	call	rand, 0
	 nop
	st	%o0, [%fp-20]
	ld	[%fp+72], %o5
	ld	[%fp+68], %g1
	sub	%o5, %g1, %g1
	add	%g1, 1, %g1
	ld	[%fp-20], %o0
	mov	%g1, %o1
	call	.rem, 0
	 nop
	mov	%o0, %o5
	ld	[%fp+68], %g1
	add	%o5, %g1, %o5
	st	%o5, [%fp-20]
	ld	[%fp-20], %g1
	mov	%g1, %i0
	ret
	restore
.LLFE1592:
	.size	_Z12generateItemIiET_S0_S0_, .-_Z12generateItemIiET_S0_S0_
	.section	".gnu.linkonce.t._ZN5DListIiE6insertERKii",#alloc,#execinstr
	.align 4
	.weak	_ZN5DListIiE6insertERKii
	.type	_ZN5DListIiE6insertERKii, #function
	.proc	020
_ZN5DListIiE6insertERKii:
.LLFB1593:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
.LLCFI49:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	st	%i2, [%fp+76]
	ld	[%fp+76], %g1
	cmp	%g1, 0
	bl	.LL340
	nop
	ld	[%fp+68], %g1
	ld	[%g1+8], %o5
	ld	[%fp+76], %g1
	cmp	%o5, %g1
	bge	.LL338
	nop
.LL340:
	sethi	%hi(.LLC54), %g1
	or	%g1, %lo(.LLC54), %o0
	sethi	%hi(.LLC42), %g1
	or	%g1, %lo(.LLC42), %o1
	mov	55, %o2
	call	__assert, 0
	 nop
.LL338:
	ld	[%fp+68], %g1
	ld	[%fp+68], %o5
	ld	[%g1+8], %o4
	ld	[%o5+12], %g1
	cmp	%o4, %g1
	bne	.LL341
	nop
	ld	[%fp+68], %o5
	ld	[%fp+68], %g1
	ld	[%g1+12], %g1
	add	%g1, %g1, %g1
	st	%g1, [%o5+12]
	ld	[%fp+68], %g1
	ld	[%g1+12], %g1
	sll	%g1, 2, %g1
	mov	%g1, %o0
	call	_Znaj, 0
	 nop
	st	%o0, [%fp-20]
	st	%g0, [%fp-24]
.LL342:
	ld	[%fp+68], %g1
	ld	[%g1+8], %o5
	ld	[%fp-24], %g1
	cmp	%o5, %g1
	ble	.LL343
	nop
	ld	[%fp-24], %g1
	sll	%g1, 2, %o5
	ld	[%fp-20], %g1
	add	%o5, %g1, %o3
	ld	[%fp+68], %o4
	ld	[%fp-24], %g1
	sll	%g1, 2, %o5
	ld	[%o4+4], %g1
	add	%o5, %g1, %g1
	ld	[%g1], %g1
	st	%g1, [%o3]
	ld	[%fp-24], %g1
	add	%g1, 1, %g1
	st	%g1, [%fp-24]
	b	.LL342
	 nop
.LL343:
	ld	[%fp+68], %g1
	ld	[%g1+4], %g1
	cmp	%g1, 0
	be	.LL346
	nop
	ld	[%fp+68], %g1
	ld	[%g1+4], %o0
	call	_ZdaPv, 0
	 nop
.LL346:
	ld	[%fp+68], %o5
	ld	[%fp-20], %g1
	st	%g1, [%o5+4]
.LL341:
	ld	[%fp+68], %g1
	ld	[%g1+8], %g1
	st	%g1, [%fp-24]
.LL347:
	ld	[%fp-24], %o5
	ld	[%fp+76], %g1
	cmp	%o5, %g1
	ble	.LL348
	nop
	ld	[%fp+68], %o4
	ld	[%fp-24], %g1
	sll	%g1, 2, %o5
	ld	[%o4+4], %g1
	add	%o5, %g1, %o3
	ld	[%fp+68], %o4
	ld	[%fp-24], %g1
	sll	%g1, 2, %o5
	ld	[%o4+4], %g1
	add	%o5, %g1, %g1
	ld	[%g1-4], %g1
	st	%g1, [%o3]
	ld	[%fp-24], %g1
	add	%g1, -1, %g1
	st	%g1, [%fp-24]
	b	.LL347
	 nop
.LL348:
	ld	[%fp+68], %o4
	ld	[%fp+76], %g1
	sll	%g1, 2, %o5
	ld	[%o4+4], %g1
	add	%o5, %g1, %o5
	ld	[%fp+72], %g1
	ld	[%g1], %g1
	st	%g1, [%o5]
	ld	[%fp+68], %o5
	ld	[%fp+68], %g1
	ld	[%g1+8], %g1
	add	%g1, 1, %g1
	st	%g1, [%o5+8]
	ret
	restore
.LLFE1593:
	.size	_ZN5DListIiE6insertERKii, .-_ZN5DListIiE6insertERKii
	.section	".gnu.linkonce.t._ZN5DListIiEixEi",#alloc,#execinstr
	.align 4
	.weak	_ZN5DListIiEixEi
	.type	_ZN5DListIiEixEi, #function
	.proc	0104
_ZN5DListIiEixEi:
.LLFB1594:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI50:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+68], %i4
	ld	[%fp+72], %g1
	sll	%g1, 2, %i5
	ld	[%i4+4], %g1
	add	%i5, %g1, %g1
	mov	%g1, %i0
	ret
	restore
.LLFE1594:
	.size	_ZN5DListIiEixEi, .-_ZN5DListIiEixEi
	.section	".gnu.linkonce.t._ZN5DListIiE6removeEi",#alloc,#execinstr
	.align 4
	.weak	_ZN5DListIiE6removeEi
	.type	_ZN5DListIiE6removeEi, #function
	.proc	020
_ZN5DListIiE6removeEi:
.LLFB1595:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
.LLCFI51:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+72], %g1
	cmp	%g1, 0
	bl	.LL354
	nop
	ld	[%fp+68], %g1
	ld	[%g1+8], %o5
	ld	[%fp+72], %g1
	cmp	%o5, %g1
	bg	.LL352
	nop
.LL354:
	sethi	%hi(.LLC55), %g1
	or	%g1, %lo(.LLC55), %o0
	sethi	%hi(.LLC42), %g1
	or	%g1, %lo(.LLC42), %o1
	mov	83, %o2
	call	__assert, 0
	 nop
.LL352:
	ld	[%fp+72], %g1
	st	%g1, [%fp-20]
.LL355:
	ld	[%fp+68], %g1
	ld	[%g1+8], %g1
	add	%g1, -1, %o5
	ld	[%fp-20], %g1
	cmp	%o5, %g1
	ble	.LL356
	nop
	ld	[%fp+68], %o4
	ld	[%fp-20], %g1
	sll	%g1, 2, %o5
	ld	[%o4+4], %g1
	add	%o5, %g1, %o3
	ld	[%fp+68], %o4
	ld	[%fp-20], %g1
	sll	%g1, 2, %o5
	ld	[%o4+4], %g1
	add	%o5, %g1, %g1
	ld	[%g1+4], %g1
	st	%g1, [%o3]
	ld	[%fp-20], %g1
	add	%g1, 1, %g1
	st	%g1, [%fp-20]
	b	.LL355
	 nop
.LL356:
	ld	[%fp+68], %o5
	ld	[%fp+68], %g1
	ld	[%g1+8], %g1
	add	%g1, -1, %g1
	st	%g1, [%o5+8]
	ret
	restore
.LLFE1595:
	.size	_ZN5DListIiE6removeEi, .-_ZN5DListIiE6removeEi
	.section	".gnu.linkonce.t._ZN5DListIcEC1ERKS0_",#alloc,#execinstr
	.align 4
	.weak	_ZN5DListIcEC1ERKS0_
	.type	_ZN5DListIcEC1ERKS0_, #function
	.proc	020
_ZN5DListIcEC1ERKS0_:
.LLFB1598:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
.LLCFI52:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+68], %o5
	sethi	%hi(_ZTV5DListIcE+8), %g1
	or	%g1, %lo(_ZTV5DListIcE+8), %g1
	st	%g1, [%o5]
	ld	[%fp+68], %o5
	ld	[%fp+72], %g1
	ld	[%g1+8], %g1
	st	%g1, [%o5+8]
	ld	[%fp+68], %o5
	ld	[%fp+72], %g1
	ld	[%g1+12], %g1
	st	%g1, [%o5+12]
	ld	[%fp+68], %l0
	ld	[%fp+68], %g1
	ld	[%g1+12], %g1
	mov	%g1, %o0
	call	_Znaj, 0
	 nop
	st	%o0, [%l0+4]
	st	%g0, [%fp-20]
.LL359:
	ld	[%fp+72], %o0
	call	_ZNK5DListIcE6lengthEv, 0
	 nop
	mov	%o0, %o5
	ld	[%fp-20], %g1
	cmp	%o5, %g1
	ble	.LL358
	nop
	ld	[%fp+68], %g1
	ld	[%g1+4], %o5
	ld	[%fp-20], %g1
	add	%o5, %g1, %o4
	ld	[%fp+72], %g1
	ld	[%g1+4], %o5
	ld	[%fp-20], %g1
	add	%o5, %g1, %g1
	ldub	[%g1], %g1
	stb	%g1, [%o4]
	ld	[%fp-20], %g1
	add	%g1, 1, %g1
	st	%g1, [%fp-20]
	b	.LL359
	 nop
.LL358:
	ret
	restore
.LLFE1598:
	.size	_ZN5DListIcEC1ERKS0_, .-_ZN5DListIcEC1ERKS0_
	.section	".gnu.linkonce.t._ZN5DListIiEaSERKS0_",#alloc,#execinstr
	.align 4
	.weak	_ZN5DListIiEaSERKS0_
	.type	_ZN5DListIiEaSERKS0_, #function
	.proc	0110
_ZN5DListIiEaSERKS0_:
.LLFB1599:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
.LLCFI53:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+68], %o5
	ld	[%fp+72], %g1
	cmp	%o5, %g1
	bne	.LL363
	nop
	ld	[%fp+68], %g1
	st	%g1, [%fp-24]
	b	.LL362
	 nop
.LL363:
	ld	[%fp+68], %o5
	ld	[%fp+72], %g1
	ld	[%g1+8], %g1
	st	%g1, [%o5+8]
	ld	[%fp+68], %o5
	ld	[%fp+72], %g1
	ld	[%g1+12], %g1
	st	%g1, [%o5+12]
	ld	[%fp+68], %g1
	ld	[%g1+4], %o0
	call	_ZdlPv, 0
	 nop
	ld	[%fp+68], %l0
	ld	[%fp+68], %g1
	ld	[%g1+12], %g1
	sll	%g1, 2, %g1
	mov	%g1, %o0
	call	_Znaj, 0
	 nop
	st	%o0, [%l0+4]
	st	%g0, [%fp-20]
.LL364:
	ld	[%fp+72], %o0
	call	_ZNK5DListIiE6lengthEv, 0
	 nop
	mov	%o0, %o5
	ld	[%fp-20], %g1
	cmp	%o5, %g1
	ble	.LL365
	nop
	ld	[%fp+68], %o4
	ld	[%fp-20], %g1
	sll	%g1, 2, %o5
	ld	[%o4+4], %g1
	add	%o5, %g1, %o3
	ld	[%fp+72], %o4
	ld	[%fp-20], %g1
	sll	%g1, 2, %o5
	ld	[%o4+4], %g1
	add	%o5, %g1, %g1
	ld	[%g1], %g1
	st	%g1, [%o3]
	ld	[%fp-20], %g1
	add	%g1, 1, %g1
	st	%g1, [%fp-20]
	b	.LL364
	 nop
.LL365:
	ld	[%fp+68], %g1
	st	%g1, [%fp-24]
.LL362:
	ld	[%fp-24], %i0
	ret
	restore
.LLFE1599:
	.size	_ZN5DListIiEaSERKS0_, .-_ZN5DListIiEaSERKS0_
	.weak	_ZTV5DListIiE
	.section	".gnu.linkonce.r._ZTV5DListIiE",#alloc
	.align 8
	.type	_ZTV5DListIiE, #object
	.size	_ZTV5DListIiE, 16
_ZTV5DListIiE:
	.long	0
	.long	_ZTI5DListIiE
	.long	_ZN5DListIiED1Ev
	.long	_ZN5DListIiED0Ev
	.weak	_ZTV7DSQueueIcE
	.section	".gnu.linkonce.r._ZTV7DSQueueIcE",#alloc
	.align 8
	.type	_ZTV7DSQueueIcE, #object
	.size	_ZTV7DSQueueIcE, 16
_ZTV7DSQueueIcE:
	.long	0
	.long	_ZTI7DSQueueIcE
	.long	_ZN7DSQueueIcED1Ev
	.long	_ZN7DSQueueIcED0Ev
	.weak	_ZTV6DQueueIcE
	.section	".gnu.linkonce.r._ZTV6DQueueIcE",#alloc
	.align 8
	.type	_ZTV6DQueueIcE, #object
	.size	_ZTV6DQueueIcE, 16
_ZTV6DQueueIcE:
	.long	0
	.long	_ZTI6DQueueIcE
	.long	_ZN6DQueueIcED1Ev
	.long	_ZN6DQueueIcED0Ev
	.weak	_ZTV6DStackIcE
	.section	".gnu.linkonce.r._ZTV6DStackIcE",#alloc
	.align 8
	.type	_ZTV6DStackIcE, #object
	.size	_ZTV6DStackIcE, 16
_ZTV6DStackIcE:
	.long	0
	.long	_ZTI6DStackIcE
	.long	_ZN6DStackIcED1Ev
	.long	_ZN6DStackIcED0Ev
	.weak	_ZTV5DListIcE
	.section	".gnu.linkonce.r._ZTV5DListIcE",#alloc
	.align 8
	.type	_ZTV5DListIcE, #object
	.size	_ZTV5DListIcE, 16
_ZTV5DListIcE:
	.long	0
	.long	_ZTI5DListIcE
	.long	_ZN5DListIcED1Ev
	.long	_ZN5DListIcED0Ev
	.section	".text"
	.align 4
	.type	_Z41__static_initialization_and_destruction_0ii, #function
	.proc	020
_Z41__static_initialization_and_destruction_0ii:
.LLFB1601:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI54:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+72], %g1
	sethi	%hi(64512), %o5
	or	%o5, 1023, %o5
	cmp	%g1, %o5
	bne	.LL368
	nop
	ld	[%fp+68], %g1
	cmp	%g1, 1
	bne	.LL368
	nop
	sethi	%hi(_ZSt8__ioinit), %g1
	or	%g1, %lo(_ZSt8__ioinit), %o0
	call	_ZNSt8ios_base4InitC1Ev, 0
	 nop
.LL368:
	ld	[%fp+72], %g1
	sethi	%hi(64512), %o5
	or	%o5, 1023, %o5
	cmp	%g1, %o5
	bne	.LL367
	nop
	ld	[%fp+68], %g1
	cmp	%g1, 0
	bne	.LL367
	nop
	sethi	%hi(_ZSt8__ioinit), %g1
	or	%g1, %lo(_ZSt8__ioinit), %o0
	call	_ZNSt8ios_base4InitD1Ev, 0
	 nop
.LL367:
	nop
	ret
	restore
.LLFE1601:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.section	".gnu.linkonce.t._ZN5DListIcED0Ev",#alloc,#execinstr
	.align 4
	.weak	_ZN5DListIcED0Ev
	.type	_ZN5DListIcED0Ev, #function
	.proc	020
_ZN5DListIcED0Ev:
.LLFB1553:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI55:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	ld	[%fp+68], %o5
	sethi	%hi(_ZTV5DListIcE+8), %g1
	or	%g1, %lo(_ZTV5DListIcE+8), %g1
	st	%g1, [%o5]
	ld	[%fp+68], %g1
	ld	[%g1+4], %g1
	cmp	%g1, 0
	be	.LL373
	nop
	ld	[%fp+68], %g1
	ld	[%g1+4], %o0
	call	_ZdlPv, 0
	 nop
.LL373:
	mov	1, %o5
	and	%o5, 3, %g1
	and	%g1, 0xff, %g1
	cmp	%g1, 0
	be	.LL370
	nop
	ld	[%fp+68], %o0
	call	_ZdlPv, 0
	 nop
.LL370:
	nop
	ret
	restore
.LLFE1553:
	.size	_ZN5DListIcED0Ev, .-_ZN5DListIcED0Ev
	.section	".gnu.linkonce.t._ZN6DStackIcED0Ev",#alloc,#execinstr
	.align 4
	.weak	_ZN6DStackIcED0Ev
	.type	_ZN6DStackIcED0Ev, #function
	.proc	020
_ZN6DStackIcED0Ev:
.LLFB1504:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI56:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	ld	[%fp+68], %o5
	sethi	%hi(_ZTV6DStackIcE+8), %g1
	or	%g1, %lo(_ZTV6DStackIcE+8), %g1
	st	%g1, [%o5]
	ld	[%fp+68], %g1
	ld	[%g1+4], %g1
	cmp	%g1, 0
	be	.LL380
	nop
	ld	[%fp+68], %g1
	ld	[%g1+4], %o0
	call	_ZdaPv, 0
	 nop
.LL379:
.LL380:
	ld	[%fp+68], %o0
	call	_ZN5DListIcED2Ev, 0
	 nop
	mov	1, %o5
	and	%o5, 3, %g1
	and	%g1, 0xff, %g1
	cmp	%g1, 0
	be	.LL375
	nop
	ld	[%fp+68], %o0
	call	_ZdlPv, 0
	 nop
.LL375:
	nop
	ret
	restore
.LLFE1504:
	.size	_ZN6DStackIcED0Ev, .-_ZN6DStackIcED0Ev
	.section	".gnu.linkonce.t._ZN6DQueueIcED0Ev",#alloc,#execinstr
	.align 4
	.weak	_ZN6DQueueIcED0Ev
	.type	_ZN6DQueueIcED0Ev, #function
	.proc	020
_ZN6DQueueIcED0Ev:
.LLFB1517:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI57:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	ld	[%fp+68], %o5
	sethi	%hi(_ZTV6DQueueIcE+8), %g1
	or	%g1, %lo(_ZTV6DQueueIcE+8), %g1
	st	%g1, [%o5]
	ld	[%fp+68], %g1
	ld	[%g1+4], %g1
	cmp	%g1, 0
	be	.LL388
	nop
	ld	[%fp+68], %g1
	ld	[%g1+4], %o0
	call	_ZdaPv, 0
	 nop
.LL387:
.LL388:
	ld	[%fp+68], %o0
	call	_ZN5DListIcED2Ev, 0
	 nop
	mov	1, %o5
	and	%o5, 3, %g1
	and	%g1, 0xff, %g1
	cmp	%g1, 0
	be	.LL383
	nop
	ld	[%fp+68], %o0
	call	_ZdlPv, 0
	 nop
.LL383:
	nop
	ret
	restore
.LLFE1517:
	.size	_ZN6DQueueIcED0Ev, .-_ZN6DQueueIcED0Ev
	.section	".gnu.linkonce.t._ZN7DSQueueIcED0Ev",#alloc,#execinstr
	.align 4
	.weak	_ZN7DSQueueIcED0Ev
	.type	_ZN7DSQueueIcED0Ev, #function
	.proc	020
_ZN7DSQueueIcED0Ev:
.LLFB1527:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI58:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	ld	[%fp+68], %o5
	sethi	%hi(_ZTV7DSQueueIcE+8), %g1
	or	%g1, %lo(_ZTV7DSQueueIcE+8), %g1
	st	%g1, [%o5]
	ld	[%fp+68], %g1
	ld	[%g1+4], %g1
	cmp	%g1, 0
	be	.LL396
	nop
	ld	[%fp+68], %g1
	ld	[%g1+4], %o0
	call	_ZdaPv, 0
	 nop
.LL395:
.LL396:
	ld	[%fp+68], %o0
	call	_ZN5DListIcED2Ev, 0
	 nop
	mov	1, %o5
	and	%o5, 3, %g1
	and	%g1, 0xff, %g1
	cmp	%g1, 0
	be	.LL391
	nop
	ld	[%fp+68], %o0
	call	_ZdlPv, 0
	 nop
.LL391:
	nop
	ret
	restore
.LLFE1527:
	.size	_ZN7DSQueueIcED0Ev, .-_ZN7DSQueueIcED0Ev
	.section	".gnu.linkonce.t._ZN5DListIiED0Ev",#alloc,#execinstr
	.align 4
	.weak	_ZN5DListIiED0Ev
	.type	_ZN5DListIiED0Ev, #function
	.proc	020
_ZN5DListIiED0Ev:
.LLFB1560:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI59:
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	ld	[%fp+68], %o5
	sethi	%hi(_ZTV5DListIiE+8), %g1
	or	%g1, %lo(_ZTV5DListIiE+8), %g1
	st	%g1, [%o5]
	ld	[%fp+68], %g1
	ld	[%g1+4], %g1
	cmp	%g1, 0
	be	.LL402
	nop
	ld	[%fp+68], %g1
	ld	[%g1+4], %o0
	call	_ZdlPv, 0
	 nop
.LL402:
	mov	1, %o5
	and	%o5, 3, %g1
	and	%g1, 0xff, %g1
	cmp	%g1, 0
	be	.LL399
	nop
	ld	[%fp+68], %o0
	call	_ZdlPv, 0
	 nop
.LL399:
	nop
	ret
	restore
.LLFE1560:
	.size	_ZN5DListIiED0Ev, .-_ZN5DListIiED0Ev
	.weak	_ZTI5DListIcE
	.section	".gnu.linkonce.r._ZTI5DListIcE",#alloc
	.align 4
	.type	_ZTI5DListIcE, #object
	.size	_ZTI5DListIcE, 8
_ZTI5DListIcE:
	.long	_ZTVN10__cxxabiv117__class_type_infoE+8
	.long	_ZTS5DListIcE
	.weak	_ZTI6DStackIcE
	.section	".gnu.linkonce.r._ZTI6DStackIcE",#alloc
	.align 4
	.type	_ZTI6DStackIcE, #object
	.size	_ZTI6DStackIcE, 12
_ZTI6DStackIcE:
	.long	_ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	_ZTS6DStackIcE
	.long	_ZTI5DListIcE
	.weak	_ZTI6DQueueIcE
	.section	".gnu.linkonce.r._ZTI6DQueueIcE",#alloc
	.align 4
	.type	_ZTI6DQueueIcE, #object
	.size	_ZTI6DQueueIcE, 12
_ZTI6DQueueIcE:
	.long	_ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	_ZTS6DQueueIcE
	.long	_ZTI5DListIcE
	.weak	_ZTI7DSQueueIcE
	.section	".gnu.linkonce.r._ZTI7DSQueueIcE",#alloc
	.align 4
	.type	_ZTI7DSQueueIcE, #object
	.size	_ZTI7DSQueueIcE, 12
_ZTI7DSQueueIcE:
	.long	_ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	_ZTS7DSQueueIcE
	.long	_ZTI5DListIcE
	.weak	_ZTI5DListIiE
	.section	".gnu.linkonce.r._ZTI5DListIiE",#alloc
	.align 4
	.type	_ZTI5DListIiE, #object
	.size	_ZTI5DListIiE, 8
_ZTI5DListIiE:
	.long	_ZTVN10__cxxabiv117__class_type_infoE+8
	.long	_ZTS5DListIiE
	.weak	_ZTS5DListIcE
	.section	".gnu.linkonce.r._ZTS5DListIcE",#alloc
	.align 8
	.type	_ZTS5DListIcE, #object
	.size	_ZTS5DListIcE, 10
_ZTS5DListIcE:
	.asciz	"5DListIcE"
	.weak	_ZTS6DStackIcE
	.section	".gnu.linkonce.r._ZTS6DStackIcE",#alloc
	.align 8
	.type	_ZTS6DStackIcE, #object
	.size	_ZTS6DStackIcE, 11
_ZTS6DStackIcE:
	.asciz	"6DStackIcE"
	.weak	_ZTS6DQueueIcE
	.section	".gnu.linkonce.r._ZTS6DQueueIcE",#alloc
	.align 8
	.type	_ZTS6DQueueIcE, #object
	.size	_ZTS6DQueueIcE, 11
_ZTS6DQueueIcE:
	.asciz	"6DQueueIcE"
	.weak	_ZTS7DSQueueIcE
	.section	".gnu.linkonce.r._ZTS7DSQueueIcE",#alloc
	.align 8
	.type	_ZTS7DSQueueIcE, #object
	.size	_ZTS7DSQueueIcE, 12
_ZTS7DSQueueIcE:
	.asciz	"7DSQueueIcE"
	.weak	_ZTS5DListIiE
	.section	".gnu.linkonce.r._ZTS5DListIiE",#alloc
	.align 8
	.type	_ZTS5DListIiE, #object
	.size	_ZTS5DListIiE, 10
_ZTS5DListIiE:
	.asciz	"5DListIiE"
	.section	".text"
	.align 4
	.type	_GLOBAL__I_menuItems, #function
	.proc	020
_GLOBAL__I_menuItems:
.LLFB1602:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI60:
	!#PROLOGUE# 1
	mov	1, %o0
	sethi	%hi(64512), %g1
	or	%g1, 1023, %o1
	call	_Z41__static_initialization_and_destruction_0ii, 0
	 nop
	nop
	ret
	restore
.LLFE1602:
	.size	_GLOBAL__I_menuItems, .-_GLOBAL__I_menuItems
	.section	".ctors",#alloc,#write
	.align 4
	.long	_GLOBAL__I_menuItems
	.section	".text"
	.align 4
	.type	_GLOBAL__D_menuItems, #function
	.proc	020
_GLOBAL__D_menuItems:
.LLFB1603:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
.LLCFI61:
	!#PROLOGUE# 1
	mov	0, %o0
	sethi	%hi(64512), %g1
	or	%g1, 1023, %o1
	call	_Z41__static_initialization_and_destruction_0ii, 0
	 nop
	nop
	ret
	restore
.LLFE1603:
	.size	_GLOBAL__D_menuItems, .-_GLOBAL__D_menuItems
	.section	".dtors",#alloc,#write
	.align 4
	.long	_GLOBAL__D_menuItems
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
	.uaword	.LLFB1490
	.uaword	.LLFE1490-.LLFB1490
	.byte	0x4
	.uaword	.LLLSDA1490
	.byte	0x4
	.uaword	.LLCFI1-.LLFB1490
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE3:
.LLSFDE5:
	.uaword	.LLEFDE5-.LLASFDE5
.LLASFDE5:
	.uaword	.LLASFDE5-.LLframe1
	.uaword	.LLFB1491
	.uaword	.LLFE1491-.LLFB1491
	.byte	0x4
	.uaword	.LLLSDA1491
	.byte	0x4
	.uaword	.LLCFI2-.LLFB1491
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
	.uaword	.LLFB1492
	.uaword	.LLFE1492-.LLFB1492
	.byte	0x4
	.uaword	.LLLSDA1492
	.byte	0x4
	.uaword	.LLCFI3-.LLFB1492
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
	.uaword	.LLFB1493
	.uaword	.LLFE1493-.LLFB1493
	.byte	0x4
	.uaword	.LLLSDA1493
	.byte	0x4
	.uaword	.LLCFI4-.LLFB1493
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
	.uaword	.LLFB1482
	.uaword	.LLFE1482-.LLFB1482
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI5-.LLFB1482
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
	.uaword	.LLFB1483
	.uaword	.LLFE1483-.LLFB1483
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI6-.LLFB1483
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE13:
.LLSFDE17:
	.uaword	.LLEFDE17-.LLASFDE17
.LLASFDE17:
	.uaword	.LLASFDE17-.LLframe1
	.uaword	.LLFB1500
	.uaword	.LLFE1500-.LLFB1500
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI8-.LLFB1500
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE17:
.LLSFDE19:
	.uaword	.LLEFDE19-.LLASFDE19
.LLASFDE19:
	.uaword	.LLASFDE19-.LLframe1
	.uaword	.LLFB1503
	.uaword	.LLFE1503-.LLFB1503
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI9-.LLFB1503
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE19:
.LLSFDE23:
	.uaword	.LLEFDE23-.LLASFDE23
.LLASFDE23:
	.uaword	.LLASFDE23-.LLframe1
	.uaword	.LLFB1506
	.uaword	.LLFE1506-.LLFB1506
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI11-.LLFB1506
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE23:
.LLSFDE27:
	.uaword	.LLEFDE27-.LLASFDE27
.LLASFDE27:
	.uaword	.LLASFDE27-.LLframe1
	.uaword	.LLFB1509
	.uaword	.LLFE1509-.LLFB1509
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI13-.LLFB1509
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE27:
.LLSFDE29:
	.uaword	.LLEFDE29-.LLASFDE29
.LLASFDE29:
	.uaword	.LLASFDE29-.LLframe1
	.uaword	.LLFB1510
	.uaword	.LLFE1510-.LLFB1510
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI14-.LLFB1510
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE29:
.LLSFDE31:
	.uaword	.LLEFDE31-.LLASFDE31
.LLASFDE31:
	.uaword	.LLASFDE31-.LLframe1
	.uaword	.LLFB1513
	.uaword	.LLFE1513-.LLFB1513
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI15-.LLFB1513
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE31:
.LLSFDE33:
	.uaword	.LLEFDE33-.LLASFDE33
.LLASFDE33:
	.uaword	.LLASFDE33-.LLframe1
	.uaword	.LLFB1516
	.uaword	.LLFE1516-.LLFB1516
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI16-.LLFB1516
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE33:
.LLSFDE35:
	.uaword	.LLEFDE35-.LLASFDE35
.LLASFDE35:
	.uaword	.LLASFDE35-.LLframe1
	.uaword	.LLFB1518
	.uaword	.LLFE1518-.LLFB1518
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI17-.LLFB1518
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE35:
.LLSFDE37:
	.uaword	.LLEFDE37-.LLASFDE37
.LLASFDE37:
	.uaword	.LLASFDE37-.LLframe1
	.uaword	.LLFB1519
	.uaword	.LLFE1519-.LLFB1519
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI18-.LLFB1519
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE37:
.LLSFDE39:
	.uaword	.LLEFDE39-.LLASFDE39
.LLASFDE39:
	.uaword	.LLASFDE39-.LLframe1
	.uaword	.LLFB1520
	.uaword	.LLFE1520-.LLFB1520
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI19-.LLFB1520
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE39:
.LLSFDE41:
	.uaword	.LLEFDE41-.LLASFDE41
.LLASFDE41:
	.uaword	.LLASFDE41-.LLframe1
	.uaword	.LLFB1523
	.uaword	.LLFE1523-.LLFB1523
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI20-.LLFB1523
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE41:
.LLSFDE43:
	.uaword	.LLEFDE43-.LLASFDE43
.LLASFDE43:
	.uaword	.LLASFDE43-.LLframe1
	.uaword	.LLFB1526
	.uaword	.LLFE1526-.LLFB1526
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI21-.LLFB1526
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE43:
.LLSFDE45:
	.uaword	.LLEFDE45-.LLASFDE45
.LLASFDE45:
	.uaword	.LLASFDE45-.LLframe1
	.uaword	.LLFB1528
	.uaword	.LLFE1528-.LLFB1528
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI22-.LLFB1528
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE45:
.LLSFDE47:
	.uaword	.LLEFDE47-.LLASFDE47
.LLASFDE47:
	.uaword	.LLASFDE47-.LLframe1
	.uaword	.LLFB1544
	.uaword	.LLFE1544-.LLFB1544
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI23-.LLFB1544
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE47:
.LLSFDE49:
	.uaword	.LLEFDE49-.LLASFDE49
.LLASFDE49:
	.uaword	.LLASFDE49-.LLframe1
	.uaword	.LLFB1546
	.uaword	.LLFE1546-.LLFB1546
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI24-.LLFB1546
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE49:
.LLSFDE51:
	.uaword	.LLEFDE51-.LLASFDE51
.LLASFDE51:
	.uaword	.LLASFDE51-.LLframe1
	.uaword	.LLFB1548
	.uaword	.LLFE1548-.LLFB1548
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI25-.LLFB1548
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE51:
.LLSFDE53:
	.uaword	.LLEFDE53-.LLASFDE53
.LLASFDE53:
	.uaword	.LLASFDE53-.LLframe1
	.uaword	.LLFB1549
	.uaword	.LLFE1549-.LLFB1549
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI26-.LLFB1549
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE53:
.LLSFDE59:
	.uaword	.LLEFDE59-.LLASFDE59
.LLASFDE59:
	.uaword	.LLASFDE59-.LLframe1
	.uaword	.LLFB1556
	.uaword	.LLFE1556-.LLFB1556
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI29-.LLFB1556
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE59:
.LLSFDE63:
	.uaword	.LLEFDE63-.LLASFDE63
.LLASFDE63:
	.uaword	.LLASFDE63-.LLframe1
	.uaword	.LLFB1561
	.uaword	.LLFE1561-.LLFB1561
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI31-.LLFB1561
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE63:
.LLSFDE65:
	.uaword	.LLEFDE65-.LLASFDE65
.LLASFDE65:
	.uaword	.LLASFDE65-.LLframe1
	.uaword	.LLFB1562
	.uaword	.LLFE1562-.LLFB1562
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI32-.LLFB1562
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE65:
.LLSFDE69:
	.uaword	.LLEFDE69-.LLASFDE69
.LLASFDE69:
	.uaword	.LLASFDE69-.LLframe1
	.uaword	.LLFB1563
	.uaword	.LLFE1563-.LLFB1563
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI34-.LLFB1563
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE69:
.LLSFDE71:
	.uaword	.LLEFDE71-.LLASFDE71
.LLASFDE71:
	.uaword	.LLASFDE71-.LLframe1
	.uaword	.LLFB1564
	.uaword	.LLFE1564-.LLFB1564
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI35-.LLFB1564
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE71:
.LLSFDE73:
	.uaword	.LLEFDE73-.LLASFDE73
.LLASFDE73:
	.uaword	.LLASFDE73-.LLframe1
	.uaword	.LLFB1565
	.uaword	.LLFE1565-.LLFB1565
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI36-.LLFB1565
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE73:
.LLSFDE75:
	.uaword	.LLEFDE75-.LLASFDE75
.LLASFDE75:
	.uaword	.LLASFDE75-.LLframe1
	.uaword	.LLFB1566
	.uaword	.LLFE1566-.LLFB1566
	.byte	0x4
	.uaword	.LLLSDA1566
	.byte	0x4
	.uaword	.LLCFI37-.LLFB1566
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE75:
.LLSFDE77:
	.uaword	.LLEFDE77-.LLASFDE77
.LLASFDE77:
	.uaword	.LLASFDE77-.LLframe1
	.uaword	.LLFB1567
	.uaword	.LLFE1567-.LLFB1567
	.byte	0x4
	.uaword	.LLLSDA1567
	.byte	0x4
	.uaword	.LLCFI38-.LLFB1567
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE77:
.LLSFDE79:
	.uaword	.LLEFDE79-.LLASFDE79
.LLASFDE79:
	.uaword	.LLASFDE79-.LLframe1
	.uaword	.LLFB1570
	.uaword	.LLFE1570-.LLFB1570
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI39-.LLFB1570
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE79:
.LLSFDE83:
	.uaword	.LLEFDE83-.LLASFDE83
.LLASFDE83:
	.uaword	.LLASFDE83-.LLframe1
	.uaword	.LLFB1572
	.uaword	.LLFE1572-.LLFB1572
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI41-.LLFB1572
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE83:
.LLSFDE87:
	.uaword	.LLEFDE87-.LLASFDE87
.LLASFDE87:
	.uaword	.LLASFDE87-.LLframe1
	.uaword	.LLFB1585
	.uaword	.LLFE1585-.LLFB1585
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI43-.LLFB1585
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE87:
.LLSFDE93:
	.uaword	.LLEFDE93-.LLASFDE93
.LLASFDE93:
	.uaword	.LLASFDE93-.LLframe1
	.uaword	.LLFB1588
	.uaword	.LLFE1588-.LLFB1588
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI46-.LLFB1588
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE93:
.LLSFDE99:
	.uaword	.LLEFDE99-.LLASFDE99
.LLASFDE99:
	.uaword	.LLASFDE99-.LLframe1
	.uaword	.LLFB1593
	.uaword	.LLFE1593-.LLFB1593
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI49-.LLFB1593
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE99:
.LLSFDE103:
	.uaword	.LLEFDE103-.LLASFDE103
.LLASFDE103:
	.uaword	.LLASFDE103-.LLframe1
	.uaword	.LLFB1595
	.uaword	.LLFE1595-.LLFB1595
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI51-.LLFB1595
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE103:
.LLSFDE105:
	.uaword	.LLEFDE105-.LLASFDE105
.LLASFDE105:
	.uaword	.LLASFDE105-.LLframe1
	.uaword	.LLFB1598
	.uaword	.LLFE1598-.LLFB1598
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI52-.LLFB1598
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE105:
.LLSFDE107:
	.uaword	.LLEFDE107-.LLASFDE107
.LLASFDE107:
	.uaword	.LLASFDE107-.LLframe1
	.uaword	.LLFB1599
	.uaword	.LLFE1599-.LLFB1599
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI53-.LLFB1599
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE107:
.LLSFDE109:
	.uaword	.LLEFDE109-.LLASFDE109
.LLASFDE109:
	.uaword	.LLASFDE109-.LLframe1
	.uaword	.LLFB1601
	.uaword	.LLFE1601-.LLFB1601
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI54-.LLFB1601
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE109:
.LLSFDE121:
	.uaword	.LLEFDE121-.LLASFDE121
.LLASFDE121:
	.uaword	.LLASFDE121-.LLframe1
	.uaword	.LLFB1602
	.uaword	.LLFE1602-.LLFB1602
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI60-.LLFB1602
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE121:
.LLSFDE123:
	.uaword	.LLEFDE123-.LLASFDE123
.LLASFDE123:
	.uaword	.LLASFDE123-.LLframe1
	.uaword	.LLFB1603
	.uaword	.LLFE1603-.LLFB1603
	.byte	0x4
	.uaword	0x0
	.byte	0x4
	.uaword	.LLCFI61-.LLFB1603
	.byte	0xd
	.byte	0x1e
	.byte	0x2d
	.byte	0x9
	.byte	0xf
	.byte	0x1f
	.align 4
.LLEFDE123:
	.ident	"GCC: (GNU) 3.4.5"
