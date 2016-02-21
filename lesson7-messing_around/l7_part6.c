// lesson seven on the c language

#include <stdion.h> 	// i/o library
#include <stdbool.h> 	// boolean library
#include <string.h> 	// string library
#include <ctype.h> 		// character library

void noMoreNewLine(char* theString){
	char * isANewLine;

	// strrchr() function
	// strchr() - this will find the first occurance
	// strrchr() - this will find the last occurance
	// These funcions return either True or False
	isANewLine = strrchr(theString, '\n');
	// ---------------------^---------^-------------
	//											1 				2							
	// 1. In what we are going to find something
	// 2. What we are going to find

	if(isANewLine) {
		// We are going to change the character that is there.
		*isANewLine = '\0';
		// And that is going to remove a new line for us.
	}
}

void makeLowecase(char* theString){
	int i = 0;
	while(theString[i]){
		// If we want to change an individual characters we should use
		// tolower() function - turn character to lowercase
		// toupper() fucntion - turn character to uppercase
		theString[i] = tolower(theString[i]);
		i++;
	}
}

void main(){

	char doYouWantToQuit[10];

	printf("Enter 'quit' to quit: \n\n");

	// And now let's allow user to enter in an information till he / she will enter the word 'quit'.
	// strcmp() function - will compare two strings

	while(strcmp(doYouWantToQuit, "quit")){
		// ---------------------------^------------------
		// the variable will be compared with this string

		// REMEMBER: fgets is going to add '\n' to the end, so we are
		// going to get rid of it. So we are going to create an outside
		// function.
		fgets(doYouWantToQuit, 10, stdin);
		noMoreNewLine(doYouWantToQuit);
		printf(doYouWantToQuit); // We will see word type by user in without a new line

		// But what if user will type 'quit' word with uppercase letters?
		// We should take an input and actually convert it to lowercase.
		// Let's create a new function.
		makeLowecase(doYouWantToQuit);
		printf(doYouWantToQuit); // We will see word type by user in without a new line and in lowecase

	}

	printf("Thank you for typing %s\n\n"
				, doYouWantToQuit
				);


}
