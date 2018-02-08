.section .text
.global outb
	push %ebp
	mov %ebp, %esp

	movb 8[%ebp], %al


	mov	%esp, %ebp
	pop	%ebp
	ret
