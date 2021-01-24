#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

// union find
class Solution {
 private:
  int n;
  vector<int> ids;
  vector<int> szs;
  unordered_map<int, int> factor2idx;
  void U(int p, int q) {
    int pid = F(p), qid = F(q);
    if (pid == qid) return;
    szs[pid] += szs[qid];
    ids[qid] = pid;
  }
  int F(int x) { return x == ids[x] ? x : ids[x] = F(ids[x]); }

 public:
  int largestComponentSize(vector<int>& A) {
    n = A.size();
    ids.resize(n);
    iota(ids.begin(), ids.end(), 0);
    szs.resize(n);
    fill(szs.begin(), szs.end(), 1);
    factor2idx.clear();
    for (int idx = 0; idx < n; ++idx) {
      int x = A[idx];
      // prime factorization
      for (int i = 2; i * i <= x; ++i) {
        if (A[idx] % i == 0) {
          while (x % i == 0) x /= i;
          auto p = factor2idx.emplace(i, idx);
          if (!p.second) {
            U(p.first->second, idx);
          }
        }
      }
      if (x != 1) {
        auto p = factor2idx.emplace(x, idx);
        if (!p.second) {
          U(p.first->second, idx);
        }
      }
    }
    return *max_element(szs.begin(), szs.end());
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> A = {4, 6, 15, 46};   // 4
  A = {20, 50, 9, 63};              // 2
//   A = {2, 3, 6, 7, 4, 12, 21, 39};  // 8
  cout << s.largestComponentSize(A) << endl;
  return 0;
}
