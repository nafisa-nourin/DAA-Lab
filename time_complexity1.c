//5. Write a c program whose time complexity is exactly T(n)=3n²+2n+4

#include <stdio.h>

int main() {
    int n, i, j;
    int count = 0;

    printf("Enter n : ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            count++;
            count++;
            count++;
        }
    }

    for(i = 0; i < n; i++) {
        count++;
        count++;
    }

    count++;
    count++;
    count++;
    count++;

    printf("Total operations executed : %d\n", count);

    return 0;
}