#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// ref: [Python] Robber n/3 Houses in Cycle
// https://leetcode.com/problems/pizza-with-3n-slices/discuss/546474/Python-Robber-n3-Houses-in-Cycle
class Solution {
 private:
  int dfs(vector<int>& slices, int r, int k, vector<vector<int>>& dp) {
    if (k == 1) return *max_element(slices.begin(), slices.begin() + r + 1);
    if (r + 1 < 2 * k - 1) return 0;
    if (dp[k - 1][r]) return dp[k - 1][r];
    return dp[k - 1][r] = max(dfs(slices, r - 1, k, dp),
                              dfs(slices, r - 2, k - 1, dp) + slices[r]);
  }
  int dfs2(vector<int>& slices, int r, int k, vector<vector<int>>& dp2) {
    if (k == 1) return *max_element(slices.begin() + 1, slices.begin() + r + 1);
    if (r < 2 * k - 1) return 0;
    if (dp2[k - 1][r]) return dp2[k - 1][r];
    return dp2[k - 1][r] = max(dfs2(slices, r - 1, k, dp2),
                               dfs2(slices, r - 2, k - 1, dp2) + slices[r]);
  }

 public:
  int maxSizeSlices(vector<int>& slices) {
    int N = slices.size(), K = N / 3;
    if (N == 3) return *max_element(slices.begin(), slices.end());
    // [0..N-2] ignore last
    vector<vector<int>> dp(K, vector<int>(N));
    // [1..N-3] include last
    vector<vector<int>> dp2(K, vector<int>(N));
    return max(dfs(slices, N - 2, K, dp),
               dfs2(slices, N - 3, K - 1, dp2) + slices[N - 1]);
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> slices = {1, 2, 3, 4, 5, 6};
  cout << s.maxSizeSlices(slices) << endl;  // 10
  slices = {9, 8, 1, 7, 7, 9, 5, 10, 7, 9, 3, 8, 3, 4, 8};
  cout << s.maxSizeSlices(slices) << endl;  // 45
  slices = {7, 8, 5, 6, 9,  10, 1, 6, 5, 10, 8,  10, 5, 4,  7,  2, 8,
            5, 9, 7, 5, 9,  3,  7, 7, 2, 2,  10, 7,  6, 4,  6,  5, 7,
            7, 9, 6, 8, 10, 7,  5, 7, 2, 5,  4,  9,  6, 10, 10, 2, 10};
  cout << s.maxSizeSlices(slices) << endl;  //
  slices = {1, 2, 3, 4, 5, 6};
  cout << s.maxSizeSlices(slices) << endl;  //
  slices = {8, 9, 8, 6, 1, 1};
  cout << s.maxSizeSlices(slices) << endl;  //
  slices = {4, 1, 2, 5, 8, 3, 1, 9, 7};
  cout << s.maxSizeSlices(slices) << endl;  //
  slices = {3, 1, 2};
  cout << s.maxSizeSlices(slices) << endl;  //
  return 0;
}
