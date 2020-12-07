#include "/user/cse320/Projects/project12.support.h"
#include <stdio.h>

unsigned update( unsigned PC, unsigned IR, unsigned CPSR ){
	
	
	int condition = IR>>28;
	int op = IR>>26 & 0x00000003;
	int sign_bit = (IR & 0x00800000)>>23;
	int simm;
	int l = IR >>24 & 0x00000003;
	if(sign_bit){
		simm = IR |0xff000000;
		}
	else{
		simm = IR & 0x00ffffff;
		}
	int n = CPSR >> 31;
	int z = CPSR >> 30 & 0x00000001;
	int c = CPSR >> 29 & 0x00000001;
	int v = CPSR >> 28 & 0x00000001;
		

	
	
	
	if (op == 2){ //if branch present
		
		if ((l != 2) && (l != 3)){//op wants to branch but bits 25:24 dont indicate b or bl, illegal
			return 0;
			}
		
		
		if (condition == 0){ // if condition is EQ
			if (z){
				PC += simm<<2;
				}
			else{
				PC += 4;
				}
			}
		else if (condition == 1){//if condition is NEQ
			if (!z){
				PC += simm<<2;
				
				}
			else{
				PC += 4;
				}
			
			}
		else if (condition == 2){//if condition is carry
			if (c){
				PC += simm<<2;
				}
			else{
				PC += 4;
				}
			}
		else if (condition == 3){//if condition is not carry
			if (!c){
				PC += simm<<2;
				}
			else{
				PC += 4;
				}
			}
		else if (condition == 4){//if condition is NEG
			if (n){
				PC += simm<<2;
				}
			else{
				PC += 4;
				}
			}
		else if (condition == 5){//if condition is not NEG
			if (!n){
				PC += simm<<2;
				}
			else{
				PC += 4;
				}
			}
		else if (condition == 6){//if condition is overflow
			if (v){
				PC += simm<<2;
				}
			else{
				PC += 4;
				}
			}
		else if (condition == 7){//if condition is not overflow
			if (!v){
				PC += simm<<2;
				}
			else{
				PC += 4;
				}
			}
		else if (condition == 8){//if condition is unsigned greater than
			if (c && !z){
				PC += simm<<2;
				}
			else{
				PC += 4;
				}
			}
		else if (condition == 9){//if condition is unsigned less than or equal to
			if (!c || z){
				PC += simm<<2;
				}
			else{
				PC += 4;
				}
			}
		else if (condition == 10){//if condition is signed greater than or equal to
			if (n == v){
				PC += simm<<2;
				}
			else{
				PC += 4;
				}
			}
		else if (condition == 11){//if condition is signed less than
			if (n != v){
				PC += simm<<2;
				}
			else{
				PC += 4;
				}
			}
		else if (condition == 12){//if condition is signed greater than
			if (!z && n==v){
				PC += simm<<2;
				}
			else{
				PC += 4;
				}
			}
		else if (condition == 13){//if condition is signed less than or equal to
			if (z || n!=v){
				PC += simm<<2;
				}
			else{
				PC += 4;
				}
			}
		else if (condition == 14){//if condition is always
			PC += simm<<2;
			}
		else{//illegal instruction, condition code is 15
			return 0;
			
			}
		}
	else{//if not branching
		if (op == 3){//if op is 11, illegal
			return 0;
			}
		//instruction is either data processing or data movement, just dont branch, not illegal
		PC += 4;
		
		}
	
	
	return PC;
	
	
	}
