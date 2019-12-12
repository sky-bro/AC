#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// divide and conquer approach, slower and more spacious...
// https://leetcode.com/problems/maximum-subarray/discuss/20477/Sharing-my-divide-and-conquer-solution-using-C%2B%2B
class Solution {
private:
    int divideAndConquer(vector<int> A, int left, int right){
        if(left == right){
            return A[left];
        }
        if(left > right){
            return INT32_MIN;
        }
        int mid = left + (right - left) / 2;
        int maxLeft = 0;
        int sum = 0;
        for(int i = mid - 1; i >= left; i--){
            sum += A[i];
            maxLeft = max(maxLeft, sum);
        }
        int maxRight = 0;
        sum = 0;
        for(int i = mid + 1; i <= right; i++){
            sum += A[i];
            maxRight = max(maxRight, sum);
        }
        int maxSumWithMid = maxLeft + A[mid] + maxRight;
        return max(maxSumWithMid, max(divideAndConquer(A, left, mid - 1), divideAndConquer(A, mid + 1, right)));
    }
public:
    int maxSubArray(vector<int>& nums) {
        return divideAndConquer(nums, 0, nums.size()-1);
    }
};