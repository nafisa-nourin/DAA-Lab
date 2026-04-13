#include <stdio.h>

int fib(int n, int dp[]) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;

    // If already calculated, return stored value
    if (dp[n] != -1)
        return dp[n];

    // Store result and return
    dp[n] = fib(n-1, dp) + fib(n-2, dp);
    return dp[n];
}

int main() {
    int n, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    int dp[n];

    // Initialize array with -1
    for(i = 0; i < n; i++) {
        dp[i] = -1;
    }

    printf("Fibonacci Series: ");
    for(i = 0; i < n; i++) {
        printf("%d ", fib(i, dp));
    }

    return 0;
}
