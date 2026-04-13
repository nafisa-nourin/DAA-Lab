/*12. write down a sorting algorithm which has 
worst case recurrance relation T(n) = 2T(n/2) + n
*/

#include <stdio.h>

void merge(int arr[], int low, int mid, int high, int n, int pass) {
    int i = low, j = mid + 1, k = low;
    int temp[100];

    while(i <= mid && j <= high) {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= mid)
        temp[k++] = arr[i++];

    while(j <= high)
        temp[k++] = arr[j++];

    for(i = low; i <= high; i++)
        arr[i] = temp[i];

    printf("Pass %d: ", pass);
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void mergeSort(int arr[], int low, int high, int n, int *pass) {
    int mid;
    if(low < high) {
        mid = (low + high) / 2;

        mergeSort(arr, low, mid, n, pass);
        mergeSort(arr, mid + 1, high, n, pass);

        (*pass)++;
        merge(arr, low, mid, high, n, *pass);
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

    mergeSort(arr, 0, n - 1, n, &pass);

    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
