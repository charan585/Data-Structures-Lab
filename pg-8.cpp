#include <stdio.h>

#define MAX_SIZE 100


int linearSearch(int array[], int size, int key);

int main() {
    int array[MAX_SIZE];
    int size, key, position;

   
    printf("Enter size of the array: ");
    scanf("%d", &size);

    
    printf("Enter elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

   
    printf("Enter the number to search: ");
    scanf("%d", &key);

    
    position = linearSearch(array, size, key);

   
    if (position != -1) {
        printf("Element found at position %d\n", position + 1);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}


int linearSearch(int array[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (array[i] == key) {
            return i; 
        }
    }
    return -1; 
}
