#include "vga_driver.h"

uint16_t *framebuffer = (uint16_t *) 0xB8000;

/*Escreve um char no terminal (framebuffer) na posição dada. Cada posição da memoria descreve um caracter do terminal, da seguinte maneira:
	-> BG|FG|CHAR
	Onde BG e FG tem 4 bits e o char tem 8.*/
void fb_write_char(uint16_t pos, uint8_t c, uint8_t fg, uint8_t bg) {
	framebuffer[pos] = ((bg << 4 | fg) << 8) | c; 
}


