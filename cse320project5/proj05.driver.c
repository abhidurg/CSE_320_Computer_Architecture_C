 /****************************************************************************
 Abhiram Durgaraju
 Computer Project #5
 ****************************************************************************/

#include <stdio.h>
//function declaration, the actual code for this is in proj05.support.c
int decode (int, const char[], char []);

int main(){
	//decleration for the arrays that are used in samples below
	char A[80];
	char B[80];
	char C[80];
	char D[80];
	char E[80];
	char F[80];
	char G[80];
	char H[80];
	char I[80];
	char J[80];
	char K[80];
	char L[80];
	char M[80];
	char N[80];
	char O[80];
	char P[80];
	char Q[80];
	char R[80];
	char S[80];
	char T[81];
	char U[80];
	char V[80];
	char W[80];
	char X[80];
	char Y[80];
	char Z[80];
	char AA[80];
	char BB[80];
	char CC[80];
	char DD[80];
	char EE[80];
	char FF[80];
	char GG[80];

	
	
	//sample positive decimal 127 converted to the 3 other types
	decode(127, "dec", &A[0]);
	printf("A contains ");
	printf(A);
	printf("\n");
	decode(127, "bin", &B[0]);
	printf("B contains ");
	printf(B);
	printf("\n");
	decode(127, "hex", &C[0]);
	printf("C contains ");
	printf(C);
	printf("\n");
	decode(127, "oct", &D[0]);
	printf("D contains ");
	printf(D);
	printf("\n");
	printf("\n");
	
	//sample negative decimal 127 converted to the 3 other types
	decode(-168, "dec", &E[0]);
	printf("E contains ");
	printf(E);
	printf("\n");
	decode(-168, "bin", &F[0]);
	printf("F contains ");
	printf(F);
	printf("\n");
	decode(-168, "hex", &G[0]);
	printf("G contains ");
	printf(G);
	printf("\n");
	decode(-168, "oct", &H[0]);
	printf("H contains ");
	printf(H);
	printf("\n");
	printf("\n");
	
	//sample positive binary converted to the 3 other types
	decode(0b011011110100, "bin", &I[0]);
	printf("I contains ");
	printf(I);
	printf("\n");
	decode(0b011011110100, "dec", &J[0]);
	printf("J contains ");
	printf(J);
	printf("\n");
	decode(0b011011110100, "hex", &K[0]);
	printf("K contains ");
	printf(K);
	printf("\n");
	decode(0b011011110100, "oct", &L[0]);
	printf("L contains ");
	printf(L);
	printf("\n");
	printf("\n");
	
	//sample negative binary converted to the 3 other types
	decode(-0b0110110100, "bin", &M[0]);
	printf("M contains ");
	printf(M);
	printf("\n");
	decode(-0b0110110100, "dec", &N[0]);
	printf("N contains ");
	printf(N);
	printf("\n");
	decode(-0b0110110100, "hex", &O[0]);
	printf("O contains ");
	printf(O);
	printf("\n");
	decode(-0b0110110100, "oct", &P[0]);
	printf("P contains ");
	printf(P);
	printf("\n");
	printf("\n");
	
	//sample positive hexadecimal converted to the 3 other types
	decode(0x5d, "hex", &Q[0]);
	printf("Q contains ");
	printf(Q);
	printf("\n");
	decode(0x5d, "dec", &R[0]);
	printf("R contains ");
	printf(R);
	printf("\n");
	decode(0x5d, "bin", &S[0]);
	printf("S contains ");
	printf(S);
	printf("\n");
	decode(0x5d, "oct", &T[0]);
	printf("T contains ");
	printf(T);
	printf("\n");
	printf("\n");
	
	//sample negative hexadecimal converted to the 3 other types
	decode(-0x3bc, "hex", &U[0]);
	printf("U contains ");
	printf(U);
	printf("\n");
	decode(-0x3bc, "dec", &V[0]);
	printf("V contains ");
	printf(V);
	printf("\n");
	decode(-0x3bc, "bin", &W[0]);
	printf("W contains ");
	printf(W);
	printf("\n");
	decode(-0x3bc, "oct", &X[0]);
	printf("X contains ");
	printf(X);
	printf("\n");
	printf("\n");
	
	//sample postive octal converted to the 3 other types
	decode(0145, "oct", &Y[0]);
	printf("Y contains ");
	printf(Y);
	printf("\n");
	decode(0145, "dec", &Z[0]);
	printf("Z contains ");
	printf(Z);
	printf("\n");
	decode(0145, "bin", &AA[0]);
	printf("AA contains ");
	printf(AA);
	printf("\n");
	decode(0145, "hex", &BB[0]);
	printf("BB contains ");
	printf(BB);
	printf("\n");
	printf("\n");
	
	//sample negative octal converted to the 3 other types
	decode(-01372, "oct", &CC[0]);
	printf("CC contains ");
	printf(CC);
	printf("\n");
	decode(-01372, "dec", &DD[0]);
	printf("DD contains ");
	printf(DD);
	printf("\n");
	decode(-01372, "bin", &EE[0]);
	printf("EE contains ");
	printf(EE);
	printf("\n");
	decode(-01372, "hex", &FF[0]);
	printf("FF contains ");
	printf(FF);
	printf("\n");
	printf("\n");
	
	//sample invalid conversion with septal base
	decode(127, "sep", &GG[0]);
	printf("GG contains");
	printf(GG);
	printf("\n");
	printf("\n");
	
return 0;
}
