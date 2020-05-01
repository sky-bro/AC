#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<string> res;
  int n;
  void dfs(string &S, int i) {
    if (n == i) {
      res.push_back(S);
      return;
    }
    dfs(S, i+1);
    if (S[i] <= 'Z' && S[i] >= 'A') {
      S[i] += 'a' - 'A';
      dfs(S, i+1);
      S[i] -= 'a' - 'A';
    } else if (S[i] <= 'z' && S[i] >= 'a') {
      S[i] -= 'a' - 'A';
      dfs(S, i+1);
      S[i] += 'a' - 'A';
    }
  }

 public:
  vector<string> letterCasePermutation(string S) {
    res.clear();
    n = S.length();
    dfs(S, 0);
    return res;
  }
};
