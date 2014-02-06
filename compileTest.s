	.section	__TEXT,__text,regular,pure_instructions
	.globl	_proc
	.align	4, 0x90
_proc:                                  ## @proc
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp2:
	.cfi_def_cfa_offset 16
Ltmp3:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp4:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movl	$0, -12(%rbp)
	movl	$0, -16(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$1000000, -16(%rbp)     ## imm = 0xF4240
	jge	LBB0_4
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	movslq	-16(%rbp), %rax
	movq	-8(%rbp), %rcx
	movl	(%rcx,%rax,4), %edx
	movl	-12(%rbp), %esi
	addl	%edx, %esi
	movl	%esi, -12(%rbp)
## BB#3:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -16(%rbp)
	jmp	LBB0_1
LBB0_4:
	movl	-12(%rbp), %eax
	popq	%rbp
	ret
	.cfi_endproc

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp7:
	.cfi_def_cfa_offset 16
Ltmp8:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp9:
	.cfi_def_cfa_register %rbp
	subq	$4000032, %rsp          ## imm = 0x3D0920
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -12(%rbp)
	movl	$0, -4000020(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$1000000, -4000020(%rbp) ## imm = 0xF4240
	jge	LBB1_4
## BB#2:                                ##   in Loop: Header=BB1_1 Depth=1
	movl	-4000020(%rbp), %eax
	movl	-4000020(%rbp), %ecx
	shll	$1, %ecx
	addl	%ecx, %eax
	movslq	-4000020(%rbp), %rdx
	movl	%eax, -4000016(%rbp,%rdx,4)
## BB#3:                                ##   in Loop: Header=BB1_1 Depth=1
	movl	-4000020(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4000020(%rbp)
	jmp	LBB1_1
LBB1_4:
	leaq	-4000016(%rbp), %rdi
	movl	$0, -4000024(%rbp)
	callq	_proc
	movq	___stack_chk_guard@GOTPCREL(%rip), %rdi
	movl	%eax, -4000024(%rbp)
	movq	(%rdi), %rdi
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rdi
	jne	LBB1_6
## BB#5:                                ## %SP_return
	movl	$0, %eax
	addq	$4000032, %rsp          ## imm = 0x3D0920
	popq	%rbp
	ret
LBB1_6:                                 ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	.cfi_endproc


.subsections_via_symbols
