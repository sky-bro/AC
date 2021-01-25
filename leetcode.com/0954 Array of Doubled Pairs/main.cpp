#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int N = 100000;
int cnts[300010];
class Solution {
 public:
  bool canReorderDoubled(vector<int>& arr) {
    memset(cnts, 0, sizeof(cnts));
    for (int num : arr) ++cnts[num + N];
    for (int i = 0; i <= 2 * N; ++i) {
      if (!cnts[i]) continue;
      int num = i - N;
      if (num < 0) {
        if (num & 1) return false;
        if ((cnts[num / 2 + N] -= cnts[i]) < 0) return false;
      } else if (num == 0) {
        if (cnts[i] & 1) return false;
      } else {  // num > 0
        if ((cnts[num * 2 + N] -= cnts[i]) < 0) return false;
      }
    }
    return true;
  }
};
