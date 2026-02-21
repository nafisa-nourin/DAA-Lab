/*9.Write a C program using nested loop whose exact time complexity is
𝑇(𝑛)= 𝑛(𝑛+1)/2
and determine its asymptotic complexity. */

#include <stdio.h>

int main() {
    int n, i, j;
    int count = 0;

    printf("Enter n = ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= i; j++) {
            count++;
        }
    }

    printf("Total operations : %d\n", count);
    printf("Asymptotic complexity : O(n^2)\n");

    return 0;
}