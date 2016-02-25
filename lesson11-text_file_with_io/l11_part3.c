// lesson nine on the c language

#include <stdio.h>
#include <stdlib.h>

int main(){

	// ### How to read from a file?
	char buffer[1000];

	FILE *pFile;

	// We are going to read our file
	pFile = fopen("randomnumbers.txt", "r");

	if(!pFile){
		printf("Error: Could not write to file\n\n");
		return 1;
	}

	// fscanf() allows us to do is pass the file and the data type to read
	// and the buffer, ofcourse, to store everything in we are gonna check for
	// valid data. fscanf() is going to return the data other then 1 if the data
	// doesn't match.
	// This was the second way to print information from a file.
	while(fscanf(pFile, "%s", buffer) == 1){
		// We are going to use puts to print this information out. And puts() is going
		// to print out a new string plus a new line.
		puts(buffer);
	}

	printf("Success reading from file\n\n");

	if(fclose(pFile) != 0){
		printf("Error: File not closed\n\n");
	}

	return 0;
}

