# $@ 目标文件；$^ 所依赖的文件；$< 第一依赖文件

BINs=undef.bin vector.bin
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

undef.o : undef.S
undef.elf : undef.o
undef.bin : undef.elf

vector.o : vector.S
vector.elf : vector.o
vector.bin : vector.elf

clean:
	rm -rf *.elf *.bin *.o
