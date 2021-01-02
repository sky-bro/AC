#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

typedef long long ll;

static vector<vector<int>> dp = []() {
  vector<vector<int>> d(10, vector<int>(11, 1));
  iota(d[1].begin(), d[1].end(), 0);
  for (int i = 2; i < 9; ++i) {
    for (int j = 1; j <= 10; ++j) {
      d[i][j] = j * d[i - 1][j];
    }
  }
  return d;
}();

class Solution {
 private:
  int cnt[10] = {0};
  bool digit[10] = {false};
  void init(vector<string>& digits) {
    for (const string& d : digits) {
      digit[d[0] - '0'] = true;
    }
    cnt[0] = digit[0];
    for (int i = 1; i < 10; ++i) {
      cnt[i] = cnt[i - 1] + digit[i];
    }
  }

 public:
  int atMostNGivenDigitSet(vector<string>& digits, int n) {
    int N = digits.size();
    init(digits);
    string s = to_string(n);
    int len = s.length();
    ll res = 0;
    for (int i = 1; i < len; ++i) {
      res += dp[i - 1][N] * (N - (i != 1 && digit[0]));
    }
    int i = 0;
    for (; i < len; ++i) {
      int idx = s[i] - '0';
      res +=
          (cnt[idx] - digit[idx] - (i == 0 && digit[0])) * dp[len - i - 1][N];
      if (!digit[idx]) {
        break;
      }
    }
    res += (i == len);
    return res;
  }
};

int main(int argc, char const* argv[]) {
  vector<string> digits = {"1", "3", "5", "7"};
  int n = 100;  // 20
  digits = {"1", "4", "9"};
  n = 1000000000;  // 29523
  digits = {"7"};
  n = 8; // 1
  Solution s;
  cout << s.atMostNGivenDigitSet(digits, n) << endl;
  return 0;
}
