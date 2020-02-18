#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  static const int MOD = 1337;
  /**
   * x < MOD
   */
  int pow_n(int x, int n) {
    int res = 1;
    for (int i = 0; i < n; ++i) {
      res *= x;
      res %= MOD;
    }
    return res;
  }

 public:
  int superPow(int a, vector<int>& b) {
    int res = 1;
    a %= MOD;
    int x = a;
    int len = b.size();
    for (int i = len - 1; i >= 0; --i) {
      if (b[i]) {
        res *= pow_n(x, b[i]);
        res %= MOD;
      }
      x = pow_n(x, 10);
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  int a = 2;
  vector<int> b = {1, 0};
  cout << s.superPow(a, b) << endl;
  return 0;
}
