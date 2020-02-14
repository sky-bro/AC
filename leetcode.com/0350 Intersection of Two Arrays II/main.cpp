#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_multiset<int> st(nums1.begin(), nums1.end());
        vector<int> res;
        for (int num: nums2) {
            auto it = st.find(num);
            if (it != st.end()) {
                res.push_back(*it);
                st.erase(it);
            }
        }
        return res;
    }
};