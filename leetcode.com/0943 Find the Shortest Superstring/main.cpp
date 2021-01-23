#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

// cabbb bbbac abbbba
// abbcccc bccccadabbccc eabbc
// aaabaaaaa aaaaab aacc

// dp[12][12][2^12]: l,r,remain -> state (total_len: 8 bits,  (cover_len: 5
// bits,) pre_ending: 4 bits, isleft: 1 bit)
int dp[12][12][4096];
int overlap[12][12];

class Solution {
 private:
  int n, mask;
  vector<string> A;
  void init() {
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int len = min(A[i].size(), A[j].size());
        for (int l = len - 1;; --l) {
          string a = A[i].substr(A[i].size() - l), b = A[j].substr(0, l);
          if (a == b) {
            overlap[i][j] = l;
            dp[i][j][mask ^ ((1 << i) | (1 << j))] =
                ((A[i].size() + A[j].size() - l) << 5) | (i << 1);
            break;
          }
        }
        for (int l = len - 1;; --l) {
          string a = A[i].substr(0, l), b = A[j].substr(A[j].size() - l);
          if (a == b) {
            overlap[j][i] = l;
            dp[j][i][mask ^ ((1 << i) | (1 << j))] =
                ((A[i].size() + A[j].size() - l) << 5) | (j << 1);
            break;
          }
        }
      }
    }
  }
  int dfs(int i, int j, int remain) {
    if (i == j) return A[i].size() << 5;
    if (~dp[i][j][remain]) return dp[i][j][remain];
    // int cnt = 0;
    // best state has least length
    int min_len = 1 << 8;
    int pre_ending;
    bool is_left;
    for (int ii = 0; ii < n; ++ii) {
      if ((remain & (1 << ii)) || i == ii || j == ii) continue;
      //   ++cnt;
      int state = dfs(ii, j, remain | (1 << i));
      int cur_len = (state >> 5) + A[i].size() - overlap[i][ii];
      if (min_len > cur_len) {
        min_len = cur_len;
        pre_ending = ii;
        is_left = true;
      }
      state = dfs(i, ii, remain | (1 << j));
      cur_len = (state >> 5) + A[j].size() - overlap[ii][j];
      if (min_len > cur_len) {
        min_len = cur_len;
        pre_ending = ii;
        is_left = false;
      }
    }
    // if (cnt == 0) return dp[i][j][remain] = A[i].size() + A[j].size() -
    // overlap[i][j];
    return dp[i][j][remain] = ((min_len << 5) | (pre_ending << 1) | is_left);
  }
  string restore_string(int i, int j, int remain) {
    if (i == j) return A[i];
    int state = dp[i][j][remain];
    int ii = (state >> 1) & 15;
    if (state & 1) {  // left
      return A[i].substr(0, A[i].size() - overlap[i][ii]) +
             restore_string(ii, j, remain | (1 << i));
    } else {  // right
      return restore_string(i, ii, remain | (1 << j)) +
             A[j].substr(overlap[ii][j]);
    }
  }

 public:
  string shortestSuperstring(vector<string>& A) {
    n = A.size();
    if (n == 1) return A[0];
    this->A = A;
    memset(dp, -1, sizeof(dp));
    memset(overlap, 0, sizeof(overlap));
    mask = (1 << n) - 1;
    init();
    int ii, jj, mn = 1 << 8;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        int state = dfs(i, j, 0);
        if ((state >> 5) < mn) {
          ii = i;
          jj = j;
          mn = state >> 5;
        }
      }
    }
    // reconstruct res
    return restore_string(ii, jj, 0);
  }
};

int main(int argc, char const* argv[]) {
  vector<string> A = {"alex", "loves", "leetcode"};
  A = {"catg", "ctaagt", "gcta", "ttca", "atgcatc"};
  Solution s;
  cout << s.shortestSuperstring(A) << endl;
  return 0;
}
