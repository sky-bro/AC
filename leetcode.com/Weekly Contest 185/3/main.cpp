#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minNumberOfFrogs(string croakOfFrogs) {
    int mp[128]{};
    int res = 0;
    for (char c : croakOfFrogs) {
      switch (c) {
        case 'c':
          if (mp['k']) --mp['k'];
          else ++res;
          ++mp['c'];
          break;
        case 'r':
          if (mp['c']-- == 0) return -1;
          ++mp['r'];
          break;
        case 'o':
          if (mp['r']-- == 0) return -1;
          ++mp['o'];
          break;
        case 'a':
          if (mp['o']-- == 0) return -1;
          ++mp['a'];
          break;
        case 'k':
          if (mp['a']-- == 0) return -1;
          ++mp['k'];
          break;
      }
    }

    return res == mp['k'] ? res : -1;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string str;
  while (cin >> str) {
    cout << s.minNumberOfFrogs(str) << endl;
  }
  return 0;
}
