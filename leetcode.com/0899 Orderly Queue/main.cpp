#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int n;
  string f1(string &S) {
    int I = 0;
    for (int i = 1; i < n; ++i) {
      bool ok = true;
      for (int j = 0; j < n; ++j) {
        if (S[(i + j) % n] == S[(I + j) % n])
          continue;
        else if (S[(i + j) % n] > S[(I + j) % n]) {
          ok = false;
          break;
        } else
          break;
      }
      if (ok) I = i;
    }
    return S.substr(I) + S.substr(0, I);
  }
  string f2(string &S) {
    int cnt[26]{};
    for (char c : S) cnt[c - 'a']++;
    string res;
    for (int i = 0; i < 26; ++i) {
      res.append(cnt[i], i + 'a');
    }
    return res;
  }

 public:
  string orderlyQueue(string S, int K) {
    n = S.length();
    if (K == 1) return f1(S);
    return f2(S);
  }
};
