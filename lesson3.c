// Lesson three on the C Language
// Here we will use gcc -std=c99 command to compile for C v99

#include <stdio.h>

// Need for exit()
#include <stdlib.h>
#include <string.h>

void main(){

	int whatToDo = 0;

	do{
		printf("\n\n");
		printf("1. What time is it?\n\n");
		printf("2. What is todays date?\n\n");
		printf("3. What day is it?\n\n");
		printf("4. Quit\n\n");

		scanf(" %d", &whatToDo);
	}while(whatToDo < 1 || whatToDo > 4);

	if(whatToDo == 1){
		printf("Print the time\n\n");
	} else if(whatToDo == 2){
		printf("Print the date\n\n");
	} else if(whatToDo == 3){
		printf("Print the day\n\n");
	} else {
		printf("Bye Bye\n\n");
		// Here we can exit out the program
		// It is not error causing error
		exit(0);
	}

	// The same as many if else statements
	switch(whatToDo){
		case(1) : printf("Print the time");
		break;

		case(2) : printf("Print the date");
		break;

		case(3) : printf("Print the day");
		break;

		default : exit(0);
		break;
	}


	// ARRAYS
	// The first value has a zero index
	// int primeNums[3] = {2,3,5};
	// int morePrime[] = {13, 17, 19};

	// It is how we build a string
	char wholeName[14] = "Andrew Kramer";
	// It is how we build an array
	int primeNumbers[3] = {2, 3, 5};
	// Or we write this if we don't want to write the exact length of the array
	int morePrimes[] = {13, 17, 19, 23};
	printf("The first prime in the list is: %d\n\n", primeNumbers[0]);

	// the silly way to define a string
	char city[7] = {'C', 'h', 'i', 'c', 'a', 'g', 'o', '\0'}; // Here you have to put a null value by yourself at the last place
	char thirdCity[] = "Paris"; // It will put a null character in the last position '\0'

	// 1. You have to remember that you may override the information 
	// in array you are currently using
	// 2. Make sure that is your array is big enough to store an
	// information you need to store in
	// Of course you don't want to make it too make in cause of using
	// too much memory



	// PROGRAM - Write your city
	char yourCity[30];

	printf("What city do you live in? ");
	// Here we don't want to use scanf(), because scanf()
	// may override data and we don't want that
	// scanf() is not smart enough to understand that
	// it doesn't have to ovveride an array
	// so we are going to use fgets()
	// fgets also gonna add '\0' character at the end of your data
	// so you must provide the size of data that is going to be added in an array
	fgets(yourCity, 30, stdin);
	// ------^-------^----^------
	// 			 1 			 2 		3 		
	// 1. Name of an array
	// 2. Size of the array
	// 3. Standard input (your keyboard)
	printf("Hello %s\n\n", yourCity);

	// We are getting rid of the new line at the end of the string
	for(int i = 0; i < 30; i++) {
		// We find the last charachter of the string
		if(yourCity[i] == '\n'){
			// We are correcting the situations and add null value at the end of the string
			yourCity[i] = '\0';
			// After that we are breaking the loop, because we've already found what we wanted
			break;
		}
	}

	printf("Hello %s\n\n", yourCity);


	// STRING COMPARE - strcmp()
	// It is gonna to take two strings and it is going to return a negative number
	// if the first string is less then the second, and it's going to return the
	// positive number, if the opposite occurs. And it's going to return zero
	// if the strings are equal.
	// To use this function we should add new include statement #include <string.h>

	printf("Is your city Paris? %d\n\n", strcmp(yourCity, thirdCity));

	// STRING CONCATINATE - strcat()
	char yourState[] = ", Pennsylvania";
	strcat(yourCity, yourState);
	printf("You live in %s\n\n", yourCity);


	// STRING LENGTH - strlen()
	// It is gonna return the length of a string MINUS the null character at the end
	// JUST the length of the letters
	printf("Letters in Paris : %d\n\n", strlen(thirdCity));


	// STRING COPY
	// We DON'T want to use string copy, because it can cause overrides in the memory.
	// Some if you want to do string copy in the safe way use - strlcpy() - string left copy
	strlcpy(yourCity,
		"El Pueblo del la Reina de Los Angeles",
		sizeof(yourCity));

	printf("New city is: %s\n\n", yourCity);


	// GLOBAL VARIABLES
	// Global variable is the variable that is outside of the any other function
	// So now we are going to create return type functions. This type of functions
	// don't have 'void' word before the function declaration
	// This function needs to be in the other file to call it then from the main
	// function. But nuw it is already in the main function and in the same file,
	// so while we are experementing with C language, it doesn't matter.

	int globalVar = 0;
	int addTwoInts(int num1, int num2){
		return num1 + num2;
	}

	// this part we should put in the main function
	int total = addTwoInts(4, 5);
	printf("The sum is %d\n\n", total);







}
