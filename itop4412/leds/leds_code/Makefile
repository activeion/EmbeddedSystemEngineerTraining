CROSS_COMPILE = arm-none-eabi-

%.o : %.S
	$(CROSS_COMPILE)gcc -o $@ $< -c 
%.o : %.c
	$(CROSS_COMPILE)gcc -o $@ $< -c 

.PHONY: all
all : 	led.elf

led.elf : start.o myboot.lds
	$(CROSS_COMPILE)ld -T myboot.lds -o led.elf $^
	$(CROSS_COMPILE)objcopy -O binary led.elf led.bin
	$(CROSS_COMPILE)objdump -D led.elf > led.dis 

.PHONY : clean
clean:
	rm -rf *.o *.elf *.bin *.dis


