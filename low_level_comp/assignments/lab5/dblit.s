	.text
	.globl	dblit
dblit:
LFB0:
	pushq	%rbp #push old stack pointer onto stack
	movq	%rsp, %rbp #copy stack pointer to base pointer
	movl	$0, -4(%rbp) #set array index to 0 
	jmp	L2 jump to L2
L3:
	movl	-4(%rbp), %eax #move array index into eax
	leal	0(,%eax,4), %edx #move value of index to edx 
	addl	%edx, %edx #double the value
	addl	$1, -4(%rbp) #increment the array index
L2:
	movl	-4(%rbp), %eax #move array index into eax
	cmpl	12(%rbp), %eax #comapre length to eax
	jl	L3 #if previous compare return less than: jump to L3
	ret
	
