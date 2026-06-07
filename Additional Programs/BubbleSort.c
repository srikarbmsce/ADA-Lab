#include <stdio.h>
#include <time.h>

void bubbleSort(int arr[], int n)
{
    int i, j, temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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

    printf("\nBefore Bubble Sort:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    start = clock();

    bubbleSort(arr, n);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nAfter Bubble Sort:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\nTime taken = %f seconds\n", time_taken);

    return 0;
}
