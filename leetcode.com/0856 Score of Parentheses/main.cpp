#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  string s;
  int f(int l, int r) {
    int res = 0;
    for (int j = l + 1; l < r; l = j, j = l + 1) {
      int cnt = 1;
      while (cnt) {
        if (s[j] == '(')
          ++cnt;
        else
          --cnt;
        ++j;
      }
      if (j - l == 2) {
        res += 1;
        l = j;
        continue;
      }
      res += 2 * f(l + 1, j - 1);
      l = j;
    }
    return res;
  }

 public:
  int scoreOfParentheses(string S) {
    s = S;
    return f(0, S.size());
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string str;
  while (cin >> str) {
    cout << s.scoreOfParentheses(str) << endl;
  }
  return 0;
}
