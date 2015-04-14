#include "descriptor_tables.h"

#define GDT_ENTRIES_NUM 3

gdt_pointer_t gdtptr;
gdt_entry_t gdt_entries[GDT_ENTRIES_NUM];

void make_gdt_entry(size_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t flags) {
	gdt_entries[num].base_low = base & 0xFFFF; 
	gdt_entries[num].base_middle = (base >> 16) & 0xFF; 
	gdt_entries[num].base_high = (base >> 24) & 0xFF; 

	gdt_entries[num].limit_low = limit & 0xFFFF; 

	/*3 bits inferiores das flags são os 3 bits do meio do limit.*/
	/*gdt_entries[num].flags = ((limit >> 16) & 0x7) | (flags & 0xF8); */
	gdt_entries[num].flags = (limit >> 16) & 0x0F;
	gdt_entries[num].flags |= flags & 0xF0;

	gdt_entries[num].access_byte = access; 
	
}

void init_gdt() {

	gdtptr.size = (sizeof(gdt_entry_t) * GDT_ENTRIES_NUM) - 1;
	gdtptr.address = (uint32_t) &gdt_entries;

	make_gdt_entry(0, 0, 0, 0, 0);

	/*0xCF = LIMITE todo setado, granularidade setada, resto em zero.*/
	/*0x9A = Executável, não escreve. PL = 0.*/
	/*0x92 = Data: escreve, não executa. PL = 0.*/
	make_gdt_entry(1, 0, 0xffffffff, 0x9A, 0xCF);
	make_gdt_entry(2, 0, 0xffffffff, 0x92, 0xCF);

	gdt_set( (uint32_t) &gdtptr);
	
}
