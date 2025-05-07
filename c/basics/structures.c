#include <stdio.h>


// A struct isn't more than a collection of data type that represent/define something
// For example: A rectangle is defined by it's length and width
// The total size of this rectangle is 4 bytes, but right now, it isn't taking any memory, since it hasn't been initialized and
// it's just a representation
struct Rectangle
{
	int length;
	int width;
};

struct ComplexNumber{
	int real;
	int imaginary;
};

struct Card {
	int face;
	int shape;
	int color;
};

// NOTE:: The computer automatically allocated 4 bytes for the char, but it only uses one.
struct SomeRandomStruct{
	int length; // 4 bytes
	int width;  // 4 bytes
	char x; // 4 bytes allocated, but only using one
}

int main(){
	//this, unlike the representation, is taking memory
	// declaration
	// struct Rectangle r;
	
	// initialization
	struct Rectangle r = {10, 5}; 

	// Array of structs
	struct Card deck[52]; 

	// dot operator to modify members 
	r.length = 9; 

	printf("%d", r.length * r.width);


}
