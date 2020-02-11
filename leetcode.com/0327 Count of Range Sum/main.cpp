#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ref: https://leetcode.com/problems/count-of-range-sum/discuss/77991/Short-and-simple-O(n-log-n)
class Solution {
private:
    int lower, upper;
    int merge_and_cnt(vector<long long>& nums, int lo, int mid, int hi) {
        int j1 = mid + 1, j2 = mid + 1, cnt = 0;
        for (int i = lo; i <= mid; ++i) {
            long long left = nums[i];
            for (; j1 <= hi && nums[j1] - left < lower; ++j1);
            for (; j2 <= hi && nums[j2] - left <= upper; ++j2);
            cnt += j2 - j1;
        }
        vector<long long> auxiliary;
        merge(nums.begin()+lo, nums.begin()+mid+1, nums.begin()+mid+1, nums.begin()+hi+1, back_inserter(auxiliary));
        for (long long num: auxiliary) {
            nums[lo++] = num;
        }
        return cnt;
    }
    int sort_and_cnt(vector<long long>& nums, int lo, int hi) {
        int cnt = 0;
        if (lo == hi) {
            if (nums[lo] <= upper && nums[lo] >= lower) return 1;
            else return 0;
        }
        int mid = lo + (hi - lo) / 2;
        cnt += sort_and_cnt(nums, lo, mid) + sort_and_cnt(nums, mid+1, hi);
        cnt += merge_and_cnt(nums, lo, mid, hi);
        return cnt;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        this->lower = lower;
        this->upper = upper;
        int n = nums.size();
        if (n == 0) return 0;
        vector<long long> nums_ll(n);
        nums_ll[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            nums_ll[i] = nums_ll[i-1] + nums[i];
        }
        return sort_and_cnt(nums_ll, 0, n-1);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {-2, 5, -1};
    int lower = -2, upper = 2;
    cout<<s.countRangeSum(nums, lower, upper)<<endl;

    nums = {2147483647,-2147483648,-1,0};
    lower = -1;
    upper = 0;
    cout<<s.countRangeSum(nums, lower, upper)<<endl;

    nums = {};
    lower = 0;
    upper = 0;
    cout<<s.countRangeSum(nums, lower, upper)<<endl;

    nums = {-2147483647,0,-2147483647,2147483647};
    lower = -564;
    upper = 3864;
    cout<<s.countRangeSum(nums, lower, upper)<<endl;

    return 0;
}
