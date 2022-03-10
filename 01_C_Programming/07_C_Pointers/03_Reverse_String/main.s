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
	.ascii "Input a string: \0"
LC1:
	.ascii "%s\0"
LC2:
	.ascii "Reverse of the string is: %s\12\0"
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
	subl	$240, %esp
	call	___main
	leal	128(%esp), %eax
	movl	%eax, 228(%esp)
	leal	28(%esp), %eax
	movl	%eax, 236(%esp)
	movl	$LC0, (%esp)
	call	_printf
	leal	128(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_scanf
	movl	$0, 232(%esp)
	jmp	L4
L5:
	addl	$1, 232(%esp)
L4:
	movl	232(%esp), %edx
	movl	228(%esp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	L5
	subl	$1, 232(%esp)
	jmp	L6
L7:
	movl	236(%esp), %eax
	leal	1(%eax), %edx
	movl	%edx, 236(%esp)
	movl	232(%esp), %edx
	leal	-1(%edx), %ecx
	movl	%ecx, 232(%esp)
	movl	%edx, %ecx
	movl	228(%esp), %edx
	addl	%ecx, %edx
	movzbl	(%edx), %edx
	movb	%dl, (%eax)
L6:
	cmpl	$0, 232(%esp)
	jns	L7
	movl	236(%esp), %eax
	movb	$0, (%eax)
	leal	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
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
	.def	_scanf;	.scl	2;	.type	32;	.endef
