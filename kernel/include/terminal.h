#ifndef TERMINAL_H
#define TERMINAL_H 

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "string.h"
#include "vga_driver.h"
#include "io.h"

#define TERMINAL_HEIGHT	25
#define TERMINAL_LENGTH	80
#define TERMINAL_SIZE TERMINAL_HEIGHT*TERMINAL_LENGTH

void terminal_write(char* msg);

void terminal_clear();

void terminal_move_cursor(uint16_t pos);

void terminal_scroll();

#endif
