// lesson twelve on the c language

/*
		Converting from Other Bases to Base 10

			How Does Base 8 Work?

				Previously we have seen how base 8 works. And now knowing this
				math we basicly know how to convert from base 8 to base 10.

				2 	=  2 * 8^0
				45 	= (4 * 8^1) + (5 * 8^0)								= 37 in Base 10
				455 = (4 * 8^2) + (5 * 8^1) + (5 * 8^0)		= 301 in Base 10
				##########################################################
								 256					40					5				= 301


			Converting From Base 8 to Base 10

				455 = (4 * 8^2) + (5 * 8^1) + (5 * 8^0)		= 301
								 256					40					5

			So, basicly we have to figure out how to use that we see on the screen
			and simply create it inside of a function. So, what is the some of the different
			things we are going to do?

			The Function is Passed:
				1. The number to convert in string form
				2. The original base of the number
				3. The number of numbers in that char array

			Then we need to create a loop that starts at the highest point of the array
			and decrements down (the highest is 5 - because we have 5, 40, 256).

			For each number in the array:
				1. Get the original base ^ increasing number
				2. Char Array Number *
				3. Add the Result to other results
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> // We are using math library to calculate the power
#include <ctype.h> // We are using ctype library to check whether the alpha number has been passed
									 // inside of the letter pass. So we will be able to convert from hexadecimal to
									 // base 10.

// We are going first on how convert regular numbers and ignore the letters for a moment
int baseToDecimal(char* number, int baseFrom, int sizeOfNumber){
	int result = 0;
	int toThePowerOf = 0;

	// We need to cycle through the digits starting from the last one or from the
	// futhers to the right. The reason we need to subtract 2 is that the first index equals
	// zero and we also need to avoid NULL character '\0'.
	for(int i = (sizeOfNumber - 2); i >= 0; --i){
		// Next we are going to copy the style that we talked about previously
		// ... + (4 * 8^1) + ...
		result += (number[i] - '0') * pow(baseFrom, toThePowerOf);
		// Then we need to increament the power
		toThePowerOf++;
		// Now it is not gonna work for hexadecimal
	}
	printf("%s in the base %d equals %d in base 10\n\n", number, baseFrom, result);
	return result;
}



char * convertBase(unsigned int numberToConvert, int base){

	char buffer[33];
	char *pConvertedNumber;

	char allValues[] = "0123456789abcdef";

	if(base < 2 || base > 16){
		printf("Enter a number between 2 and 16\n\n");
		exit(1);
	}

	pConvertedNumber = &buffer[sizeof(buffer) - 1];

	*pConvertedNumber = '\0';

	do{

		int value = numberToConvert % base;

		pConvertedNumber = pConvertedNumber - 1;

		*pConvertedNumber = allValues[value];

		numberToConvert /= base;
	} while(numberToConvert != 0);

	printf("%s", pConvertedNumber);
	return pConvertedNumber;
}

int main(void){

	unsigned int numberOne = 60;

	printf("%d in Base 2 = ", numberOne);
	converBase(numberOne, 2);
	printf("\n");

	printf("%d in Base 8 = ", numberOne);
	converBase(numberOne, 8);
	printf("\n");

	printf("%d in Base 16 = ", numberOne);
	converBase(numberOne, 16);
	printf("\n");

	char numberToConvert[] = "74";
	baseToDecimal(numberToConvert, 8, sizeof(numberToConvert));

	return 0;
}
