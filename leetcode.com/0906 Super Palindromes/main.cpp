#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

class Solution {
 private:
  bool chk(ull x) {
    string x_s = to_string(x);
    for (int i = 0, j = x_s.length() - 1; i < j; ++i, --j) {
      if (x_s[i] != x_s[j]) return false;
    }
    return true;
  }
  int f(ull x) {
    if (!x) return 0;
    int res = 0;
    for (int i = 1;; ++i) {
      string i_s = to_string(i);
      string num_s = i_s + string(i_s.rbegin() + 1, i_s.rend());
      ull num = stoull(num_s);
      num *= num;
      if (num > x) break;
      if (chk(num)) ++res;
      num_s = i_s + string(i_s.rbegin(), i_s.rend());
      num = stoull(num_s);
      num *= num;
      if (num > x) continue;
      if (chk(num)) ++res;
    }
    return res;
  }

 public:
  int superpalindromesInRange(string L, string R) {
    return f(stoull(R)) - f(stoull(L) - 1);
  }
};

int main(int argc, char const *argv[]) {
  string L, R;
  Solution s;
  while (cin >> L >> R) {
    cout << s.superpalindromesInRange(L, R) << endl;
  }
  return 0;
}
