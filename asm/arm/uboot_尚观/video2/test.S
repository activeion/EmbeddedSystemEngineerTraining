	.cpu arm7tdmi
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"test.c"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.global	serial_puts
	.data
	.align	2
	.type	serial_puts, %object
	.size	serial_puts, 4
serial_puts:
	.word	1619231492
	.global	sprintf
	.align	2
	.type	sprintf, %object
	.size	sprintf, 4
sprintf:
	.word	1619423188
	.global	glob_stop_here
	.bss
	.align	2
	.type	glob_stop_here, %object
	.size	glob_stop_here, 4
glob_stop_here:
	.space	4
	.section	.rodata
	.align	2
.LC0:
	.ascii	"hello, u-boot. glob_stop_here=%d.\012\000"
	.text
	.align	2
	.global	main
	.arch armv4t
	.syntax unified
	.arm
	.fpu softvfp
	.type	main, %function
main:
.LFB0:
	.file 1 "test.c"
	.loc 1 7 1
	.cfi_startproc
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 256
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 11, -8
	.cfi_offset 14, -4
	add	fp, sp, #4
	.cfi_def_cfa 11, 4
	sub	sp, sp, #256
	.loc 1 8 10
	nop
.L2:
	.loc 1 8 11 discriminator 1
	ldr	r3, .L4
	ldr	r3, [r3]
	.loc 1 8 10 discriminator 1
	cmp	r3, #0
	bne	.L2
	.loc 1 11 5
	ldr	r3, .L4+4
	ldr	r3, [r3]
	ldr	r2, .L4
	ldr	r2, [r2]
	sub	r0, fp, #260
	ldr	r1, .L4+8
	mov	lr, pc
	bx	r3
.LVL0:
	.loc 1 12 5
	ldr	r3, .L4+12
	ldr	r3, [r3]
	sub	r2, fp, #260
	mov	r0, r2
	mov	lr, pc
	bx	r3
.LVL1:
	.loc 1 14 12
	mov	r3, #0
	.loc 1 15 1
	mov	r0, r3
	sub	sp, fp, #4
	.cfi_def_cfa 13, 8
	@ sp needed
	pop	{fp, lr}
	.cfi_restore 14
	.cfi_restore 11
	.cfi_def_cfa_offset 0
	bx	lr
.L5:
	.align	2
.L4:
	.word	glob_stop_here
	.word	sprintf
	.word	.LC0
	.word	serial_puts
	.cfi_endproc
.LFE0:
	.size	main, .-main
.Letext0:
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0xe9
	.2byte	0x4
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.4byte	.LASF5
	.byte	0xc
	.4byte	.LASF6
	.4byte	.LASF7
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	.Ldebug_line0
	.uleb128 0x2
	.4byte	0x34
	.4byte	0x34
	.uleb128 0x3
	.4byte	0x3b
	.byte	0
	.uleb128 0x4
	.byte	0x4
	.byte	0x5
	.ascii	"int\000"
	.uleb128 0x5
	.byte	0x4
	.4byte	0x48
	.uleb128 0x6
	.byte	0x1
	.byte	0x8
	.4byte	.LASF0
	.uleb128 0x7
	.4byte	0x41
	.uleb128 0x8
	.4byte	.LASF1
	.byte	0x1
	.byte	0x1
	.byte	0x7
	.4byte	0x5f
	.uleb128 0x5
	.byte	0x3
	.4byte	serial_puts
	.uleb128 0x5
	.byte	0x4
	.4byte	0x25
	.uleb128 0x2
	.4byte	0x34
	.4byte	0x7a
	.uleb128 0x3
	.4byte	0x7a
	.uleb128 0x3
	.4byte	0x3b
	.uleb128 0x9
	.byte	0
	.uleb128 0x5
	.byte	0x4
	.4byte	0x41
	.uleb128 0x8
	.4byte	.LASF2
	.byte	0x1
	.byte	0x2
	.byte	0x7
	.4byte	0x92
	.uleb128 0x5
	.byte	0x3
	.4byte	sprintf
	.uleb128 0x5
	.byte	0x4
	.4byte	0x65
	.uleb128 0x8
	.4byte	.LASF3
	.byte	0x1
	.byte	0x4
	.byte	0x5
	.4byte	0x34
	.uleb128 0x5
	.byte	0x3
	.4byte	glob_stop_here
	.uleb128 0xa
	.4byte	.LASF8
	.byte	0x1
	.byte	0x6
	.byte	0x5
	.4byte	0x34
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.4byte	0xd5
	.uleb128 0xb
	.ascii	"buf\000"
	.byte	0x1
	.byte	0xa
	.byte	0xa
	.4byte	0xd5
	.uleb128 0x3
	.byte	0x91
	.sleb128 -264
	.byte	0
	.uleb128 0xc
	.4byte	0x41
	.4byte	0xe5
	.uleb128 0xd
	.4byte	0xe5
	.byte	0xff
	.byte	0
	.uleb128 0x6
	.byte	0x4
	.byte	0x7
	.4byte	.LASF4
	.byte	0
	.section	.debug_abbrev,"",%progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x15
	.byte	0x1
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",%progbits
	.4byte	0x1c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x4
	.byte	0
	.2byte	0
	.2byte	0
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	0
	.4byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF4:
	.ascii	"unsigned int\000"
.LASF1:
	.ascii	"serial_puts\000"
.LASF5:
	.ascii	"GNU C17 8.2.0 -mcpu=arm7tdmi -mfloat-abi=soft -marm"
	.ascii	" -march=armv4t -g\000"
.LASF8:
	.ascii	"main\000"
.LASF2:
	.ascii	"sprintf\000"
.LASF7:
	.ascii	"/home/jizh/git/u-boot/uboot_code/video2\000"
.LASF6:
	.ascii	"test.c\000"
.LASF0:
	.ascii	"char\000"
.LASF3:
	.ascii	"glob_stop_here\000"
	.ident	"GCC: (Arch Repository) 8.2.0"
