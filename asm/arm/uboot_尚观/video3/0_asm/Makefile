# $@ 目标文件；$^ 所依赖的文件；$< 第一依赖文件

BINs=asm.bin

OBJs=$(patsubst %.bin, %.o, $(BINs))
ELFs=$(patsubst %.bin, %.elf, $(BINs))

all: $(BINs) 

$(OBJs):
	arm-none-eabi-gcc -c $^ -g -o $@  # arm-none-eabi-as
$(ELFs):
	arm-none-eabi-ld -Ttext=0x80008000 $^ -o $@
$(BINs):
	arm-none-eabi-objcopy -O binary $^ $@
	cp $@ /srv/tftp/

asm.o : asm.S
asm.elf : asm.o
asm.bin : asm.elf

clean:
	rm -rf *.elf *.bin *.o
