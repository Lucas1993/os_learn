#include "terminal.h"

size_t cursor_pos = 0;
/*Escreve uma mensagem no terminal, usando o fundo preto e a letra cinza.*/
void terminal_write(char* msg) {
	size_t len = strlen(msg);

	for (size_t i = 0; i < len; i++) {
		if (msg[i] == '\n') {
			cursor_pos -= cursor_pos % TERMINAL_LENGTH;
			cursor_pos += TERMINAL_LENGTH;
			terminal_move_cursor(cursor_pos);
		} else {
			fb_write_char(cursor_pos, msg[i], COLOR_LIGHT_GREY, COLOR_BLACK);
			cursor_pos++;
			if (cursor_pos > TERMINAL_SIZE) {
				cursor_pos = TERMINAL_SIZE - TERMINAL_LENGTH;
				terminal_scroll();
			}
			terminal_move_cursor(cursor_pos);
		}
	}

}

void terminal_clear() {
	for (size_t i = 0; i < TERMINAL_SIZE; i++) {
		fb_write_char(i, ' ', COLOR_LIGHT_GREY, COLOR_BLACK);
	}

}

/*Move o cursor através de comunicação com a porta respectiva*/
void terminal_move_cursor(uint16_t pos) {
	outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
	outb(FB_DATA_PORT, (pos >> 8) & 0xFF);
	outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
	outb(FB_DATA_PORT, pos & 0xFF);
}

void terminal_scroll() {
	for (size_t i = 1; i < TERMINAL_HEIGHT; i++) {
		memcpy(framebuffer + TERMINAL_LENGTH*(i-1), framebuffer + TERMINAL_LENGTH*i, TERMINAL_LENGTH*2);
	}
	for (size_t i = TERMINAL_LENGTH*(TERMINAL_HEIGHT - 1); i < TERMINAL_SIZE; i++) {
		fb_write_char(i, ' ', COLOR_LIGHT_GREY, COLOR_BLACK);
	}
	
}
