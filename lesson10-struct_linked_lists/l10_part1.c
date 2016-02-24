// lesson nine on the c language

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
	float price;
	char productName[30];

	struct product *next;
};

struct product *pFirstNode = NULL;
struct product *pLastNode = NULL;


void createNewList(){
	struct product *pNewStruct = (struct product *) malloc(sizeof(struct product));

	pNewStruct->next = NULL;

	printf("Enter product name: ");
	scanf("%s", &(pNewStruct)->productName);

	printf("Enter product price: ");
	scanf("%f", &(pNewStruct)->price);

	// When we are creating new struct we are going to be sure
	// that our first node is our last node and it is also
	// our new node.
	pFirstNode = pLastNode = pNewStruct;
}


void inputData(){

	// If our first node in the list has point to the next struct NULL value
	// we want to initialize a function that will create this new list
	if(pFirstNode == NULL){
		createNewList();
	} else {
		struct product *pNewStruct = (struct product *) malloc(sizeof(struct product));

		printf("Enter product name: ");
		scanf("%s", &(pNewStruct)->productName);

		printf("Enter product price: ");
		scanf("%f", &(pNewStruct)->price);

		// Now we want work with the second struct in the list
		if(pFirstNode == pLastNode){
			// Here we place point to next struct our pNewStruct
			pFirstNode->next = pNewStruct;
			// But then our pLastNode is this new struct
			pLastNode = pNewStruct;
			// And also we need to put NULL value inside 'point to next struct' for this last struct
			pNewStruct->next = NULL;
		} else {
			// Here we will work with not the first, not the second
			// but the third and every other node thereafter
			pLastNode->next = pNewStruct;
			// Since it is last item in the list - next is equal to null
			pNewStruct->next = NULL;

			pLastNode = pNewStruct;
		}
	}

}

void outputData(){
	// To output data we need to move through all the
	// product structs in our list untill the last 
	// pinter will be NULL
	struct product *pProducts = pFirstNode;

	printf("Products entered: \n\n");

	while(pProducts != NULL){
		printf("%s costs %.2f\n", pProducts->productName, pProducts->price);
		// After printing out and continue looping through the list
		// we are going to change the location
		pProducts = pProducts->next;
	}

}

// We are going to create global for the function productToDelete
struct product *pProductBeforeProductToDelete = NULL;

// This function is going to return struct because then we are going to find and
// delete set product. It is going to receive product name
//
struct product* searchForProduct(char * productName){
	// We are going to create new struct that is holding
	// our struct as we cycling through all of them.
	struct product *pProductIterator = pFirstNode;
	while(pProductIterator != NULL){
		// We are going to compare the first 30 characters of the product names
		// 30 characters comes from the value we set at the very begining
		// when we created struct for a product 'char productName[30]'
		int areTheyEqual = strncmp(pProductIterator->productName, productName, 30);

		// NOTE: we need to place '!' (not operator) because strncmp returns
		// '0' (zero) if it will find a match
		if(!areTheyEqual){
			printf("%s was found and it costs %.2f\n\n",
						pProductIterator->productName,
						pProductIterator->price
						);

			return pProductIterator;
		}

		// We are assigning pProductBeforeProductToDelete before pProductIterator
		// will change it's value.
		pProductBeforeProductToDelete = pProductIterator;
		// We are changing the pProductIterator to the next product
		pProductIterator = pProductIterator->next;

	}

	printf("%s wasn't found\n\n", productName);
	// In this way we have to return something so we return NULL
	return NULL;
}

void removeProduct(char * productName){
	struct product *pProductToDelete = NULL;
	pProductToDelete = searchForProduct(productName);
	if(pProductToDelete != NULL){
		printf("%s was deleted\n\n", productName);
		// And if this product is the first product in our list
		// and we want it to delete we must define the next product in the list
		// to the first node.
		if(pProductToDelete == pFirstNode){
			pFirstNode = pProductToDelete->next;
		} else {
			// We need to got pProductToDelete and assigned it next to the product
			// that before the product is deleted
			pProductBeforeProductToDelete->next = pProductToDelete->next;
		}

		free(pProductToDelete);
	} else {
		// If we did not find a product
		printf("%s was not found", productName);
	}
}


int main(){

	inputData();
	inputData();
	inputData();

	outputData();

	removeProduct("Tomato");

	outputData();

	return 0;
}
