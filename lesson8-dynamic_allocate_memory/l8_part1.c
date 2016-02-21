// lesson eight on the c language

/*
		How memory allocation works?

			A char gets 8 bits (1 Byte)
		_________________________________________________________________
		|				|				|				|				|				|				|				|				|
		|		1		|		2		|		3		|		4		|		5		|		6		|		7		|		8		|
		|_______|_______|_______|_______|_______|_______|_______|_______|


			And int gets 4 Bytes
		_________________________________
		|				|				|				|				|
		|		1		|		2		|		3		|		4		|
		|_______|_______|_______|_______|


			A char[] gets the Number of Bytes asked for in the original code

		A character array allow us to store pretty much as many bytes of data
		as we possibly want. Problem is we have to part code that. We not actually
		able to icrease that size or icrease the size of an array at runtime. That
		is where allocator function comes in.
		_________________________________________________________________
		|				|				|				|				|				|				|				|				|
		|		1		|		2		|		3		|		4		|		5		|		6		|		7		|		8		|
		|_______|_______|_______|_______|_______|_______|_______|_______|

*/

#include <stdio.h>
#include <stdlib.h>

int main() {

	// Here is memory allocation function
	// malloc() - it allocates memory at runtime.
	// Actually, you are going pass over to it at runtime the amount of space you want
	// and it is going to provide it.

	int amtOfNumbersToStore;

	printf("How many numbers should be store? \n\n");
	scanf(" %d", &amtOfNumbersToStore);

	// Then we are going to create an integer pointer
	// It will set aside enougth space to pull the number of ints
	// that we've just asked for.
	int * pRandomNumbers;

	// We are going to put the typecast here
	// Actually inside C Language you don't need this
	// and some people prefer to not use this.
	// You do need this when you will program inside of C++.
	pRandomNumbers = (int *) malloc(amtOfNumbersToStore * sizeof(int));

	// The next step is very important to do. If the memory
	// allocator was not able to set aside the amount of space we wanted
	// it is going to set back the value of NULL.
	if(pRandomNumbers != NULL){
		int i = 0;
		printf("Enter a number or quit: \n\n");

		while(i < amtOfNumbersToStore && scanf("%d", &pRandomNumbers[i]) == 1){
			printf("Enter a number or quit: \n\n");
			i++;
		}

		// We want to print out all the numbers we print in
		printf("\nYou've entered the following numbers.\n");

		// And we want to go through all the numbers
		for(int j = 0; j < i; j++){
			printf("%d\n\n", pRandomNumbers[j]);
		}

	}

	// Now we are going to use function called free()
	// and it will return all of the memory that was allocated by the memory
	// allocator function back to the system to use this program.
	// The reason why free() function is NOT really needed is because all
	// allocated memory is returned back to the system when the program
	// terminates. What free() is really use for is in situatuations in which
	// you are allocation the large box of memory over and over again without
	// returning it.

	// Let's say you will get 10k of data.
	// You use it, but you DON'T use free() function to send it back to the system.
	// However, as your computer program continues, it has no use to that 10k.
	// You then command and you get ANOTHER 10k.
	// Then you get another 10k.

	// We have:
	// _____________________________________________
	// 1. 10k - no longer used, but memory not freed
	// 2. 10k - no longer used, but memory not freed
	// 3. 10k - no longer used, but memory not freed
	// ---------------------------------------------
	// 		30k TOTAL of memory

	// Eventualy, if you keep doing that, you will get a memory leak. And that
	// basicly just means you run out of memory and your program crashes.

	free(pRandomNumbers);

	return 0;

}
