# $@ 目标文件；$^ 所依赖的文件；$< 第一依赖文件

BINs=mmu.bin
SRCs=$(patsubst %.bin, %.c, $(BINs))
ASMs=$(patsubst %.bin, %.S, $(BINs))
OBJs=$(patsubst %.bin, %.o, $(BINs))
ELFs=$(patsubst %.bin, %.elf, $(BINs))

all: $(BINs) 

$(ASMs):
	arm-none-eabi-gcc -S $^ -g -o $@  # arm-none-eabi-as
$(OBJs):
	arm-none-eabi-gcc -c $^ -g -o $@  # arm-none-eabi-as
$(ELFs):
	arm-none-eabi-ld -Ttext=0x80008000 $^ -o $@
$(BINs):
	arm-none-eabi-objcopy -O binary $^ $@
	cp $@ /srv/tftp/

mmu.S : mmu.c
mmu.o : mmu.S
mmu.elf : mmu.o
mmu.bin : mmu.elf


clean:
	rm -rf *.elf *.bin *.o *.S
