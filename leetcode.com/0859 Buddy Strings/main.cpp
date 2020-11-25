#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool buddyStrings(string A, string B) {
    int cnt[26] = {0};
    int cnt2[26] = {0};
    int n = A.size();
    if (n != B.size()) return false;
    int diff = 0;
    for (int i = 0; i < n; ++i) {
      char a = A[i] - 'a';
      char b = B[i] - 'a';
      cnt[a]++;
      cnt2[b]++;
      if (a != b) ++diff;
    }
    if (diff != 2 && diff != 0) return false;
    bool same = false;
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] > 1) same = true;
      if (cnt[i] != cnt2[i]) return false;
    }
    return diff ? true : same;
  }
};

int main(int argc, char const *argv[]) {
  string A, B;
  Solution s;
  while (cin >> A >> B) {
    cout << s.buddyStrings(A, B) << endl;
  }
  return 0;
}
