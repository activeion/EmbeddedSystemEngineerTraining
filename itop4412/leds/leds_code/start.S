#include "s3c4412_gpio.h"
.global _start

.word 0x2000
.word 0x0
.word 0x0
.word 0x0


_start:
	ldr	r10,=0x1002330c
	ldr	r11,[r10]
	orr	r11,r11,#0x300
	str	r11,[r10]

	ldr	r10,=0x11000c08
	ldr	r11,=0x0
	str	r11,[r10]
	//dsb
		
	ldr	r10,=GPL2CON
	mov	r11,#(0x01<<0)
	str	r11,[r10]

	ldr	r10,=GPK1CON
	mov	r11,#(0x01<<4)
	str	r11,[r10]

1:
	ldr	r10,=GPK1DAT
	mov	r11,#0x02
	str	r11,[r10]

	ldr	r10,=GPL2DAT
	mov	r11,#0x01
	str	r11,[r10]

	b	1b

