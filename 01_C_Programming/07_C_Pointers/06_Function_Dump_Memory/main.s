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
	.ascii "\12\0"
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
	subl	$48, %esp
	call	___main
	movw	$4352, 32(%esp)
	movw	$13090, 34(%esp)
	movw	$21828, 36(%esp)
	movw	$30566, 38(%esp)
	movw	$-26232, 40(%esp)
	movw	$-17494, 42(%esp)
	movw	$-8756, 44(%esp)
	movw	$-18, 46(%esp)
	movb	$-1, 20(%esp)
	movl	$-1430532899, 24(%esp)
	movb	$-86, 28(%esp)
	movw	$-4370, 30(%esp)
	movl	$12, 4(%esp)
	leal	20(%esp), %eax
	movl	%eax, (%esp)
	call	_dump_memory
	movl	$LC0, (%esp)
	call	_printf
	movl	$16, 4(%esp)
	leal	32(%esp), %eax
	movl	%eax, (%esp)
	call	_dump_memory
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.section .rdata,"dr"
LC1:
	.ascii "Value\0"
LC2:
	.ascii "Address\0"
LC3:
	.ascii "%-15s%-15s\12\0"
LC4:
	.ascii "0x%-13X0x%-13X\12\0"
	.text
	.globl	_dump_memory
	.def	_dump_memory;	.scl	2;	.type	32;	.endef
_dump_memory:
LFB11:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$LC1, 8(%esp)
	movl	$LC2, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$0, -12(%ebp)
	jmp	L6
L7:
	movl	8(%ebp), %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	movl	8(%ebp), %ecx
	movl	-12(%ebp), %edx
	addl	%ecx, %edx
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	addl	$1, -12(%ebp)
L6:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	L7
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE11:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	___mingw_vprintf;	.scl	2;	.type	32;	.endef
