#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n);
        vector<queue<int>> vq(101);
        for (int i = 0; i < n; ++i) {
          vq[T[i]].push(i);
        }
        for (int i = 0; i < n; ++i) {
          int idx = INT32_MAX;
          for (int j = T[i] + 1; j <= 100; ++j) {
            if (vq[j].empty()) continue;
            idx = min(idx, vq[j].front());
          }
          res[i] = idx == INT32_MAX ? 0 : idx - i;
          vq[T[i]].pop();
        }
        return res;
    }
};
