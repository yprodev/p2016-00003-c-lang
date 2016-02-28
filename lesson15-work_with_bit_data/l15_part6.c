// lesson fifteen on the c language

/*

	Passing Memory Addresses, Bitwise Operators, Singned Integers,
	Shift Operators, Two's Compliment, Bit Masking

*/

/*
		How To Represent Fractions in Binary

			Let's just say that we want to represent .625 inside of binary number. How exactly
			would you do that?

			Let's just say we have 4 bits inside of memory and that is we wanna save our
			information. We are going to take our fraction and we are going multiply in times 2.
			And then we are going to have 1.25
			.625 * 2 = 1.25

					3 			2 			1 			0
			---------------------------------
			|				|				|				|				|
			|		0		|		0		|		0		|		0		|
			|				|				|				|				|
			---------------------------------


			So, the 1 before float point goes at the place of the 3rd index from the right.

					3 			2 			1 			0
			---------------------------------
			|				|				|				|				|
			|		1		|		0		|		0		|		0		|
			|				|				|				|				|
			---------------------------------

			Then we are going to multiply .25 times 2 and we gonna get 0.50
			0.25 * 2 = 0.50

			So, the 0 before float point goes at the place of the 2rd index from the right. (Nothing changes)

					3 			2 			1 			0
			---------------------------------
			|				|				|				|				|
			|		1		|		0		|		0		|		0		|
			|				|				|				|				|
			---------------------------------

			Then we are going to take 0.50 move it down and multiply it times 2 and we gonna take this
			1.00.

			So, the 1 before float point goes at the place of the 1rd index from the right.

					3 			2 			1 			0
			---------------------------------
			|				|				|				|				|
			|		1		|		0		|		1		|		0		|
			|				|				|				|				|
			---------------------------------

			And now we have no longer anything to multiply times this is going to be a representation of our
			fraction inside of memory. So, at the index of zero we will put 0.



		What about INFINITE Fractions?

			Sometimes things don't work that well. Ofcourse we have things in the world called infinite
			fractions. Now we are going to have things like:
			.1 * 2 = 0.2 (Binary .0)
			.2 * 2 = 0.4 (Binary .00)
			.4 * 2 = 0.8 (Binary .000)
			.8 * 2 = 1.6 (Binary .0001)

			That is why most programming languages have trouble in regards to precision in regards to fractions.
			Like we saw in the last part of the tutorial everything works out when we don't have infinite
			fractions. But when we do have infinite fractions we can run in the trouble.

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

	unsigned int analyzeMyBits = 170;
	unsigned int theMask = 15;
	unsigned int last4Bits = analyzeMyBits & theMask;

	printf("Last 4 Bits: %s ", convertBase(last4Bits, 2, pConvertedNumber));

	free(pConvertedNumber);
	return 0;
}
