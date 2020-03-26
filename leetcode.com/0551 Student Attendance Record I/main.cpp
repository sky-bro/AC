#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool checkRecord(string s) {
    int cnt_A = 0, pre_L = 0;
    for (char c : s) {
      if (c == 'L') {
        if (++pre_L > 2) return false;
      } else {
        pre_L = 0;
        if (c == 'A' && cnt_A++) return false;
      }
    }
    return true;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string str;
  while (cin >> str) {
    cout << s.checkRecord(str) << endl;
  }
  return 0;
}
