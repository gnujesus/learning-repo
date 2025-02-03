#include <stdio.h>
#include <stdlib.h>

int main(){
	size_t size = 0;

	printf("What's the size of the desired array? ");

	scanf("%zu",  &size);

	int* mPtr = (int*)malloc((int)size * sizeof(mPtr));

	int arr[size];

	for(int i = 0; i < sizeof(arr)/sizeof(int); i++){
		printf("Introduce the value number %d: ", i);
		scanf("%d", &arr[i]);
	}

	free(mPtr);
	printf("Finish\n\n");

	for(int i = 0; i < sizeof(arr)/sizeof(int); i++){
		printf("%d ", arr[i]);
	}

}
