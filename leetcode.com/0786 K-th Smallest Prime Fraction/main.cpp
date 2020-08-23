#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// TLE

class Solution {
 public:
  vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
    int N = A.size();
    auto cmp = [&A](const pair<int, int>& a, const pair<int, int>& b) {
      return A[a.first] * A[b.second] > A[b.first] * A[a.second];
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(
        cmp);
    for (int i = N - 1; i >= 1; --i) {
      // pq.push({0, i});
      pq.emplace(0, i);
    }
    pair<int, int> cur;
    while (K--) {
      cur = pq.top();
      pq.pop();
      if (cur.first + 1 < cur.second) {
        // if (A[cur.first] < A[cur.second]) {  // in case A[i] == A[j]
        pq.emplace(cur.first + 1, cur.second);
        // }
      }
    }
    return {A[cur.first], A[cur.second]};
  }
};
