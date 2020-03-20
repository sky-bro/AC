#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// ref: [Easy] Algorithm Explanation Step By Step
// https://leetcode.com/problems/random-flip-matrix/discuss/155341/Easy-Algorithm-Explanation-Step-By-Step
class Solution {
 private:
  int n, N, c;
  unordered_map<int, int> m;

 public:
  Solution(int n_rows, int n_cols) : n(n_rows * n_cols), c(n_cols) {
    m.clear();
    N = n;
  }

  vector<int> flip() {
    int r = rand() % n--;
    int i = m.count(r) ? m[r] : r;
    m[r] = m.count(n) ? m[n] : n;
    return {i / c, i % c};
  }

  void reset() {
    m.clear();
    n = N;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */