// lesson twelve on the c language

/*
		Binary File I/O and Error Handling with C
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h> // Library for error handling

int main(){
	// We are going to create a file pointer
	FILE *pFile

	// Then we are going to create a buffer
	// And the very first thing we are doing to do is just printing
	// text out to a binary file and then reading that back in.
	char * buffer;

	// New thing we are going to use is
	// size_t - it is a data type that is used to reperesent an element in bytes.
	// For example 10 characters will be equal to a size eleven.
	// If you have 10 characters and you want to store a number of bytes
	// in this size_t file - that it just it gonna hold just in bytes.
	size_t dataInFile;

	long fileSize;

	pFile = fopen("names.bin", "rb+");
	// rb - stands for 'read binary'

	if(pFile == NULL){
		// Since we want to read data, that is ectually through an error (because now
		// we have no information there). So we will get an error and catch it.
		// perror() will print a string and follow with a standard error message
		perror("Error occured");
		// And on top of that if we will print another string with printf()
		// it is going to provide an error code value here.
		printf("Error code %d\n\n", errno);
		printf("File is going to be created\n", );
		// Since the file does not exist we are going to create it
		pFile = fopen("names.bin", "wb+");
		// wb - stands for 'write (create) binary'
		// Here can be also an error that occurs in this situation
		// So we need to prevent it
		if(pFile == NULL){
			perror("Error occured");
			printf("Error code %d\n\n", errno);
			exit(1);
		}
	}

	// Otherwise we know that we got our file created and we are going to do some stuff
	// with it. So, we are going to create a character array.
	char name[] = "Daniel Morini";

	// If we are going to write binary data to a file, we are gonna use function fwrite()
	// and then inside of it we are going to pass a pointer that we want to write to the
	// file. At the first name we just put a name of the variable. At the second place we
	// will put the size of EACH ELEMENT in the array. So, we are going to pass the size
	// of the one character. Then the third thing is going to be the NUMBER OF ELEMENTS
	// that we plan on writing to our file. And to do this we are going to use two sizeofs.
	// The size of name (array of characters) devided by size of individual character. And
	// the fourth thing we are going to put in is the FILE that we are going to write
	// this data to.
	fwrite(name, sizeof(name[0]), sizeof(name)/sizeof(name[0]), pFile);

	// The next thing we are going to do is to get the actuall file size.
	// We are using fseek() to move to the end of our file.
	fseek(pFile, 0, SEEK_END);

	// Here we are going to get our file size
	fileSize = ftell(pFile);

	// This function - rewind() is going to rewind us back to the beginning of our file
	rewind(pFile);

	// Then we are going to create a buffer. And rememeber, we do not need this char data
	// for C, but we need it for C++ - so we gonna write 'char*'. Then we are going to use
	// memory allocation function. So, we are figuring out how much space we need.
	buffer = (char*) malloc(sizeof(char)*fileSize);

	if(buffer == NULL){
		perror("Error occured");
		printf("Error code %d\n\n", errno);
		exit(2); // Here exit has value of 2, because we have already used the value of 1
	}

	// And to read this information from our file into our new buffer we are going to use
	// our new function, called fread().
	// First we put WHERE we will PUT the INFORMATION. In our case it is a buffer.
	// Second we put the NUMBER of BYTES taken up by each element.
	// Third we put the NUMBER of ELEMENTS that now is stored in fileSize variable.
	// Fourth we put the FILE.
	dataInFile = fread(buffer, 1, fileSize, pFile);

	// If the data in the file is NOT equal to the file size we catching an error.
	if(dataInFile != fileSize){
		perror("Error occured");
		printf("Error code %d\n\n", errno);
		exit(3); // Here exit has value of 3, because we have already used the value of 1 and 2.
	}

	// Otherwise we know that we got an information.
	printf("%s\n", buffer);

	// Finally we are going to use fclose() on our file.
	fclose(pFile);
	// And we also are going to free our buffer. That is going to deallocate the memory block
	// that was created for our buffer.
	free(buffer);

	return 0;
}























