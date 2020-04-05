#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numSteps(string s) {
    int i = 0;
    while (s[i] == '0') ++i;
    s = s.substr(i);
    int n = s.length();
    bool c = false;
    int res = 0;
    for (int i = n - 1; i > 0; --i) {
      bool is_one = c ^ (s[i] == '1');
      c = is_one || (c && s[i] == '1');
      if (is_one)
        res += 2;
      else
        res += 1;
    }
    if (c) res += 1;
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string num;
  while (cin >> num) {
    cout << s.numSteps(num) << endl;
  }
  return 0;
}
