# $@ 目标文件；$^ 所依赖的文件；$< 第一依赖文件

SRCS=test.c
ASM=$(SRCS:.c=.S)
OBJS=$(SRCS:.c=.o)
ELF=$(SRCS:.c=.elf)
BIN=$(SRCS:.c=.bin)

all: $(BIN) 

$(ASM):$(SRCS)
	arm-none-eabi-gcc -S $< -g -o $@  
$(OBJS):$(ASM)
	arm-none-eabi-gcc -c $< -g -o $@  # arm-none-eabi-as
$(ELF):$(OBJS)
	arm-none-eabi-ld -Ttext=0x80008000 $< -o $@
$(BIN):$(ELF)
	arm-none-eabi-objcopy -O binary $< $@
	cp $@ /srv/tftp/
clean:
	rm -rf *.elf *.bin *.o *.S
