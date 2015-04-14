#include "pic.h"

void pic_remap(uint8_t offset1, uint8_t offset2) {

	outb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);
	outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);

	outb(PIC1_DATA, offset1);
	outb(PIC2_DATA, offset2);

	outb(PIC1_DATA, 0x04);
	outb(PIC2_DATA, 0x02);

	outb(PIC1_DATA, ICW4_8086);
	outb(PIC2_DATA, ICW4_8086);

	outb(PIC1_DATA, 0xFD);
	outb(PIC2_DATA, 0xFF);
	

}

void pic_send_EOI(uint8_t irq_num) {
	if (irq_num > 7) {
		outb(PIC2_COMMAND, PIC_EOI);
	}
	outb(PIC1_COMMAND, PIC_EOI);
}

uint16_t pic_get_reg(uint8_t ocw3) {
	outb(PIC1_COMMAND, ocw3);
	outb(PIC2_COMMAND, ocw3);

	return (  (inb(PIC2_COMMAND) << 8) | (inb(PIC1_COMMAND))  );

}

uint16_t pic_get_irr() {
	return pic_get_reg(PIC_READ_IRR);
}

uint16_t pic_get_isr() {
	return pic_get_reg(PIC_READ_ISR);
}
