#include <limits.h> // For INT_MIN
#include <stdlib.h> // For malloc
#include <stdio.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int areDistinct(int* nums, int start, int end) {
    int freq[100001] = { 0 };  
    for (int i = start; i <= end; i++) {
        freq[nums[i]]++;
        if (freq[nums[i]] > 1) {
            return 0;  
        }
    }
    return 1;  
}

long long maximumSubarraySum(int* nums, int numsSize, int k) {
    if (k > numsSize) {
        return 0; 
    }

    long long maxSum = 0;
    long long currentSum = 0;

    for (int i = 0; i <= numsSize - k; i++) {
        if (areDistinct(nums, i, i + k - 1)) {
            currentSum = 0;
            for (int j = i; j < i + k; j++) {
                currentSum += nums[j];
            }
            maxSum = MAX(maxSum, currentSum);
        }
    }
    return maxSum;
}

int main() {
    int nums[] = { 4, 2, 4, 5, 6 };
    int k = 3;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    long long result = maximumSubarraySum(nums, numsSize, k);
    printf("Maximum sum of distinct subarrays of length %d: %lld\n", k, result);

    return 0;
}

