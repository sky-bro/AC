#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  void get_ab(string &num, int &a, int &b) {
    a = b = 0;

    bool flag = num[0] == '-';
    int i = flag;
    for (; num[i] != '+'; ++i) a = a * 10 + num[i] - '0';
    if (flag) a = -a;

    flag = num[++i] == '-';
    i += flag;
    for (; num[i] != 'i'; ++i) b = b * 10 + num[i] - '0';
    if (flag) b = -b;
  }

 public:
  string complexNumberMultiply(string a, string b) {
    int aa, ab, ba, bb, ca, cb;
    get_ab(a, aa, ab);
    get_ab(b, ba, bb);
    ca = aa * ba - ab * bb;
    cb = aa * bb + ab * ba;
    char buf[16];
    sprintf(buf, "%d+%di", ca, cb);
    return buf;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string a, b;
  while (cin >> a >> b) {
    cout << s.complexNumberMultiply(a, b) << endl;
  }
  return 0;
}
