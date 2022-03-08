	.file	"main.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "__STDC__ = %d\12\0"
LC1:
	.ascii "__STDC_HOSTED__ = %d\12\0"
LC2:
	.ascii "__STDC_VERSION__ = %ld\12\0"
LC3:
	.ascii "main.c\0"
LC4:
	.ascii "__FILE__ = %s\12\0"
LC5:
	.ascii "__LINE__ = %d\12\0"
LC6:
	.ascii "Mar  8 2022\0"
LC7:
	.ascii "__DATE__ = %s\12\0"
LC8:
	.ascii "__func__ = %s\12\0"
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
	movl	$1, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	$1, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	$201112, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	$LC3, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$20, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	$LC6, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	movl	$___func__.1883, 4(%esp)
	movl	$LC8, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.section .rdata,"dr"
	.align 4
___func__.1883:
	.ascii "main\0"
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
