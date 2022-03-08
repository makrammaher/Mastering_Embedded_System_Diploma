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
	.ascii "DEC_0 = %d\12\0"
LC1:
	.ascii "DEC_1 = %d\12\0"
LC2:
	.ascii "DEC_2 = %d\12\0"
LC3:
	.ascii "DEC_3 = %d\12\0"
LC4:
	.ascii "DEC_4 = %d\12\0"
LC5:
	.ascii "DEC_5 = %d\12\0"
LC6:
	.ascii "DEC_6 = %d\12\0"
LC7:
	.ascii "DEC_7 = %d\12\0"
LC8:
	.ascii "DEC_8 = %d\12\0"
LC9:
	.ascii "DEC_9 = %d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB10:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$16, %esp
	call	___main
	movl	$0, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	$1, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	$2, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	$3, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$4, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$5, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	$6, 4(%esp)
	movl	$LC6, (%esp)
	call	_printf
	movl	$7, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	movl	$8, 4(%esp)
	movl	$LC8, (%esp)
	call	_printf
	movl	$9, 4(%esp)
	movl	$LC9, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	___mingw_vprintf;	.scl	2;	.type	32;	.endef
