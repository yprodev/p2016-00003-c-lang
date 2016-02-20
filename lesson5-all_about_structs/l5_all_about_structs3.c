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

typedef struct dog{
	const char *name;
	const char *breed;
	int avgHeightCm;
	int avgWeightLbs;
	struct dogsFavs favouriteThings;

} dog;

void getDogsFavs(dog theDog){
	printf("\n");
	printf("%s loves %s and his friend is %s\n\n",
					theDog.name,
					theDog.favouriteThings.food,
					theDog.favouriteThings.friend);

}

// Here we have to add an asterisk to get exact location of
// 
void setDogWeightPtr(dog *theDog, int newWeight){
	// The same thing we need to do with theDog down here
	// And when you are dealing with structs we have to surround
	// them with parentacies. Just a rule. There is actually anather
	// way to do it.
	(*theDog).avgWeightLbs = newWeight;
	// And then when you reffere to this information, you also should
	// use parentacies.
	printf("The weight was changed to %d\n\n", (*theDog).avgWeightLbs);

	// There is also another way to do this. We can rid of parentacies and
	// asterisk. Specificly when you use data in size of a struck, you
	// can go and draw like a little arrow inside of it.
	printf("The weight was changed to %d\n\n", theDog->avgWeightLbs);
	// ----------------------------------------------^^^------------
	// It means avgWeightLbs in the struct - theDog
}

void main(){

	dog benji = {"Benji", "Silky Terrier", 25, 9, {"Meat", "Joe Camp"}};

	// setDogWeightPtr - which refferes to pointer
	// We have just to add ampercent to benji argument
	setDogWeightPtr(&benji, 11);
	printf("The weight in main() %d\n\n", benji.avgWeightLbs);

}