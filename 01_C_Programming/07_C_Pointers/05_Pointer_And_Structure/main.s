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
	.ascii "Exmployee Name : %s\12\0"
LC1:
	.ascii "Exmployee ID : %d\12\12\0"
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
	pushl	%edi
	andl	$-16, %esp
	subl	$208, %esp
	.cfi_offset 7, -12
	call	___main
	movl	$1919639885, 148(%esp)
	movl	$1293970785, 152(%esp)
	movl	$1919248481, 156(%esp)
	movl	$0, 160(%esp)
	leal	164(%esp), %edx
	movl	$0, %eax
	movl	$8, %ecx
	movl	%edx, %edi
	rep stosl
	movl	%edi, %edx
	movw	%ax, (%edx)
	addl	$2, %edx
	movl	$1000, 200(%esp)
	movl	$1869768011, 92(%esp)
	movl	$7562604, 96(%esp)
	leal	100(%esp), %edx
	movl	$0, %eax
	movl	$10, %ecx
	movl	%edx, %edi
	rep stosl
	movl	%edi, %edx
	movw	%ax, (%edx)
	addl	$2, %edx
	movl	$1001, 144(%esp)
	movl	$2019912769, 36(%esp)
	movl	$0, 40(%esp)
	leal	44(%esp), %edx
	movl	$0, %eax
	movl	$10, %ecx
	movl	%edx, %edi
	rep stosl
	movl	%edi, %edx
	movw	%ax, (%edx)
	addl	$2, %edx
	movl	$1002, 88(%esp)
	leal	148(%esp), %eax
	movl	%eax, 24(%esp)
	leal	92(%esp), %eax
	movl	%eax, 28(%esp)
	leal	36(%esp), %eax
	movl	%eax, 32(%esp)
	leal	24(%esp), %eax
	movl	%eax, 204(%esp)
	movl	204(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	204(%esp), %eax
	movl	(%eax), %eax
	movl	52(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	204(%esp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	204(%esp), %eax
	movl	4(%eax), %eax
	movl	52(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	204(%esp), %eax
	movl	8(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	204(%esp), %eax
	movl	8(%eax), %eax
	movl	52(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	$0, %eax
	movl	-4(%ebp), %edi
	leave
	.cfi_restore 5
	.cfi_restore 7
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	___mingw_vprintf;	.scl	2;	.type	32;	.endef
