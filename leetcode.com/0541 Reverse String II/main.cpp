#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string reverseStr(string s, int k) {
    if (k <= 1) return s;
    int n = s.length();
    string res = "";
    res.reserve(n);
    for (int i = 0; i < n; i += 2 * k) {
      for (int j = min(i + k - 1, n - 1); j >= i; --j) res.push_back(s[j]);
      for (int rb = min(n, i + 2 * k), j = i + k; j < rb; ++j)
        res.push_back(s[j]);
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string str;
  int k;
  while (cin >> str >> k) {
    cout << s.reverseStr(str, k) << endl;
  }
  return 0;
}
