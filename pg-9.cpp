#include <stdio.h>

int binarySearch(int array[], int size, int key);

int main() {
    int array[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(array) / sizeof(array[0]);
    int key, position;

    
    printf("Enter the number to search: ");
    scanf("%d", &key);


    position = binarySearch(array, size, key);

   
    if (position != -1) {
        printf("Element found at position %d\n", position + 1);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}


int binarySearch(int array[], int size, int key) {
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

       
        if (array[mid] == key) {
            return mid;
        }
        
        else if (key > array[mid]) {
            low = mid + 1;
        }
       
        else {
            high = mid - 1;
        }
    }

   
    return -1;
}
