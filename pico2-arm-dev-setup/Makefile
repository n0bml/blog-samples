CC=arm-none-eabi-gcc
CPPLAGS+=-Wall -Wextra -Wshadow -Wuseless-cast -Wpedantic -pedantic
CFLAGS+=-std=c17 -g -O2

multiply.o: multiply.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) multiply.o
