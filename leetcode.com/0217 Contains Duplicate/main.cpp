#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        if (st.size() == nums.size()) return false;
        return true;
    }
};