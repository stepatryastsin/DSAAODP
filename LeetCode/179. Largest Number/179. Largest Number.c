#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare(const void* a, const void* b) {
    char* str1 = *(char**)a;
    char* str2 = *(char**)b;

    char combo1[200], combo2[200];
    strcpy(combo1, str1);
    strcat(combo1, str2);

    strcpy(combo2, str2);
    strcat(combo2, str1);

    return strcmp(combo2, combo1);
}

char* largestNumber(int* nums, int numsSize) {
    char** numStrs = (char**)malloc(numsSize * sizeof(char*));
    for (int i = 0; i < numsSize; i++) {
        numStrs[i] = (char*)malloc(12 * sizeof(char));
        sprintf(numStrs[i], "%d", nums[i]);
    }

    qsort(numStrs, numsSize, sizeof(char*), compare);

    if (strcmp(numStrs[0], "0") == 0) {
        free(numStrs);
        return "0";
    }

    char* result = (char*)malloc(numsSize * 12 * sizeof(char));
    result[0] = '\0';
    for (int i = 0; i < numsSize; i++) {
        strcat(result, numStrs[i]);
        free(numStrs[i]);
    }
    free(numStrs);

    return result;
}