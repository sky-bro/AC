#include <iostream>
#include <vector>

using namespace std;

// idea is record the possible number of unmatched '(' (lower bound and upper
// bound) each loop, if lower bound < 0, icrease it to 0 (number left
// parenthesis must not be negtive at index) if upper bound is negative, this
// string must not be valid
class Solution {
 public:
  bool checkValidString(string s) {
    int lo = 0, hi = 0;
    for (char c : s) {
      lo += c == '(' ? 1 : -1;  // meet '(', lo += 1, or lo -= 1 (lo is the
                                // least possible number of '(')
      hi += c != ')' ? 1 : -1;  // meet ')', unmatched '(' - 1
      if (hi < 0) return false;
      lo = max(lo, 0);
    }
    return lo == 0;
  }
};

int main(int argc, char const *argv[]) {
  string str;
  Solution s;
  while (cin >> str) {
    cout << s.checkValidString(str) << endl;
  }
  return 0;
}
