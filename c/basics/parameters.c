// #include <stdio.h>
//
// // Pass by address
// void addressSwap(int *x, int *y){
// 	*x = *y + *x;
// 	*y = *x - *y;
// 	*x = *x - *y;
// }
//
// // Pass by value (actual value is not modified)
// void valueSwap(int x, int y){
//
// }
//
// int main(){
//
// 	int a, b;
// 	a = 3;
// 	b = 7;
//
// 	addressSwap(&a, &b);
//
// 	printf("%d, %d", a, b);
//
// 	return 0;
// }
//
//
//
//
//

#include <stdio.h>

Function to swap two integers using references
void swap(int& a, int& b) {
    a = a + 1;
    b = b + 1;
}

void example(int *a, int *b){
	*a = *a+1;
	*b = *b+1;
}

int main() {
    int x = 10;
    int y = 20;

    swap(x, y);

    printf("%d, %d", x, y);

    return 0;
}

