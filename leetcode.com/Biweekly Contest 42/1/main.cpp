#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

class Solution {
 public:
  int countStudents(vector<int>& students, vector<int>& sandwiches) {
    int a = 0, b = 0;
    for (int x : students) {
      if (x)
        ++a;
      else
        ++b;
    }
    int i = 0, n = sandwiches.size();
    for (; i < n; ++i) {
      if (sandwiches[i] == 1) {
        if (a)
          --a;
        else {
          break;
        }
      } else {
        if (b)
          --b;
        else {
          break;
        }
      }
    }
    return n - i;
  }
};
