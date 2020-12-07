		.global	add
		.global	sub
		.global	mul
		.global	negate
		.global	absolute
		.global	divide
		.global	remain
		.global	power
		.global factorial
		
		.text
		
add:
		push	{lr}
		
		adds	r0, r0, r1
		bvs		inv1			@branch if overflow
	
		pop		{lr}
		bx		lr

inv1:	
		mov		r0, #0x80000000		@put error code into return register
		pop		{lr}
		bx		lr





		
sub:
		push	{lr}
		
		subs	r0, r0, r1
		bvs		inv1

		pop		{lr}
		bx		lr






		
mul:
		push	{r4, r5, r6, lr}
		

		smull	r4, r5, r0, r1
		
		and		r6, r4, #0x80000000		@if sign bit is 1 after masking
		cmp		r6, #0x00000000
		beq		check1
		
		cmp		r6, #0x80000000		@if sign bit is 0 after masking
		beq		check2
				

check1:
		cmp		r5, #0x00000000		@are all bits in rdhi 0? if not error
		bne		inv2
		
		mov		r0, r4
		
		pop		{r4, r5, r6, lr}
		bx		lr

check2:
		cmp		r5, #0xffffffff		@are all bits in rdhi 1? if not error
		bne		inv2
		
		mov		r0, r4
		
		pop		{r4, r5, r6, lr}
		bx		lr

inv2:	
		mov		r0, #0x80000000
		
		pop		{r4, r5, r6,lr}
		bx		lr








negate:	
		push	{lr}
		rsb 	r0, r0, #0
		pop		{lr}
		bx		lr

		
absolute:
		push	{lr}
		
		cmp		r0, #0
		blt		negate		@nested function call if conditions are met

		pop		{lr}
		bx		lr





divide:						
		push	{lr}

		cmp		r1, #0		@check for divide by zero
		beq		inv1
		
		sdiv	r0, r0, r1
		
		pop		{lr}
		bx		lr
		


		
remain:
		push	{r4, r5, lr}
		
		
		sdiv	r4, r0, r1
		mul		r5, r4, r1		@multiply by quotient
		sub		r0, r0, r5		@subtract from original value
		
		pop		{r4, r5, lr}
		bx		lr








		
power:
		push	{r4, r5, r6, r7, r8, lr}
		
		mov		r4, r0
		mov		r5, r1
		mov		r6, #1		@count
		
		cmp		r5, #0		@if exponent is 0
		beq		spec1	
		
		cmp		r5, #0		@if exponent is negative
		blt		spec2
		
inc:
		cmp		r6, r5
		bge		exitinc
		
		add		r6, r6, #1
		smull	r4, r7, r4, r0
		and		r8, r4, #0x80000000		@same logic as function mul
		cmp		r8, #0x00000000
		beq		check3
		cmp		r8, #0x80000000
		beq		check4
		
check3:
		cmp		r7, #0x0000000
		bne		spec2
		
		b		inc

check4:
		cmp		r7, #0xffffffff
		bne		spec2
		
		b		inc

exitinc:		
		
		mov		r0, r4
		
		pop		{r4, r5, r6, r7, r8, lr}
		bx		lr

spec1:
		mov		r0, #1
		
		pop		{r4, r5, r6, r7, r8, lr}
		bx		lr
		
spec2:
		mov		r0, #0x80000000
		
		pop		{r4, r5, r6, r7, r8, lr}
		bx		lr



		
factorial:

		push	{r4, r5, r6, lr}
		
		mov 	r6, r0
		mov 	r5, r0

		cmp 	r5, #0
		beq		spec3
		blt		spec4
		
facloop:
		
		cmp 	r5, #1
		ble		exitfac
		
		sub 	r5, r5, #1		@keep decreasing the number until its one
		mov		r0, r6
		mov		r1, r5			@move the arguments into register 0 and 1 to call nested function mul
		bl		mul
		mov		r6, r0			@move the result back into register 6 to continue loop logic
		b 		facloop
				
exitfac:	
		mov		r0, r6
		pop		{r4, r5, r6, lr}
		bx		lr

spec3:
		mov 	r0, #1				@zero factorial is 1
		pop		{r4, r5, r6, lr}
		bx		lr

spec4:
		mov		r0, #0x80000000		@negative factorial makes no sense
		pop		{r4, r5, r6, lr}
		bx		lr




