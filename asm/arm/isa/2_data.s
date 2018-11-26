.global _start
_start:
    /* 3.4 数据处理指令 */

    // 3.12 
    mov r1, r0
    //mov pc, r14 //r14==0，本指令将跳转到start_执行
    mov r1, r0, lsl #3
    mov r0, #5

    //3.13
    mvn r0, #0 //0取反后为ffffffff, r0=-1
    mvn r1, r2

    // 3.14  桶形移位器
    mov r0, #0
    mov r1, #0x80000004
    mov r0, r1, lsl #1 // r1不变，r0发生了变化

    // 3.15 
    mrs r0, cpsr
    bic r0, r0, #0x0F
    msr cpsr, r0
    mov r0, #0
    mov r1, #0x80000004
    movs r0, r1, lsl #1 //观察cpsr的变化

    // 3.16 
    mrs r0, cpsr
    bic r0, r0, #0x0F
    msr cpsr, r0
    mov r0, #-1
    mov r1, #0x1
    movs r0, r1, lsl #1 //观察cpsr的变化

loop: mov r0, r0
    ldr pc, loop
    

.end

