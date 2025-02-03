#include <stdio.h>
#include <stdlib.h>

int main(){
	// r = read
	// w = write
	// a = append (add into)
	FILE* fpointer = fopen("employees.txt", "a");

	fprintf(fpointer, "Gavbriel, SS\nEva, xd\nAdan, ultraXD");

	fclose(fpointer);

	return 0;
}

