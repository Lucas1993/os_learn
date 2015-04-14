#ifndef ISR_H
#define ISR_H

#include <stdint.h>

struct registers {
	//uint32_t ds;
	uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
	uint32_t int_num, error_code;
	uint32_t eip, cs, eflags;
		//, useresp, ss;
};
typedef struct registers registers_t;

typedef void (*int_handler_t)(registers_t);

void interrupt_handler(registers_t);

void int_req_handler(registers_t);

void init_isr_vector();

#endif
