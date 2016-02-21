// Lesson six on the C Language


/*
		Storing Myltiple Types of Data

			Weight: Pounds, Grams, Kilograms, Milligrams, Ounces, etc.
			Measurement: Centimeter, Feet, Inch, Millimeter, etc.

		Is it possible to store all this different data in one variable?

		#EX.1 We are selling oranges.

					Orange on the individual base costs:	$0.45
					Oranges per Pound cost: 							$1.14
					Orange juice (160z):									$2.43

		How you can store data of different types?
		Is it even possible?

		The answer is a UNION.

		Basiclly declaring a union data type is like saying: sometimes this variable
		is an integer, sometimes is a short, othertime a float, etc. But never both at once.
		You CAN NOT store more then one value in a union variable.

		The easiest way to get used to a union just basiclly to create one.

*/

#include <stdio.h>

void main(){

	// Creating a union
	typedef union{
		short individual; // Buying oranges on the individual level
		float pound; 			// Buying oranges in pounds
		float ounce; 			// Buying oranges in ounces
	} amount; // 'amount' is the name for this exect union

	// But exactly you are going to add values to it?
	// We are going to use a Designated Initializer.
	amount orangeAmt = {.ounce = 16};
	// ^------^------------^------^--
	// 1 			2 					 3 			4 

	// 1. union data type name
	// 2. variable name
	// 3. pointer in the union
	// 4. value for exact pointer


	// The other way to do it.
	// This is a short version of the customized data type.
	amount orangeAmt.individual = 4;


}
