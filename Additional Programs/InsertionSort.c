#include <stdio.h>
#include <time.h>

void insertionSort(int arr[], int n)
{
    int i, key, j;

    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    int arr[100], n, i;
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nBefore Insertion Sort:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    start = clock();

    insertionSort(arr, n);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nAfter Insertion Sort:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\nTime taken = %f seconds\n", time_taken);

    return 0;
}
