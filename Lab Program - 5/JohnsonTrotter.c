#include <stdio.h>https://github.com/srikarbmsce/ADA-Lab/tree/main/Lab%20Program%20-%204

#define LEFT 0
#define RIGHT 1

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int getLargestMobile(int arr[], int dir[], int n) {
    int largestMobile = -1;
    int index = -1;
    for(int i = 0; i < n; i++) {
        if (dir[i] == LEFT && i != 0 && arr[i] > arr[i-1]) {
            if(arr[i] > largestMobile) {
                largestMobile = arr[i];
                index = i;
            }
        } else if (dir[i] == RIGHT && i != n-1 && arr[i] > arr[i+1]) {
            if(arr[i] > largestMobile) {
                largestMobile = arr[i];
                index = i;
            }
        }
    }
    return index;
}


void reverseDirection(int arr[], int dir[], int n, int largest) {
    for(int i = 0; i < n; i++) {
        if(arr[i] > largest) {
            dir[i] = 1 - dir[i];
        }
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int dir[n];


    for(int i = 0; i < n; i++) {
        arr[i] = i + 1;
        dir[i] = LEFT;
    }

    printArray(arr, n);

    while(1) {
        int largestIndex = getLargestMobile(arr, dir, n);
        if(largestIndex == -1) break;


        int swapIndex = (dir[largestIndex] == LEFT) ? largestIndex - 1 : largestIndex + 1;
        int temp = arr[largestIndex];
        arr[largestIndex] = arr[swapIndex];
        arr[swapIndex] = temp;


        int tempDir = dir[largestIndex];
        dir[largestIndex] = dir[swapIndex];
        dir[swapIndex] = tempDir;

        reverseDirection(arr, dir, n, arr[swapIndex]);

        printArray(arr, n);
    }

    return 0;
}
