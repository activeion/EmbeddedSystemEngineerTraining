// 调试方法:
// qemu_uboot.sh
// tftp 90000000 vector.bin
// tftp 80008000 undef.bin
// go 80008000

// cgdb_arm.sh undef.elf

.section .text

.global main

    // 死循环！为了方便gdb调试                                               
    repeat: mov r0, #1                                                      
    ldr r1, g_stop_here                                                     
    cmp r0, r1                                                              
    beq repeat                                                              

    @ 设置异常向量表重新定位在0x90000000地址处存放
    ldr r0,=0x90000000
    mcr p15,0,r0,c12,c0,0 @ VBAR = Vector Base Address Register 

main:
    mov ip, sp
    stmfd sp!, {fp, ip, lr, pc}
    sub fp, ip, #4
    
    .word 0x77777777
    
    sub sp, fp, #12
    ldmfd sp, {fp, sp, pc}

g_stop_here:
    .word 0 // 1: 死循环; 0: 不循环
