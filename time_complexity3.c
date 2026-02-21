/*7. Write a C program that exhibits a time complexity of
𝑇(𝑛)=2𝑛^3 + 𝑛^2 + 7
and state its overall Big-O complexity.*/

#include <stdio.h>

int main() {
    int n, i, j, k;
    int count = 0;

    printf("Enter n : ");
    scanf("%d", &n);

    /* 2n^3 operations */
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            for(k = 0; k < n; k++) {
                count++;
                count++;
            }
        }
    }

    /* n^2 operations */
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            count++;
        }
    }

    /* 7 constant operations */
    for(i = 1; i <= 7; i++) {
        count++;
    }

    printf("Total operations executed : %d\n", count);
    printf("Overall Big-O complexity : O(n^3)\n");

    return 0;
}