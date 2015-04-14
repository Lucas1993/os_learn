#include "keyboard.h"

#define KEYBOARD_DATA_PORT 0x60

uint8_t read_kbd_data() {
	return inb(KEYBOARD_DATA_PORT);
}
