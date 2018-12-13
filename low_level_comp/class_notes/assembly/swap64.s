	.text
	.global swap64
	.type swap64, @function
swap64:
	movl (%rdi), %eax
	movl (%rsi), %edx
	movl %edx, (%rdi)
	movl %eax, (%rsi)
	ret
	
