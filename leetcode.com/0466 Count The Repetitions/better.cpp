#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    for (auto c : s2) {
      // preventive checkings, it could be O(n), but who cares.
      if (s1.find(c) == string::npos) return 0;
    }
    int p1 = 0, p2 = 0, mark = 0;
    while (p1 < s1.length() * n1) {
      char c = s2[p2 % s2.length()];
      while (s1[p1 % s1.length()] != c && p1 < s1.length() * n1) p1++;
      p2++;
      p1++;
      // optimization part below
      if (p2 % s2.length() == 0) {
        if (p2 == s2.length()) {
          mark = p1;  // mark the position in s1, when the first s2 ends
        } else if (p1 % s1.length() == mark % s1.length()) {
          // s1 reaches the same position, which means the repeating cycle
          // found.
          // Then we can leap forward.
          int round = (s1.length() * n1 - p1) / (p1 - mark);
          p1 += round * (p1 - mark);
          p2 += round * (p2 - s2.length());
        }
      }
    }
    return p2 / s2.length() / n2;
  }
};

int main(int argc, char const *argv[]) {
  string s1 = "acb", s2 = "ab";
  int n1 = 4, n2 = 2;
  Solution s;
  cout << s.getMaxRepetitions(s1, n1, s2, n2) << endl;
  return 0;
}
