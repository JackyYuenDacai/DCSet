	.file	"main.cpp"
	.globl	Copyright
	.data
	.type	Copyright, @object
	.size	Copyright, 30
Copyright:
	.string	"Copyright 2014@JackyYuenDacai"
	.section	.text._ZN7DCDNodeC2Ex,"axG",@progbits,_ZN7DCDNodeC5Ex,comdat
	.align 2
	.weak	_ZN7DCDNodeC2Ex
	.type	_ZN7DCDNodeC2Ex, @function
_ZN7DCDNodeC2Ex:
.LFB3:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, -32(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, -28(%ebp)
	movl	$12, (%esp)
	call	malloc
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%edx, 8(%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	4(%edx), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebp), %ecx
	movl	-32(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%eax, 16(%ecx)
	movl	%edx, 20(%ecx)
	movl	$0, -16(%ebp)
	movl	$0, -12(%ebp)
	jmp	.L2
.L3:
	movl	8(%ebp), %eax
	movl	4(%eax), %ebx
	movl	$12, (%esp)
	call	malloc
	movl	%eax, 4(%ebx)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	4(%eax), %eax
	movl	8(%ebp), %edx
	movl	4(%edx), %edx
	movl	%edx, 8(%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	4(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%eax)
	addl	$1, -16(%ebp)
	adcl	$0, -12(%ebp)
.L2:
	movl	-32(%ebp), %eax
	movl	-28(%ebp), %edx
	addl	$-1, %eax
	adcl	$-1, %edx
	cmpl	-12(%ebp), %edx
	jg	.L3
	cmpl	-12(%ebp), %edx
	jl	.L5
	cmpl	-16(%ebp), %eax
	ja	.L3
.L5:
	movl	$8, (%esp)
	call	malloc
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	%edx, 8(%eax)
	movl	8(%ebp), %eax
	movl	8(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 12(%eax)
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	$0, (%eax)
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	_ZN7DCDNodeC2Ex, .-_ZN7DCDNodeC2Ex
	.weak	_ZN7DCDNodeC1Ex
	.set	_ZN7DCDNodeC1Ex,_ZN7DCDNodeC2Ex
	.section	.text._ZN7DCDNode6SettleEx,"axG",@progbits,_ZN7DCDNode6SettleEx,comdat
	.align 2
	.weak	_ZN7DCDNode6SettleEx
	.type	_ZN7DCDNode6SettleEx, @function
_ZN7DCDNode6SettleEx:
.LFB5:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, -32(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, -28(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	.L7
	jmp	.L6
.L7:
	movl	$12, (%esp)
	call	malloc
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%edx, 8(%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	4(%edx), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebp), %ecx
	movl	-32(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%eax, 16(%ecx)
	movl	%edx, 20(%ecx)
	movl	$0, -16(%ebp)
	movl	$0, -12(%ebp)
	jmp	.L9
.L10:
	movl	8(%ebp), %eax
	movl	4(%eax), %ebx
	movl	$12, (%esp)
	call	malloc
	movl	%eax, 4(%ebx)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	4(%eax), %eax
	movl	8(%ebp), %edx
	movl	4(%edx), %edx
	movl	%edx, 8(%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	4(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%eax)
	addl	$1, -16(%ebp)
	adcl	$0, -12(%ebp)
.L9:
	movl	-32(%ebp), %eax
	movl	-28(%ebp), %edx
	addl	$-1, %eax
	adcl	$-1, %edx
	cmpl	-12(%ebp), %edx
	jg	.L10
	cmpl	-12(%ebp), %edx
	jl	.L12
	cmpl	-16(%ebp), %eax
	ja	.L10
.L12:
	movl	$8, (%esp)
	call	malloc
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	%edx, 8(%eax)
	movl	8(%ebp), %eax
	movl	8(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 12(%eax)
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	$0, (%eax)
.L6:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE5:
	.size	_ZN7DCDNode6SettleEx, .-_ZN7DCDNode6SettleEx
	.section	.text._ZN7DCDNode7AddNodeEx,"axG",@progbits,_ZN7DCDNode7AddNodeEx,comdat
	.align 2
	.weak	_ZN7DCDNode7AddNodeEx
	.type	_ZN7DCDNode7AddNodeEx, @function
_ZN7DCDNode7AddNodeEx:
.LFB6:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, -32(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, -28(%ebp)
	movl	$0, -16(%ebp)
	movl	$0, -12(%ebp)
	jmp	.L14
.L15:
	movl	8(%ebp), %eax
	movl	4(%eax), %ebx
	movl	$12, (%esp)
	call	malloc
	movl	%eax, 4(%ebx)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	4(%eax), %eax
	movl	8(%ebp), %edx
	movl	4(%edx), %edx
	movl	%edx, 8(%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	4(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	20(%eax), %edx
	movl	16(%eax), %eax
	addl	$1, %eax
	adcl	$0, %edx
	movl	8(%ebp), %ecx
	movl	%eax, 16(%ecx)
	movl	%edx, 20(%ecx)
	addl	$1, -16(%ebp)
	adcl	$0, -12(%ebp)
.L14:
	movl	-16(%ebp), %eax
	movl	-12(%ebp), %edx
	cmpl	-28(%ebp), %edx
	jl	.L15
	cmpl	-28(%ebp), %edx
	jg	.L13
	cmpl	-32(%ebp), %eax
	jb	.L15
.L13:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE6:
	.size	_ZN7DCDNode7AddNodeEx, .-_ZN7DCDNode7AddNodeEx
	.section	.text._ZN7DCDNode6AddTopEc,"axG",@progbits,_ZN7DCDNode6AddTopEc,comdat
	.align 2
	.weak	_ZN7DCDNode6AddTopEc
	.type	_ZN7DCDNode6AddTopEc, @function
_ZN7DCDNode6AddTopEc:
.LFB7:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movb	%al, -12(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %ebx
	movl	$12, (%esp)
	call	malloc
	movl	%eax, 8(%ebx)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%eax), %eax
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movzbl	-12(%ebp), %edx
	movb	%dl, (%eax)
	movl	8(%ebp), %eax
	movl	20(%eax), %edx
	movl	16(%eax), %eax
	addl	$1, %eax
	adcl	$0, %edx
	movl	8(%ebp), %ecx
	movl	%eax, 16(%ecx)
	movl	%edx, 20(%ecx)
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE7:
	.size	_ZN7DCDNode6AddTopEc, .-_ZN7DCDNode6AddTopEc
	.section	.text._ZN7DCDNode7NodeSetEx,"axG",@progbits,_ZN7DCDNode7NodeSetEx,comdat
	.align 2
	.weak	_ZN7DCDNode7NodeSetEx
	.type	_ZN7DCDNode7NodeSetEx, @function
_ZN7DCDNode7NodeSetEx:
.LFB8:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$68, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, -48(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, -44(%ebp)
	movl	-48(%ebp), %eax
	movl	-44(%ebp), %edx
	addl	$1, %eax
	adcl	$0, %edx
	movl	%eax, %ecx
	movl	%edx, %ebx
	movl	8(%ebp), %eax
	movl	20(%eax), %edx
	movl	16(%eax), %eax
	cmpl	%edx, %ebx
	jl	.L19
	cmpl	%edx, %ebx
	jg	.L37
	cmpl	%eax, %ecx
	jbe	.L19
.L37:
	movl	-48(%ebp), %eax
	movl	-44(%ebp), %edx
	addl	$1, %eax
	adcl	$0, %edx
	movl	8(%ebp), %ecx
	movl	20(%ecx), %ebx
	movl	16(%ecx), %ecx
	subl	%ecx, %eax
	sbbl	%ebx, %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN7DCDNode7AddNodeEx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	jmp	.L21
.L19:
	cmpl	$0, -44(%ebp)
	jns	.L22
	movl	$0, -32(%ebp)
	movl	$0, -28(%ebp)
	jmp	.L23
.L24:
	movl	$48, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN7DCDNode6AddTopEc
	addl	$1, -32(%ebp)
	adcl	$0, -28(%ebp)
.L23:
	movl	-48(%ebp), %eax
	movl	-44(%ebp), %edx
	negl	%eax
	adcl	$0, %edx
	negl	%edx
	cmpl	-28(%ebp), %edx
	jg	.L24
	cmpl	-28(%ebp), %edx
	jl	.L38
	cmpl	-32(%ebp), %eax
	ja	.L24
.L38:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	jmp	.L21
.L22:
	movl	8(%ebp), %eax
	movl	20(%eax), %edx
	movl	16(%eax), %eax
	movl	%edx, %ecx
	shrl	$31, %ecx
	movl	$0, %ebx
	addl	%ecx, %eax
	adcl	%ebx, %edx
	shrdl	$1, %edx, %eax
	sarl	%edx
	movl	$1, %ecx
	cmpl	-44(%ebp), %edx
	jl	.L26
	cmpl	-44(%ebp), %edx
	jg	.L27
	cmpl	-48(%ebp), %eax
	jbe	.L26
.L27:
	movl	$0, %ecx
.L26:
	movzbl	%cl, %eax
	testl	%eax, %eax
	je	.L29
	cmpl	$1, %eax
	je	.L30
	jmp	.L41
.L29:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -36(%ebp)
	movl	$0, -24(%ebp)
	movl	$0, -20(%ebp)
	jmp	.L31
.L32:
	movl	-36(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -36(%ebp)
	addl	$1, -24(%ebp)
	adcl	$0, -20(%ebp)
.L31:
	movl	-24(%ebp), %eax
	movl	-20(%ebp), %edx
	cmpl	-44(%ebp), %edx
	jl	.L32
	cmpl	-44(%ebp), %edx
	jg	.L39
	cmpl	-48(%ebp), %eax
	jb	.L32
.L39:
	movl	-36(%ebp), %eax
	jmp	.L21
.L30:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -36(%ebp)
	movl	$0, -16(%ebp)
	movl	$0, -12(%ebp)
	jmp	.L34
.L35:
	movl	-36(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, -36(%ebp)
	addl	$1, -16(%ebp)
	adcl	$0, -12(%ebp)
.L34:
	movl	8(%ebp), %eax
	movl	20(%eax), %edx
	movl	16(%eax), %eax
	subl	-48(%ebp), %eax
	sbbl	-44(%ebp), %edx
	addl	$-1, %eax
	adcl	$-1, %edx
	cmpl	-12(%ebp), %edx
	jg	.L35
	cmpl	-12(%ebp), %edx
	jl	.L40
	cmpl	-16(%ebp), %eax
	ja	.L35
.L40:
	movl	-36(%ebp), %eax
	jmp	.L21
.L41:
	movl	$0, %eax
.L21:
	addl	$68, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE8:
	.size	_ZN7DCDNode7NodeSetEx, .-_ZN7DCDNode7NodeSetEx
	.section	.text._ZN7DCDNode6DelAllEv,"axG",@progbits,_ZN7DCDNode6DelAllEv,comdat
	.align 2
	.weak	_ZN7DCDNode6DelAllEv
	.type	_ZN7DCDNode6DelAllEv, @function
_ZN7DCDNode6DelAllEv:
.LFB10:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -16(%ebp)
	movl	$0, -12(%ebp)
	jmp	.L43
.L44:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	8(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	call	free
	addl	$1, -16(%ebp)
	adcl	$0, -12(%ebp)
.L43:
	movl	8(%ebp), %eax
	movl	20(%eax), %edx
	movl	16(%eax), %eax
	addl	$-1, %eax
	adcl	$-1, %edx
	cmpl	-12(%ebp), %edx
	jg	.L44
	cmpl	-12(%ebp), %edx
	jl	.L46
	cmpl	-16(%ebp), %eax
	ja	.L44
.L46:
	movl	8(%ebp), %eax
	movl	$1, 16(%eax)
	movl	$0, 20(%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	4(%edx), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%edx, 8(%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE10:
	.size	_ZN7DCDNode6DelAllEv, .-_ZN7DCDNode6DelAllEv
	.section	.text._ZN7DCDNode10ArrayShowcEv,"axG",@progbits,_ZN7DCDNode10ArrayShowcEv,comdat
	.align 2
	.weak	_ZN7DCDNode10ArrayShowcEv
	.type	_ZN7DCDNode10ArrayShowcEv, @function
_ZN7DCDNode10ArrayShowcEv:
.LFB14:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -24(%ebp)
	movl	8(%ebp), %eax
	movl	20(%eax), %edx
	movl	16(%eax), %eax
	addl	$1, %eax
	movl	%eax, (%esp)
	call	malloc
	movl	%eax, -20(%ebp)
	movl	$0, -16(%ebp)
	movl	$0, -12(%ebp)
	jmp	.L48
.L49:
	movl	-16(%ebp), %edx
	movl	-20(%ebp), %eax
	addl	%eax, %edx
	movl	-24(%ebp), %eax
	movzbl	(%eax), %eax
	movb	%al, (%edx)
	movl	-24(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -24(%ebp)
	addl	$1, -16(%ebp)
	adcl	$0, -12(%ebp)
.L48:
	movl	8(%ebp), %eax
	movl	20(%eax), %edx
	movl	16(%eax), %eax
	cmpl	-12(%ebp), %edx
	jg	.L49
	cmpl	-12(%ebp), %edx
	jl	.L52
	cmpl	-16(%ebp), %eax
	ja	.L49
.L52:
	movl	8(%ebp), %eax
	movl	20(%eax), %edx
	movl	16(%eax), %eax
	movl	%eax, %edx
	movl	-20(%ebp), %eax
	addl	%edx, %eax
	movb	$0, (%eax)
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	-20(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	12(%eax), %ebx
	movl	$8, (%esp)
	call	malloc
	movl	%eax, 4(%ebx)
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	4(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 12(%eax)
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	$0, (%eax)
	movl	-20(%ebp), %eax
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE14:
	.size	_ZN7DCDNode10ArrayShowcEv, .-_ZN7DCDNode10ArrayShowcEv
	.section	.text._ZN7DCDNode10ClearArrayEv,"axG",@progbits,_ZN7DCDNode10ClearArrayEv,comdat
	.align 2
	.weak	_ZN7DCDNode10ClearArrayEv
	.type	_ZN7DCDNode10ClearArrayEv, @function
_ZN7DCDNode10ClearArrayEv:
.LFB16:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movb	$0, -13(%ebp)
	movl	8(%ebp), %eax
	movl	8(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 12(%eax)
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	.L54
	jmp	.L53
.L54:
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	free
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	4(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 12(%eax)
	jmp	.L56
.L57:
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	free
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	4(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 12(%eax)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	free
.L56:
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	.L57
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, (%esp)
	call	free
	movl	8(%ebp), %eax
	movl	8(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 12(%eax)
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	$0, (%eax)
.L53:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE16:
	.size	_ZN7DCDNode10ClearArrayEv, .-_ZN7DCDNode10ClearArrayEv
	.section	.text._ZN7DCDNode9GetLengthEv,"axG",@progbits,_ZN7DCDNode9GetLengthEv,comdat
	.align 2
	.weak	_ZN7DCDNode9GetLengthEv
	.type	_ZN7DCDNode9GetLengthEv, @function
_ZN7DCDNode9GetLengthEv:
.LFB17:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	20(%eax), %edx
	movl	16(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE17:
	.size	_ZN7DCDNode9GetLengthEv, .-_ZN7DCDNode9GetLengthEv
	.section	.text._ZN7DCDNodeixEx,"axG",@progbits,_ZN7DCDNodeixEx,comdat
	.align 2
	.weak	_ZN7DCDNodeixEx
	.type	_ZN7DCDNodeixEx, @function
_ZN7DCDNodeixEx:
.LFB18:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-16(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN7DCDNode7NodeSetEx
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE18:
	.size	_ZN7DCDNodeixEx, .-_ZN7DCDNodeixEx
	.section	.text._ZN7DCDNodeD2Ev,"axG",@progbits,_ZN7DCDNodeD5Ev,comdat
	.align 2
	.weak	_ZN7DCDNodeD2Ev
	.type	_ZN7DCDNodeD2Ev, @function
_ZN7DCDNodeD2Ev:
.LFB28:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN7DCDNode10ClearArrayEv
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN7DCDNode6DelAllEv
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, (%esp)
	call	free
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	free
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE28:
	.size	_ZN7DCDNodeD2Ev, .-_ZN7DCDNodeD2Ev
	.weak	_ZN7DCDNodeD1Ev
	.set	_ZN7DCDNodeD1Ev,_ZN7DCDNodeD2Ev
	.section	.text._ZN7Integer10ArrayShowcEv,"axG",@progbits,_ZN7Integer10ArrayShowcEv,comdat
	.align 2
	.weak	_ZN7Integer10ArrayShowcEv
	.type	_ZN7Integer10ArrayShowcEv, @function
_ZN7Integer10ArrayShowcEv:
.LFB30:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN7DCDNode10ArrayShowcEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE30:
	.size	_ZN7Integer10ArrayShowcEv, .-_ZN7Integer10ArrayShowcEv
	.section	.text._ZN7Integer3AddEj,"axG",@progbits,_ZN7Integer3AddEj,comdat
	.align 2
	.weak	_ZN7Integer3AddEj
	.type	_ZN7Integer3AddEj, @function
_ZN7Integer3AddEj:
.LFB31:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$32, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN7DCDNode9GetLengthEv
	addl	$-1, %eax
	adcl	$-1, %edx
	movl	%eax, -16(%ebp)
	movl	%edx, -12(%ebp)
	jmp	.L67
.L68:
	movl	-16(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	8(%ebp), %ecx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	%ecx, (%esp)
	call	_ZN7DCDNodeixEx
	movl	%eax, %ecx
	movzbl	(%ecx), %esi
	movl	12(%ebp), %ebx
	movl	$-858993459, %edx
	movl	%ebx, %eax
	mull	%edx
	shrl	$3, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	subl	%eax, %ebx
	movl	%ebx, %edx
	movl	%edx, %eax
	addl	%esi, %eax
	movb	%al, (%ecx)
	movl	12(%ebp), %eax
	movl	$-858993459, %edx
	mull	%edx
	movl	%edx, %eax
	shrl	$3, %eax
	movl	%eax, 12(%ebp)
	addl	$-1, -16(%ebp)
	adcl	$-1, -12(%ebp)
.L67:
	cmpl	$0, 12(%ebp)
	jne	.L68
	jmp	.L69
.L70:
	movl	12(%ebp), %ecx
	movl	$-858993459, %edx
	movl	%ecx, %eax
	mull	%edx
	shrl	$3, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	movl	%edx, %eax
	addl	$48, %eax
	movsbl	%al, %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_ZN7DCDNode6AddTopEc
	movl	12(%ebp), %eax
	movl	$-858993459, %edx
	mull	%edx
	movl	%edx, %eax
	shrl	$3, %eax
	movl	%eax, 12(%ebp)
.L69:
	cmpl	$0, 12(%ebp)
	jne	.L70
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN7DCDNode9GetLengthEv
	addl	$-1, %eax
	adcl	$-1, %edx
	movl	%eax, -16(%ebp)
	movl	%edx, -12(%ebp)
	jmp	.L71
.L73:
	movl	-16(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	8(%ebp), %ecx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	%ecx, (%esp)
	call	_ZN7DCDNodeixEx
	movzbl	(%eax), %eax
	cmpb	$57, %al
	jbe	.L72
	movl	-16(%ebp), %eax
	movl	-12(%ebp), %edx
	addl	$-1, %eax
	adcl	$-1, %edx
	movl	8(%ebp), %ecx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	%ecx, (%esp)
	call	_ZN7DCDNodeixEx
	movzbl	(%eax), %edx
	addl	$1, %edx
	movb	%dl, (%eax)
	movl	-16(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	8(%ebp), %ecx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	%ecx, (%esp)
	call	_ZN7DCDNodeixEx
	movzbl	(%eax), %edx
	subl	$10, %edx
	movb	%dl, (%eax)
.L72:
	addl	$-1, -16(%ebp)
	adcl	$-1, -12(%ebp)
.L71:
	movl	-16(%ebp), %eax
	movl	-12(%ebp), %edx
	orl	%edx, %eax
	testl	%eax, %eax
	jne	.L73
	movl	8(%ebp), %eax
	movl	$0, 4(%esp)
	movl	$0, 8(%esp)
	movl	%eax, (%esp)
	call	_ZN7DCDNodeixEx
	movzbl	(%eax), %eax
	cmpb	$57, %al
	jbe	.L66
	movl	8(%ebp), %eax
	movl	$49, 4(%esp)
	movl	%eax, (%esp)
	call	_ZN7DCDNode6AddTopEc
	movl	8(%ebp), %eax
	movl	$1, 4(%esp)
	movl	$0, 8(%esp)
	movl	%eax, (%esp)
	call	_ZN7DCDNodeixEx
	movzbl	(%eax), %edx
	subl	$10, %edx
	movb	%dl, (%eax)
.L66:
	addl	$32, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE31:
	.size	_ZN7Integer3AddEj, .-_ZN7Integer3AddEj
	.section	.text._ZN7Integer6AssignEj,"axG",@progbits,_ZN7Integer6AssignEj,comdat
	.align 2
	.weak	_ZN7Integer6AssignEj
	.type	_ZN7Integer6AssignEj, @function
_ZN7Integer6AssignEj:
.LFB34:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN7DCDNode6DelAllEv
	movl	8(%ebp), %eax
	movl	$0, 4(%esp)
	movl	$0, 8(%esp)
	movl	%eax, (%esp)
	call	_ZN7DCDNodeixEx
	movl	%eax, %ebx
	movl	12(%ebp), %ecx
	movl	$-858993459, %edx
	movl	%ecx, %eax
	mull	%edx
	shrl	$3, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	movl	%edx, %eax
	addl	$48, %eax
	movb	%al, (%ebx)
	movl	12(%ebp), %eax
	movl	$-858993459, %edx
	mull	%edx
	movl	%edx, %eax
	shrl	$3, %eax
	movl	%eax, 12(%ebp)
	jmp	.L76
.L77:
	movl	12(%ebp), %ecx
	movl	$-858993459, %edx
	movl	%ecx, %eax
	mull	%edx
	shrl	$3, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	movl	%edx, %eax
	addl	$48, %eax
	movsbl	%al, %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_ZN7DCDNode6AddTopEc
	movl	12(%ebp), %eax
	movl	$-858993459, %edx
	mull	%edx
	movl	%edx, %eax
	shrl	$3, %eax
	movl	%eax, 12(%ebp)
.L76:
	cmpl	$0, 12(%ebp)
	jne	.L77
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE34:
	.size	_ZN7Integer6AssignEj, .-_ZN7Integer6AssignEj
	.section	.text._ZN7IntegeraSEj,"axG",@progbits,_ZN7IntegeraSEj,comdat
	.align 2
	.weak	_ZN7IntegeraSEj
	.type	_ZN7IntegeraSEj, @function
_ZN7IntegeraSEj:
.LFB35:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN7Integer6AssignEj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE35:
	.size	_ZN7IntegeraSEj, .-_ZN7IntegeraSEj
	.section	.text._ZN7IntegerpLEj,"axG",@progbits,_ZN7IntegerpLEj,comdat
	.align 2
	.weak	_ZN7IntegerpLEj
	.type	_ZN7IntegerpLEj, @function
_ZN7IntegerpLEj:
.LFB37:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN7Integer3AddEj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE37:
	.size	_ZN7IntegerpLEj, .-_ZN7IntegerpLEj
	.section	.text._ZN7IntegerC2Ev,"axG",@progbits,_ZN7IntegerC5Ev,comdat
	.align 2
	.weak	_ZN7IntegerC2Ev
	.type	_ZN7IntegerC2Ev, @function
_ZN7IntegerC2Ev:
.LFB47:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$1, 4(%esp)
	movl	$0, 8(%esp)
	movl	%eax, (%esp)
	call	_ZN7DCDNodeC1Ex
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	$1, 4(%esp)
	movl	$0, 8(%esp)
	movl	%eax, (%esp)
	call	_ZN7DCDNodeC1Ex
	movl	8(%ebp), %eax
	addl	$48, %eax
	movl	$1, 4(%esp)
	movl	$0, 8(%esp)
	movl	%eax, (%esp)
	call	_ZN7DCDNodeC1Ex
	movl	8(%ebp), %eax
	movzbl	72(%eax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	.L81
	jmp	.L80
.L81:
	movl	8(%ebp), %eax
	movl	$1, 4(%esp)
	movl	$0, 8(%esp)
	movl	%eax, (%esp)
	call	_ZN7DCDNode6SettleEx
	movl	8(%ebp), %eax
	movl	$0, 4(%esp)
	movl	$0, 8(%esp)
	movl	%eax, (%esp)
	call	_ZN7DCDNodeixEx
	movb	$48, (%eax)
	movl	8(%ebp), %eax
	movb	$1, 72(%eax)
.L80:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE47:
	.size	_ZN7IntegerC2Ev, .-_ZN7IntegerC2Ev
	.weak	_ZN7IntegerC1Ev
	.set	_ZN7IntegerC1Ev,_ZN7IntegerC2Ev
	.section	.text._ZN7IntegerD2Ev,"axG",@progbits,_ZN7IntegerD5Ev,comdat
	.align 2
	.weak	_ZN7IntegerD2Ev
	.type	_ZN7IntegerD2Ev, @function
_ZN7IntegerD2Ev:
.LFB54:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$48, %eax
	movl	%eax, (%esp)
	call	_ZN7DCDNodeD1Ev
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	%eax, (%esp)
	call	_ZN7DCDNodeD1Ev
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN7DCDNodeD1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE54:
	.size	_ZN7IntegerD2Ev, .-_ZN7IntegerD2Ev
	.weak	_ZN7IntegerD1Ev
	.set	_ZN7IntegerD1Ev,_ZN7IntegerD2Ev
	.section	.rodata
.LC0:
	.string	"%s"
	.text
	.globl	main
	.type	main, @function
main:
.LFB52:
	.cfi_startproc
	.cfi_personality 0,__gxx_personality_v0
	.cfi_lsda 0,.LLSDA52
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	andl	$-16, %esp
	subl	$176, %esp
	.cfi_offset 3, -12
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	_ZN7IntegerC1Ev
	leal	100(%esp), %eax
	movl	%eax, (%esp)
	call	_ZN7IntegerC1Ev
	movl	$-1, 16(%esp)
	movl	16(%esp), %eax
	movl	%eax, 4(%esp)
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	_ZN7IntegeraSEj
	movl	16(%esp), %eax
	movl	%eax, 4(%esp)
	leal	100(%esp), %eax
	movl	%eax, (%esp)
	call	_ZN7IntegeraSEj
	movl	16(%esp), %eax
	movl	%eax, 4(%esp)
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	_ZN7IntegerpLEj
	movl	16(%esp), %eax
	movl	%eax, 4(%esp)
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	_ZN7IntegerpLEj
	movl	16(%esp), %eax
	movl	%eax, 4(%esp)
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	_ZN7IntegerpLEj
	movl	16(%esp), %eax
	movl	%eax, 4(%esp)
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	_ZN7IntegerpLEj
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	_ZN7Integer10ArrayShowcEv
	movl	%eax, 20(%esp)
	movl	20(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
.LEHB0:
	call	printf
	movl	$10, (%esp)
	call	putchar
.LEHE0:
	movl	$0, %ebx
	leal	100(%esp), %eax
	movl	%eax, (%esp)
	call	_ZN7IntegerD1Ev
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	_ZN7IntegerD1Ev
	movl	%ebx, %eax
	jmp	.L89
.L88:
	movl	%eax, %ebx
	leal	100(%esp), %eax
	movl	%eax, (%esp)
	call	_ZN7IntegerD1Ev
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	_ZN7IntegerD1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
.LEHB1:
	call	_Unwind_Resume
.LEHE1:
.L89:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE52:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA52:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE52-.LLSDACSB52
.LLSDACSB52:
	.uleb128 .LEHB0-.LFB52
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L88-.LFB52
	.uleb128 0
	.uleb128 .LEHB1-.LFB52
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSE52:
	.text
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
