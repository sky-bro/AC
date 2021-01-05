#include <array>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

class Solution {
 public:
  int sumSubarrayMins(vector<int> &arr) {
    int n = arr.size();
    // if (n == 1) return arr[0];
    ll res = 0;
    stack<array<ll, 3>> stk;
    for (int i = 0; i < n; ++i) {
      array<ll, 3> x = {arr[i], 1, i};
      while (!stk.empty() && stk.top()[0] > arr[i]) {
        auto t = stk.top();
        stk.pop();
        res = (res + t[0] * t[1] * (i - t[2])) % MOD;
        x[1] += t[1];
      }
      stk.push(x);
    }
    while (!stk.empty()) {
      auto &t = stk.top();
      res = (res + t[0] * t[1] * (n - t[2])) % MOD;
      stk.pop();
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> arr = {3, 1, 2, 4};
  // (3, 1, 0)
  // (1, 2, 1) res += 3*1*1 = 3
  // (1, 2, 1), (2, 1, 2)
  // (1, 2, 1), (2, 1, 2), (4, 1, 3)
  // res += 4 * 1 * 1 + 2 * 1 * 2 + 1 * 2 * 3 = 17
  arr = {11, 81, 94, 43, 3};
  cout << s.sumSubarrayMins(arr) << endl;
  return 0;
}
