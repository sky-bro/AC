#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// time: O(n), space: O(n)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(), i;
        vector<bool> _nums(n);
        for (auto x: nums) if (x <= n && x > 0) _nums[x-1] = true;
        for (i = 0; i < n && _nums[i]; ++i);
        return i+1;
    }
};

// time: O(n), space: O(1), does this counts as O(1) space, I his this implementation is bad
// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         int r = nums.size(), i;
//         for (i = 0; i < r;) {
//             if (nums[i] > r || nums[i] <= 0) swap(nums[i], nums[--r]);
//             else {
//                 int ind = nums[i]-1;
//                 if (nums[ind] == nums[i]) {
//                     if (i == ind) ++i;
//                     else nums[i++] = 0;
//                 } else {
//                     swap(nums[ind], nums[i]);
//                 }
//             }
//         }
//         for (i = 0; i < r && nums[i] == i + 1; ++i);
//         return i+1;
//     }
// };

// time: O(nlogn)
// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int i = 0, j = 1, n = nums.size();
//         for (; i < n && nums[i] <= 0; ++i);
//         for (; j + i - 1 < n && nums[j + i - 1] == j; ++j) {
//             for (;j + i < n && nums[j + i - 1] == nums[j + i]; ++i);
//         }
//         return j;
//     }
// };

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> vi = {1, 1};
    cout<<s.firstMissingPositive(vi)<<endl;
    return 0;
}
