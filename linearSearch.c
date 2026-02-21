//1. 08-01-26 linear search

#include <stdio.h>

int main() {
    int n, i, key, found = 0;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++) {
        printf("Pass %d: Comparing %d with %d\n", i + 1, key, arr[i]);

        if(arr[i] == key) {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("Element not found\n");
    }

    return 0;
}