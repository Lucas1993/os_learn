#include "io.h"

void serial_configure_baud_rate(unsigned short com, unsigned short divisor) {
	outb(SERIAL_LINE_COMMAND_PORT(com),
		 SERIAL_LINE_ENABLE_DLAB);
	outb(SERIAL_DATA_PORT(com),
		 (divisor >> 8) & 0x00FF);
	outb(SERIAL_DATA_PORT(com),
		 divisor & 0x00FF);
}

void serial_configure_line(unsigned short com) {
	outb(SERIAL_LINE_COMMAND_PORT(com), 0x03);
}

int serial_is_transmit_fifo_empty(unsigned int com) {
	return inb(SERIAL_LINE_STATUS_PORT(com)) & 0x20;
}

void serial_write_char(char c) {
	while(serial_is_transmit_fifo_empty(SERIAL_COM1_BASE) == 0);
	outb(SERIAL_COM1_BASE, c);

}

void serial_write(char* data) {
	size_t i = 0, len = strlen(data);
	while(i < len) {
		serial_write_char(data[i]);
		i++;
	}
}
