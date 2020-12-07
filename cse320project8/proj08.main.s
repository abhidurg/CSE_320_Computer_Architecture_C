@Project 08
@by Abhiram Durgaraju
@This program checks the contents of a file, prints every character,
@and checks if its a lower case, upper case, hex, number, newline,
@whitespace, or control characters and displays the count for each

		.global main
		
		.text
main:	push	{lr}
		
		mov		r4, #0	@total char count
		mov		r5, #0	@total upper case
		mov		r6, #0	@total lower case
		mov		r7, #0	@total hex count
		mov		r8, #0	@total numbers
		mov		r9, #0	@total newlinechars
		mov		r10, #0	@total special characters
		mov		r11, #0	@total control characters
		
loop:	bl		getchar		@this gets the character and stops on EOF

		cmp 	r0, #-1
		beq		end
		bl 		putchar		@this put the char on outputstream
		
		add		r4, r4, #1	@add to total char count

if13:	cmp		r0, #0x20	@control chars from 0x00 to 0x1F
		blt		if14		@the first 20 characters in ascii are control characters
		b		if15		@else, check if the char is DEL

if14:	add		r11, r11, #1	@add 1 to control
		b		if12			@move on to the rest of the code

if15:	cmp		r0, #0x7F	@control char DEL
		beq		if14		@DEL is a control, add to control count
		b		if12		@else, check newlines etc.


if12:	cmp		r0, #0x20	@Is it a space? If so add 1 to whitespace character couunt
		beq		if11
		b		if10		@else, check for horizontal tab

if10:	cmp		r0, #0x09	@Is it a horizontal tab? If so, add 1 to whitespace
		beq		if11
		b		if8			@else, check for newline

if11:	add		r10, r10, #1	@add 1 to whitespace char count
		b		loop

if8:	cmp		r0, #'\n'	@check for newline	
		beq		if9			@if so, add 1 to newline and whitespace count
		b		if1			@else, check for Upper case alphabetical chars
		
if9:	add		r9, r9, #1		@add 1 to newline
		add		r10, r10, #1	@add 1 to whitespace
		b		loop			@no need to add to control because already done in if14

if1:	cmp		r0, #'['		@less than '[' is 'Z'
		blt		if2				@then go to if2 if less than
		
		cmp		r0, #'`'		@greater than or equal to 'a'
		bgt		if4				@go to if4 is greater
		b 		loop

if2:	cmp		r0, #'@'		@if also greater than or equal to 'A'
		bgt		if3				@then branch to if 3
		cmp		r0, #':'		@if less than or equal to '9'
		blt		if6				@go to if6 to check other numbers
		b		loop

if6:	cmp		r0, #'/'		@if also greater than '0'
		bgt		if7				@increment number and hex count by branching to if7
		b		loop

if7:	add		r7, r7, #1		@add 1 to hex count
		add		r8, r8, #1		@add 1 to numbers count
		b		loop



if3:	add		r5, r5, #1		@add 1 to uppercase
		add		r7, r7, #1		@add 1 to hex
		b		loop

if4:	cmp		r0, #'{'		@if less than or equal to 'z'
		blt		if5				@go to if5 to increment lowercase
		b		loop

if5:	add		r6, r6, #1		@increment lowercase count
		add		r7, r7, #1		@increment hex count
		b		loop			@go back to loop to check next character, listed after every count
		
end: 	ldr		r0, =fmt		@first argument, the string, loaded into register 0
		mov		r1, r4			@second argument, the count, loaded into register 1
		bl		printf			@calls printf, same format for the next 7 calls
		
		ldr		r0, =fmt2
		mov		r1, r5
		bl		printf
		
		ldr		r0, =fmt3
		mov		r1, r6
		bl		printf
		
		ldr		r0, =fmt4
		mov		r1, r7
		bl		printf
		
		ldr		r0, =fmt5
		mov		r1, r8
		bl		printf
		
		ldr		r0, =fmt6
		mov		r1, r9
		bl		printf
		
		ldr		r0, =fmt7
		mov		r1, r10
		bl		printf
		
		ldr		r0, =fmt8
		mov		r1, r11
		bl		printf
		
		pop		{lr}
		bx		lr
		
fmt:	.asciz	"\nTotal Characters = %d\n"		@strings to display the counts
fmt2:	.asciz  "\nUpper Case = %d\n"
fmt3:	.asciz	"\nLower Case = %d\n"
fmt4:	.asciz	"\nHexadecimal = %d\n"
fmt5:	.asciz	"\nNumbers = %d\n"
fmt6:	.asciz	"\nNewline = %d\n"
fmt7:	.asciz	"\nWhitespace = %d\n"
fmt8:	.asciz	"\nControl = %d\n"

