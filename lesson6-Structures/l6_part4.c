// Lesson six on the C Language

#include <stdio.h>

typedef struct product {
	// -------------^----------------------
	// That is why we have name 'product' also here and at the end
	// because we are referrencing to the product, when we use
	// 'struct product *next' - so we need this also.

	// We create a little store.
	// And we want to track all the different
	// product we have and their price.
	const char *name;
	float price;

	// LINKED LIST
	// Basiclly a linked list can store an unlimited number of items.
	// And it calls a linked list, because it can store an information
	// that links name and price (of the product). But it is also gonna
	// have a link which is gonna be a pointer to the next struct in
	// the list. That is going to create a recursive structure - just a
	// link list that has a bunch of structs inside of it.
	struct product *next;

	// Another side benefit to link list is that you can insert new item
	// into pretty much any place in the list, if you decide to reorder
	// it. It is also pretty easy to put items inside of it.

} product; // REMEMBER also to put here the name if you want to do type definition



void printLinkedList(product *pProduct){
	while(pProduct.next != NULL) {
		// There are multiple different ways to print out these structs
		// We may use struct name 												(*varName).
		// And also we may use a little arrow notation 		->
		printf("A %s costs %.2f\n\n"
					, (*pProduct).name 													// One method
					, pProduct->price 													// Second method
					);

		pProduct = pProduct->next;

	}
}

void main(){

	// You might say why don't you go and just type:
	// product theProduct[20];
	// ...and create for ourselves an array?

	// And there is a big problem about that - an array has a fixed length.
	// A LIST is something that has not a fixed lenght.
	// That is known as a LINKED LIST.

	product tomato = {"Tomato", .51, NULL};
	// NULL - it means we have to put link to the next struct in the
	// list, but it doesn'n exists yet.
	product tomato = {"Tomato", .51, NULL};
	product potato = {"Potato", 1.21, NULL};
	product lemon = {"Lemon", 1.61, NULL};
	product milk = {"Milk", 3.09, NULL};
	product turkey = {"Turkey", 1.86, NULL};

	// Now we have to turn them into link list.
	// We use next pointer to give a link to the
	// next struct in the linked list.
	// And we need to do this 4 times, because the fifth item (turkey),
	// will be the last one and it has no next linked structure
	tomato.next = &potato;
	potato.next = &lemon;
	lemon.next = &milk;
	milk.next = &turkey;


	// Imagine, that you want to have apples in your list. But you don't
	// want apples to be after turkey. You want apples to be after lemons
	// for example.
	// So create an apple struct.
	product apple = {"Apple", 1.58, NULL};

	// Reassign next for milk
	lemon.next = &apple;
	// Assign next for apple
	apple.next = &milk;


	// Now let's print this information out to test if all is right
	printLinkedList(&tomato);

	// Why we put here a tomato? Because tomato is the first item,
	// and we want to print out all the next items in this case.
	// So, it is gonna be right to start from the first item.







}