// lesson fifteen on the c language

/*

	Passing Memory Addresses, Bitwise Operators, Singned Integers,
	Shift Operators, Two's Compliment, Bit Masking

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

char * convertBase(unsigned int numberToConvert, int base, char *pConvertedNumber){

	char allValues[] = "0123456789abcdef";

	if(base < 2 || base > 16){
		printf("Enter a number between 2 and 16\n\n");
		exit(1);
	}


	// And we want to save the NULL character as before
	pConvertedNumber[32] = '\0';

	do{

		int value = numberToConvert % base;
		pConvertedNumber = pConvertedNumber - 1;

		// How we can use this memory location back and fourth between two functions?
		*pConvertedNumber = allValues[value];

		numberToConvert /= base;
	} while(numberToConvert != 0);

	return pConvertedNumber;
}

int main(void){

	unsigned int numberSix = 6; // 110
	unsigned int numberSeven = 7; // 111

	// So, we are going to create a buffer that holds 32 bits + NULL character
	char *pConvertedNumber;
	// Now we are going to allocate some memory for it
	pConvertedNumber = malloc(33 * sizeof(char));

	// Here we want to execute our function, but now we want also to put here a memory
	// location to use the same memory address between two different functions.
	printf("%s\n", convertBase(numberSix, 2, pConvertedNumber));

	// Ofcourse, after allocation memory, we want to free it.
	free(pConvertedNumber);


	return 0;
}
