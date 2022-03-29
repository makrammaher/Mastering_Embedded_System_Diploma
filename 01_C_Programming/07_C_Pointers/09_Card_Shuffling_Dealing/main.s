	.file	"main.c"
	.text
	.def	_printf;	.scl	3;	.type	32;	.endef
_printf:
LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	leal	12(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	___mingw_vprintf
	movl	%eax, %ebx
	movl	%ebx, %eax
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "Spades\0"
LC1:
	.ascii "Hearts\0"
LC2:
	.ascii "Diamonds\0"
LC3:
	.ascii "Clubs\0"
LC4:
	.ascii "Ace\0"
LC5:
	.ascii "Two\0"
LC6:
	.ascii "Three\0"
LC7:
	.ascii "Four\0"
LC8:
	.ascii "Five\0"
LC9:
	.ascii "Six\0"
LC10:
	.ascii "Seven\0"
LC11:
	.ascii "Eight\0"
LC12:
	.ascii "Nine\0"
LC13:
	.ascii "Ten\0"
LC14:
	.ascii "Jack\0"
LC15:
	.ascii "Queen\0"
LC16:
	.ascii "King\0"
LC17:
	.ascii "\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB12:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	andl	$-16, %esp
	subl	$320, %esp
	.cfi_offset 7, -12
	call	___main
	movl	$LC0, 304(%esp)
	movl	$LC1, 308(%esp)
	movl	$LC2, 312(%esp)
	movl	$LC3, 316(%esp)
	movl	$LC4, 252(%esp)
	movl	$LC5, 256(%esp)
	movl	$LC6, 260(%esp)
	movl	$LC7, 264(%esp)
	movl	$LC8, 268(%esp)
	movl	$LC9, 272(%esp)
	movl	$LC10, 276(%esp)
	movl	$LC11, 280(%esp)
	movl	$LC12, 284(%esp)
	movl	$LC13, 288(%esp)
	movl	$LC14, 292(%esp)
	movl	$LC15, 296(%esp)
	movl	$LC16, 300(%esp)
	leal	44(%esp), %edx
	movl	$0, %eax
	movl	$52, %ecx
	movl	%edx, %edi
	rep stosl
	movl	$0, (%esp)
	call	_time
	movl	%eax, (%esp)
	call	_srand
	movl	$13, 8(%esp)
	movl	$4, 4(%esp)
	leal	44(%esp), %eax
	movl	%eax, (%esp)
	call	_shuffle
	movl	$LC17, (%esp)
	call	_puts
	movl	$13, 16(%esp)
	movl	$4, 12(%esp)
	leal	252(%esp), %eax
	movl	%eax, 8(%esp)
	leal	304(%esp), %eax
	movl	%eax, 4(%esp)
	leal	44(%esp), %eax
	movl	%eax, (%esp)
	call	_deal_Four_Players
	movl	$0, %eax
	movl	-4(%ebp), %edi
	leave
	.cfi_restore 5
	.cfi_restore 7
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE12:
	.globl	_shuffle
	.def	_shuffle;	.scl	2;	.type	32;	.endef
_shuffle:
LFB13:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$0, -12(%ebp)
	jmp	L6
L7:
	call	_rand
	movl	$0, %edx
	divl	12(%ebp)
	movl	%edx, -16(%ebp)
	call	_rand
	movl	$0, %edx
	divl	16(%ebp)
	movl	%edx, -20(%ebp)
	movl	16(%ebp), %eax
	imull	-16(%ebp), %eax
	movl	%eax, %edx
	movl	-20(%ebp), %eax
	addl	%edx, %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L7
	movl	16(%ebp), %eax
	imull	-16(%ebp), %eax
	movl	%eax, %edx
	movl	-20(%ebp), %eax
	addl	%edx, %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%eax, (%edx)
	addl	$1, -12(%ebp)
L6:
	movl	12(%ebp), %eax
	imull	16(%ebp), %eax
	cmpl	-12(%ebp), %eax
	ja	L7
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE13:
	.section .rdata,"dr"
LC18:
	.ascii "Player 4\0"
LC19:
	.ascii "Player 3\0"
LC20:
	.ascii "Player 2\0"
LC21:
	.ascii "Player 1\0"
LC22:
	.ascii "%12s%24s\11%20s\11%20s\12\0"
LC23:
	.ascii "%5s of %-8s%c\0"
	.text
	.globl	_deal_Four_Players
	.def	_deal_Four_Players;	.scl	2;	.type	32;	.endef
_deal_Four_Players:
LFB14:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	$LC18, 16(%esp)
	movl	$LC19, 12(%esp)
	movl	$LC20, 8(%esp)
	movl	$LC21, 4(%esp)
	movl	$LC22, (%esp)
	call	_printf
	movl	$0, -12(%ebp)
	jmp	L9
L17:
	movl	$0, -16(%ebp)
	jmp	L10
L16:
	movl	$0, -20(%ebp)
	jmp	L11
L15:
	movl	-16(%ebp), %eax
	imull	$52, %eax, %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-20(%ebp), %eax
	movl	(%edx,%eax,4), %eax
	cmpl	-12(%ebp), %eax
	jne	L12
	movl	-12(%ebp), %eax
	addl	$1, %eax
	andl	$3, %eax
	testl	%eax, %eax
	jne	L13
	movl	$10, %ecx
	jmp	L14
L13:
	movl	$9, %ecx
L14:
	movl	-16(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-20(%ebp), %eax
	leal	0(,%eax,4), %ebx
	movl	16(%ebp), %eax
	addl	%ebx, %eax
	movl	(%eax), %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC23, (%esp)
	call	_printf
L12:
	addl	$1, -20(%ebp)
L11:
	movl	-20(%ebp), %eax
	cmpl	24(%ebp), %eax
	jb	L15
	addl	$1, -16(%ebp)
L10:
	movl	-16(%ebp), %eax
	cmpl	20(%ebp), %eax
	jb	L16
	addl	$1, -12(%ebp)
L9:
	movl	20(%ebp), %eax
	imull	24(%ebp), %eax
	cmpl	-12(%ebp), %eax
	ja	L17
	nop
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE14:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	___mingw_vprintf;	.scl	2;	.type	32;	.endef
	.def	_time;	.scl	2;	.type	32;	.endef
	.def	_srand;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_rand;	.scl	2;	.type	32;	.endef
