@Project11
@by Abhiram Durgaraju
@This program reads a file in a certain format. After taking a
@struct table in an initial argument, finds a player based on
@jersey number and can insert other players in jersey order in the table
@as well as delete and reorganize table to be sorted





		.global search
		.global	delete
		.global insert
		
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
		blt		end1			@stop searching if the jersey number is lower that the current jersey
		
		add		r6, r6, #1		@increment index
		b		loop
		
end1:	
		str		r8, [r2]	@NEW LINED ADDED
		mov		r0, #0		@player not found, returning 1 just for debugging
			
		pop		{r4, r5, r6, r7, r8, r9, lr}
		bx		lr

found:

		str		r8, [r2]
		mov		r0, #1		@player found
		

		pop		{r4, r5, r6, r7, r8, r9, lr}
		bx		lr


delete:
		push	{r4, r5, r6, r7, r8, r9, lr}
		
		mov		r4, r0		@the address to player table
		mov		r5, r1		@the jersey number of player to delete	
		
		ldr		r2, =third	@store the pointer to pointer on a variable named third
		bl		search
		
		cmp		r0,#0		@if search failed
		beq		end2
		
		
		ldr		r0, [r2]
		
		ldr		r6, [r4, #4]	@base adress of the array of players
		ldrh	r7, [r4, #2]	@number of players
		mov		r8, #44
		mul		r8, r8, r7		@number of players times 44
		add		r6, r6, r8		@add above value to base address
		
		
		sub		r9, r6, #44		@this is address of last player


		cmp		r0, r9			@if we are deleting last player, simply decrease count by 1 (at end3)
		beq		end3

		
		
loop2:		
		add		r1, r0, #44		@copy the the contents at address r1 and place it at r0
		mov		r2, #44
		bl		memmove
		
		add		r0, r0, #44		@go to the next element
		cmp		r1, r6
		bne		loop2

end3:
		sub		r7, r7, #1		@deletion means reduce player count by 1
		strh	r7, [r4, #2]	
		
		mov		r0, #1		@delete successful
		
		pop		{r4, r5, r6, r7, r8, r9, lr}
		bx		lr
		
end2:
		mov		r0, #0			@search failed, and so delete failed
		
		pop		{r4, r5, r6, r7, r8, r9, lr}
		bx		lr

		

insert:
		push	{r4, r5, r6, r7, r8, r9, r10, r11, lr}
		
		mov		r4, r0		@the address of the player table
		mov		r5, r1		@jersey number to insert
		mov		r6, r2		@we are using r2 for search, so we need to save its contents elsewhere, i.e r6
		mov		r11, r3		@4th argument
		
		ldr		r2, =third		@r0 is table, r1 is jersey, r2 is empty slot to store pointer
		bl		search
		
		ldr		r10, [r2]		@store this pointer elsewhere since r2 is going to be used for memmove
		
		cmp		r0,#1
		beq		end4			@player is already in list, can't insert
		
		ldrh		r7, [r4]		@capacity
		ldrh		r8, [r4, #2]
		
		cmp		r7, r8
		beq		end4		@capacity and count are equal, can't insert anymore
		
		ldr		r7, [r4, #4]	@base address of array of players
	
		
		ldrh	r8, [r4, #2]	@number of players
		sub		r8, r8, #1
		mov		r9, #44
		mul		r9, r9, r8		@number of players times 44
		add		r7, r7, r9		@add above value to base address, this is address of last player
		
		cmp		r7, r10
		beq		end5
			
loop3:
		add		r0, r7, #44		@go to the next player (destination address)
		mov		r1, r7			@source address
		mov		r2, #44			@we need to copy 44 bytes
		bl		memmove
		
		sub		r7, r7, #44		@go back one player (destination)
		
		cmp		r1, r10
		bne		loop3
		
cont:
		add		r8, r8, #2
		strh	r8, [r4, #2]	@need to increase count by 1 and store it in the table

		strh	r5, [r10]		@insert jersey number
		
		ldrd	r4, [r6]		@insert character name 8 bytes at a time (3 times total)
		strd	r4, [r10, #2]
		
		ldrd	r4, [r6, #8]
		strd	r4, [r10, #10]
		
		ldrd	r4, [r6, #16]
		strd	r4, [r10, #18]
		
		ldrb	r4, [r6, #24]	@insert 25th bytes for name
		strb	r4, [r10, #26]

		
		strh	r11, [r10, #28]	@insert number of games played, get from 4th argument stored in r11
		
		
		ldrh	r4, [sp, #36]	@get the 5th argument
		strh	r4, [r10, #30]	@insert number of 2-point baskets
		
		ldrh	r6, [sp, #40]	@get 6th argument
		strh	r6, [r10, #32]	@insert number of 3-point baskets
		
		ldrh	r7, [sp, #44]	@get 7th argument
		strh	r7, [r10, #34]	@insert number of free throws
		
		mov		r1, #2			@calculate total points by adding 2-point, 3-point, and freethrows according to point values
		mul		r8, r4, r1
		mov		r2, #3
		mul		r9, r6, r2
		add		r3, r8, r9
		add		r3, r3, r7
		
		strh	r3, [r10, #36]	@insert number of total points
		
		
							
		fmsr	s0, r3		@copy r3 into FPU, total points
		fsitos	s1, s0		@convert to float
		
							
		fmsr	s2, r11		@copy r11 into FPU, number of games played
		fsitos	s3, s2		@convert to float

		fdivs	s4, s1, s3	@divide total points by number of games playerd to get points per game
		
		fsts	s4, [r10, #40]	@store at offset 40, last element in struct player
			
		mov		r0, #1		@insert succeeded
		
		pop		{r4, r5, r6, r7, r8, r9, r10, r11, lr}
		bx		lr


end4:
		mov		r0, #0		@insert failed because element already in table
		
		pop		{r4, r5, r6, r7, r8, r9, r10, r11, lr}
		bx		lr

end5:
		add		r10, r10, #44		@go to the element after the last element of the array, this is the address of the newest element
		b		cont



		.data
third:	.word	0
