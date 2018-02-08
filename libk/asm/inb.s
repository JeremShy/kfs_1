.section .text
.global inb
inb:
	push %ebp
	mov %esp, %ebp

	movb 8(%ebp), %dl

	inb %dx	, %al

	mov %dx, %ax
	mov	%esp, %ebp
	pop	%ebp
	ret
