#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int n = nums.size(), prod = 1, ans = 0, left = 0;
        for (int i = 0; i < n; i++) {
            prod *= nums[i];
            while (prod >= k) prod /= nums[left++];
            ans += i - left + 1;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
  Solution s;
  vector<int> nums = {10,5,2,6};
  int k = 100;
  cout<<s.numSubarrayProductLessThanK(nums, k)<<endl;
  return 0;
}

