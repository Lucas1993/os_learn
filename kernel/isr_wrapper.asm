;Definindo macros gerais para auxiliar na
;definição dos interrupt handlers.
;As 6 primeiras não possuem codigo de erro
;na stack, tem que colocar dummy

;======== No error normal interrupt macro

%macro noerror_isr 1
global isr%1
isr%1:
	cli
	push	dword 0
	push	dword %1
	jmp		common_isr
%endmacro

;======== Error normal interrupt macro

%macro error_isr 1
global isr%1
isr%1:
	cli
	push	dword %1
	jmp		common_isr
%endmacro

;======== IRQ macro

%macro irq 2
global irq%1
irq%1:
	cli
	push	dword 0
	push	dword %2
	jmp		common_irq_handler
%endmacro

;======== Função padrão para gerenciar interrupts normais

extern interrupt_handler

common_isr:
	pusha
	;mov		ax, ds
	;push	eax

;;Coloca os segmentos de dados para ser os do kernel.
	;mov		ax, 0x10
	;mov		ds, ax
	;mov		es, ax
	;mov		fs, ax
	;mov		gs, ax

	call interrupt_handler

	;pop		eax
	;mov		ds, ax
	;mov		es, ax
	;mov		fs, ax
	;mov		gs, ax

	popa
;Remove o codigo de erro e o numero da interrupção da stack
	add		esp, 8
	sti
	iret


extern int_req_handler

common_irq_handler:
	pusha
	;mov		ax, ds
	;push	eax

;;Coloca os segmentos de dados para ser os do kernel.
	;mov		ax, 0x10
	;mov		ds, ax
	;mov		es, ax
	;mov		fs, ax
	;mov		gs, ax

	call int_req_handler

	;pop		eax
	;mov		ds, ax
	;mov		es, ax
	;mov		fs, ax
	;mov		gs, ax

	popa
;Remove numero da irq da stack
	add		esp, 8
	sti
	iret

noerror_isr 0
noerror_isr 1
noerror_isr 2
noerror_isr 3
noerror_isr 4
noerror_isr 5
noerror_isr 6
error_isr 7
error_isr 8
error_isr 9
error_isr 10
error_isr 11
error_isr 12
error_isr 13
error_isr 14
error_isr 15
error_isr 16
error_isr 17
error_isr 18
error_isr 19
error_isr 20
error_isr 21
error_isr 22
error_isr 23
error_isr 24
error_isr 25
error_isr 26
error_isr 27
error_isr 28
error_isr 29
error_isr 30
error_isr 31
irq 0, 32
irq 1, 33
irq 2, 34
irq 3, 35
irq 4, 36
irq 5, 37
irq 6, 38
irq 7, 39
irq 8, 40
irq 9, 41
irq 10, 42
irq 11, 43
irq 12, 44
irq 13, 45
irq 14, 46
irq 15, 47
