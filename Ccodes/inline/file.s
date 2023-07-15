	.file	"file.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB17:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$48, %esp
	call	___main
	movl	$1847621965, 26(%esp)
	movl	$543518049, 30(%esp)
	movl	$1327526761, 34(%esp)
	movl	$544366957, 38(%esp)
	movl	$1634564417, 42(%esp)
	movw	$110, 46(%esp)
	leal	26(%esp), %eax
	movl	%eax, (%esp)
	call	_fun1
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE17:
	.def	_fun1;	.scl	3;	.type	32;	.endef
_fun1:
LFB18:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	_i.3110, %eax
	addl	$1, %eax
	movl	%eax, _i.3110
	movl	_i.3110, %eax
	cmpl	$9, %eax
	jg	L5
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_puts
	movl	8(%ebp), %eax
	addl	$1, %eax
	movl	%eax, (%esp)
	call	_fun1
L5:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE18:
.lcomm _i.3110,4,4
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_puts;	.scl	2;	.type	32;	.endef
