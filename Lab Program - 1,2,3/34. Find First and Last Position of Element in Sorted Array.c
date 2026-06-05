/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *ans = (int*)malloc(2*(sizeof(int)));
    ans[0] = -1;
    ans[1] = -1;
    *returnSize = 2;
    for(int i=0,j=numsSize-1;i<numsSize && j>=0;i++,j--){
        if(nums[i]==target && ans[0]==-1){
            ans[0] = i;
        }
        if(nums[j]==target && ans[1]==-1){
            ans[1] = j;
        }
    }
    return ans;
}
