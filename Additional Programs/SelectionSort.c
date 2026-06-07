#include <stdio.h>
#include <time.h>

void selectionSort(int arr[], int n)
{
    int i, j, min, temp;

    for(i = 0; i < n - 1; i++)
    {
        min = i;

        for(j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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

    printf("\nBefore Selection Sort:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    start = clock();

    selectionSort(arr, n);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nAfter Selection Sort:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\nTime taken = %f seconds\n", time_taken);

    return 0;
}
