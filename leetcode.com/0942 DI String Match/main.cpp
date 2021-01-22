#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int N;

 public:
  vector<int> diStringMatch(string S) {
    N = S.size();
    int hi = N, lo = 0;
    vector<int> res(N + 1);
    int i = 0;
    for (char c : S) {
      if (c == 'I')
        res[i++] = lo++;
      else
        res[i++] = hi--;
    }
    res[i] = hi;
    return res;
  }
};
