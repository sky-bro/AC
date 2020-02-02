#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        if (n == 0 || k == 0) return result;
        multiset<int, greater<int>> st;
        for (int i = 0; i < k; ++i) {
            st.insert(nums[i]);
        }
        result.push_back(*st.begin());
        for (int i = k; i < n; ++i) {
            st.erase(st.find(nums[i-k]));
            st.insert(nums[i]);
            result.push_back(*st.begin());
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {-7,-8,7,5,7,1,6,0};
    int k = 4;
    Solution s;

    s.maxSlidingWindow(nums, k);
    return 0;
}
