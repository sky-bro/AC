#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() <= k + 1) {
            unordered_set<int> st(nums.begin(), nums.end());
            if (st.size() < nums.size()) return true;
            return false;
        }

        unordered_set<int> st(nums.begin(), nums.begin()+k+1);
        if (st.size() <= k) return true;
        for (int i = k + 1; i < nums.size(); ++i) {
            st.erase(nums[i-k-1]);
            st.insert(nums[i]);
            if (st.size() <= k) return true;
        }
        return false;
    }
};