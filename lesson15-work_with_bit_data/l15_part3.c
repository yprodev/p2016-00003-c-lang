// lesson fifteen on the c language

/*

	Passing Memory Addresses, Bitwise Operators, Singned Integers,
	Shift Operators, Two's Compliment, Bit Masking

*/

/*

		How are Signed Integers Represented?

					7				6				5				4				3				2				1				0
			-----------------------------------------------------------------
			|				|				|				|				|				|				|				|				|
			|		1		|		0		|		0		|		0		|		0		|		0		|		1		|		1		|
			|				|				|				|				|				|				|				|				|
			-----------------------------------------------------------------
				 Sign		 64			 32			 16				8				4				2				1

			Sign data can make things just a little more complicated. And you can think about how we could
			represent a NEGATIVE number say inside of C, we might say that if we wanna you the number 3 and
			represent it in memory as negative we could just put a 1 to represent a sign at the 7 index
			from the end. And that is a very logical way to represent a negative numbers inside of memory.

			But THAT IS NOT THE WAY HOW COMPUTERS REPRESENT IT.

		What is Two's Complement

			Computers instead take the number two (00000010) and they use something called the Two's Complement.
			To get to the negative two (-2) they are going to invert all of the numbers (00000010 --> 11111101).
			Then to get to the final negative value we are simply going to add to the previous inverted number
			to get our final result.

					-----------------------------------------------------------------
					|				|				|				|				|				|				|				|				|
		2			|		0		|		0		|		0		|		0		|		0		|		0		|		1		|		0		|
					|				|				|				|				|				|				|				|				|
					-----------------------------------------------------------------

					-----------------------------------------------------------------
					|				|				|				|				|				|				|				|				|
					|		1		|		1		|		1		|		1		|		1		|		1		|		0		|		1		|
					|				|				|				|				|				|				|				|				|
					-----------------------------------------------------------------

					Plus one

					1  = 1
					10 = 2
					11 = 3

					-----------------------------------------------------------------
					|				|				|				|				|				|				|				|				|
		-2		|		1		|		1		|		1		|		1		|		1		|		1		|		1		|		0		|
					|				|				|				|				|				|				|				|				|
					-----------------------------------------------------------------

			And what is really cool about this so this if we wanna change from negative
			two (-2) to positive two (2). W

					-----------------------------------------------------------------
					|				|				|				|				|				|				|				|				|
		-2		|		1		|		1		|		1		|		1		|		1		|		1		|		1		|		0		|
					|				|				|				|				|				|				|				|				|
					-----------------------------------------------------------------

					-----------------------------------------------------------------
					|				|				|				|				|				|				|				|				|
					|		0		|		0		|		0		|		0		|		0		|		0		|		0		|		1		|
					|				|				|				|				|				|				|				|				|
					-----------------------------------------------------------------

					Plus one

					-----------------------------------------------------------------
					|				|				|				|				|				|				|				|				|
		2			|		0		|		0		|		0		|		0		|		0		|		0		|		1		|		0		|
					|				|				|				|				|				|				|				|				|
					-----------------------------------------------------------------

					And the easy way to perform these calculations is called the One's Complement Operator.
					And all it does just flips all the bits.
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

	// ### The fourth bitwise operator we are going to work with is One's Complement Operator - ~
	unsigned int onesCompSolution = ~numberSix;
	// 110 & 111 = 1
	printf("~%s = ", convertBase(numberSix, 2, pConvertedNumber)); // 11111111111111111111111111111001
	printf("%s\n\n", convertBase(onesCompSolution, 2, pConvertedNumber));

	printf("Negative of %d = %d\n\n", numberSix, (onesCompSolution + 1)); // Negative of 6 = -6

	free(pConvertedNumber);
	return 0;
}
