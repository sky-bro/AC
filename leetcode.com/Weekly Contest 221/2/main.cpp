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
  int eatenApples(vector<int> &apples, vector<int> &days) {
    int n = apples.size();
    int i = 0, res = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    for (; i < n; ++i) {
      if (apples[i]) pq.push(make_pair(i + days[i], apples[i]));
      while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        if (p.first <= i) continue;
        ++res;
        --p.second;
        if (p.second) pq.push(p);
        break;
      }
    }
    while (!pq.empty()) {
      auto p = pq.top();
      pq.pop();
      if (p.first <= i) continue;
      int cur = min(p.second, p.first - i);
      res += cur;
      i += cur;
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> apples = {3, 0, 0, 0, 0, 2}, days = {3, 0, 0, 0, 0, 2};  // 5
  // apples = {1, 2, 3, 5, 2};
  // days = {3, 2, 1, 4, 2}; // 7
  cout << s.eatenApples(apples, days) << endl;
  return 0;
}
