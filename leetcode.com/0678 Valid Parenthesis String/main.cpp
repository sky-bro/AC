#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int n;
  bool dfs(string &s, int i, int left, vector<vector<bool>> &vis) {
    if (i == n) {
      return left == 0;
    }
    if (vis[i][left]) return false;
    vis[i][left] = true;
    if (s[i] == '(') {
      return dfs(s, i + 1, left + 1, vis);
    } else if (s[i] == ')') {
      if (left && dfs(s, i+1, left - 1, vis)) return true;
    } else {  // "*"
      // "("
      if (dfs(s, i + 1, left + 1, vis)) return true;
      // ")"
      if (left && dfs(s, i + 1, left - 1, vis)) return true;
      // ""
      if (dfs(s, i + 1, left, vis)) return true;
    }
    return false;
  }

 public:
  bool checkValidString(string s) {
    n = s.length();
    vector<vector<bool>> vis(n, vector<bool>(n));
    return dfs(s, 0, 0, vis);
  }
};

int main(int argc, char const *argv[]) {
  string str;
  Solution s;
  while (cin >> str) {
    cout << s.checkValidString(str) << endl;
  }
  return 0;
}
