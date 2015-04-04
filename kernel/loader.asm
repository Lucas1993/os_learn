global _start

MAGIC_NUMBER equ 0x1BADB002
FLAGS		equ 0x0
CHECKSUM	equ	-(MAGIC_NUMBER + FLAGS)
KERNEL_STACK_SIZE equ 4096

section .bss
kernel_stack:
resb KERNEL_STACK_SIZE

section .text
align 4
	dd	MAGIC_NUMBER
	dd FLAGS
	dd CHECKSUM

_start:
	mov esp, kernel_stack + KERNEL_STACK_SIZE
	extern kmain
	call kmain

.loop:
	jmp .loop
