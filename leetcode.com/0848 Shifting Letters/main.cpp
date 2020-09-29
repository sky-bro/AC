#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string shiftingLetters(string S, vector<int>& shifts) {
    int n = S.length();
    for (int i = 0; i < n; ++i) {
      shifts[i] %= 26;
    }
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; ++i) {
      cnt[0] += shifts[i];
      cnt[i + 1] -= shifts[i];
    }
    for (int i = 1; i < n; ++i) {
      cnt[i] = ((cnt[i] + cnt[i - 1]) % 26 + 26) % 26;
    }
    for (int i = 0; i < n; ++i) {
      S[i] = (cnt[i] + (S[i] - 'a')) % 26 + 'a';
    }
    return S;
  }
};
