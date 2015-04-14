global idt_set

idt_set:
	mov		eax, [esp + 4]
	lidt	[eax]
	ret
