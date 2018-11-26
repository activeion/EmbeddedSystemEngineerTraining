
////////////基本指令//////////                                          
.section .text

.global main

    // 死循环！为了方便gdb调试                                               
    repeat: mov r0, #1                                                      
    ldr r1, g_stop_here                                                     
    cmp r0, r1                                                              
    beq repeat                                                              

main:
    mov ip, sp
    stmfd sp!, {fp, ip, lr, pc}
    sub fp, ip, #4
    
    .word 0x77777777
    
    sub sp, fp, #12
    ldmfd sp, {fp, sp, pc}

g_stop_here:
    .word 1
