#include <stdio.h>

struct Item {
    int value;
    int weight;
};

void sortItems(struct Item arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            double r1 = (double)arr[j].value / arr[j].weight;
            double r2 = (double)arr[j + 1].value / arr[j + 1].weight;
            if (r1 < r2) {
                int tempval = arr[j].value;
                arr[j].value = arr[j+1].value;
                arr[j+1].value = tempval;
                int tempwt = arr[j].weight;
                arr[j].weight = arr[j+1].weight;
                arr[j+1].weight = tempwt;
            }
        }
    }
}

double fractionalKnapsack(struct Item arr[], int n, int capacity) {
    sortItems(arr, n);

    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity >= arr[i].weight) {
            capacity -= arr[i].weight;
            totalValue += arr[i].value;
        } else {
            totalValue += arr[i].value * ((double)capacity / arr[i].weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    int n, capacity, i;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item arr[n];

    printf("Enter value and weight of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].value, &arr[i].weight);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    double maxValue = fractionalKnapsack(arr, n, capacity);

    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}
