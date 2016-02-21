// lesson seven on the c language

#include <stdion.h> 	// i/o library
#include <stdbool.h> 	// boolean library
#include <string.h> 	// string library
#include <ctype.h> 		// character library

void main(){

	char name[50];

	printf("What is your name?\n\n");

	// If we create string like this, in essence what randomString is
	// doing - is creating a string array or a pointer to the first
	// element in array.
	char * randomString = "Just some random stuff";

	// While the randomString inside of it, we are going to INCREMENT
	// through all the different characters inside of random string.
	// At some point we are going to go to the null character - '\0'.
	// And whenever string get the number of null, it is going to
	// translate to zero, and it is gonna end our while loop.
	while(*randomString){
		putchar(*randomString++); // we will get 'Just some random stuff' without new line char
	}

	// It is natural, but not optimized way to cycle through it.
	int i = 0;

	while(randomString[i] != '\0'){
		putchar(randomString[i++]);
	}

}
