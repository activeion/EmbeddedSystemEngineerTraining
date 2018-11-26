.global _start
_start:

    // 在内存中准备数据
    mov r0, #0x80000000
    mov r1, #0x90
    mov r2, #1
add:     add r1, r1, r2
    str r1, [r0], #4 // x/100x 0x80000000
    cmp r1, #0x100
    ldrne pc, =add

    /*Load & Store */
    // 3.41
    //ldr r0, #40 //没有这种形式，必须有两个reg，而且必须是一个reg，一个地址
    // 使用标号
    ldr r4, _start
    //str r5, data1

    // pre-indexed
    ldr r0, [r1]
    ldr r0, [r1, r2] // 先+
    ldr r0, [r1, #8]
    ldr r0, [r1, r2, lsl#2]
    // auto-indexed
    mov r1, #1
    str r0, [r1, r2]! // (gdb) x/5x 0 0地址内容发生的变化
    str r0, [r1, #8]!
    str r0, [r1, r2, lsl#2]!
    // post-indexed
    ldr r0, [r1], #8
    ldr r0, [r1], r2
    ldr r0, [r1], r2, lsl#2

    // 3.42
    ldr r1, [r2, r5]!
    //str r2, [r3], #0xfffff8
    //streq r4, [r0, r4, lsl r5]
    //streq r4, [r0, r4, lsl #32]
    streq r3, [r6], #-0x08
    //ldr r0, [r2]!, -r6
    ldr r4, _start
    ldr r4, [sp, #-0x04]
    str r2, _start
    //ldr pc, r6
    //ldr pc, [r6]
    //ldr r1, [r3, r15]

    // 3.43
    ldrb r0, [r1]
    ldrb r0, [r1, #8]
    strb r0, [r1]
    strb r0, [r1, #8]

    // 3.44
    ldrh r0, [r1]
    ldrh r0, [r1, #8]
    ldrh r0, [r1, r2]
    strh r0, [r1]

    // 3.45
    ldrsb r0, [r1, #4]
    ldrsh r0, [r2], #2

    // 3.46
    mov r0, #0x00900000
    add r0, r0, #0x10
    mov r1, #1
    str r1, [r0]
    mov r2, #1
    mov r3, #2
    mov r4, #3

    ldmia r0!, {r2-r4}
    ldmib r0!, {r2-r4}

    //3.47 
    ldr sp, =#0x70010
    ldr r4, =#0x00000003
    ldr r3, =#0x00000002
    ldr r2, =#0x00000001
    stmfd sp!, {r2-r4} //r2-r4入栈
    ldmfd sp!, {r6-r8}

    // 3.48
    swp r0, r1, [r2]
    swp r0, r0, [r1]

.end

