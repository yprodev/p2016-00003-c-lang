// lesson nine on the c language


// File is just a block of memory with a name
// However, file can be stored in many blocks of memory that is not
// necessarily sequential. But do not worry about that because C
// compiler is going to act as they are sequential. Here we will work
// with text files.

#include <stdio.h>
#include <stdlib.h>

int main(){

	// ### How to write to a file?
	int randomNumber;

	// We are creating a pointer to a file
	FILE *pFile;

	// We are going to open (e.g. CREATE) file (in the MEMORY). If file does not exist
	// currently we are going to create it. And either way we are going
	// to completely delete what is there. And it is going to provide us
	// the 'write' access.
	// w - Write
	// a - Append
	// r - Read
	// a+ - Open or Create a file then Append for Writing and Reading
	// r+ - Open for Reading and Writing
	// w+ - Open or Create and Delete the original
	// if we put 'a' instead of 'w' we will append new information to the existing
	// information in the file.
	// if we put 'r' it will allow us to read from the file.
	pFile = fopen("randomnumbers.txt", "w");

	// We are going to check if it was opened
	// fopen will return 1 (true) if it was NOT opened
	// So we need to use '!' operator
	if(!pFile){
		printf("Error: Could not write to file\n\n");
		return 1;
	}

	// If we are able to write to the file
	// We are going to print 10 random numbers
	for(int i = 0; i < 10; i++){
		randomNumber = rand() % 100;
		// It basicly is going to print whatever is supplied to a file.
		// Like 'footprint' in the file - that is how this will write to a file.
		// Just like printf() prints to a screen.
		// 1. At the first place you put the file, from which you are going to print out
		// 2. Then you put type of data you want to print out
		// 3. Then you put refference to that data
		fprintf(pFile, "%d\n", randomNumber);
	}

	printf("Success writing to file\n\n");

	// End the very end of this we want to CLOSE the file
	// It is going to return one is everything is going well
	// and zero (False) if it did not go well.
	if(fclose(pFile) != 0){
		printf("Error: File not closed\n\n");
	}
	// Basicly we are going to need fclose() on all the different files that we've
	// opened. Otherwise we are going to run out the file handlers we gonna run out
	// the memory.


	return 0;
}

