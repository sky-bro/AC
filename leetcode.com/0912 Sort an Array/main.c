#include <memory.h>
// #include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
  int t = *b;
  *b = *a;
  *a = t;
}

void quick_sort(int* nums, int l, int r) {
  if (l >= r) return;
  int target = nums[rand() % (r - l + 1) + l];
  int i = l, low = l, high = r;
  while (i <= high) {
    if (nums[i] == target) {
      ++i;
    } else if (nums[i] < target) {
      swap(&nums[i++], &nums[low++]);
    } else {
      swap(&nums[i], &nums[high--]);
    }
  }
  quick_sort(nums, l, low - 1);
  quick_sort(nums, high + 1, r);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize) {
  quick_sort(nums, 0, numsSize - 1);
  *returnSize = numsSize;
  return nums;
}
