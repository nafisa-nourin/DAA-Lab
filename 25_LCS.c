#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    char X[] = "BCDAACD";
    char Y[] = "ACDBAC";

    int m = strlen(X);
    int n = strlen(Y);

    int L[20][20];

    // Build LCS table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = 1 + L[i-1][j-1];
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }

    // Print table
    printf("LCS Table:\n\n   ");
    for (int j = 0; j < n; j++)
        printf("%c ", Y[j]);
    printf("\n");

    for (int i = 0; i <= m; i++) {
        if (i == 0)
            printf("  ");
        else
            printf("%c ", X[i-1]);

        for (int j = 0; j <= n; j++) {
            printf("%d ", L[i][j]);
        }
        printf("\n");
    }

    // Length
    printf("\nLength of LCS = %d\n", L[m][n]);

    // Backtracking to find LCS string
    int i = m, j = n;
    char lcs[20];
    int index = L[m][n];
    lcs[index] = '\0';

    while (i > 0 && j > 0) {
        if (X[i-1] == Y[j-1]) {
            lcs[index-1] = X[i-1];
            i--;
            j--;
            index--;
        }
        else if (L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }

    printf("LCS String = %s\n", lcs);

    return 0;
}
