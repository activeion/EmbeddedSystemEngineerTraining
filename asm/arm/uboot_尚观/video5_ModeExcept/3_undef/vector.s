// qemu_uboot.sh
// tftp 90000000 vector.bin
// tftp 80008000 undef.bin
// go 80008000

// cgdb_arm.sh undef.elf

.section .text
    b reset
    b und
    b swi
    b abt_pre
    b abt_dat
    .word 0
    b irq
    b fiq

reset:
und:
    mov sp, #0x82000000 //serial_puts函数需要堆栈
    
    adr r0, str @PIC
    ldr r3, serial_puts

    mov lr, pc
    mov pc, r3
    
loop: 
    b loop
swi:
abt_pre:
abt_dat:
irq:
fiq:

serial_puts:
    .word 0x60838304
str:
    .asciz "customed abnormal:undefined instruction.\n"

