/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//Merge Sort
void mergeSort(int* nums, int low, int high);
void mergeArray(int* nums, int low, int mid, int high);

void mergeSort(int* nums, int low, int high) {
    if (low >= high) {
        return;
    }

    int mid = (low + high) / 2;


    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);


    mergeArray(nums, low, mid, high);
}

void mergeArray(int* nums, int low, int mid, int high) {
    int sFirst = mid - low + 1;
    int sSecond = high - mid;


    int* first = (int*)malloc(sizeof(int) * sFirst);
    int* second = (int*)malloc(sizeof(int) * sSecond);


    for (int i = 0; i < sFirst; i++) {
        first[i] = nums[low + i];
    }
    for (int i = 0; i < sSecond; i++) {
        second[i] = nums[mid + 1 + i];
    }

    int i = 0, j = 0, k = low;


    while (i < sFirst && j < sSecond) {
        if (first[i] <= second[j]) {
            nums[k] = first[i];
            i++;
        }
        else {
            nums[k] = second[j];
            j++;
        }
        k++;
    }


    while (i < sFirst) {
        nums[k] = first[i];
        i++;
        k++;
    }


    while (j < sSecond) {
        nums[k] = second[j];
        j++;
        k++;
    }


    free(first);
    free(second);
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    mergeSort(nums, 0, numsSize - 1);
    return nums;
}