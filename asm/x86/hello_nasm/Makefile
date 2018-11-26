helloworld: helloworld.o
	ld -m elf_i386 -o helloworld helloworld.o

helloworld.o: helloworld.asm
	nasm -f elf32 -g -F stabs helloworld.asm -l helloworld.lst
