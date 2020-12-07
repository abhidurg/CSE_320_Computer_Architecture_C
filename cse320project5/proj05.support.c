 /****************************************************************************
 Abhiram Durgaraju
 Computer Project #5
 ****************************************************************************/
#include <stdio.h>
/*---------------------------------------------------------------------------
 Name: decode
 Purpose: Convert the twos-complement representation of an integer into
 either a binary, decimal, hexadecimal, or octal external representation
 and pass it into an character array. 
 Receive: value to be converted, the base to convert into, and the address
 off the character array
 Return: 1 if conversion was successful, 0 if unsuccessful
 ---------------------------------------------------------------------------*/
int decode (int, const char[], char []);

int decode (int value, const char base[], char ary[]){
	int value_temp = value; //store the value in a temp variable
	if (base[0] == 'b' && base[1] == 'i' && base[2] == 'n'){
		//convert to binary
		if (value < 0){
		//if the value is negative, treat it normally during conversion
			value = value*(-1);
		}
		int digit; //the remainder digit to undergo modulus oferation
		int i = 0;
		
		while (value != 0){
			digit = value%2; //digit is remainder
			ary[i] = digit + '0'; //convert int to string
			value = value/2;
			i += 1;
		}
		if (value_temp < 0){ //compare the original temp value
			ary[i] = '-'; //add negative sign to end of array
		}
		else{
			ary[i] = '+'; //add positive sign to end of array
		}
		ary[i+1] = '\0'; //lastly add null sign at the end of array
	}
	else if (base[0] == 'd' && base[1] == 'e' && base[2] == 'c'){ 
		//code structure same as above for binary
		if (value < 0){
			value = value*(-1);
		}
		int digit;
		int i= 0;
		while (value != 0){
			digit = value%10;
			ary[i] = digit + '0';
			value = value/10;
			i += 1;
		}
		if (value_temp < 0){
			ary[i] = '-';
			}
		else{
			ary[i] = '+';
			}
		ary[i+1] = '\0';

	}
	else if (base[0] == 'h' && base[1] == 'e' && base[2] == 'x'){
		//code structure same as binary
		if (value < 0){
			value = value*(-1);
		}
		int digit;
		int i = 0;
		while (value != 0){
			digit = value%16;
			if (digit >= 10){
				ary[i] = (digit - 10) + 'A';
				//if above 10, save the appropiate letter A-F
			}
			else{
				ary[i] = digit + '0';
				//if not, just save the digit
			}
			value = value/16;
			i += 1;
		}
		if (value_temp < 0){
			ary[i] = '-';
		}
		else{
			ary[i] = '+';
		}
		ary[i+1] = '\0';
	}
	
	else if (base[0] == 'o' && base[1] == 'c' && base[2] == 't'){
		//code structure same as binary
		if (value < 0){
			value = value*(-1);
		}
		int digit;
		int i = 0;
		while (value != 0){
			digit = value%8;
			ary[i] = digit + '0';
			value = value/8;
			i += 1;
		}
		if (value_temp < 0){
			ary[i] = '-';
		}
		else{
			ary[i] = '+';
		}
		ary[i+1] = '\0';
	}
	else{return 0;} //invalid base -> return 0, no conversion
	//variables used to iterate through loop
	int i; 
	int size;
	int j;
	char temp;
	//this loop gets the index of the last element, and therefore size
	for (i=0; ary[i] != '\0'; i++){}
	size = i;
	i = size-1; //last index is the size of the array minus 1
	j = 0; //go from the start of the array
	while(j<i){ //only loop while the start index is less than the end
	temp = ary[i]; //store last value in a temp variable
	ary[i] = ary[j];//make the last value as the first value
	ary[j] = temp;//make the first value as temp (finished swap)
	i -= 1; 
	j += 1;
		
	}	
	
		
	return 1;
}
	
	
