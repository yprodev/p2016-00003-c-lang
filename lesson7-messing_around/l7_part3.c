// lesson seven on the c language

#include <stdion.h> 	// i/o library
#include <stdbool.h> 	// boolean library
#include <string.h> 	// string library
#include <ctype.h> 		// character library

void main(){

	char name[50]; 									// The character limit

	printf("What is your name?\n\n");

	// We are going to use gets() function
	// It receives the string from a keyboard until a new line is entered.
	// But then it is going to replace a new line with a null character.
	// Whenever you use gets() function, JUST MAKE SURE that you don't go
	// over the character limit. Because gets() doesn't check if you reach
	// the character limit of storage in the string we've defined earlier.

	gets(name);

	// puts() function is going to receive a string and to print it out
	// followed by a new line. gets() function takes a new line off.
	// Everytime puts() is called it will put a new line.
	puts("Hi!");
	puts(name);

}
