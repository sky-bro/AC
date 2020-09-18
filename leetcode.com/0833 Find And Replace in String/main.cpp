#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string findReplaceString(string S, vector<int>& indexes,
                           vector<string>& sources, vector<string>& targets) {
    int n = indexes.size();
    vector<pair<int, int>> tr;
    for (int i = 0; i < n; ++i) {
      tr.emplace_back(indexes[i], i);
    }
    sort(tr.begin(), tr.end());

    int base = 0;
    for (int i = 0; i < n; ++i) {
      int idx = tr[i].first + base;
      int len = 0, LEN = sources[tr[i].second].length();
      if (S.length() - idx < LEN) continue;
      while (len < LEN && S[idx + len] == sources[tr[i].second][len]) ++len;
      if (len == LEN) {
        S.replace(idx, len, targets[tr[i].second]);
        base += targets[tr[i].second].length() - len;
      }
    }
    return S;
  }
};
