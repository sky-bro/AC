#include <iostream>
#include <numeric>
#include <vector>

#include "leetcode.hpp"

using namespace std;

class Solution {
 public:
  vector<int> constructArray(int n, int k) {
    vector<int> res(n);
    iota(res.begin(), res.end(), 1);
    // n = k + x (x is any positive integer), k = 4
    // 1 2 3
    //  5 4

    // k = 10
    // 1  2  3 4 5 6
    //  11 10 9 8 7
    for (int i = 1, num = 2 + k; i <= k; i += 2) res[i] = --num;
    for (int i = 2, num = 1; i <= k; i += 2) res[i] = ++num;
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int n, k;
  while (cin >> n >> k) printArr(s.constructArray(n, k));
  return 0;
}
