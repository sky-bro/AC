#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), res= 0, cur = 1;
        while (r < n) {
          cur *= nums[r];
          if (cur < k) {
            ++r;
          } else if (l == r) {
            ++l;
            ++r;
            cur = 1;
          } else {
            res += r - l;
            cur /= nums[r] * nums[l++];
          }
        }
        return res + (r - l) * (r - l + 1) / 2;
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

