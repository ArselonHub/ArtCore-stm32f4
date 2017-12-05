	.cpu cortex-m0
	.fpu softvfp

//-------------------------------------------
// PendSV_Handler
//-------------------------------------------
	.align	2
	.code	16
	.thumb_func
	.global PendSV_Handler

PendSV_Handler:
	push	{lr}

	// call perform
	blx		_ZN3Art3Svc10executeSvcEv

	// test if context switch enabled
testSwitchNeeded:
	ldr		r3,=_ZN3Art7contextE
	ldr		r1, [r3, #4]
	ldr		r2, [r3, #8]
	cmp		r1, r2
	bne		testIdle
	pop		{pc}

// test if idle
testIdle:
	mov		r2, r3
	add		r2, #0x10
	str		r1, [r3, #8]
	cmp		r1, r2
	beq		enterSleep

exitSleep:
	// clear scr
	movs	r0, #0
	ldr		r2, =0xE000ED10
	str		r0, [r2]

	// test if context switch needed
	ldr		r0, [r3, #0]	// current
	cmp		r0, r1
	bne		switchContext
	pop		{pc}

switchContext:
	pop		{r2}
	mov		lr, r2

	// push registers
	push	{r4-r7}
	mov		r4, r8
	mov		r5, r9
	mov		r6, r10
	mov		r7, r11
	push	{r4-r7}

	// store sp
	mrs		r2, msp
	str		r2, [r0, #8]	// previous.stack = sp

	// load sp
	ldr		r2, [r1, #8]
	msr		msp, r2

	// pop registers
	pop		{r4-r7}
	mov		r8, r4
	mov		r9, r5
	mov		r10, r6
	mov		r11, r7
	pop		{r4-r7}
	str		r1, [r3, #0]	// current = target
	bx		lr

enterSleep:
	// set bit 2 of scr	to enter sleep
	ldrb	r1, [r3, #12]
	ldr		r2,=0xE000ED10
	str		r1, [r2]
	pop		{pc}

//-------------------------------------------
// SVC_Handler
//-------------------------------------------
	.align	2
	.code	16
	.thumb_func
	.text
	.global SVC_Handler

SVC_Handler:
	// load arguments and call svc function
	mrs		r0, msp
	ldr		r1, [r0, #16]
	mov		r12, r1
	ldm		r0, {r0-r3}
	push	{lr}
	blx     r12

	// store result
	mrs		r2, msp
	str		r0, [r2, #4]

	// test if switch needed
	ldr		r3,=_ZN3Art7contextE
	ldr		r1, [r3, #4]
	ldr		r2, [r3, #8]
	cmp		r1, r2
	bne		testIdle
	pop		{pc}

//-------------------------------------------
// SysTick_Handler
//-------------------------------------------
	.align	2
	.code	16
	.thumb_func
	.text
	.global SysTick_Handler

SysTick_Handler:
	push	{lr}
	bl		_ZN3Art3Sit11processTickEv

	// test if switch needed
	ldr		r3,=_ZN3Art7contextE
	ldr		r1, [r3, #4]
	ldr		r2, [r3, #8]
	cmp		r1, r2
	bne		testIdle
	pop		{pc}

//-------------------------------------------
// Art::enableModes
//-------------------------------------------
	.align	2
	.code	16
	.thumb_func
	.text
	.global	_ZN3Art14enterThreadingEv
	.global SystemInit
	.func

_ZN3Art14enterThreadingEv:
SystemInit:
	bx		lr

	.end
