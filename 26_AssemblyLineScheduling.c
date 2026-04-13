#include <stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int a1[] = {0, 12, 6, 7, 11};
    int a2[] = {11, 8, 9, 7, 8};

    int t1[] = {2, 3, 1, 3}; 
    int t2[] = {2, 1, 2, 2};  

    int e1 = 3, e2 = 5;   // entry
    int x1 = 2, x2 = 1;   // exit

    int n = 5;

    int f1[10], f2[10];
    
    f1[0] = e1 + a1[0];
    f2[0] = e2 + a2[0];

    for (int i = 1; i < n; i++) {
        f1[i] = min(f1[i-1] + a1[i], f2[i-1] + t2[i-1] + a1[i]);
        f2[i] = min(f2[i-1] + a2[i], f1[i-1] + t1[i-1] + a2[i]);
    }

    int result = min(f1[n-1] + x1, f2[n-1] + x2);

    printf("Minimum cost = %d\n", result);

    return 0;
}
