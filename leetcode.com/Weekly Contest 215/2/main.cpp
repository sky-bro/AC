#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool closeStrings(string word1, string word2) {
    int n1 = word1.length();
    if (n1 != word2.length()) return false;
    int cnt1[26]{0};
    int cnt2[26]{0};
    vector<int> a, b;
    for (int i = 0; i < n1; ++i) {
      cnt1[word1[i] - 'a']++;
      cnt2[word2[i] - 'a']++;
    }
    for (int i = 0; i < 26; ++i) {
      a.push_back(cnt1[i]);
      b.push_back(cnt2[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < 26; ++i) {
      if ((!cnt1[i]) ^ (!cnt2[i])) return false;
    }
    return a == b;
  }
};
