// lesson nine on the c language

#include <stdio.h>
#include <stdlib.h>

int main(){

	// ### How to read from a file?
	char buffer[1000];

	FILE *pFile;
	// Now we are going to use different data
	pFile = fopen("randomwords.txt", "r+");

	if(!pFile){
		printf("Error: Could not write to file\n\n");
		return 1;
	}

	// If we want DIRECTLY print DIRECTLY to the file
	fputs("Messing with strings", pFile);
	// Now we want to just move around with the data we have
	// just put inside of the file.

	// Using fseek() in the first place we put the file we are going to
	// work with. At the second place 'that we are going 12 characters in from
	// begginig'. At the third place we are going to put SEEK_SET after 12 chars
	// from the begging of the file.
	fseek(pFile, 12, SEEK_SET);

	// SEEK_SET - Stands for 'Start from the begging of the file'
	// SEEK_CUR - Stands for 'Move based off of current position in file'
	// SEEK_END - Stands for 'Move based off of starting at end of file'

	// All these values mean that we are moving cursor in the file. Using SEEK_SET
	// we moved our cursor 12 chars from the begining and now we want something
	// to print in the file. Here we will use fputs() to be nice and simple.
	// Here we are going to replace word 'strings' with the word 'Files'.
	fputs(" Files  ", pFile);

	// Here we just want to print out our information. However since it is going to
	// be a string and we just printed out information above (fputs(" Files  ", pFile);),
	// where do you think the cursor is? It will be at the end of the string. So, there
	// will not be any information to print. So we need to do first is to use fseek() before
	// the while loop and change the second argument to zero. It will move the cursor back
	// to the beggining of our file.
	fseek(pFile, 0, SEEK_SET);
	// And if we want to go to the end of the file just type the string:
	// fseek(pFile, 0, SEEK_END);

	// Another piece of information we can get is HOW MANY BYTES WE ARE FROM THE BEGINING
	// OF THE FILE?
	fseek(pFile, 0, SEEK_END);

	// As we are now at the end of the file ftell() function will tell us how many bytes
	// we are from the begining of the file (or how big this file is or the number of total bytes
	// inside of our file)
	long numberOfBytes = ftell(pFile);
	printf("Number of bytes: %d\n\n", numberOfBytes);

	// After that we will find out that we are 20 bytes far from the begining of the file
	// so we can move cursor 20 bytes back to the begining from the current position.
	fseek(pFile, -20, SEEK_CUR);

	while(fgets(buffer, 1000, pFile) != NULL){
		printf("%s", buffer);
	}

	printf("Success reading from file\n\n");

	if(fclose(pFile) != 0){
		printf("Error: File not closed\n\n");
	}

	return 0;
}

