// lesson twelve on the c language

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int baseToDecimal(char* number, int baseFrom, int sizeOfNumber){
	int result = 0;
	int toThePowerOf = 0;

	for(int i = (sizeOfNumber - 2); i >= 0; --i){
		// We need to change our for loop to work with hexadecimal
		if(isalpha(number[i])){
			// Then we need to convert the letter in the right character code
			// and then subtract 87 to convert lower case letter 'a' into 10
			int charCode = ((int)tolower(number[i])) - 87;
			result += charCode * pow(baseFrom, toThePowerOf);
		} else {
			result += (number[i] - '0') * pow(baseFrom, toThePowerOf);
		}

		toThePowerOf++;
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

	char numberToConvert[] = "3C";
	baseToDecimal(numberToConvert, 16, sizeof(numberToConvert));

	// The problem is - this code is not gonna work for hexadecimal
	// We need to think about how key codes work. Because we have to
	// convert letters 'a' through 'f' into actual numbers. Now we try
	// to figure out what is a key code for letter 'a'.
	// printf("a : %d\n", 'a'); // 97
	// printf("A : %d\n", 'A'); // 65
	// printf("b : %d\n", 'b'); // 98
	// printf("B : %d\n", 'B');
	// printf("c : %d\n", 'c'); // 99
	// printf("C : %d\n", 'C');
	// printf("d : %d\n", 'd'); // 100
	// printf("D : %d\n", 'D');
	// printf("e : %d\n", 'e'); // 101
	// printf("E : %d\n", 'E');
	// printf("f : %d\n", 'f'); // 102
	// printf("F : %d\n", 'F');

	return 0;
}
