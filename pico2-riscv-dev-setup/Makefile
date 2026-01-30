TOOLCHAINS=$(HOME)/pico/toolchains

RISCVCC=$(TOOLCHAINS)/gcc14-rp2350-no-zcmp/bin/riscv32-unknown-elf-gcc
HAZARD3CC=$(TOOLCHAINS)/gcc14-hazard3-rp2350/bin/riscv32-unknown-elf-gcc

CPPLAGS+=-Wall -Wextra -Wshadow -Wuseless-cast -Wpedantic -pedantic
CFLAGS+=-std=c17 -g -O2

all: riscv-multiply.o hazard3-multiply.o

riscv-multiply.o: multiply.c
	$(RISCVCC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

hazard3-multiply.o: multiply.c
	$(HAZARD3CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) riscv-multiply.o hazard3-multiply.o
