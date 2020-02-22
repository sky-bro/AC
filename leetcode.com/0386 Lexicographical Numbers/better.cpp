#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> lexicalOrder(int n) {
    vector<int> res(n);
    int cur = 1;
    for (int i = 0; i < n; i++) {
      res[i] = cur;
      if (cur * 10 <= n) {
        cur *= 10;
      } else {
        if (cur == n) cur /= 10;
        // if (cur >= n) cur /= 10;
        cur += 1;
        while (cur % 10 == 0) cur /= 10;
      }
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int n = 30;
  s.lexicalOrder(n);
  return 0;
}
