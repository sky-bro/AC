#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 private:
  int n;
  int dfs(const string &s, int i, unordered_set<string> &words) {
    if (i == n) return 0;
    int res = -1;
    for (int len = 1; len + i <= n; ++len) {
      string word = s.substr(i, len);
      if (words.count(word)) continue;
      words.insert(word);
      int sub_res = dfs(s, i + len, words);
      if (~sub_res) {
        res = max(res, 1 + sub_res);
      }
      words.erase(word);
    }
    return res;
  }

 public:
  int maxUniqueSplit(string s) {
    n = s.length();
    unordered_set<string> words;
    return dfs(s, 0, words);
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string str;
  while (cin >> str) {
    cout << s.maxUniqueSplit(str) << endl;
  }
  // cout << -4 % 3 << endl;
  return 0;
}
