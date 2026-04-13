//4. 08-01-26 Modified Bubble Sort

#include <stdio.h>

int main() {
    int n, i, j, temp;
    int arr[100];
    int swapped;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n - 1; i++) {
        swapped = 0;   // flag reset

        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;   // swap happened
            }
        }

        printf("Pass %d: ", i + 1);
        for(j = 0; j < n; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");

        // If no swap, array is already sorted
        if(swapped == 0) {
            printf("No swapping in this pass, array already sorted\n");
            break;
        }
    }

    printf("Sorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
