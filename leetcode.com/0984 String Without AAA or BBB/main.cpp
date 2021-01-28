#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string strWithout3a3b(int a, int b) {
    string res, t;
    bool pre_a;
    if (pre_a = (a > b)) {
      t = string(min(a, 2), 'a');
      a -= t.size();
    } else {
      t = string(min(b, 2), 'b');
      b -= t.size();
    }
    res.append(t);
    while (a + b) {
      if (pre_a) {
        t = (b < a) ? "b" : string(min(2, b), 'b');
        b -= t.size();
      } else {
        t = (a < b) ? "a" : string(min(2, a), 'a');
        a -= t.size();
      }
      res.append(t);
      pre_a = !pre_a;
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int a, b;
  while (cin >> a >> b) {
    cout << s.strWithout3a3b(a, b) << endl;
  }
  return 0;
}
