#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// ref: [C++/Java/Python] O(N) Using Deque
// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/discuss/143726/C%2B%2BJavaPython-O(N)-Using-Deque

class Solution {
 public:
  int shortestSubarray(vector<int>& A, int K) {
    int N = A.size(), res = N + 1;
    deque<int> d;
    for (int i = 0; i < N; i++) {
      if (i > 0) A[i] += A[i - 1];
      if (A[i] >= K) res = min(res, i + 1);
      while (d.size() > 0 && A[i] - A[d.front()] >= K)
        res = min(res, i - d.front()), d.pop_front();
      while (d.size() > 0 && A[i] <= A[d.back()]) d.pop_back();
      d.push_back(i);
    }
    return res <= N ? res : -1;
  }
};
