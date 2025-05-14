#include <stdio.h>
#include <stdlib.h>
#include <string.h>  

typedef struct DictionaryItem{
	char key[100];
	char value[100];
} DictionaryItem;

typedef struct Dictionary{
	DictionaryItem* items;
	size_t size;
} Dictionary;



void printItems(Dictionary dictionary) {
    // Loop through the dictionary items based on the size
    for (int i = 0; i < dictionary.size; i++) {
        printf("Key: %s, Value: %s\n", dictionary.items[i].key, dictionary.items[i].value);
    }
}


int main(){

    // Create dictionary
    Dictionary dictionary;

    // Set capacity
    size_t capacity = 10;

    // Set size
    dictionary.size = 2;

    // Allocate memory for 10 dictionary items 
    dictionary.items = malloc(sizeof(DictionaryItem) * capacity);

    // Use strcpy to copy string literals into the key and value arrays
    strcpy(dictionary.items[0].key, "1");    // Copy "1" into the first item key
    strcpy(dictionary.items[0].value, "Jordan");  // Copy "Jordan" into the first item value

    strcpy(dictionary.items[1].key, "2");    // Copy "2" into the second item key
    strcpy(dictionary.items[1].value, "Kobe");   // Copy "Kobe" into the second item value

    // Print the items
    printItems(dictionary);

    // Free the allocated memory
    free(dictionary.items);

    return 0;

}
