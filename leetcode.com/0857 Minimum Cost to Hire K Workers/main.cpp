#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
    vector<pair<double, int>> workers;
    int n = quality.size();
    for (int i = 0; i < n; ++i) {
      workers.emplace_back(wage[i] * 1.0 / quality[i], quality[i]);
    }
    sort(workers.begin(), workers.end());
    priority_queue<int> pq;
    int qsum = 0;
    double res = __DBL_MAX__;
    for (int i = 0; i < n; ++i) {
      qsum += workers[i].second;
      pq.push(workers[i].second);
      if (pq.size() > K) {
        qsum -= pq.top();
        pq.pop();
      }
      if (pq.size() == K) {
        res = min(res, qsum * 1.0 * workers[i].first);
      }
    }
    return res;
  }
};
