Medium 2
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
 
Example 1:
Input: nums = [3,2,3]
Output: [3]
Example 2:
Input: nums = [1]
Output: [1]

code:
#include <stdio.h>
#include <stdlib.h>

int* majorityElement(int* nums, int numsSize, int* returnSize) {
    if (nums == NULL || numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    
    int candidate1 = nums[0], count1 = 0;
    int candidate2 = nums[0], count2 = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) {
            count1++;
        } else if (nums[i] == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = nums[i];
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = nums[i];
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

   
    count1 = count2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) {
            count1++;
        } else if (nums[i] == candidate2) {
            count2++;
        }
    }

   
    int threshold = numsSize / 3;
    *returnSize = 0;
    int* result = (int*)malloc(sizeof(int) * 2);

    if (count1 > threshold) {
        result[(*returnSize)++] = candidate1;
    }
    if (count2 > threshold && candidate1 != candidate2) {
        result[(*returnSize)++] = candidate2;
    }

    return result;
}

int main() {
    // Example 1
    int nums1[] = {3, 2, 3};
    int size1;
    int* result1 = majorityElement(nums1, 3, &size1);
    printf("Example 1: [");
    for (int i = 0; i < size1; i++) {
        printf("%d", result1[i]);
        if (i < size1 - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    free(result1);

    // Example 2
    int nums2[] = {1};
    int size2;
    int* result2 = majorityElement(nums2, 1, &size2);
    printf("Example 2: [");
    for (int i = 0; i < size2; i++) {
        printf("%d", result2[i]);
        if (i < size2 - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    free(result2);

    return 0;
}
output:

Example 1: [3]
Example 2: [1]
