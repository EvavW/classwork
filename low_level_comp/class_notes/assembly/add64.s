	.text
	.global add64
	.type add64, @function
add64:
	movl %edi, %eax /* movl = move long */
	addl %esi, %eax /* add long */
	ret /* return */
	
