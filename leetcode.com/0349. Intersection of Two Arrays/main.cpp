#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin(), nums1.end());
        unordered_set<int> res;
        for (int num: nums2) {
            if (st.find(num) != st.end()) res.insert(num);
        }
        return vector<int>(res.begin(), res.end());
    }
};