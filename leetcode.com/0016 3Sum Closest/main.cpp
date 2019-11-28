#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // nums.size() >= 3
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int min_diff_sum = nums[0] + nums[1] + nums[2];
        int min_diff = abs(min_diff_sum - target);
        
        int tmp_sum, tmp_diff;
        for (int i = 0; i < n - 2; ++i) {
            if (nums[i]*3 - target >= min_diff) break;
            int l = i + 1, r = n - 1;
            for (;l < r;){
                tmp_sum = nums[l] + nums[r] + nums[i];
                if (tmp_sum > target) {
                    --r;
                    tmp_diff = tmp_sum - target;
                    if (tmp_diff < min_diff) {
                        min_diff_sum = tmp_sum;
                        min_diff = tmp_diff;
                    }
                } else if (tmp_sum < target) {
                    ++l;
                    tmp_diff = target - tmp_sum;
                    if (tmp_diff < min_diff) {
                        min_diff_sum = tmp_sum;
                        min_diff = tmp_diff;
                    }
                } else {
                    return tmp_sum;
                }
            }
        }
        return min_diff_sum;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v({1,1,1,0});
    cout<<s.threeSumClosest(v, 100)<<endl;
    return 0;
}
