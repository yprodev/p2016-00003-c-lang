// Lesson two on the C Language

#include <stdio.h>

main(){

	// If you want to compile your program, and need to name
	// it in some different way than default (default name is 'a.out')
	// you need to type the line
	// gcc ProgramName.c -o NewProgramName
	// Than to execute this program you need to type
	// ./NewProgramName instead of ./a.out

	/*
			Relational operators

				var1 > var2
				var1 < var2
				var1 == var2
				var1 >= var2
				var1 <= var2
				var1 != var2
	*/

	printf("\n");

	int num1 = 1, num2 = 2;										// Will give us 0 - a boolean value
	printf("Is 1 > 2 : %d\n\n", num1 > num2);

	if(num1 > num2){
		printf("%d is greater then %d\n\n", num1, num2);
	} else if (num1 < num2){
		printf("%d is less then %d\n\n", num1, num2);
	} else {
		printf("%d and %d are equal\n\n", num1, num2);
	}

	/*
			Logical operators

				&& - And
				|| - Or
				!  - Not

				!0 will return 1
				!1 will return 0

	*/

	int custAge = 38;
	if(custAge > 21 && custAge < 35) printf("They are welcome\n\n");
	else printf("They are not welcome\n\n");

	printf("! turns a true into false : %d\n\n", !1);


	// CASE:
	// Missed less then 10 days work AND
	// Has over 30000 OR
	// Signed up more then 30 new customers

	int bobMissedDays = 8, bobTotalSales = 24000,
			bobNewCust = 32;

	if(bobMissedDays < 10 && bobTotalSales > 30000 || bobNewCust > 30){
		printf("Bob gets a raise");
	} else {
		printf("Bob doesn't get a raise");
	}


	/*
		Shortcut for comparison
	*/

	int custAge = 38;
	char* legalAge = (custAge > 21) ? "true" : "false";
	printf("Is the customer of legal age? %s\n\n", legalAge);

	int numOfProducts = 10;
	printf("I bought %s products\n\n",
		(numOfProducts > 1) ? "many" : "one");


	/*
		How much memory use different data types?
	*/

	printf("A char take up %d bytes\n\n", sizeof(char));					// 1 byte
	printf("A int take up %d bytes\n\n", sizeof(int));						// 4 bytes
	printf("A long int take up %d bytes\n\n", sizeof(long int));	// 8 bytes
	printf("A float take up %d bytes\n\n", sizeof(float));				// 4 bytes
	printf("A double take up %d bytes\n\n", sizeof(double));			// 8 bytes

	// Bit - is a short for a binary digit. It can be 1 or 0
	// Byte - is generally considered to be an 8 bits


	// 00000000 == 0 - here 8 bits and it is 1 byte
	// 00000001 == 1 - here 8 bits and it is 1 byte
	// 00000010 == 2 - here 8 bits and it is 1 byte
	// 00000011 == 3 - here 8 bits and it is 1 byte
	// 00000100 == 4 - here 8 bits and it is 1 byte

	// Let's see the example of 3 bits
	// 1    0    0 - (3 bits)
	// 4    2    1 - every next bit (1, not 0) on the top, it's like doubling the previous two decimal numbers below

	// 1    1    1    1    1    1 - What does it mean? What is the decimal number?
	// 32   16   8    4    2    1 - just sum all of these = 63
	// __________________________
	// total = 63

	// How much memory will it take for 8 bits or 1 byte?
	// 0    0    0    0    0    0    0    0
	// 128  64   32   16   8    4    2    1 - we will sum it and we will get...
	// ____________________________________
	// 255 or 256 possible chars if we include 0

	// What about integers? What is the maximum value?
	// 0    0    0    0    0    0    0    0
	// 128  64   32   16   8    4    2    1
	// 0    0    0    0    0    0    0    0
	// #    #    #    #    #    1024 512  256 - we are not include here all the numbers because of the length
	// ____________________________________
	// 32 boxes allow for 4,294,967,295
	// or Max value of 2,147,483,647 and a minimum of -2,147,483,648


	// This value will be negative. Because this kind of integer
	// that ends with an 8 has negative sign. If you will
	// correct this and type 7 at the end of this number
	// you will get a positive number.
	int bigInt = 2147483648;
	printf("I'm bigger then you have heard %d\n\n", bigInt);

	int numberHowBig = 0;
	printf("How many bits?\n\n");
	scanf(" %d", &numberHowBig);
	printf("\n\n");

	// 0 : Print what is given
	// 1 : Print what is given
	// 2 : 1 + 2 = 3 		OR 00000000 00000011 (in the binary world without space)
	// 3 : 3 + 4 = 7 		OR 00000000 00000111
	// ##### We get 7 from the line above because we have already calculated this
	// 4 : 7 + 8 = 15 	OR 00000000 00001111

	int myIncrementor = 1, myMultiplier = 1,
			finalValue = 1;















































}