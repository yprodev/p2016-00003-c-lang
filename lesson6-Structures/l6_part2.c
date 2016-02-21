// Lesson six on the C Language

	/*

		A UNION only holds 1 Value at a Time

			=====================================================
												DON'T GET TRICKED
				An Example Below will Show Hou you can be Fooled
			=====================================================

			It may seem as if it can hold more, but that's
			coincidence because values are stored in the same
			block of memory.



	*/

#include <stdio.h>

void main(){

	typedef union{
		short individual;
		float pound;
		float ounce;
	} amount;

	amount orangeAmt = {.ounce = 16}; // Here you create your orangeAmt variable
	orangeAmt.individual = 4; 				// This changes the value for orange amount

	// But the reason why people think it will work, it is because very often it does.

	printf("Orange Juice Amount: %.2f : Size: %d\n\n"
				, orangeAmt.ounce 					// Here we will see 16
				, sizeof(orangeAmt.ounce)		// Here we will see 4
				);

	printf("Number of oranges: %d : Size: %d\n\n"
				, orangeAmt.individual 						// Here we will see 4
				, sizeof(orangeAmt.individual)		// Here we will see 2
				);

	/*

			================================================================
											WHY DOES IT SEEM LIKE THIS WORKS?
				Homework hint: the answer lies with the numbers 100 and 10000
			================================================================

	*/

	// just change here to float type - '%f'
	// you are playing around in memory changing type
	// and value changes according the type that is
	// declared in union
	printf("Number of oranges: %f : Size: %d\n\n"
				, orangeAmt.individual 						// Here we will see 16.000008 INSTEAD OF 4
				, sizeof(orangeAmt.individual)		// Here we will see 2
				);

	orangeAmt.pound = 1.5; 			// Also going to be a float (defined in the union amount)

	// Once more we will get float date type with two nums after float point
	// Everything looks OK this way. But it's a TRICK. If you start to play
	// with data types in the print out string - everything gonna change.
	printf("Number of oranges: %.2f : Size: %d\n\n"
				, orangeAmt.pound 						// Here we will see 1.50
				, sizeof(orangeAmt.pound)		// Here we will see 4
				);

	/*

			============================================================================
													THE POINTER FOR EACH WILL BE EQUAL
				Print &orangeAmt.individual, &orangeAmt.pound and &orangeAmt.ounce to see
			============================================================================

	*/


}
