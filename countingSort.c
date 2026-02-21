//17. 19-02-26 Counting Sort

#include <stdio.h>

void countingSort(int arr[], int n) {
    int i;
    int count[100] = {0};  
    int max = arr[0];

    for(i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }

    for(i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int index = 0;
    for(i = 0; i <= max; i++) {
        while(count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

int main() {
    int n, i;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements (non-negative integers):\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    countingSort(arr, n);

    printf("Sorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}