.file "lab4.s"
.globl main
	.type	main, @function

.text
main:
	pushq %rbp		#stack housekeeping
	movq %rsp, %rbp

Label1:
#as you go through this program note the changes to %rip
	movq	$0x8877665544332211, %rax	# the value of %rax is:
	movb	$-1, %al			# the value of %rax is:
	movw	$-1, %ax			# the value of %rax is:
	movl	$-1, %eax			# the value of %rax is:
	movq	$-1, %rax			# the value of %rax is:

	movl	$-1, %eax			# the value of %rax is:
	cltq					# the value of %rax is:

	movl	$0x7fffffff, %eax		# the value of %rax is:
	cltq					# the value of %rax is:

	movq	$0x8877665544332211, %rax	# the value of %rax is:

	# the value of %rdx *before* movb $0xAA, %dl executes is:
	movb	$0xAA, %dl			# the value of %rdx is:
	movb	%dl, %al			# the value of %rax is:
	movsbw	%dl, %ax			# the value of %rax is:
	movzbw	%dl, %ax			# the value of %rax is:

	movq	$0x8877665544332211, %rax	# the value of %rax is:
	movb 	%dl, %al			# the value of %rax is:
	movsbl	%dl, %eax			# the value of %rax is:
	movzbl	%dl, %eax			# the value of %rax is:

	movq	$0x8877665544332211, %rax	# the value of %rax is:
	movb 	%dl, %al			# the value of %rax is:
	movsbq	%dl, %rax			# the value of %rax is:
	movzbq	%dl, %rax			# the value of %rax is:

	movq	$0x8877665544332211, %rax	# the value of %rax is:
	# the value of %rdx *before* movb $0x55, %dl executes is:
	movb	$0x55, %dl			# the value of %rdx is:
	movb	%dl, %al			# the value of %rax is:
	movsbw	%dl, %ax			# the value of %rax is:
	movzbw	%dl, %ax			# the value of %rax is:

	movq	$0x8877665544332211, %rax	# the value of %rax is:
	movb 	%dl, %al			# the value of %rax is:
	movsbl	%dl, %eax			# the value of %rax is:
	movzbl	%dl, %eax			# the value of %rax is:

	movq	$0x8877665544332211, %rax	# the value of %rax is:
	movb 	%dl, %al			# the value of %rax is:
	movsbq	%dl, %rax			# the value of %rax is:
	movzbq	%dl, %rax			# the value of %rax is:

#	movq	$0x8877665544332211, %rax	# the value of %rax is:
#	pushb	%al
#	movq	$0, %rax
#	popb	%al				# the value of %rax is:

	movq	$0x8877665544332211, %rax	# the value of %rax is:		the value of %rsp is:
	pushw	%ax				# the value of %rsp is:
						# the difference between the two values of %rsp is:
	movq	$0, %rax			# the value of %rax is:
	popw	%ax				# the value of %rax is:		How did the value of %rsp change?

	movq	$0x8877665544332211, %rax	# the value of %rax is:		the value of %rsp is:
	pushw	%ax				# the value of %rsp is:
						# the difference between the two values of %rsp is:
	movq	$-1, %rax			# the value of %rax is:
	popw	%ax				# the value of %rax is:		How did the value of %rsp change?


#	movq	$0x8877665544332211, %rax	# the value of %rax is:
#	pushl	%eax
#	movq	$0, %rax
#	popl	%eax				# the value of %rax is:

	movq	$0x8877665544332211, %rax	# the value of %rax is:		the value of %rsp is:
	pushq	%rax				# the value of %rsp is:
						# the difference between the two values of %rsp is:
	movq	$0, %rax			# the value of %rax is:
	popq	%rax				# the value of %rax is:		How did the value of %rsp change?

						# what eflags are set?

	movq	$0x500, %rax			# the value of %rax is:
	movq	$0x123, %rcx			# the value of %rcx is:
	subq	%rax, %rcx			# the value of %rax is:
						# the value of %rcx is:

						# what eflags are set?

	movq 	$0x500, %rax			# the value of %rax is:
	movq	$0x123, %rcx			# the value of %rcx is:
	subq	%rcx, %rax			# the value of %rax is:
						# what eflags are set?

	movq	$0x500, %rax			# the value of %rax is:
	movq	$0x500, %rcx			# the value of %rcx is:
	subq	%rcx, %rax			# the value of %rax is:
						# what eflags are set?

	movb	$0xff, %al			# the value of %rax is:
	incb	%al				# the value of %rax is:		what eflags are set?

	movq	$-1, %rax			# the value of %rax is:
	incq	%rax				# the value of %rax is:		what eflags are set?

	movq	$0x8877665544332211, %rax	# the value of %rax is:		the value of %rsp is:
	movq	$0x8877665544332211, %rcx	# the value of %rax is:		what eflags are set?
	addq	%rcx, %rax			# the value of %rax is:		what eflags are set?
	leave
	ret

.size	main, .-main
