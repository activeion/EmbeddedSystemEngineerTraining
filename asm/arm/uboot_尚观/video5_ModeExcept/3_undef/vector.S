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
    mov sp, #0x82000000 
    
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
    .asciz "undefined instruction.\n"

