#include <cstring>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int d[1010][1010];

class Solution {
 private:
  int n;
  unordered_map<int, int> mp;
  int dfs(int i, int j, vector<int>& A) {
    if (~d[i][j]) return d[i][j];
    auto it = mp.find(A[i] + A[j]);
    if (it == mp.end()) return 0;
    int k = it->second;
    return d[i][j] = 1 + dfs(j, k, A);
  }

 public:
  int lenLongestFibSubseq(vector<int>& A) {
    mp.clear();
    n = A.size();
    for (int i = 0; i < n; ++i) mp[A[i]] = i;
    memset(d, -1, sizeof(d));
    int res = 0;
    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        res = max(res, dfs(i, j, A));
      }
    }
    return res ? res + 2 : 0;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
  cout << s.lenLongestFibSubseq(nums) << endl;
  return 0;
}
