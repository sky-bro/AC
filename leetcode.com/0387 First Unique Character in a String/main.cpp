#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int firstUniqChar(string s) {
    // -1: not seen yet
    // -2: seen more than once
    // other: index of the char which has only been seen once
    vector<int> indexes(26, -1);
    int n = s.length();
    for (int i = 0; i < n; ++i) {
      int ii = s[i] - 'a';
      if (indexes[ii] == -1) {
        indexes[ii] = i;
      } else if (indexes[ii] != -2) {
        indexes[ii] = -2;
      }
    }
    int res = n;
    for (int idx : indexes) {
      if (idx >= 0) res = min(res, idx);
    }
    return res == n ? -1 : res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string str;
  while (cin >> str) {
    cout << s.firstUniqChar(str) << endl;
  }

  return 0;
}
