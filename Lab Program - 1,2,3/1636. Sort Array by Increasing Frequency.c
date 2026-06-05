/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int freq(int k,int* num,int numsSize){
    int c = 0;
    for(int i=0;i<numsSize;i++){
        if(num[i]==k){c = c+1;}
    }
    return c;
}


int* frequencySort(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int *fa = (int*)malloc(numsSize*sizeof(int));

    for(int i=0;i<numsSize;i++){
        fa[i] = freq(nums[i],nums,numsSize);
    }
    for(int j=0;j<numsSize-1;j++){
        for(int k=0;k<numsSize-1;k++){
            if((fa[k]>fa[k+1]) || (fa[k]==fa[k+1] && nums[k]<nums[k+1])){
                int temp = nums[k];
                nums[k] = nums[k+1];
                nums[k+1] = temp;
                int tempf = fa[k];
                fa[k] = fa[k+1];
                fa[k+1] = tempf;

            }
        }
    }
    return nums;

}
