#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int n;
  int len;
  bool dfs(int i, int j, vector<int>& arr, vector<vector<int>>& pieces,
           vector<bool>& vis) {
    int sub_len = pieces[i].size();
    int k = 0;
    for (; k < sub_len && pieces[i][k] == arr[j + k]; ++k)
      ;
    if (k != sub_len) return false;
    if (j + sub_len == len) return true;
    for (int k = 0; k < n; ++k) {
      if (vis[k]) continue;
      vis[k] = true;
      if (dfs(k, j + sub_len, arr, pieces, vis)) return true;
      vis[k] = false;
    }
    return false;
  }

 public:
  bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    len = arr.size();
    n = pieces.size();
    vector<bool> vis(n);
    for (int i = 0; i < n; ++i) {
      vis[i] = true;
      if (dfs(i, 0, arr, pieces, vis)) return true;
      vis[i] = false;
    }
    return false;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> arr = {85};
  vector<vector<int>> pieces = {{85}};
  Solution s;
  cout << s.canFormArray(arr, pieces) << endl;
  return 0;
}
