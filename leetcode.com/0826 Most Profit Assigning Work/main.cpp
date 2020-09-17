#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
   * @param difficulty difficulty of jobs
   * @param profit profit of jobs
   * @param worker max difficulty of jobs workers can take
   * @returns max profits can achieve with each worker taking at most one job, a
   * job can be taken multiple times
   */
  int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                          vector<int>& worker) {
    int res = 0;
    int nW = worker.size(), nJ = difficulty.size();
    vector<pair<int, int>> jobs;  // (profit, difficult)
    for (int i = 0; i < nJ; ++i) jobs.emplace_back(profit[i], difficulty[i]);
    sort(jobs.rbegin(), jobs.rend());      // profit decreasing order
    sort(worker.rbegin(), worker.rend());  // worker ability decreasing order
    int i = 0;
    for (int w : worker) {
      while (i < nJ && jobs[i].second > w) ++i;
      if (i < nJ)
        res += jobs[i].first;
      else
        break;
    }
    return res;
  }
};
