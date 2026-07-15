	.file	"drawing_engine.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"enter your name :"
.LC1:
	.string	"%s"
.LC2:
	.string	"name is :%s"
	.text
	.globl	main
	.type	main, @function
main:
.LFB23:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$40, %rsp
	.cfi_def_cfa_offset 64
	movq	%fs:40, %rax
	movq	%rax, 24(%rsp)
	xorl	%eax, %eax
	leaq	.LC0(%rip), %rsi
	movl	$2, %edi
	call	__printf_chk@PLT
	leaq	14(%rsp), %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	$0, %ebx
	jmp	.L2
.L3:
	movl	$95, %edi
	call	putchar@PLT
	addl	$1, %ebx
.L2:
	cmpl	$122, %ebx
	jle	.L3
	movl	$10, %edi
	call	putchar@PLT
	movl	$0, %ebp
	jmp	.L4
.L6:
	movl	$32, %edi
	call	putchar@PLT
	addl	$1, %ebx
.L5:
	cmpl	$122, %ebx
	jle	.L6
	movl	$124, %edi
	call	putchar@PLT
	movl	$10, %edi
	call	putchar@PLT
	addl	$1, %ebp
.L4:
	cmpl	$132, %ebp
	jg	.L12
	movl	$124, %edi
	call	putchar@PLT
	leaq	14(%rsp), %rdx
	leaq	.LC2(%rip), %rsi
	movl	$2, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movl	$0, %ebx
	jmp	.L5
.L12:
	movl	$0, %ebx
	jmp	.L8
.L9:
	movl	$95, %edi
	call	putchar@PLT
	addl	$1, %ebx
.L8:
	cmpl	$132, %ebx
	jle	.L9
	movl	$10, %edi
	call	putchar@PLT
	movq	24(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L13
	movl	$0, %eax
	addq	$40, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L13:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE23:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04.1) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
