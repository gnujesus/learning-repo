#include <stdlib.h>
#include <stdio.h>
 
struct Rectangle {
	int length;
	int width;
};

int main(){

	// Pointers
	/*
	
	int a = 10;
	int *pointer_a = &a;

	*pointer_a = 2;

	printf("value of a: %d", a);
	printf("\n");
	printf("value of p a: %d", *pointer_a);

	*/

	// Memory Allocation
	/*
	int amount_of_elements = 5;
	int *p = (int *) malloc(amount_of_elements * sizeof(int));

	p[0] = 10;

	for(int i = 0; i < amount_of_elements; i++){
		printf("%d - ", p[i]);
	}

	p = NULL;
	free(p);
	*/

	// Point to structures
	struct Rectangle *r;
	r = (struct Rectangle *)malloc(sizeof(struct Rectangle));
	r->length = 10;
	r->width = 20;
	printf("length: %d\n", r->length);
	printf("width: %d\n", r->width);

	return 0;
}
