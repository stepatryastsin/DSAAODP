#define MAX(a,b) (((a)>(b))?(a):(b))
int maxSubArray(int* nums, int numsSize) {
    int best =-999999;
    int sum = -999999;
    for (size_t i = 0; i < numsSize; i++){
     sum  = MAX(nums[i],nums[i]+sum);
     best = MAX(best,sum);
    }
    return best;
}
