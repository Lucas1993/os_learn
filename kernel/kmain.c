#include "terminal.h"
#include "descriptor_tables.h"
#include "timer.h"


void kmain() {

	terminal_clear();
	serial_configure_line(SERIAL_COM1_BASE);
	/*serial_write("teste");*/
	init_gdt();
	init_idt();
	/*init_timer(50);*/
	/*asm volatile("int $0x4");*/
	/*terminal_write(",,,,,,,\n,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,");*/

	return;
}
