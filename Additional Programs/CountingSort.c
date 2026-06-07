#include <stdio.h>
#include <time.h>

void countingSort(int arr[], int n)
{
    int i, max = arr[0];

    for(i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }

    int count[max + 1];

    for(i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    for(i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    int index = 0;

    for(i = 0; i <= max; i++)
    {
        while(count[i] > 0)
        {
            arr[index] = i;
            index++;
            count[i]--;
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

    printf("\nBefore Counting Sort:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    start = clock();

    countingSort(arr, n);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nAfter Counting Sort:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\nTime taken = %f seconds\n", time_taken);

    return 0;
}
