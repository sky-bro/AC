#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#include "leetcode.hpp"

using namespace std;

// ref: problem 56. merge intervals
// https://leetcode.com/problems/merge-intervals/

class Solution {
 public:
  vector<int> partitionLabels(string S) {
    vector<pair<int, int>> m(26, {-1, -1});
    int n = S.length();
    for (int i = 0; i < n; ++i) {
      int c = S[i] - 'a';
      if (~m[c].first) {
        m[c].second = i;
      } else {
        m[c].first = m[c].second = i;
      }
    }
    vector<int> res;
    // merge intervals
    vector<pair<int, int>> m2;
    sort(m.begin(), m.end());
    int i = 0, j = 0;
    while (m[i].first == -1) ++i;
    m2.push_back(m[i++]);
    for (; i < 26; ++i) {
      if (m[i].first <= m2[j].second) {
        if (m[i].second > m2[j].second) {
          m2[j].second = m[i].second;
        }
      } else {
        m2.push_back(m[i]);
        ++j;
      }
    }
    for (auto &p : m2) {
      res.push_back(p.second - p.first + 1);
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string S;
  while (cin >> S) {
    printArr(s.partitionLabels(S));
  }
  return 0;
}
