#include <iostream>
#include <vector>

using namespace std;

int arr1[100100], arr2[100100];

class Solution {
 private:
  int n;
  bool chk(vector<int>& nums, int i) {
    int sum1 = arr1[i];
    int sum2 = arr2[i];
    if (i & 1) {
      sum1 -= nums[i];
    } else {
      sum2 -= nums[i];
    }
    sum1 += arr2[n - 1] - arr2[i];
    sum2 += arr1[n - 1] - arr1[i];
    return sum1 == sum2;
  }

 public:
  int waysToMakeFair(vector<int>& nums) {
    int cnt = 0;
    n = nums.size();
    arr1[0] = 0, arr2[0] = nums[0];
    for (int i = 1; i < n; ++i) {
      if (i & 1) {
        arr1[i] = nums[i] + arr1[i - 1];
        arr2[i] = arr2[i - 1];
      } else {
        arr2[i] = nums[i] + arr2[i - 1];
        arr1[i] = arr1[i - 1];
      }
    }
    for (int i = 0; i < n; ++i) {
      cnt += chk(nums, i);
    }
    return cnt;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {2, 1, 6, 4};
    cout << s.waysToMakeFair(nums) << endl;
  nums = {1, 1, 1};
  cout << s.waysToMakeFair(nums) << endl;
  return 0;
}
