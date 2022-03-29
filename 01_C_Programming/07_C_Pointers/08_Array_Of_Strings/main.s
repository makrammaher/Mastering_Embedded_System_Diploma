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
	.align 4
LC4:
	.ascii "suit[0] = %s \11 Address = 0x%X\12\0"
	.align 4
LC5:
	.ascii "suit[1] = %s \11 Address = 0x%X\12\0"
	.align 4
LC6:
	.ascii "suit[2] = %s \11 Address = 0x%X\12\0"
	.align 4
LC7:
	.ascii "suit[3] = %s \11 Address = 0x%X\12\0"
LC8:
	.ascii "\12Dump memory:\12\0"
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
	movl	$LC0, 16(%esp)
	movl	$LC1, 20(%esp)
	movl	$LC2, 24(%esp)
	movl	$LC3, 28(%esp)
	movl	16(%esp), %edx
	movl	16(%esp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	20(%esp), %edx
	movl	20(%esp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	24(%esp), %edx
	movl	24(%esp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC6, (%esp)
	call	_printf
	movl	28(%esp), %edx
	movl	28(%esp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	movl	$LC8, (%esp)
	call	_printf
	movl	16(%esp), %eax
	movl	$29, 4(%esp)
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
LC9:
	.ascii "Value\0"
LC10:
	.ascii "Address\0"
LC11:
	.ascii "%-15s%-15s\12\0"
LC12:
	.ascii "0x%-13X%-13c\12\0"
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
	movl	$LC9, 8(%esp)
	movl	$LC10, 4(%esp)
	movl	$LC11, (%esp)
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
	movl	$LC12, (%esp)
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
