#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

class Solution {
 private:
  int n1, n2;
  vector<int> S;

  int sum(int i) {
    int res = 0;
    while (i) {
      res = max(res, S[i]);
      i -= i & -i;
    }
    return res;
  }

  void add(int i, int k) {
    while (i <= n1) {
      S[i] = max(S[i], k);
      i += i & -i;
    }
  }

  /**
   * here elements in A are distinct
   * we can compute the LCS(A, B) in O(nlogn) time
   */
  int LCS(vector<int>& A, vector<int>& B) {
    S.clear();
    S.resize(n1 + 1);
    unordered_map<int, int> mp;
    for (int i = 0; i < n1; ++i) mp[A[i]] = i;
    for (int b : B) {
      if (mp.count(b)) {
        add(mp[b] + 1, sum(mp[b]) + 1);
      }
    }
    return sum(n1);
  }

 public:
  int minOperations(vector<int>& target, vector<int>& arr) {
    n1 = target.size(), n2 = arr.size();
    return n1 - LCS(target, arr);
  }
};