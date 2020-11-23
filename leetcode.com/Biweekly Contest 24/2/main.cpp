#include <bits/stdc++.h>

#include "leetcode.hpp"
using namespace std;

class Solution {
 public:
  int findMinFibonacciNumbers(int k) {
    int M = 1e9;
    vector<int> nums = {1, 1};
    for (int i = 3;; ++i) {
      int num = nums[i - 2] + nums[i - 3];
      if (num > M) break;
      nums.push_back(num);
    }
    // 1 1 2 3 5 8 13 21 34 ...
    printArr(nums);
    cout << "size:" << nums.size() << endl;  // 44
    reverse(nums.begin(), nums.end());

    int n = nums.size();
    int res = 0;
    // define the problem(int i, int k): minimal number of fib-numbers to build k using nums[i..n]
    // say we can include nums[i], but we do not include any amout of it,
    // for every missing nums[i], we must at least use 2 smaller fib-numbers to make up this missing nums[i]
    // meaning 2 + problem(i+1, k-nums[i]) < 1 + problems(i+1, k-nums[i])
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
