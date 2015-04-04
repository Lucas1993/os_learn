OBJECTS= loader.o kmain.o vga_driver.o string.o io.o terminal.o serial.o
CC=i686-elf-gcc
CFLAGS=-std=gnu99 -I$(INCLUDEDIR) -nostdlib -nostartfiles -ffreestanding -O2 -Wall -Wextra
LDFLAGS= -T link.ld -melf_i386
AS=nasm
ASFLAGS=-felf32
INCLUDEDIR=kernel/include

VPATH=kernel

all: kernel.elf

kernel.elf: $(OBJECTS)
	i686-elf-ld $(LDFLAGS) $(OBJECTS) -o kernel.elf

os.iso: kernel.elf
	cp kernel.elf iso/boot/kernel.elf
			genisoimage -R                              \
						-b boot/grub/stage2_eltorito    \
						-no-emul-boot                   \
						-boot-load-size 4               \
						-A os                           \
						-input-charset utf8             \
						-quiet                          \
						-boot-info-table                \
						-o os.iso                       \
						iso

run: os.iso
		bochs -rc .bochs/bochsdebug.txt -f .bochs/bochsrc.txt -q

go: kernel.elf run

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


%.o: %.asm
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf *.o kernel.elf os.iso com1.out bochslog.txt
