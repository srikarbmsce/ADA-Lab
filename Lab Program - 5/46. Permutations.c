/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced.
 */

#include <stdlib.h>
#include <string.h>

#define LEFT -1
#define RIGHT 1

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int getMobile(int* perm, int* dir, int n) {

    int mobile = -1;
    int mobileIndex = -1;

    for (int i = 0; i < n; i++) {

        if (dir[i] == LEFT && i > 0 && perm[i] > perm[i - 1]) {
            if (perm[i] > mobile) {
                mobile = perm[i];
                mobileIndex = i;
            }
        }

        if (dir[i] == RIGHT && i < n - 1 && perm[i] > perm[i + 1]) {
            if (perm[i] > mobile) {
                mobile = perm[i];
                mobileIndex = i;
            }
        }
    }

    return mobileIndex;
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    int total = 1;
    for (int i = 1; i <= numsSize; i++)
        total *= i;

    int** result = (int**)malloc(total * sizeof(int*));
    *returnColumnSizes = (int*)malloc(total * sizeof(int));

    int* sorted = (int*)malloc(numsSize * sizeof(int));
    memcpy(sorted, nums, numsSize * sizeof(int));
    qsort(sorted, numsSize, sizeof(int), cmp);

    int* perm = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++)
        perm[i] = i + 1;

    int* dir = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++)
        dir[i] = LEFT;

    *returnSize = 0;

    while (1) {

        result[*returnSize] = (int*)malloc(numsSize * sizeof(int));

        for (int i = 0; i < numsSize; i++) {
            result[*returnSize][i] = sorted[perm[i] - 1];
        }

        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;

        int mobileIndex = getMobile(perm, dir, numsSize);

        if (mobileIndex == -1)
            break;

        int swapIndex = mobileIndex + dir[mobileIndex];

        int temp = perm[mobileIndex];
        perm[mobileIndex] = perm[swapIndex];
        perm[swapIndex] = temp;

        temp = dir[mobileIndex];
        dir[mobileIndex] = dir[swapIndex];
        dir[swapIndex] = temp;

        mobileIndex = swapIndex;
        int mobileValue = perm[mobileIndex];

        for (int i = 0; i < numsSize; i++) {
            if (perm[i] > mobileValue)
                dir[i] *= -1;
        }
    }

    free(sorted);
    free(perm);
    free(dir);

    return result;
}
