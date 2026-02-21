/*13.write down a sorting algorithm which has 
worst case recurrance relation T(n) = T(n-1) + n */

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high, int n, int *pass) {
    int pivot = arr[high];
    int i = low - 1;
    int j;

    for(j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);

    
    (*pass)++;
    printf("Pass %d: ", *pass);
    for(j = 0; j < n; j++)
        printf("%d ", arr[j]);
    printf("\n");

    return i + 1;
}

void quickSort(int arr[], int low, int high, int n, int *pass) {
    int pi;
    if(low < high) {
        pi = partition(arr, low, high, n, pass);

        quickSort(arr, low, pi - 1, n, pass);
        quickSort(arr, pi + 1, high, n, pass);
    }
}

int main() {
    int n, i;
    int arr[100];
    int pass = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, n - 1, n, &pass);

    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}