/*
This is a multiline comment in C language
*/

// This is a single line comment in C language

// If we want to use pringf or some user's input
// we should use include

#include <stdio.h> // This means Standard Input / Output
#include <string.h> // This we need to work with strings

// If we want do define something, like constant
// we should use word define

#define MYNAME "Peter Johnson"

// Now we need to define main function
// This function is main because it helps
// other function in our program to execute

// Variable outside the main function
// is called global variable
// It will be accessable for every entire function
// in our program

int globalVar = 100;

main(){

	// This is a local variable
	char firstLetter = 'D';

	// int - only whole numbers without float point from -32768 to 32768
	int age = 38;

	// If you need to use intager that is bigger (also without float point)
	long int superBigNum = -32767000;

	// If you want to use decimals - you should use float
	float piValue = 3.14159;

	// If you need to use bigger than just float number
	double reallyBigPi = 3.1415948472032439;

	// If we need to print something to a screen we use printf()
	printf("\n"); // printing new line

	// \n - new line
	// \t - one tab
	// \\ - one slash
	// \" - using a regular qoute

	printf("This will print to screen\n\n");
	printf("I am %d years old\n\n", age);															// %d - digit data type
	printf("Big Number %ld ", superBigNum);														// %ld - long digit data type
	printf("PI = %.5f\n\n", piValue);																	// %.2f - number of digits after the float point and float data type
	printf("Big PI = %.15f\n\n", reallyBigPi);
	printf("The first letter in his name is: %c\n\n", firstLetter);		// %c - character data type
	printf("His name is: %s\n\n", "Dillan");		// %s - string data type

	// To create a string, we need to create a character array
	// We need to tell how much characters we need in the string
	// Then we need to add one more character for String Terminator - 0\
	// For string "Dillan Block" we need only 12 'boxes' of memory
	// including space. So, the total number will be 13
	// char myName[13] = "Dillan Block";
	// But you also may not to put that value
	char myName[] = "Dillan Block";

	printf("His name is: %s\n\n", myName);		// %s - string data type

	// It will be nice to assign new value to the charachter array we have already created
	// But we can't do that
	// That is why you need to use strcpy - string copy
	// That is why we need #include <string.h> - for these kind of operations
	strcpy(myName, "Bob Smith");


	// Now we will try to get something from user
	// We are creating an empty variable
	char middleInitial;
	printf("What is your middle initial? ");

	scanf(" %c", &middleInitial);								// We need & to know in what variable we want to save a user input
	printf("Middle initial %c", middleInitial);

	// But the code above will not work with more then one charachter
	// We need to do something better
	char firstName[30], lastName[30];
	printf("What is your name? ");
	scanf(" %s %s", firstName, lastName);
	printf("Your name is: %s %c %s\n\n", firstName, middleInitial, lastName);

	int month, day, year;

	printf("What's your birth dat? ");
	scanf(" %d/%d/%d", &month, &day, &year);
	printf("\nBirth Date %d/%d/%d\n\n", month, day, year);


	// Something about math in C language
	int num1 = 12, num2 = 15, numAns;
	float decimal1 = 1.2, decimal2 = 1.5, decimalAns;

	printf("Integer Calculation: %d\n\n", num2 / num1);					// Devision
	printf("Float Calculation: %f\n\n", decimal2 / decimal1);		// Devision
	printf("Modulus: %d\n\n", num2 % num1);											// Modulus

	// ORDER OF OPERATIONS MATTERS
	printf("Without parentheses: %d\n\n", 3 + 6 * 10);
	printf("With parentheses: %d\n\n", (3 + 6) * 10);

	int randomNum = 1;

	// Shortcut operations
	// += - add whatever number is on the right to itself
	// -= - subtract whatever number is on the right to itself
	// *= - multiplicate whatever number is on the right to itself
	// /= - divide whatever number is on the right to itself
	// %= - modulus whatever number is on the right to itself (ONLY if you are working with integers)
	// ++ - quickly adds 1 to a value, like value++ (increment)
	// -- - quickly subtract 1 from a value, like value-- (decrement)
	printf("1 += 2: %d\n\n", randomNum += 2); // (1 += 2) == 3 - and that is OK

	// But why we didn't put %d instead of one at the begining of the line?
	// Because C language do all the math before and puts the result earlier
	printf("%d += 2: %d\n\n", randomNum, randomNum += 2); // (5 += 2) == 5 - we will get 5
	//			^											^						^																							
	//		stage3								stage2			stage1																					


	int exNum = 1;
	printf("++%d : %d\n\n", exNum, ++exNum); // Here we increment it and then it printed out

	// reseting exNum back to 1
	int exNum = 1;
	printf("%d++ : %d\n\n", exNum, exNum++); // It will show 1 on stage 2, and then increments

	// CAST A VALUE

	int numberEx = 12;
	int = numberEx2 = 14;

	// This is the method to show up the data type you want there to show
	// Here we want an integer division to show like float
	printf("numberEx / numberEx2 : %f\n\n", (float) numberEx / numberEx2);

}