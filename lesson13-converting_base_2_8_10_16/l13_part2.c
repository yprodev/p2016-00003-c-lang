// lesson twelve on the c language

/*
		Converting from Base 10 to Base 2, 8 and 16
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * convertBase(unsigned int numberToConvert, int base){

	char buffer[33];
	char *pConvertedNumber;

	// We are going to create a character array. We are going to put in here
	// all the potential values that could be stored to create all of the different
	// bases we gonna need.
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

		// And we are going to change this line.
		*pConvertedNumber = allValues[value];

		numberToConvert /= base; // numberToConvert = numberToConvert / 2;
	} while(numberToConvert != 0);

	printf("%s", pConvertedNumber);
	return pConvertedNumber;
}

int main(void){

	unsigned int numberOne = 60; // in binary it is going to be - 111100

	printf("%d in Base 2 = ", numberOne); // 111100
	converBase(numberOne, 2);
	printf("\n");

	printf("%d in Base 8 = ", numberOne); // 74
	converBase(numberOne, 8);
	printf("\n");

	printf("%d in Base 16 = ", numberOne); // 3c
	converBase(numberOne, 16);
	printf("\n");

	return 0;
}















