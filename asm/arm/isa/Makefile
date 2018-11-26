all: led.elf immed_8.elf 1_addr.elf 2_data.elf 3_ldst.elf 4_branch.elf 

led.elf: led.o
	arm-none-eabi-ld -Ttext 0x800000 -o $@ $^
immed_8.elf: immed_8.o
	arm-none-eabi-ld -Ttext 0x0 -o $@ $^
1_addr.elf: 1_addr.o
	arm-none-eabi-ld -Ttext 0x0 -o $@ $^
2_data.elf: 2_data.o
	arm-none-eabi-ld -Ttext 0x0 -o $@ $^
3_ldst.elf: 3_ldst.o
	arm-none-eabi-ld -o $@ $^
4_branch.elf: 4_branch.o
	arm-none-eabi-ld -Ttext 0x0 -o $@ $^

%.o: %.s
	arm-none-eabi-gcc -o $@ $< -g -c -O0
clean:
	rm *.o *.elf -f


# $@ target
# $* stem of the target filename
# $< first pre-requisite
# $? pre-requisites newer than target
# $^ all pre-requisites
# $+ similar to $^, including duplicates
# $% file name of an archive member
