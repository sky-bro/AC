#include <iostream>
#include <vector>

using namespace std;

// ref:
// https://leetcode.com/problems/count-the-repetitions/discuss/95398/C%2B%2B-solution-inspired-by-%4070664914-with-organized-explanation
// ref:
// https://leetcode.com/problems/count-the-repetitions/discuss/201674/JavaScript-56ms-O(s1.length-*-s2.length)-Time-and-O(1)-Space
class Solution {
 public:
  int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    int len1 = s1.length(), len2 = s2.length();
    int j = 0, nonMatch = 0, res = 0, perCycle = 0, firstEnd = -1;
    for (int i = 0; i < len1 * n1; ++i) {
      if (s2[j] == s1[i % len1]) {
        ++j;
        nonMatch = 0;
      } else if (++nonMatch >= len1)
        break;
      else
        continue;

      if (j == len2) {
        ++res;
        j = 0;
        if (firstEnd == -1) {
          firstEnd = i;
          perCycle = 0;
        } else {
          ++perCycle;
          int cycleLen = i - firstEnd;
          if (cycleLen % len1) continue;
          int cycles = (len1 * n1 - i - 1) / cycleLen;
          res += cycles * perCycle;
          i += cycles * cycleLen;
        }
      }
    }
    return res / n2;
  }
};

int main(int argc, char const *argv[]) {
  string s1 = "acb", s2 = "ab";
  int n1 = 4, n2 = 2;
  Solution s;
  cout << s.getMaxRepetitions(s1, n1, s2, n2) << endl;
  return 0;
}
