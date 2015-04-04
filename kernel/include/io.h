#ifndef IO_H
#define IO_H 

#include <stdint.h>
#include <stddef.h>
#include "string.h"

#define SERIAL_COM1_BASE                0x3F8      /* COM1 base port */

#define SERIAL_DATA_PORT(base)          (base)
#define SERIAL_FIFO_COMMAND_PORT(base)  (base + 2)
#define SERIAL_LINE_COMMAND_PORT(base)  (base + 3)
#define SERIAL_MODEM_COMMAND_PORT(base) (base + 4)
#define SERIAL_LINE_STATUS_PORT(base)   (base + 5)

/*Configuração para mandar 8 bits por vez*/
#define SERIAL_LINE_ENABLE_DLAB         0x80

void outb(uint16_t port, uint16_t data);

unsigned char inb(unsigned short port);

void serial_configure_baud_rate(unsigned short com, unsigned short divisor);

void serial_configure_line(unsigned short com);

int serial_is_transmit_fifo_empty(unsigned int com);

void serial_write(char* data);

#endif
