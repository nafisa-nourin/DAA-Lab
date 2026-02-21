//10. build your own sorting algorithm [29-01-26]

#include <stdio.h>

int main()
{
    int A[] = {7, 3, 1, 9, 8, 2, 6, 4};
    int n = 8;
    int i, temp;
    int swapped;
    int pass = 1;

    do
    {
        swapped = 0;
        printf("Pass %d:\n", pass);

        // Step 1: sort inside pairs
        for (i = 0; i < n - 1; i += 2)
        {
            if (A[i] > A[i + 1])
            {
                temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
                swapped = 1;
            }
        }

        // Step 2: sort across pairs
        for (i = 1; i < n - 1; i += 2)
        {
            if (A[i] > A[i + 1])
            {
                temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
                swapped = 1;
            }
        }

        // Print array after this pass
        for (i = 0; i < n; i++)
        {
            printf("%d ", A[i]);
        }
        printf("\n\n");

        pass++;

    } while (swapped);

    return 0;
}