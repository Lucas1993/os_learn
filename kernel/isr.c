#include "isr.h"
#include "terminal.h"
#include "pic.h"
#include "int_handlers.h"

int_handler_t int_routines[256];

void interrupt_handler(registers_t regs) {
	/*terminal_write("interrupt received!");*/
	int_handler_t handler = int_routines[regs.int_num];
	handler(regs);
}

void init_isr_vector() {
	int_routines[0] =   handler_int0; 
	int_routines[1] =   handler_int1; 
	int_routines[2] =   handler_int2; 
	int_routines[3] =   handler_int3; 
	int_routines[4] =   handler_int4; 
	int_routines[5] =   handler_int5; 
	int_routines[6] =   handler_int6; 
	int_routines[7] =   handler_int7; 
	int_routines[8] =   handler_int8; 
	int_routines[9] =   handler_int9; 
	int_routines[10] =  handler_int10;
	int_routines[11] =  handler_int11;
	int_routines[12] =  handler_int12;
	int_routines[13] =  handler_int13;
	int_routines[14] =  handler_int14;
	int_routines[15] =  handler_int15;
	int_routines[16] =  handler_int16;
	int_routines[17] =  handler_int17;
	int_routines[18] =  handler_int18;
	int_routines[19] =  handler_int19;
	int_routines[20] =  handler_int20;
	int_routines[21] =  handler_int21;
	int_routines[22] =  handler_int22;
	int_routines[23] =  handler_int23;
	int_routines[24] =  handler_int24;
	int_routines[25] =  handler_int25;
	int_routines[26] =  handler_int26;
	int_routines[27] =  handler_int27;
	int_routines[28] =  handler_int28;
	int_routines[29] =  handler_int29;
	int_routines[30] =  handler_int30;
	int_routines[31] =  handler_int31;
	int_routines[32] =  handler_int32;
	int_routines[33] =  handler_int33;
	int_routines[34] =  handler_int34;
	int_routines[35] =  handler_int35;
	int_routines[36] =  handler_int36;
	int_routines[37] =  handler_int37;
	int_routines[38] =  handler_int38;
	int_routines[39] =  handler_int39;
	int_routines[40] =  handler_int40;
	int_routines[41] =  handler_int41;
	int_routines[42] =  handler_int42;
	int_routines[43] =  handler_int43;
	int_routines[44] =  handler_int44;
	int_routines[45] =  handler_int45;
	int_routines[46] =  handler_int46;
	int_routines[47] =  handler_int47;
}


void int_req_handler(registers_t regs) {
	int irq = regs.int_num - 32;
	if (regs.int_num == 32) {
		uint16_t picregs = pic_get_isr();
		if ( !( picregs & 1) ) {
			return;
		} else {
			pic_send_EOI(regs.int_num);
		}
	} else if (regs.int_num == 40) {
		uint16_t picregs = pic_get_isr();
		if (!(  (picregs >> 8) & 1)) {
			return;
		} else {
			pic_send_EOI(regs.int_num);
		}

	} else {
		pic_send_EOI(irq);
	}
	int_handler_t handler = int_routines[regs.int_num];
	handler(regs);
}
