// lesson seven on the c language

#include <stdion.h> 	// i/o library
#include <stdbool.h> 	// boolean library
#include <string.h> 	// string library
#include <ctype.h> 		// character library

void main(){

	char name[50];

	printf("What is your name?\n\n");


	// fgets() function is going to except the string you are going
	// print to. It is also going to ask for the maximum size and it
	// will also ask "hey, where does it come from?" (what type of
	// input). And this function is going to keep read the informtaion
	// to the array till the new line OR until the array has been fulled.
	// And it does put a new line at the end of the set.
	fgets(name, 50, stdin);

	// fputs() was designed to work with fgets(), is going to allow us
	// to put multiple different strings inside of here.
	// fputs() function does not attach a new line.
	fputs("Hi ", stdout);
	fputs(name, stdout);




}
