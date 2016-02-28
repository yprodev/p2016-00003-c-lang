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

	pConvertedNumber[32] = '\0';

	do{

		int value = numberToConvert % base;
		pConvertedNumber = pConvertedNumber - 1;

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

	// ### The fourth bitwise operator we are going to work with is Shift Operator - << or >>
	// It basicly allow us to shift bits to the left or to the right. We are going to shift
	// bits first to the left.
	unsigned int shiftLeftTwo = numberSix << 2;
	printf("%s << 2 = ", convertBase(numberSix, 2, pConvertedNumber));
	printf("%s = %d\n\n", convertBase(shiftLeftTwo, 2, pConvertedNumber), shiftLeftTwo);
	// 110 << 2 = 11000 = 24

	unsigned int shiftRightTwo = numberSix >> 2;
	printf("%s >> 2 = ", convertBase(numberSix, 2, pConvertedNumber));
	printf("%s = %d\n\n", convertBase(shiftRightTwo, 2, pConvertedNumber), shiftRightTwo);
	// 110 >> 2 = 1 = 1

	free(pConvertedNumber);
	return 0;
}
