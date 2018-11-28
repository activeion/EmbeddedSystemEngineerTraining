# $@ 目标文件；$^ 所依赖的文件；$< 第一依赖文件

BINs=pic1.bin pic2.bin pic3.bin
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

pic1.o : pic1.s
pic1.elf : pic1.o
pic1.bin : pic1.elf

pic2.o : pic2.s
pic2.elf : pic2.o
pic2.bin : pic2.elf
	
pic3.o : pic3.s
pic3.elf : pic3.o
pic3.bin : pic3.elf

clean:
	rm -rf *.elf *.bin *.o
