// Lesson six on the C Language

#include <stdio.h>

void main(){

	typedef union{
		short individual;
		float pound;
		float ounce;
	} amount;

	amount orangeAmt = {.ounce = 16};
	orangeAmt.individual = 4;

	printf("Number of oranges: %f : Size: %d\n\n"
				, orangeAmt.individual
				, sizeof(orangeAmt.individual)
				);

	orangeAmt.pound = 1.5;

	printf("Number of oranges: %.2f : Size: %d\n\n"
				, orangeAmt.pound
				, sizeof(orangeAmt.pound)
				);

	typedef struct{
		char *brand;
		amount theAmount; // We are using our union in our created struct
		quantity theQuantity;
	} orangeProduct; 		// The name for this struct

	// We are going to initialize this struct
	// using designated initializer

	orangeProduct productOrdered = {"Chiquita",
					// And if we want to add value to the amount
					// we need to use . operator
					.theAmount.ounce = 16
	};

	//Now let's print it out
	printf("You bought %.2f ounces of %s oranges\n\n"
				, productOrdered.theAmount.ounce
				, productOrdered.brand
	);

	// And that is bring us to the problem we have above.
	// We will get a BAD data if the wrong CONVERSION characters will be entered (%d, %f, %s).
	// There is an easy way to solve it, but first we need to learn about Enumerated Types.

	// ENUMERATED TYPES
	// You gonna use one of these guys whenever you know that you
	// will never ever need anything but the value that just go
	// inside of here
	typedef enum{ INDIV, OUNCE, POUND } quantity;

	// But if we will comment this line, where we just put
	// our quantity type, we will get another output
	// from the code below. Answers will be changed according
	// to the type we want to use.
	quantity quantityType = INDIV;
	// HOMEWORK: Place quantity into the created struct

	orangeAmt.individual = 4;

	if(quantityType == INDIV) {

		// This is going to be a short data type
		printf("You bought %d"
					, orangeAmt.individual
					);

	} else if (quantityType == OUNCE) {

		// This is going to be a float data type
		printf("You bought %.2f ounces of oranges"
					, orangeAmt.ounce
					);

	} else {

		// This is going to be a float data type, but pounds
		printf("You bought %.2f pounds of oranges"
					, orangeAmt.pound
					);

	}


















}