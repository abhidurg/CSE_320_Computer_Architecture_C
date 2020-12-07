#include "/user/cse320/Projects/project12.support.h"
#include <stdio.h>


int main(){
	
	printf("\ntesting\n");
	
	//these examples use 0 for PC and 4 for imm24, these values if changed won't affect the program
	//so they are kept constant so that the driver won't have to contain 100s of examples
	
	printf("PC: %08x\n", update(0x00000000,0x03000004,0x00000000)); //data-processing, +4 PC
	printf("PC: %08x\n", update(0x00000000,0x07000004,0x00000000)); //data-movement, +4 PC
	
	printf("PC: %08x\n", update(0x00000000,0x0b000004,0x00000000)); //branch, EQ, z not set, +4 PC
	printf("PC: %08x\n", update(0x00000000,0x0b000004,0x40000000)); //branch, EQ, z is set, use equation
	
	printf("PC: %08x\n", update(0x00000000,0x0f000004,0x00000000)); //op is 11, illegal, return 0
	printf("PC: %08x\n", update(0x00000000,0x08000004,0x40000000)); //branch, but 25:24 is 00, illegal, return 0
	printf("PC: %08x\n", update(0x00000000,0x09000004,0x40000000)); //branch, but 25:24 is 01, illegal, return 0
	printf("PC: %08x\n", update(0x00000000,0xfb000004,0x00000000)); //branch, but condition code is 1111, illegal, return 0
	
	printf("PC: %08x\n", update(0x00000000,0x1b000004,0x40000000)); //branch, not EQ, z is set, +4 PC
	printf("PC: %08x\n", update(0x00000000,0x1b000004,0x00000000)); //branch, not EQ, z is clear, use equation
	
	printf("PC: %08x\n", update(0x00000000,0x2b000004,0x00000000)); //branch, carry, C is not set, +4 PC
	printf("PC: %08x\n", update(0x00000000,0x2b000004,0x20000000)); //branch, carry, C is set, use equation
	
	printf("PC: %08x\n", update(0x00000000,0x3b000004,0x20000000)); //branch, not carry, C is set, +4 PC
	printf("PC: %08x\n", update(0x00000000,0x3b000004,0x00000000)); //branch, not carry, C is not set, use equation
	
	printf("PC: %08x\n", update(0x00000000,0x4b000004,0x00000000)); //branch, negative, N is not set, +4 PC
	printf("PC: %08x\n", update(0x00000000,0x4b000004,0x80000000)); //branch, negative, N is set, use equation
	
	
	printf("PC: %08x\n", update(0x00000000,0x5b000004,0x80000000)); //branch, not negative, N is set, +4 PC
	printf("PC: %08x\n", update(0x00000000,0x5b000004,0x00000000)); //branch, not negative, N is not set, use equation
	
	printf("PC: %08x\n", update(0x00000000,0x6b000004,0x00000000)); //branch, overflow, V is not set, +4 PC
	printf("PC: %08x\n", update(0x00000000,0x6b000004,0x10000000)); //branch, overflow, V is set, use equation
	
	printf("PC: %08x\n", update(0x00000000,0x7b000004,0x10000000)); //branch, not overflow, V is set, +4 PC
	printf("PC: %08x\n", update(0x00000000,0x7b000004,0x00000000)); //branch, not overflow, V is not set, use equation
	
	printf("PC: %08x\n", update(0x00000000,0x8b000004,0x00000000)); //branch, unsinged greater than, C is not set, +4 PC
	printf("PC: %08x\n", update(0x00000000,0x8b000004,0x20000000)); //branch, unsinged greater than, C is set, Z clear, use equation
	
	printf("PC: %08x\n", update(0x00000000,0x9b000004,0x20000000)); //branch, unsinged LE C is set, +4 PC
	printf("PC: %08x\n", update(0x00000000,0x9b000004,0x80000000)); //branch, unsinged LE, C is not set, Z clear, use equation
	
	printf("PC: %08x\n", update(0x00000000,0xab000004,0x80000000)); //branch, signed GE, N != V, +4 PC
	printf("PC: %08x\n", update(0x00000000,0xab000004,0x00000000)); //branch, signed GE, N == V, use equation
	
	printf("PC: %08x\n", update(0x00000000,0xbb000004,0x00000000)); //branch, signed less than, N == V, +4 PC
	printf("PC: %08x\n", update(0x00000000,0xbb000004,0x80000000)); //branch, signed less than, N != V, use equation
	
	printf("PC: %08x\n", update(0x00000000,0xcb000004,0x80000000)); //branch, signed greater than, z set, +4 PC
	printf("PC: %08x\n", update(0x00000000,0xcb000004,0x00000000)); //branch, signed greater than, z clear,  N == V, use equation
	
	printf("PC: %08x\n", update(0x00000000,0xdb000004,0x00000000)); //branch, signed LE, z clear, +4 PC
	printf("PC: %08x\n", update(0x00000000,0xdb000004,0xc0000000)); //branch, signed LE, z set,  N != V, use equation
	
	printf("PC: %08x\n", update(0x00000000,0xeb000004,0xc0000000)); //branch, always, use equation
	
	return 0;
	}
	
	
