// lesson nine on the c language


/*

		How a Linked List Works?

			-----------						-----------
			|					|						|					|
			|	Tomato	|						|	Potato	|
			|					|						|					|
			-----------					>	-----------					> Goes on and on and on till the next struct has point to next struct NULL
			|					|				 /	|					|				 /
			|	0.51		|				/		|	1.21		|				/
			|					|			 /		|					|			 /
			-----------			/			-----------			/
			|					|		 /			|					|		 /
			|	point		|		/				|	point		|		/
			|	to next	|	 /				|	to next	|	 /
			|	struct	|	/					|	struct	|	/
			|					|						|					|
			-----------						-----------

*/

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

int main(){

	inputData();
	inputData();
	inputData();

	outputData();
	return 0;
}
