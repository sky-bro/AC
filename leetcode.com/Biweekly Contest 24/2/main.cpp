#include <bits/stdc++.h>

#include "leetcode.hpp"
using namespace std;

class Solution {
 public:
  int findMinFibonacciNumbers(int k) {
    vector<int> nums = {1, 1};
    for (int i = 3; i <= 44; ++i) {
      int num = nums.back() + nums[nums.size() - 2];
      nums.push_back(num);
    }
    // printArr(nums);
    // cout << "size:" << nums.size() << endl;
    reverse(nums.begin(), nums.end());
    int n = nums.size();
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i] <= k) {
        int cnt = k / nums[i];
        res += cnt;
        k -= cnt * nums[i];
      }
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  int a = 1, b = 1;
  int n = 2;
  int M = 1e9;
  while (b < M) {
    int c = a + b;
    a = b;
    b = c;
    ++n;
  }
  cout << n << endl;
  cout << b << endl;
  Solution s;
  int num;
  while (cin >> num) cout << s.findMinFibonacciNumbers(num) << endl;
  return 0;
}
