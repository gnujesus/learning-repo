#include <stdio.h>
 
int main(){
	// Allocate memory for 5 integers
	// Must be explicitly type casted, since malloc returns a void *
	int *p = (int *) malloc(5 * sizeof(int));

	return 0;
}
