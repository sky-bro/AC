#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

class Solution {
 private:
  int el, n;
  string s1, s2, evil;

  int dfs(int idx, int is_pre, int cur_el, vector<vector<vector<int>>> &dp,
          vector<int> &tr) {
    if (cur_el == el) return 0;
    if (idx == n) return 1;
    if (~dp[cur_el][idx][is_pre]) return dp[cur_el][idx][is_pre];

    int res = 0;
    int start = (is_pre & 1) ? s1[idx] : 'a';
    int end = (is_pre & 2) ? s2[idx] : 'z';
    for (int i = start; i <= end; ++i) {
      int _is_pre = 0;
      if (i == start && (is_pre & 1)) _is_pre |= 1;
      if (i == end && (is_pre & 2)) _is_pre |= 2;
      int _cur_el = cur_el;
      while (_cur_el && i != evil[_cur_el]) {
        _cur_el = tr[_cur_el - 1];
      }
      if (i == evil[_cur_el]) ++_cur_el;
      res += dfs(idx + 1, _is_pre, _cur_el, dp, tr);
      res %= MOD;
    }
    return dp[cur_el][idx][is_pre] = res;
  }

 public:
  int findGoodStrings(int n, string s1, string s2, string evil) {
    this->n = n;
    this->s1 = s1;
    this->s2 = s2;
    this->evil = evil;
    el = evil.length();

    vector<int> tr(el);
    for (int i = 1, j = 0; i < el; ++i) {
      while (j && evil[i] != evil[j]) j = tr[j - 1];
      if (evil[i] == evil[j]) ++j;
      tr[i] = j;
    }

    vector<vector<vector<int>>> dp(el,
                                   vector<vector<int>>(n, vector<int>(4, -1)));
    return dfs(0, 3, 0, dp, tr);
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int n = 36;
  string s1 = "sngdmqatjfksenidrvprcbefgytikdhypsyk";
  string s2 = "yspvjpkmagzzkgvmlryhxcfrikqlkjtwerdb";
  string evil = "cmzeekdtszmcsrhsciljsrdoidz";
  cout << s.findGoodStrings(2, "aa", "da", "b") << endl;                 // 51
  cout << s.findGoodStrings(8, "leetcode", "leetgoes", "leet") << endl;  // 0
  cout << s.findGoodStrings(2, "gx", "gz", "x") << endl;                 // 2
  cout << s.findGoodStrings(n, s1, s2, evil) << endl;                    // 2
  return 0;
}
