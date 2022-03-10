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
	.align 4
LC0:
	.ascii "Input the number of elements to store in the array (max 15): \0"
LC1:
	.ascii "%s\12\0"
LC2:
	.ascii "%d\0"
LC3:
	.ascii "Element - %d: \0"
	.align 4
LC4:
	.ascii "\12The elements of array in reverse order are :\12\0"
LC5:
	.ascii "Element - %d: %d\12\0"
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
	subl	$96, %esp
	call	___main
	leal	28(%esp), %eax
	movl	%eax, 92(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	leal	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_scanf
	movl	$0, 88(%esp)
	jmp	L4
L5:
	movl	88(%esp), %eax
	addl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	92(%esp), %eax
	leal	4(%eax), %edx
	movl	%edx, 92(%esp)
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_scanf
	addl	$1, 88(%esp)
L4:
	movl	24(%esp), %eax
	cmpl	%eax, 88(%esp)
	jl	L5
	movl	$LC4, (%esp)
	call	_printf
	movl	24(%esp), %eax
	movl	%eax, 88(%esp)
	jmp	L6
L7:
	subl	$4, 92(%esp)
	movl	92(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, 8(%esp)
	movl	88(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	subl	$1, 88(%esp)
L6:
	cmpl	$0, 88(%esp)
	jg	L7
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	___mingw_vprintf;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
