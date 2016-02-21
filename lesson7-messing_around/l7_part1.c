// Lesson seven on the C Language

#include <stdion.h> 	// I/O library
#include <stdbool.h> 	// Boolean library
#include <string.h> 	// String library
#include <ctype.h> 		// Character library

void main(){

	// For this you need to include boolean library
	_Bool isANumber; // We are going to check if the number was entered

	// Basiclly we've created a boolean variable
	// True will be one - 1
	// False will be zero - 0

	// Also if you are using boolean library you may change this:
	//			_Bool isANumber;
	// to that:
	//			bool isANumber;

	int number;
	int sumOfNumbers = 0;

	printf("Enter a number:\n\n");

	// The reason we use scanf() it is because if
	// user will enter from 0 through a 9 it will be one (True).
	// It also allows to put a minus symbol to write a negative number.
	isANumber = (scanf(" %d", &number) == 1);

	while(isANumber){

		sumOfNumbers = sumOfNumbers + number;

		printf("Enter a number:\n\n");
		// This is one more another way to get input from user
		isANumber = (scanf(" %d", &number) == 1);
	}

	printf("The sum is %d\n\n", sumOfNumbers);

}
