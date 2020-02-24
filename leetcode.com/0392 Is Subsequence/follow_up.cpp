#include <iostream>
#include <vector>

using namespace std;

// ref: Binary search solution for follow-up with detailed comments (java)
// https://leetcode.com/problems/is-subsequence/discuss/87302/Binary-search-solution-for-follow-up-with-detailed-comments

class Solution {
 public:
  bool isSubsequence(string s, string t) {
    vector<vector<int>> idx(26, vector<int>());
    int m = s.length(), n = t.length();
    for (int i = 0; i < n; ++i) {
      idx[t[i] - 'a'].push_back(i);
    }
    int pre_idx = 0;
    for (int i = 0; i < m; ++i) {
      auto &vi = idx[s[i] - 'a'];
      auto it = lower_bound(vi.begin(), vi.end(), pre_idx);
      if (it == vi.end()) return false;
      pre_idx = (*it) + 1;
    }
    return true;
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  string s = "axc", t = "ahbgdc";
  cout << sol.isSubsequence(s, t) << endl;
  return 0;
}