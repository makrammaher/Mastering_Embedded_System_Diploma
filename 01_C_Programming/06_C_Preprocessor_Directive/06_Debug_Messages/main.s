	.file	"main.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "main.c\0"
LC1:
	.ascii ">> File: %s\12\0"
LC2:
	.ascii ">> \0"
LC3:
	.ascii "Test Debug level = %d\0"
LC4:
	.ascii "\12\0"
LC5:
	.ascii ">> File: %s  Func: %s\12\0"
	.align 4
LC6:
	.ascii ">> File: %s  Func: %s  Line: %d\12\0"
	.align 4
LC7:
	.ascii ">> File: %s  Func: %s  Line: %d  STD:%ld\12\0"
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
	subl	$32, %esp
	call	___main
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	$LC2, (%esp)
	call	_printf
	movl	$1, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$LC4, (%esp)
	call	_puts
	movl	$___func__.1889, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	$LC2, (%esp)
	call	_printf
	movl	$2, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$LC4, (%esp)
	call	_puts
	movl	$39, 12(%esp)
	movl	$___func__.1889, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC6, (%esp)
	call	_printf
	movl	$LC2, (%esp)
	call	_printf
	movl	$3, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$LC4, (%esp)
	call	_puts
	movl	$201112, 16(%esp)
	movl	$40, 12(%esp)
	movl	$___func__.1889, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	movl	$LC2, (%esp)
	call	_printf
	movl	$4, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$LC4, (%esp)
	call	_puts
	call	_function1
	call	_function2
	call	_function1
	call	_function3
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	$LC2, (%esp)
	call	_printf
	movl	$1, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$LC4, (%esp)
	call	_puts
	movl	$___func__.1889, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	$LC2, (%esp)
	call	_printf
	movl	$2, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$LC4, (%esp)
	call	_puts
	movl	$51, 12(%esp)
	movl	$___func__.1889, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC6, (%esp)
	call	_printf
	movl	$LC2, (%esp)
	call	_printf
	movl	$3, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$LC4, (%esp)
	call	_puts
	movl	$201112, 16(%esp)
	movl	$52, 12(%esp)
	movl	$___func__.1889, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	movl	$LC2, (%esp)
	call	_printf
	movl	$4, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$LC4, (%esp)
	call	_puts
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.globl	_function1
	.def	_function1;	.scl	2;	.type	32;	.endef
_function1:
LFB11:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	$LC2, (%esp)
	call	_printf
	movl	$1, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$LC4, (%esp)
	call	_puts
	movl	$___func__.1893, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	$LC2, (%esp)
	call	_printf
	movl	$2, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$LC4, (%esp)
	call	_puts
	movl	$63, 12(%esp)
	movl	$___func__.1893, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC6, (%esp)
	call	_printf
	movl	$LC2, (%esp)
	call	_printf
	movl	$3, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$LC4, (%esp)
	call	_puts
	movl	$201112, 16(%esp)
	movl	$64, 12(%esp)
	movl	$___func__.1893, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	movl	$LC2, (%esp)
	call	_printf
	movl	$4, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$LC4, (%esp)
	call	_puts
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE11:
	.globl	_function2
	.def	_function2;	.scl	2;	.type	32;	.endef
_function2:
LFB12:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	$LC2, (%esp)
	call	_printf
	movl	$1, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$LC4, (%esp)
	call	_puts
	movl	$___func__.1897, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	$LC2, (%esp)
	call	_printf
	movl	$2, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$LC4, (%esp)
	call	_puts
	movl	$72, 12(%esp)
	movl	$___func__.1897, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC6, (%esp)
	call	_printf
	movl	$LC2, (%esp)
	call	_printf
	movl	$3, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$LC4, (%esp)
	call	_puts
	movl	$201112, 16(%esp)
	movl	$73, 12(%esp)
	movl	$___func__.1897, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	movl	$LC2, (%esp)
	call	_printf
	movl	$4, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$LC4, (%esp)
	call	_puts
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE12:
	.globl	_function3
	.def	_function3;	.scl	2;	.type	32;	.endef
_function3:
LFB13:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	$LC2, (%esp)
	call	_printf
	movl	$1, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$LC4, (%esp)
	call	_puts
	movl	$___func__.1901, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	$LC2, (%esp)
	call	_printf
	movl	$2, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$LC4, (%esp)
	call	_puts
	movl	$81, 12(%esp)
	movl	$___func__.1901, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC6, (%esp)
	call	_printf
	movl	$LC2, (%esp)
	call	_printf
	movl	$3, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$LC4, (%esp)
	call	_puts
	movl	$201112, 16(%esp)
	movl	$82, 12(%esp)
	movl	$___func__.1901, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	movl	$LC2, (%esp)
	call	_printf
	movl	$4, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$LC4, (%esp)
	call	_puts
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE13:
	.section .rdata,"dr"
	.align 4
___func__.1889:
	.ascii "main\0"
	.align 4
___func__.1893:
	.ascii "function1\0"
	.align 4
___func__.1897:
	.ascii "function2\0"
	.align 4
___func__.1901:
	.ascii "function3\0"
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
