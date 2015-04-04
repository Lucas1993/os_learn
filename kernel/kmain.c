#include "terminal.h"


void kmain() {
	terminal_clear();
	/*for (int i = 0; i < 25; i++) {*/
		/*terminal_write("................................................................................");*/
	/*}*/
	serial_configure_line(SERIAL_COM1_BASE);
	serial_write("teste");
	terminal_write(",,,,,,,\n,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,");

	return;
}
