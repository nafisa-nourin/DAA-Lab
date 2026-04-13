#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n = 4; 

    int profit[] = {0, 2, 4, 7, 10};
    int weight[] = {0, 1, 3, 5, 7};

    int W = 8; 

    int dp[10][10]; 
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0; 
            else if (weight[i] <= w)
                dp[i][w] = max(dp[i-1][w],
                               profit[i] + dp[i-1][w - weight[i]]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    printf("DP Table:\n");
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            printf("%d ", dp[i][w]);
        }
        printf("\n");
    }
    printf("\nMaximum Profit = %d\n", dp[n][W]);

    return 0;
}
