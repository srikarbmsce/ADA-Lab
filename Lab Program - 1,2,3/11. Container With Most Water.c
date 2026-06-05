int max(int i,int j){
    if(i>=j){return i;}
    return j;
}
int min(int i,int j){
    if(i<=j){return i;}
    return j;
}

int maxArea(int* height, int heightSize) {
    int ans = 0;
    int left = 0;
    int right = heightSize-1;

    while(left<right){
        int crr = (right-left)*min(height[left],height[right]);
        ans = max(ans,crr);
        if(height[left]<height[right]){
            left++;
        }
        else{
            right--;
        }
    }
    return ans;
}
