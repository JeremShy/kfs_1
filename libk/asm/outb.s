# Pourquoi diable ça ne marche pas ?!

.section .text
.global outb
outb:
	push %ebp
	mov %esp, %ebp

	movb 8(%ebp), %al
	movb 4(%ebp), %dl

	outb %al, %dx

	mov	%esp, %ebp
	pop	%ebp
	ret
