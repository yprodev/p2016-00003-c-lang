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

	char *pConvertedNumber;
	pConvertedNumber = malloc(33 * sizeof(char));

	// ### First bitwise operator we are going to work with AND - &
	unsigned int andSolution = numberSix & numberSeven;
	// And it is going to compare this two numbers in binary base.
	// 110 & 111 = 110
	// 1   & 1   = 1
	//  1  &  1  =  1
	//   0 &   1 =   0
	printf("%s & ", convertBase(numberSix, 2, pConvertedNumber));
	printf("%s = ", convertBase(numberSeven, 2, pConvertedNumber));
	printf("%s\n\n", convertBase(andSolution, 2, pConvertedNumber));

	// ### The second bitwise operator we are going to work with OR - |
	// It is going to return a one if either of this binary numbers contain 1
	unsigned int orSolution = numberSix | numberSeven;
	// 110 & 111 = 111
	printf("%s | ", convertBase(numberSix, 2, pConvertedNumber));
	printf("%s = ", convertBase(numberSeven, 2, pConvertedNumber));
	printf("%s\n\n", convertBase(orSolution, 2, pConvertedNumber));

	// ### The third bitwise operator we are going to work with is Exclusive OR (EXOR) - ^
	// A 1 is gonna be returned only if one of numbers is equal to 1 and the other is equal to 0.
	unsigned int exOrSolution = numberSix | numberSeven;
	// 110 & 111 = 1
	printf("%s ^ ", convertBase(numberSix, 2, pConvertedNumber));
	printf("%s = ", convertBase(numberSeven, 2, pConvertedNumber));
	printf("%s\n\n", convertBase(exOrSolution, 2, pConvertedNumber));

	free(pConvertedNumber);
	return 0;
}
