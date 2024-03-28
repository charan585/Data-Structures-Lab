#include <stdio.h>


void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int* a, int* b);

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int i;

    printf("Original array: ");
    for (i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    quickSort(arr, 0, arr_size - 1);

    printf("Sorted array: ");
    for (i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        
        if (arr[j] < pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        
        int pi = partition(arr, low, high);

       
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
