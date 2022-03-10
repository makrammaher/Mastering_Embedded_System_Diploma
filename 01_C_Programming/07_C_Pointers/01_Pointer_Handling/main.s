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
	.ascii "Address of m: 0x%x\12\0"
LC1:
	.ascii "Value of m: %d\12\0"
	.align 4
LC2:
	.ascii "\12now ab is assgined with the adress of m.\12\0"
LC3:
	.ascii "Address of pointer ab: 0x%x\12\0"
LC4:
	.ascii "Content of pointer ab: %d\12\0"
	.align 4
LC5:
	.ascii "\12The value of m assigned to 34 now\12\0"
	.align 4
LC6:
	.ascii "\12The pointer variable ab is assigned with the value 7 now:\12\0"
LC7:
	.ascii "value of m: %d\12\0"
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
	movl	$29, 24(%esp)
	leal	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	leal	24(%esp), %eax
	movl	%eax, 28(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	28(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$34, 24(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	28(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	28(%esp), %eax
	movl	$7, (%eax)
	movl	$LC6, (%esp)
	call	_printf
	leal	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC7, (%esp)
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
