// Lesson five on the C Language

// STRUCTS
// Struct is used when you need more then one piece of data to
// describe one thing. You may ask why not to use array? Remember,
// we can use arrays with only one data type.

#include <stdio.h>

struct dog{
	const char *name;
	const char *breed;
	int avgHeightCm;
	int avgWeightLbs;
}; // DON'T FORGET TO PUT A SEMICOLON HERE

// Here we will declare getDogInfo method
// As parameters we should give data type (struct), type of struct (dog)
// and name of the exact struct that will be using that function
void getDogInfo(struct dog theDog){
	printf("\n");
	// You might think that we will use
	// theDog[0] if we want to get the dog's name
	// but it is wrong. It will not work.

	// We are going to use the dot (.) operator.
	// String data type
	printf("Name: %s\n\n", theDog.name);
	printf("Breed: %s\n\n", theDog.breed);
	// Digit data type
	printf("Average Height: %d (cm)\n\n", theDog.avgHeightCm);
	printf("Average Weight: %d (lbs)\n\n", theDog.avgWeightLbs);
}

void getMemoryLocation(struct dog theDog){

	// We don't have to use here an ampersent '&'
	// because name and breed is already a pointers
	printf("Name location: %d\n\n", theDog.name);
	printf("Breed location: %d\n\n", theDog.breed);

	// But these aren't pointers, so we need to use ampersent here
	printf("Height location: %d\n\n", &theDog.avgHeightCm);
	printf("Weight location: %d\n\n", &theDog.avgWeightLbs);
}

void main(){
	// We are going to use struct dog here
	// To define it here we do the next:
	// 1. We are going to give it a name
	// 2. Define a breed
	// 3. Define average height in centimeters
	// 4. Define average weight in lbs
	// 'cujo' here is a variable name
	struct dog cujo = {"Cujo", "Saint Bernard", 90, 264};

	// And now it will be easy to get all this information
	// using an individual function
	getDogInfo(cujo);

	// Here we will create another dog struct
	// And we will give it a data that is currently in 'cujo'
	struct dog cujo2 = cujo;

	getMemoryLocation(cujo);
	getMemoryLocation(cujo2);
}

/*
		Structs and Memory

			A STRUCT defines a template for your data type
			A STRUCT VARIABLE difines the memory needed to fit the data

			|					|					|					|					|
			|	*name 	|	*breed 	|		90		|		264 	|
			|					|					|					|					|


			|					|					|					|					|
			|	*name 	|	*breed 	|		90		|		264 	|
			|					|					|					|					|
					^						^				^					^			
											pointers								

			*name = "Cujo"
			*breed = "Saint Bernard"

*/


