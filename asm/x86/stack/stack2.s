	.file	"stack2.c"
	.text
	.globl	g
	.type	g, @function
g:
.LFB0:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	addl	$57, %eax
	popl	%ebp
	ret
.LFE0:
	.size	g, .-g
	.globl	f
	.type	f, @function
f:
.LFB1:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	8(%ebp)
	call	g
	addl	$4, %esp
	leave
	ret
.LFE1:
	.size	f, .-f
	.globl	main
	.type	main, @function
main:
.LFB2:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	$9
	call	f
	addl	$4, %esp
	addl	$1, %eax
	leave
	ret
.LFE2:
	.size	main, .-main
	.section	.text.__x86.get_pc_thunk.ax,"axG",@progbits,__x86.get_pc_thunk.ax,comdat
	.globl	__x86.get_pc_thunk.ax
	.hidden	__x86.get_pc_thunk.ax
	.type	__x86.get_pc_thunk.ax, @function
__x86.get_pc_thunk.ax:
.LFB3:
	movl	(%esp), %eax
	ret
.LFE3:
	.ident	"GCC: (GNU) 8.2.1 20180831"
	.section	.note.GNU-stack,"",@progbits
