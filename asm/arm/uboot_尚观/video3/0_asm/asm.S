// 死循环！为了方便gdb调试                                               
repeat: mov r0, #1                                                      
ldr r1, g_stop_here                                                     
cmp r0, r1                                                              
beq repeat                                                              

////////////基本指令//////////                                          

    ldr r0, =0x3342343                                                  
    ldr r1, =0x8888                                                     
    ldr r0, [r1]                                                        
    mov r0, #55                                                         
    str r0, [r1]                                                        

    ldr r2, str @ 取label数据                                           
    ldr r3, str1                                                        

    ldr r2, =str @取label得地址                                         
    add r0, r1, r0                                                      

    stmfd sp!, {r0-r1}                                                  
    ldmfd sp!, {r2-r3}                                                  

//////////////////函数调用////////                                      
    // 函数参数                                                         
    ldr r0, =(serial_puts+4) @ =hello                                   

    ldr r5, =0x82000000 @临时保存                                       
    str lr, [r5]                                                        

    mov lr, pc @ 由于pc=pc+8,紧贴函数调用                               
    ldr pc, serial_puts @函数调用                                      

    ldr lr, [r5]                                                        

////////////使用stack的函数调用规范//////                               
abc:                                                                    
    stmfd sp!, {fp, lr}  @ 先保存旧值，从右到左入栈
    add fp, sp, #0  @ mov fp, sp                                         
    @stmfd sp!, {lr, pc, fp, ip} @ 1. 浪费并不影响 2. 次序也没有关系    
    sub sp, sp, #0x100

    bl test                                                             

    sub sp, fp, #0 @ mov sp, fp  
    ldmfd sp!, {fp, lr} @从左到右出栈
    bx lr

////////////使用stack的函数调用规范//////                               
test:
    stmfd sp!, {fp, lr}         @ 先保存fp                               
    add fp, sp, #0 @ mov fp, sp ，再修改fp
    @stmfd sp!, {fp, ip, lr, pc} @ 再次保存, 依然不影响
    sub sp, sp, #0x200

    ldr r0, =hello  @ r0已经被破坏为0x0，重新赋值

    @bl serial_puts
    mov lr, pc
    ldr pc, serial_puts

    sub sp, fp, #0 @ mov sp, fp 
    ldmfd sp!, {fp, lr}                                              
    bx lr

//////////////////数据//////

g_stop_here:
    .word 0x1 @本程序不需要调试的话，修改为0
str: 
    .word 0x77777777
str1:
    .word 0x88888888

serial_puts:
    .word 0x60838304
hello:
    .asciz "hello, u-boot.\n"
