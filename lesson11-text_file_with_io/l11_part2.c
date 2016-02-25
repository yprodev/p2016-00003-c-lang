// lesson nine on the c language

#include <stdio.h>
#include <stdlib.h>

int main(){

	// ### How to read from a file?
	// We are going to need a buffer to store the information we are going to
	// pull out out of the file.
	// And we are going to define that we are expecting we will pull out
	// just 1000 characters per line to be needed.
	char buffer[1000];

	FILE *pFile;

	// We are going to read our file
	pFile = fopen("randomnumbers.txt", "r");

	if(!pFile){
		printf("Error: Could not write to file\n\n");
		return 1;
	}

	// We are going to use fgets() to read out up to 1000 chars per line
	// until fgets() is going to return a value of NULL, which is going to
	// occur when it reaches the end of a file.
	// This is the one way how you can print out this information
	while(fgets(buffer, 1000, pFile) != NULL){
		printf("%s", buffer);
	}

	printf("Success reading from file\n\n");

	if(fclose(pFile) != 0){
		printf("Error: File not closed\n\n");
	}

	return 0;
}

