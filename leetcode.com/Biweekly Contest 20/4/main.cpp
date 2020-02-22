#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int MOD = 1e9 + 7;
  // sum from 1 to n
  inline int get_sum(int n) { return (n + 1) * n / 2; }

 public:
  int countOrders(int n) {
    if (n == 1) return 1;
    long long res = 1;
    int cnt = 2;
    for (int i = 2; i <= n; ++i) {
      int cur_sum = get_sum(cnt + 1);
      res *= cur_sum;
      res %= MOD;
      cnt += 2;
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int n;
  while (cin >> n) {
    cout << s.countOrders(n) << endl;
  }

  return 0;
}
