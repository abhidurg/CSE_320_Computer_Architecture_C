/*
 *Abhiram Durgaraju 
 *CSE 320 Project 9
 *Simple mathematical operations using ARM, and returns 0x80000000 if error
 */


#include <stdio.h>

int add(int A, int B);
int sub(int A, int B);
int mul(int A, int B);
int negate(int N);
int absolute(int N);
int divide(int A, int B);
int remain(int A, int B);
int power(int N, int I);
int factorial(int N);

int main(){

	int A = 0x7ffffff1;		//large positive number
	int B = 0x5afafbf1;		
	int C = 0x4;			//4 in base 10 also			
	int D = 0xf0000002;		//large negative number
	int E = 0xfffffffc;		//-4 in base 10
	int F = 0x12;			//18 in base 10
	int G = 0xffffffee;		//-18 in base 10
	
	int H = add(B, C);
	int I = add(A, B);
	
	int J = sub(B, C);
	int K = sub(A, D);
	
	int L = negate(C);
	int M = negate(E);
	
	int N = absolute(C);
	int O = absolute(E);
	
	int P = mul(C, F);
	int Q = mul(A, F);
	int R = mul(A, G);
	
	int S = divide(F, C);
	int T = divide(F, 0);
	
	int U = remain(F, C);
	int V = remain(F, E);
	int W = remain(G, C);
	int X = remain(G, E);
	
	int Y = power(F, C);
	int Z = power(F, E);
	int AA = power(A, F);
	
	int BB = factorial(C);
	int CC = factorial(0);
	int DD = factorial(E);
	
	printf( "Add 2 numbers:						%08x\n\n", H);
	printf( "Add 2 very large numbers:				%08x\n\n", I); //overflow
	
	printf( "Subtract 2 numbers:					%08x\n\n", J);
	printf( "Subtract large negative number from large positive:	%08x\n\n",K); //overflow
	
	printf( "Negate a positive number:				%08x\n\n", L);
	printf( "Negate a negative number:				%08x\n\n", M);
	
	printf( "Absolute value of positive number:			%08x\n\n", N);
	printf( "Absolute value of negative number:			%08x\n\n", O);
	
	printf( "Multiply 2 numbers:					%08x\n\n", P);
	printf( "Multiply large positive number with another number:	%08x\n\n", Q); //overflow
	printf( "Multiply large positive number with negative number:	%08x\n\n", R); //overflow
	
	printf( "Divide 2 numbers:					%08x\n\n", S);
	printf( "Divide a number by 0:					%08x\n\n", T); //special case
	
	printf( "Remainder of 2 positive numbers:			%08x\n\n", U);
	printf( "Remainder of positive and negative:			%08x\n\n", V);
	printf( "Remainder of 2 negative numbers:			%08x\n\n", W);
	printf( "Remainder of negative and positive:			%08x\n\n", X);
	
	printf( "Power of 2 positive numbers:				%08x\n\n", Y);
	printf( "Power of positive number with negative exponent:	%08x\n\n", Z); //special case
	printf( "Power of a large number with another number:		%08x\n\n", AA); //overflow
	
	printf( "Factorial of a positive number, 4:			%08x\n\n", BB);
	printf( "Factorial of 0:						%08x\n\n", CC); //special case
	printf( "Factorial of a negative number:				%08x\n\n", DD); //special case


}
