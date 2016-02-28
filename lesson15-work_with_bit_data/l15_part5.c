// lesson fifteen on the c language

/*

	Passing Memory Addresses, Bitwise Operators, Singned Integers,
	Shift Operators, Two's Compliment, Bit Masking

*/

/*
		Bit Masking

			Basicly bit masking is used to select parts of a series of bits that you have.
			And it is very easy to do. Basicly what you need to do is use mask (2nd example
			from the top).

					7 			6 			5 			4 			3 			2 			1 			0
			-----------------------------------------------------------------
			|				|				|				|				|				|				|				|				|
			|		1		|		1		|		1		|		0		|		1		|		0		|		1		|		0		|
			|				|				|				|				|				|				|				|				|
			-----------------------------------------------------------------

			Decide if you want to know what bits from 0 to 3rd (including) indexes are, from 
			the hole 8 bits array of data.

			Our Mask
			-----------------------------------------------------------------
			|				|				|				|				|				|				|				|				|
			|		0		|		0		|		0		|		0		|		1		|		1		|		1		|		1		|
			|				|				|				|				|				|				|				|				|
			-----------------------------------------------------------------
			And we use our mask and place ones (1) in the every 'box for a bit' in the same
			place (at the same indexes) of bits we want to retrieve from our previous array
			of bits. And then we are going to perform an AND bitwise operator on it.

			-----------------------------------------------------------------
			|				|				|				|				|				|				|				|				|
			|		0		|		0		|		0		|		0		|		1		|		0		|		1		|		0		|
			|				|				|				|				|				|				|				|				|
			-----------------------------------------------------------------

																					^
																					It is going to return 1 if this is one
																									^
																									It is going to return 0 if it is a zero
																													^
																													...and so on...

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

	unsigned int analyzeMyBits = 170; // 10101010
	unsigned int theMask = 15; 			// 00001111
	unsigned int last4Bits = analyzeMyBits & theMask;

	// 10101010
	// 00001111
	// 00001010

	printf("Last 4 Bits: %s ", convertBase(last4Bits, 2, pConvertedNumber));

	free(pConvertedNumber);
	return 0;
}
