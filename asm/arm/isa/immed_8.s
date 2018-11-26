.equ STACK_BASE, 0x0c002000
.equ STACK_SIZE, 0x00001000
.text
entry:
    ldr sp, = STACK_BASE
    ldr sl, = STACK_BASE - STACK_SIZE
    ldr pc, = entry
