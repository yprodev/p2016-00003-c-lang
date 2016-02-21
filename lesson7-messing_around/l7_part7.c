// lesson seven on the c language

#include <stdion.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void noMoreNewLine(char* theString){
	char * isANewLine;
	isANewLine = strrchr(theString, '\n');
	if(isANewLine) {
		*isANewLine = '\0';
	}
}

void makeLowecase(char* theString){
	int i = 0;
	while(theString[i]){
		theString[i] = tolower(theString[i]);
		i++;
	}
}

void getCharInfo(){
	char theChar;

	while((theChar = getchar()) != '\n'){
		// We place here %d because we want to check True or False (1 or 0)
		printf("Letter or a number was entered %d\n\n"
					// isalnum() function - checks for numbers
					, isalnum(theChar)
					);

		printf("Alphabetic character: %d\n\n"
					// isalpha() function - checks for characters
					, isalpha(theChar)
					);

		// We can check for spaces
		printf("Standard blank: %d\n\n"
					// isblank() function - checks for blank spaces
					, isblank(theChar)
					);

		// We can check if ctrl button was pressed
		printf("Ctrl key was pressed: %d\n\n"
					// iscntrl() function - checks for pressed ctrl key
					, iscntrl(theChar)
					);

		printf("Digit char: %d\n\n"
					// isdigit() function - checks if number is one digit
					, isdigit(theChar)
					);

		printf("Anything but space: %d\n\n"
					// isgraph() function - checks if space was pressed
					, isgraph(theChar)
					);

		printf("Lowercase: %d\n\n"
					// islower() function - checks for lowercase
					, islower(theChar)
					);

		printf("Uppercase: %d\n\n"
					// isupper() function - checks for uppercase
					, isupper(theChar)
					);

		printf("Not a character (Punctuation): %d\n\n"
					// ispunct() function - checks for punctuation
					, ispunct(theChar)
					);

		printf("Any space: %d\n\n"
					// isspace() function - checks for any type of space at all
					, isspace(theChar)
					);
	}
}

void main(){

	getCharInfo();


}
