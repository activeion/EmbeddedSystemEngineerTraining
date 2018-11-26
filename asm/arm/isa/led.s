    .globl _start  
.arm  
_start:  
    LDR R0,=0x11000C20  
    LDR R1,[R0]  
    BIC R1,R1,#0x0000000f  
    ORR R1,R1,#0x00000001  
    STR R1,[R0]  

loop:  
    LDR R0,=0x11000C24  
    LDR R1,[R0]  
    ORR R1,R1,#0x01  
    STR R1,[R0]  
    BL delay  
    LDR R1,[R0]  
    BIC R1,R1,#0x01  
    STR R1,[R0]  
    BL delay  
    B loop  

delay:  
    LDR R2,=0xfffffff  
loop1:  
    SUB R2,R2,#0x1  
    CMP R2,#0x0  
    BNE loop1  
    MOV PC,LR  
    .end
