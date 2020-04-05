#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  char chars[3] = {'a', 'b', 'c'};
  void sort3(int cnt[3], int &first, int &second) {
    int idx[3] = {0, 1, 2};
    sort(idx, idx + 3, [&](int a, int b) { return cnt[a] > cnt[b]; });
    first = idx[0];
    second = idx[1];
  }

 public:
  string longestDiverseString(int a, int b, int c) {
    int cnt[3] = {a, b, c};
    int total = a + b + c;
    int first, second;
    int pre = -1;

    string res = "";
    while (total) {
      sort3(cnt, first, second);
      if (first == pre) {
        if (cnt[second]) {
          res.push_back(chars[second]);
          cnt[second]--;
          pre = second;
          --total;
        } else
          break;
      } else {
        pre = first;
        res.push_back(chars[first]);
        --total;
        cnt[first]--;
        if (cnt[first]) {
          --total;
          cnt[first]--;
          res.push_back(chars[first]);
        }
      }
    }
    return res;
  }
};