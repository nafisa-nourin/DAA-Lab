/* 6. Write a c program that runs in 
T(n)=n log(n) + 5n + 10 and identify the dominant term.*/

#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j;
    int count = 0;

    printf("Enter n : ");
    scanf("%d", &n);

    //n log n operations 
    for(i = 0; i < n; i++) {
        for(j = 1; j <= n; j = j * 2) {
            count++;
        }
    }

    //5n operations 
    for(i = 0; i < 5 * n; i++) {
        count++;
    }

    // 10 constant operations
    for(i = 0; i < 10; i++) {
        count++;
    }

    printf("Total operations executed : %d\n", count);
    printf("Dominant term : n log n");

    return 0;
}
