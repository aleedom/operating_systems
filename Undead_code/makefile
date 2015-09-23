cc=gcc
CCFLAGS = -g -O2

all: asm
	gcc -g -m32 -o undead_code undead_code.c
asm:
	gcc -g -m32 -S undead_code.c

clean:
	rm *.s undead_code
