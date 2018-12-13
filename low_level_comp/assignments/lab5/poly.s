	.text
	.global poly
poly:
	movl %edi, %eax
	imull %edi, %eax #eax = x^2
	imull %esi, %eax #eax = ax^2
	imull %edi, %edx #edx = bx
	addl %edx, %eax #eax = ax^2 + bx
	addl %ecx, %eax #eax = ax^2 + bx + c
	ret
