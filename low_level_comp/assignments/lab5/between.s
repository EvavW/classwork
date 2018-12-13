	.text
	.globl	between
between:
LFB0:
	movl	%edi, %eax #copy value of first register into eax
	cmpl	%esi, %eax #compare value of 2nd register to eax
	jle	L2 #if previous compare return less than or equal to: jump to L2
	cmpl	%edx, %eax #compare value of 3rd register to eac
	jge	L2 #if previous comapre return greater than or equal to: jump to L2
	movl	$1, %eax #if we havent jumped to L2: move 1 into eax
	jmp	L3 #jump to L3
L2:
	movl	$0, %eax #move 0 into eax
L3:
	ret #return eax

	
