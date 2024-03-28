#include <stdio.h>

#define MAX_SIZE 100


void insertElement(int array[], int *size, int element, int position);
void deleteElement(int array[], int *size, int position);
void displayArray(int array[], int size);

int main() {
    int array[MAX_SIZE];
    int size = 0;

   
    insertElement(array, &size, 10, 0);
    insertElement(array, &size, 20, 1);
    insertElement(array, &size, 30, 2);


    printf("Array after insertion: ");
    displayArray(array, size);

   
    deleteElement(array, &size, 1);

  
    printf("Array after deletion: ");
    displayArray(array, size);

    return 0;
}


void insertElement(int array[], int *size, int element, int position) {
    if (*size >= MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }

    if (position < 0 || position > *size) {
        printf("Invalid position.\n");
        return;
    }

   
    for (int i = *size - 1; i >= position; i--) {
        array[i + 1] = array[i];
    }

  
    array[position] = element;
    (*size)++;
}


void deleteElement(int array[], int *size, int position) {
    if (*size <= 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }

    if (position < 0 || position >= *size) {
        printf("Invalid position.\n");
        return;
    }

    
    for (int i = position; i < *size - 1; i++) {
        array[i] = array[i + 1];
    }

    (*size)--;
}


void displayArray(int array[], int size) {
    if (size <= 0) {
        printf("Array is empty.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
