// Lesson four on the C Language

#include <stdio.h>
#include <stdlib.h>


void generateTwoRandomNums(int num1, int num2) {
	// We use random number generator function that is built-in
	// This will generate number from 0 to 49
	// If you want to include 50 just add 1
	num1 = rand() % 50 + 1;
	num2 = rand() % 50 + 1;

	printf("new rand1 number = %d\n\n", num1);
	printf("new rand2 number = %d\n\n", num2);
}

// If you want to pass pointers like an arguments in your
// function, you should use asterisk after the data type.
void pointerRandomNumbers(int* num1, int* num2) {

	// To get the address of the value we are going to use and ampersent - '&'
	// To access the data that is in the address we are going to use an asterisk - '*'

	// And if we wonna to assign we should add the asterisk before the variable
	*num1 = rand() % 50 + 1;
	*num2 = rand() % 50 + 1;

	// Alse if you want to retrive the data you should use the asterisk
	printf("new rand1 number = %d\n\n", *num1);
	printf("new rand2 number = %d\n\n", *num2);
}

void editMessageSent(char* message, int size) {

	char newMessage[] = "New Message";
	if(size > sizeof(newMessage)) {
		for(int i = 0; i < sizeof(newMessage); i++){
			message[i] = newMessage[i];
		}
	} else {
		printf("New message is too big\n\n");
	}

}

void main() {

	// Each of these variables will have a place of 4 bytes in the memory
	// And each of those areas of memory are going to have an address, which
	// we are going to use to set data. We can actually return set address.
	int rand1 = 12, rand2 = 15;
	// %p - means percent
	// We will get hex code for the location in the memory
	printf("rand1 = %p : rand2 = %p\n\n", &rand1, &rand2);
	// The decimal verison of the previous row of code
	printf("rand1 = %d : rand2 = %d\n\n", &rand1, &rand2);
	printf("Size of int %d\n\n", sizeof(rand1));
	// After this trick you will see that very often values of variables
	// are stored in the memory not close to each other. They are stored
	// in the different places.

	// If we will need to access the data and the location of some date
	// in the memory, we may use pointers. We are gonna to use the same
	// data type for our pointer. And very often pointer are going to
	// have a p in front of them.
	// & - getting the addres in the memory
	// p - means that is the pointer
	int * pRand1 = &rand1;
	printf("Pointer = %p\n\n", pRand1);
	printf("Pointer = %d\n\n", pRand1);


	// But if we want to get the data that is stored in the exact location
	// of memory, using pointers, we gonna use an asterisk - *.
	// It is called derefferencing the pointer. It means to use the pointer
	// to access the value.
	printf("Value %d\n\n", *pRand1);


	int primeNumbers[] = {2,3,5,7};
	// Printing the value by index
	printf("First index %d\n\n", primeNumbers[0]);
	// But another way to print it - is using the asterisk
	// The asterisk is going to print out the first index value
	printf("First index %d\n\n", *primeNumbers);

	// But how we are going to get the other index?
	// What we should do to get 3 value from the array?
	printf("First index %d\n\n", primeNumbers[1]);
	// Here we are gonna use Pointer Arithmetic
	// In essence we are going to do is adding 1 to the address
	printf("First index %d\n\n", (*primeNumbers + 1));



	// How we work with arrays of strings?
	// We are going to create an array of strings by
	// creating an arrays of pointers

	char * students[4] = {"Sally", "Mark", "Paul", "Sue"};
	// Now we want to retrieve them
	for(int i = 0; i < 4; i++){
		// Every name is a string, so we use %s
		// and %d - we want to know address
		// This will give us all the names with their memory locations
		printf("%s : %d\n\n", students[i], &students[i]);
	}



	// How to use this with functions?
	int rand1 = 0, rand2 = 0;

	generateTwoRandomNums(rand1, rand2);

	// the generateTwoRandomNums will not change the values
	// but here the values will be the same: 0 and 0
	printf("rand1 = %d\n\n", rand1);
	printf("rand2 = %d\n\n", rand2);

	// So what can we do?
	// We have to use pointers.

	printf("Main before function call\n\n");

	printf("rand1 = %d\n\n", rand1);
	printf("rand2 = %d\n\n", rand2);

	// But in this situation we are going to pass an address
	// We just add '&' to the function arguments
	pointerRandomNumbers(rand1, rand2);
	printf("Main after function call\n\n");

	// now this new function will change the values
	printf("rand1 = %d\n\n", rand1);
	printf("rand2 = %d\n\n", rand2);



	// We are going to create random message
	char randomMessage[] = "Edit my function";

	printf("Old Message: %s\n\n", randomMessage);
	editMessageSent(randomMessage, sizeof(randomMessage));

	printf("New Message: %s\n\n", randomMessage);


}
