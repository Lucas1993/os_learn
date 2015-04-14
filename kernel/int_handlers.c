#include "int_handlers.h"
#include "terminal.h"
#include "keyboard.h"

void generic_int_handler(registers_t regs) {
	terminal_write("interrupt X received!\n");
}

void handler_int0(registers_t regs){
	terminal_write("interrupt 0 received!\n");
}

void handler_int1(registers_t regs){
	terminal_write("interrupt 1 received!\n");
}

void handler_int2(registers_t regs){
	terminal_write("interrupt 2 received!\n");
}

void handler_int3(registers_t regs){
	terminal_write("interrupt 3 received!\n");
}

void handler_int4(registers_t regs){
	terminal_write("interrupt 4 received!\n");
}

void handler_int5(registers_t regs){
	terminal_write("interrupt 5 received!\n");
}

void handler_int6(registers_t regs){
	terminal_write("interrupt 6 received!\n");
}

void handler_int7(registers_t regs){
	terminal_write("interrupt 7 received!\n");
}

void handler_int8(registers_t regs){
	terminal_write("interrupt 8 received!\n");
}

void handler_int9(registers_t regs){
	terminal_write("interrupt 9 received!\n");
}

void handler_int10(registers_t regs){
	terminal_write("interrupt 10 received!\n");
}

void handler_int11(registers_t regs){
	terminal_write("interrupt 11 received!\n");
}

void handler_int12(registers_t regs){
	terminal_write("interrupt 12 received!\n");
}

void handler_int13(registers_t regs){
	terminal_write("interrupt 13 received!\n");
}

void handler_int14(registers_t regs){
	terminal_write("interrupt 14 received!\n");
}

void handler_int15(registers_t regs){
	terminal_write("interrupt 15 received!\n");
}

void handler_int16(registers_t regs){
	terminal_write("interrupt 16 received!\n");
}

void handler_int17(registers_t regs){
	terminal_write("interrupt 17 received!\n");
}

void handler_int18(registers_t regs){
	terminal_write("interrupt 18 received!\n");
}

void handler_int19(registers_t regs){
	terminal_write("interrupt 19 received!\n");
}

void handler_int20(registers_t regs){
	terminal_write("interrupt 20 received!\n");
}

void handler_int21(registers_t regs){
	terminal_write("interrupt 21 received!\n");
}

void handler_int22(registers_t regs){
	terminal_write("interrupt 22 received!\n");
}

void handler_int23(registers_t regs){
	terminal_write("interrupt 23 received!\n");
}

void handler_int24(registers_t regs){
	terminal_write("interrupt 24 received!\n");
}

void handler_int25(registers_t regs){
	terminal_write("interrupt 25 received!\n");
}

void handler_int26(registers_t regs){
	terminal_write("interrupt 26 received!\n");
}

void handler_int27(registers_t regs){
	terminal_write("interrupt 27 received!\n");
}

void handler_int28(registers_t regs){
	terminal_write("interrupt 28 received!\n");
}

void handler_int29(registers_t regs){
	terminal_write("interrupt 29 received!\n");
}

void handler_int30(registers_t regs){
	terminal_write("interrupt 30 received!\n");
}

void handler_int31(registers_t regs){
	terminal_write("interrupt 31 received!\n");
}

void handler_int32(registers_t regs){
	terminal_write("interrupt 32 received!\n");
}

void handler_int33(registers_t regs){
	terminal_write("interrupt 33 received!\n");
	read_kbd_data();
}

void handler_int34(registers_t regs){
	terminal_write("interrupt 34 received!\n");
}

void handler_int35(registers_t regs){
	terminal_write("interrupt 35 received!\n");
}

void handler_int36(registers_t regs){
	terminal_write("interrupt 36 received!\n");
}

void handler_int37(registers_t regs){
	terminal_write("interrupt 37 received!\n");
}

void handler_int38(registers_t regs){
	terminal_write("interrupt 38 received!\n");
}

void handler_int39(registers_t regs){
	terminal_write("interrupt 39 received!\n");
}

void handler_int40(registers_t regs){
	terminal_write("interrupt 40 received!\n");
}

void handler_int41(registers_t regs){
	terminal_write("interrupt 41 received!\n");
}

void handler_int42(registers_t regs){
	terminal_write("interrupt 42 received!\n");
}

void handler_int43(registers_t regs){
	terminal_write("interrupt 43 received!\n");
}

void handler_int44(registers_t regs){
	terminal_write("interrupt 44 received!\n");
}

void handler_int45(registers_t regs){
	terminal_write("interrupt 45 received!\n");
}

void handler_int46(registers_t regs){
	terminal_write("interrupt 46 received!\n");
}

void handler_int47(registers_t regs){
	terminal_write("interrupt 47 received!\n");
}


