#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  int findMaximizedCapital(int k, int W, vector<int>& Profits,
                           vector<int>& Capital) {
    int res = W, n = Profits.size();
    priority_queue<int> pq;
    multiset<pair<int, int>> projects;
    for (int i = 0; i < n; ++i) projects.emplace(Capital[i], Profits[i]);
    auto it = projects.begin();
    for (int i = 0; i < k; ++i) {
      while (it != projects.end() && it->first <= res) pq.push(it++->second);
      if (pq.empty()) break;
      res += pq.top();
      pq.pop();
    }
    return res;
  }
};