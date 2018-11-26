.global _start
_start:
    /*Branch */
    // 3.50
backward:
    sub r1, r1, #1
    cmp r1, #0
    beq forward
    sub r1, r2, #3
    sub r1, r1, #1
forward:
    add r1, r2, #4
    add r2, r3, #2
    b backward


.end

