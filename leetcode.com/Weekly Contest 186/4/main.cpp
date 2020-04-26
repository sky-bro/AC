#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int res = nums[0], n = nums.size();
        vector<int> dp;
        dp.push_back(nums[0]);
        multiset<int> st;
        st.insert(-nums[0]);
        for (int i = 1; i < n; ++i) {
          int num = *st.begin();
          if (num < 0) dp.push_back(nums[i]-num);
          else dp.push_back(nums[i]);
          st.insert(-dp.back());
          if (i - k >= 0) {
            auto it = st.find(-dp[i-k]);
            st.erase(it);
          }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main(int argc, char const *argv[])
{
  Solution s;
  vector<int> nums = {10,-2,-10,-5,20}; int k  =2;
  cout<<s.constrainedSubsetSum(nums, k)<<endl;
  return 0;
}
