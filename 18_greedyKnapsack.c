// 05-03-26 Greedy Fractional Knapsack

#include <stdio.h>

struct Item {
    int weight;
    int profit;
    float ratio;
};

void sort(struct Item arr[], int n) {
    int i, j;
    struct Item temp;

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(arr[i].ratio < arr[j].ratio) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    float capacity, totalProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item arr[n];

    for(i = 0; i < n; i++) {
        printf("Enter weight and profit of item %d: ", i + 1);
        scanf("%d %d", &arr[i].weight, &arr[i].profit);

        arr[i].ratio = (float)arr[i].profit / arr[i].weight;
    }

    printf("Enter capacity of knapsack: ");
    scanf("%f", &capacity);

    sort(arr, n);

    for(i = 0; i < n; i++) {
        if(capacity >= arr[i].weight) {
            capacity = capacity - arr[i].weight;
            totalProfit = totalProfit + arr[i].profit;
        }
        else {
            totalProfit = totalProfit + arr[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum Profit = %.2f\n", totalProfit);

    return 0;
}
