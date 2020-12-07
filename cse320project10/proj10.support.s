@Project10
@by Abhiram Durgaraju
@This program reads a file in a certain format. After taking a
@struct table in an initial argument, finds a player based on
@jersey number and lists other attributes about the player using
@an instructor-provided driver



		.global search
		.global view
		
		
		.text


		

search:
		push	{r4, r5, r6, r7, r8, r9, lr}
		
		ldr		r4, [r0, #4]	@base adress of the array of players
		ldrh	r5, [r0, #2]	@number of players
		
		mov		r6, #0			@initializing index to zero
	
loop:	cmp		r6, r5			@compare count to total number of players
		bge 	end1
		
		mov		r7, #44			@size of struct player
		mul		r7, r6, r7		@size times index is offset
		add		r8, r4, r7		@base + offset
		
		ldrh	r9, [r8]		@jersey number of current player
		
		cmp		r1, r9			@if jersey number matches
		beq		found
		
		cmp		r1, r9
		blt		end1			@NEW LINE ADDED
		
		add		r6, r6, #1		@increment index
		b		loop

		
		
end1:	
		str		r8, [r2]	@NEW LINED ADDED
		mov		r0, #1		@player not found
			
		pop		{r4, r5, r6, r7, r8, r9, lr}
		bx		lr

found:

		str		r8, [r2]
		mov		r0, #1		@player found
		

		pop		{r4, r5, r6, r7, r8, r9, lr}
		bx		lr

view:
		push	{r4, r5, r6, lr}
		
		
		mov		r4, r0		@save the initial arguments r0 and r1 to be used later
		mov		r5, r1
		
		ldr		r2, =third	@store the pointer to pointer on a variable named third
		bl		search
		
		cmp		r0,#0		@if search failed
		beq		end2
		
		ldr		r0, =fmt1
		ldr		r6, [r2]		@player at address of r2 is stored at r6
		ldrh	r1, [r6]		@first element, jersey number
		add		r2, r6, #2		@at offset 2 the string begins
		ldrh	r3, [r6, #28]	@at offset 28, number of games played
		bl		printf
		
		mov		r0, r4			@printf only takes 3 arguments, need to re-search
		mov		r1, r5			
		ldr		r2, =third
		bl		search


		ldr		r0, =fmt2
		ldr		r6, [r2]
		ldrh	r1, [r6, #30]	@number of 2 point baskets at offset 30
		ldrh	r2, [r6, #32]	@number of 3 point baskets at offset 32
		ldrh	r3, [r6, #34]	@number of free throws at offset 34
		bl		printf
		
		mov		r0, r4			@again need to re-search for last argument
		mov		r1, r5
		ldr		r2, =third
		bl		search
		
		ldr		r0, =fmt3
		ldr		r6, [r2]
		ldrh	r1, [r6, #36]	@total points at offset 36
		bl		printf
		
		mov		r0, #1			@sucessfully viewed a player, return 1
		
		pop		{r4, r5, r6, lr}
		bx		lr


end2:
		mov		r0, #0			@search failed, return 0 from function view
		
		pop		{r4, r5, r6, lr}
		bx		lr



fmt1:	.asciz	"\nJersey Number = %d\nName = %-20s\nNumber of games played = %d"
fmt2:	.asciz	"\nNumber of 2-point baskets = %d\nNumber of 3-point baskets = %d\nNumber of free throws = %d\n"
fmt3:	.asciz	"Total points scored = %d\n"


		.data
third:	.word	0

