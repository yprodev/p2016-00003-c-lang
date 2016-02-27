// lesson twelve on the c language

/*
		Converting from Base 10 to Base 2, 8 and 16
*/

/*

	With C we can to work with individual bits.
	In this case we can to work with individual bits, with C we can to
	work with hardware.


		The Base 10 World

			2 = 	 2 * 10^0 														(to power of zero)
			45 = 	(4 * 10^1) + (5 * 10^0)
			455 = (4 * 10^2) + (4 * 10^1) + (5 * 10^0)

			Same as:
			(1 * 1000) + (5 * 100) + (6 * 10) + (7 * 1)
			OR
			(1 * 10^3) + (5 * 10^2) + (6 * 10^1) + (7 * 10^0)

			The power of zero (10^0 = 1) tells us how many 1s we need to create the final number.
			The power of one and more tells us how many 10s we nedd to create the final number.


		2 Fingered Computers Rule the World

			1 = 	 1 * 2^0
			10 = 	(1 * 2^1) + (0 * 2^0)
			111 = (1 * 2^2) + (1 * 2^1) + (1 * 2^0)
			----------^-----------^-----------^-----
								4 					2 					1 		
			one 4 + one 2 + one 1 = 4 + 2 + 1 = 7 in base 10 = 111 in binary

			The power of zero (2^0 = 1) tells us how many 1s do we need to create the final number.
			The power of one and more tells us how many 2s do we nedd to create the final number.
			So, if we take 2 + 0 that means that one zero in binary is equal to 2.


		Let's Take Another Byte

					7 			6				5				4 			3				2 			1 			0
			-----------------------------------------------------------------
			|				|				|				|				|				|				|				|				|
			|		1 	|		1 	|		1 	|		1 	|		1 	|		1 	|		1 	|		1 	|
			|				|				|				|				|				|				|				|				|
			-----------------------------------------------------------------
				 128 		 64 		 32 		 16 			8				4 			2 			1 			= 255
			#################################################################
				 2^7 		 2^6 		 2^5 		 2^4 		 2^3 		 2^2 		 2^1 		 2^0

			8 bits can hold maximum number of 255, because of how binary numbers work.


		How Does Base 8 Work?

			2 = 	 2 * 8^0
			45 = 	(4 * 8^1) + (4 * 8^0) 						=	37 in Base 10
			455 = (4 * 8^2) + (5 * 8^1) + (5 * 8^0)
			#######################################
							 256				 40						5			= 301 in Base 10


		How Does Base 16 Work? (hexadecimal)

			10 Hex = 16 Base 10

			10: A
			11: B
			12: C
			13: D
			14: E
			15: F

			2 = 	 2 * 16^0
			2D = 	(2 * 16^1) + (13 * 16^0)								= 45 Base 10
			1C7 = (1 * 16^2) + (12 * 16^1) + (7 * 16^0)
			#######################################
							 256					 192						7				= 455 in Base 10


		How Can We Print Out Binaries?

											---------
											|				|
											|	 11 	|
											|				|
											---------

			So let's say that our base 10 number we are gonna be use is 11.
			How exactly we are going to convert it into a string in binary code
			that we are going to print out to a screen.

			We've decided to create a character array. At the end of that character
			array we are gonna put a NULL value - '\0'. So, this in essence is going
			to be a buffer.

			So there is a neet little way to convert to pretty much every type of base.
			And what we are going to use to do so is the modulus character. So, if you
			take your original base 10 number and use the modulus character followed by
			the base that you want to convert into.

			11 % 2 = 1

			In the essence what we are asking here is do I have odd number inside of this
			number that I want to convert? The answer for this would be 'YES' (becase 11 % 2 = 1
			- it is not a zero, so it is true).

			It is going to provide you with the number that you have to put in the array
			before NULL character (0 index in reverse).

					3				2				1				0
			-----------------------------------------
			|				|				|				|				|				|
			|				|				|				|		1 	|	 '\0'	|			Do I have an Odd number?
			|				|				|				|				|				|
			-----------------------------------------

			Then to continue moving on we are going to take 11 and devide it by 2:

			11 / 2 = 5

			Move the five down here:

			5 % 2 = 1

			So the question is do I need a 2? And the answer is 'YES'. And we put 1 down below at
			the second index from the end.

					3				2				1				0
			-----------------------------------------
			|				|				|				|				|				|
			|				|				|		1 	|		1 	|	 '\0'	|			Do I need a 2?
			|				|				|				|				|				|
			-----------------------------------------

			Let's continue our calculation.

			5 / 2 = 2

			and...

			2 % 2 = 0

			So, now question is: 'Do I need 4?'. And the answer is 'NO'. So We take the zero and
			put it down at the third index from the end.


					3				2				1				0
			-----------------------------------------
			|				|				|				|				|				|
			|				|		0 	|		1 	|		1 	|	 '\0'	|			Do I need a 4?
			|				|				|				|				|				|
			-----------------------------------------

			Then we gonna continue until the number we devide everytime become zero.

			2 / 2 = 1

			1 % 2 = 1

			Question is: 'Do I need 8?'. And the answer is 'YES'. So We take the one and
			put it down at the fourth index from the end.

					3				2				1				0
			-----------------------------------------
			|				|				|				|				|				|
			|		1 	|		0 	|		1 	|		1 	|	 '\0'	|			Do I need a 8?
			|				|				|				|				|				|
			-----------------------------------------

			Then if we will do an aditional calculation we will get an error. And we
			will finish.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// We are going to create a function and it is going to return to us a character array
// that is going to have a binary number.
char * convertBase(unsigned int numberToConvert, int base){

	// Now we will concentrate on converting base 10 to binary
	// So we want to work with bytes. So, we are going to use 32 bits. The 33rd character
	// is for NULL character (\0).
	char buffer[33];

	// We want to create one more character array. And this is going to be the converted
	// number.
	char *pConvertedNumber;

	if(base < 2 || base > 16){
		printf("Enter a number between 2 and 16\n\n");
		exit(1);
	}

	// Now we need to point to the last index in the our character array
	// and that is where we are going to store our NULL character. - 1 we use
	// because of the zero index.
	pConvertedNumber = &buffer[sizeof(buffer) - 1];

	// Now we are pointing to the right position.
	// Now we need to set the value for that. And to do that we are going to
	// through the NULL character inside that.
	*pConvertedNumber = '\0';

	// And then we are going to do one thing over and over and over again with
	// do while loop.
	do{

		//We are just repeating the theory we have above.
		int value = numberToConvert % base;

		// Then we are going to move left from our NULL character
		pConvertedNumber = pConvertedNumber - 1;

		// Then we need to store a proper value in the character array for the final
		// converted number. And if we want to put an intager inside of this character
		// array one of the shortest ways is to do that - put the zero character like
		// and to add value.
		*pConvertedNumber = '0' + value;

		numberToConvert /= base; // numberToConvert = numberToConvert / 2;
	} while(numberToConvert != 0);

	printf("%s", pConvertedNumber);
	return pConvertedNumber;
}

int main(void){

	unsigned int numberOne = 60; // in binary it is going to be - 111100
	printf("%d in Base 2 = ", numberOne);
	converBase(numberOne, 2);
	printf("\n");

	return 0;
}















