
#define MAX(a,b) (((a)>(b))?(a):(b))

#define MAX(a,b) (((a)>(b))?(a):(b))

int maxSubArrayO3(int* nums, int numsSize) {
    int best =-999999;
    for (size_t i = 0; i < numsSize; i++){
        for (size_t j = i; i < numsSize; i++){
             int sum = 0;
             for (size_t k = j; i <= j; i++){
              sum += nums[i];
             }
              best = MAX(best,sum);
            }  
        }
    return best;
}

int maxSubArrayO2(int* nums, int numsSize) {
int best = -999999;
  for (int a = 0; a < numsSize; a++) {
    int sum = 0;
    for (int b = a; b < numsSize; b++) {
        sum += nums[b];
        best = max(best,sum);
    }
  }
}

int maxSubArrayO1(int* nums, int numsSize) {
 int best =-999999;
 int sum = -999999;
  for (size_t i = 0; i < numsSize; i++){
     sum  = MAX(nums[i],nums[i]+sum);
     best = MAX(best,sum);
  }
    return best;
}

