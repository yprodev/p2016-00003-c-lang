// lesson twelve on the c language

/*
		Binary File I/O and Error Handling with C
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h> // Library for error handling

int main(){

	FILE *pFile
	char * buffer;
	size_t dataInFile;

	long fileSize;
	// We are going to generate an array of random numbers and then randomly
	// allow the user to pick one.
	pFile = fopen("randomnums.bin", "rb+");

	if(pFile == NULL){
		perror("Error occured");
		printf("Error code %d\n\n", errno);
		printf("File is going to be created\n", );
		pFile = fopen("randomnums.bin", "wb+");
		if(pFile == NULL){
			perror("Error occured");
			printf("Error code %d\n\n", errno);
			exit(1);
		}
	}

	// We are going to create integer array with 20 numbers inside it.
	int randomNumbers[20];

	// Then we are going to create a for loop
	for(int i = 0; i < 20; i++){
		randomNumbers[i] = rand() % 100;
		printf("Number %d is %d\n\n", i, randomNumbers[i]);
	}

	// Now we are going to use fwrite() function just like before.
	fwrite(randomNumbers, sizeof(int), 20, pFile);

	// this number will allow the user to dynamicly pick the random number
	// from the file that they want.
	long randomIndexNumber;
	int numberAtIndex;

	printf("Which random number do you want? \n");
	scanf(" %ld", &randomIndexNumber);

	// We are going to use fseek() function in binary mode and the only
	// real difference here is whenever you are using fseek() in binary
	// mode you have to make sure that the offset is the number of the
	// elements (that you are looking for) times (* - multiplied) the 
	// possible size.
	fseek(pFile, randomIndexNumber * sizeof(int), SEEK_SET);

	// Then we use just fread() function to read the next int from our
	// file after we moved our cursor to the right position. And we are
	// going to store this.
	fread(&numberAtIndex, sizeof(int), 1, pFile);

	printf("The random number at index %d is %d\n\n", randomIndexNumber, numberAtIndex);

	fclose(pFile);
	free(buffer);

	return 0;
}























