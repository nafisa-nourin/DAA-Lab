//11. Write a searching algorithm which follows T(n) = T(n/2) + c

#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;          // element found
        else if(arr[mid] < key)
            low = mid + 1;       // search right half
        else
            high = mid - 1;      // search left half
    }
    return -1;                   // element not found
}

int main() {
    int n, i, key, pos;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements in sorted order:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    pos = binarySearch(arr, n, key);

    if(pos != -1)
        printf("Element found at position %d\n", pos + 1);
    else
        printf("Element not found\n");

    return 0;
}