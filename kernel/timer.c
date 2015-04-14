#include "timer.h"

#include "io.h"

void init_timer(uint32_t freq) {

	uint32_t div = 1193180 / freq;

	outb(0x43, 0x36);

	uint8_t low_div = (uint8_t) (div & 0xFF);
	uint8_t high_div = (uint8_t) (div >> 8) & 0xFF;

	outb(0x40, low_div);
	outb(0x40, high_div);

}
