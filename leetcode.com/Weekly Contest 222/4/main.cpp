#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

// TLE, O(m*n)
// class Solution {
//   int LCS(vector<int>& A, vector<int>& B) {
//     int len1 = A.size(), len2 = B.size();
//     vector<vector<int>> dp(2, vector<int>(len2 + 1));
//     for (int i = 0; i <= len2; i++) dp[0][i] = 0;
//     dp[1][0] = 0;
//     int cur = 1, pre = 0;
//     for (int i = 1; i <= len1; i++) {
//       for (int j = 1; j <= len2; j++) {
//         if (A[i - 1] == B[j - 1])
//           dp[cur][j] = dp[pre][j - 1] + 1;
//         else
//           dp[cur][j] = max(dp[cur][j - 1], dp[pre][j]);
//       }
//       swap(cur, pre);
//     }
//     return dp[pre][len2];
//   }

//  public:
//   int minOperations(vector<int>& target, vector<int>& arr) {
//     return target.size() - LCS(target, arr);
//   }
// };

// reduce LCS to LIS (because one of the array has distinct elements)
class Solution {
 private:
  int n1, n2;
  /**
   * here elements in A are distinct
   * we can compute the LCS(A, B) in O(nlogn) time
   */
  int LCS(vector<int>& A, vector<int>& B) {
    unordered_map<int, int> indexes;
    for (int i = 0; i < n1; ++i) indexes[A[i]] = i;
    vector<int> C;
    for (int b : B) {
      if (indexes.count(b)) {
        int idx = indexes[b];
        auto it = lower_bound(C.begin(), C.end(), idx);
        if (it == C.end())
          C.emplace_back(idx);
        else
          *it = idx;
      }
    }
    return C.size();
  }

 public:
  int minOperations(vector<int>& target, vector<int>& arr) {
    n1 = target.size(), n2 = arr.size();
    return n1 - LCS(target, arr);
  }
};