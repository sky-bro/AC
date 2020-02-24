#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    for (; i != s.length() && j != t.length(); ++j) {
      if (s[i] == t[j]) ++i;
    }
    return i == s.length();
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  string s = "axc", t = "ahbgdc";
  cout << sol.isSubsequence(s, t) << endl;
  return 0;
}
