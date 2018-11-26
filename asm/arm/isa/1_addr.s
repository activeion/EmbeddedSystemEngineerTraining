.global _start
_start:
    //比较
    mov r0, #4000 //4000, OK; 4100, error! 不能大于4096
    mov r1, #0
    cmp r0, #0      // 比较r0是否为0
    cmpne r1, #1    // 不是，则比较r1是否为1，是，则忽略本指令。故本指令正常执行
    addeq r2, r0, r1    // 不是，而且r1==1，则r2=r0+r1，如果r1！=1，则忽略本本指令。故本指令被忽略

    // 在内存中准备数据
    mov r0, #0x80000000
    mov r1, #0x90
    mov r2, #1
add:     add r1, r1, r2
    str r1, [r0], #4 // x/100x 0x80000000
    cmp r1, #0x100
    ldrne pc, =add
    

    // 3.1 p68 指令格式
    ldr r0, [r1]
    beq enddata
    mov r3, #3
enddata:   
    adds r2, r1, #1
    
    //3.2 p69 S的作用
    sub r1, r0, r3 //p/t $cpsr
    subs r1, r0, r3 //p/t $cpsr
    
    //3.3 p69 !的作用
    mov r0, #0x80000000
    mov r1, #0xfe
    ldr r3, [r0, #4]!

    /* 3.3 寻址方式 */
    //3.5 立即数寻址
    mov r0, #15

    //3.6 寄存器寻址
    mov r1, #0x87
    mov r2, #3
    add r0, r1, r2

    //3.7 寄存器间接寻址
    mov r4, #0
    ldr r0, [r4] // r0 <- [r4]

    //3.8 寄存器移位寻址
    mov r1, #0
    mov r2, #1
    add r0, r1, r2, lsl #1

    mov r1, #2
    mov r0, r1, lsl r2
    
    //3.9 基址变址寻址
    mov r1, #0x80000000
    mov r2, #0x8
    ldr r0, [r1, #4]
    ldr r0, [r1, #4]!
    ldr r0, [r1], #4 // r1会自增4
    ldr r0, [r1, r2]! // r1会自增r2

    //3.10 load multiple & increase address
    mov r0, #0x80000004
    ldmia r0!, {r1-r4}

    //3.11 堆栈寻址
    mov sp, #0x90000000
    stmfd sp!, {r1-r4} //入栈 x/-50x 0x90000000
    ldmfd sp!, {r1-r4} //出栈

loop:
    mov r0, r0
    b loop

.end

    //ldr r0, #40 //没有这种形式，必须有两个reg，而且必须是一个reg，一个地址
    ldr r0, r1, #4100 
