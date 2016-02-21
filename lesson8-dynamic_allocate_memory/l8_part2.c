// lesson eight on the c language

#include <stdio.h>
#include <stdlib.h>


// We are going to dynamicly allocate memory for structs
struct product{

	float price;
	char productName[30];

};

int main() {

	// So, we are going to create pointer to a struct
	struct product *pProducts;

	// Then we are going to create some junk variables
	// to iterate through this guy.
	int i, j;

	int numberOfProducts;

	printf("Enter the number of products to store: \n\n");
	scanf("%d", &numberOfProducts);

	// Then we are going to get our pointer
	// and point to the address for the memory that we are gonna have
	// the memory allocatot allocate for.
	pProducts = (struct product *) malloc(numberOfProducts * sizeof(struct product));

	// It will cycle through and store inside the data
	for(i = 0; i < numberOfProducts; ++i){

		printf("Enter a product name: \n\n");
		// We are going to use pointer arithmetic this time to cycle
		// through our data. We are gonna be getting ourselves a string (%s).
		// &(pProducts + 1) is using pointer arithmetic.
		// And then we are just pointing to product name, using arrow (->).
		scanf("%s", &(pProducts + i)->productName);

		// The same thing we are going to do with price.
		printf("Enter a product price: \n\n");
		scanf("%f", &(pProducts + i)->price);

	}

	printf("Products stored: \n\n");

	for(j = 0; j < numberOfProducts; ++j) {
		printf("%s\t%.2f\n"
					, (pProducts + j)->productName
					, (pProducts + j)->price
					);
	}

	// Because we are the GOOD PROGRAMMERS ;)
	// We are going to use free() function and
	// free our pointer.
	free(pProducts);


	return 0;

}
