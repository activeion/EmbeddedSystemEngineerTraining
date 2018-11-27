.section .text
.global abc

abc:
    mov ip, sp
    stmfd sp!, {fp, ip, lr, pc}
    sub fp, ip, #4

    ldr r0, =str

    sub sp, fp, #12
    ldmfd sp, {fp, sp, pc}

.section .data

str:
    .word 0x77777777


