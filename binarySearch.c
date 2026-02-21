//2. 08-01-26 Binary Search

#include <stdio.h>

int main() {
    int n, i, key;
    int arr[100];
    int low, high, mid, pass = 1, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements in SORTED order:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while(low <= high) {
        mid = (low + high) / 2;

        printf("Pass %d: low=%d, high=%d, mid=%d, arr[mid]=%d\n",
               pass++, low, high, mid, arr[mid]);

        if(arr[mid] == key) {
            printf("Element found at position %d\n", mid + 1);
            found = 1;
            break;
        }
        else if(arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if(found == 0) {
        printf("Element not found\n");
    }

    return 0;
}