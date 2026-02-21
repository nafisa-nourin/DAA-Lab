/*8.Construct a C program whose execution time follows
𝑇(𝑛)= 𝑛^3 + 𝑛log(𝑛) + 20
and simplify it to Big-O notation.  */

#include <stdio.h>

int main() {
    int n, i, j, k;
    int count = 0;

    printf("Enter n : ");
    scanf("%d", &n);

    /* n^3 operations */
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            for(k = 0; k < n; k++) {
                count++;
            }
        }
    }

    /* n log n operations */
    for(i = 0; i < n; i++) {
        for(j = 1; j < n; j = j * 2) {
            count++;
        }
    }

    /* 20 constant operations */
    for(i = 0; i < 20; i++) {
        count++;
    }

    printf("Total operations : %d\n", count);
    printf("Overall Big-O complexity : O(n^3)\n");

    return 0;
}

