// Lesson five on the C Language

// STRUCTS
// Struct is used when you need more then one piece of data to
// describe one thing. You may ask why not to use array? Remember,
// we can use arrays with only one data type.

#include <stdio.h>

// Can we create struct inside of the another struct? YES, we can.

// Favorites for dogs
struct dogsFavs{
	char *food;
	char *friend;
};

// We don't have to write 'struct' over and over again.
// We can use something that is called 'typedef'.
// and take 'dog' - the name we reffere to and type
// it in the end.
typedef struct dog{
	const char *name;
	const char *breed;
	int avgHeightCm;
	int avgWeightLbs;

	// Now we want to use dog favoriets here - inside this struct
	// Just type the next:
	struct dogsFavs favouriteThings;

} dog; // Here at the end


// Now even HERE you can type dog without word 'struct' because of typedef
void getDogsFavs(dog theDog){

	printf("\n");

	// Here we are going to use chaining with . operator
	printf("%s loves %s and his friend is %s\n\n",
					theDog.name,
					theDog.favouriteThings.food,
					theDog.favouriteThings.friend);

}

void setDogWeight(dog theDog, int newWeight){
	theDog.avgWeightLbs = newWeight;

	// Note here we are not using ampersent to change the weight
	printf("The weight was changed to %d\n\n", theDog.avgWeightLbs);
}

void main(){

	// Earlier we should to type 'struct dog *name'.
	// But now, because of the typedef we can type only 'dog'
	dog benji = {"Benji", "Silky Terrier", 25, 9, {"Meat", "Joe Camp"}};

	getDogsFavs(benji);

	// The weight will change
	setDogWeight(benji, 11);
	printf("The weight in main() %d\n\n", benji.avgWeightLbs);
	// But in main the weight will not change it's value
	// It is all because old struct was created first (benji struct has value of 9).
	// An then, when function sets new value, new struct is creating in the memory,
	// so we will see changed value in the function, but not changed in the main function.
	// So how we can fix this? We are going to use pointers.
	// See the changes in the file l5_all_about_structs3.c

}
