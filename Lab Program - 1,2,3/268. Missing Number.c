int missingNumber(int* nums, int numsSize) {
    int sum = 0;
    for(int i=0;i<numsSize;i++){
        sum = sum + nums[i];
    }
    int rsum = numsSize*(numsSize+1)/2;
    return rsum - sum;
}
