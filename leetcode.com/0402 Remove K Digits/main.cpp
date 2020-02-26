#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string removeKdigits(string num, int k) {
    int n = num.size();
    if (k == 0) return num;
    if (k == n) return "0";
    char *buf = new char[n + 1];  // buf[0] not used
    int len = 0;                  // starts from idx 1

    for (int i = 0; i < n; ++i) {
      buf[++len] = num[i];
      for (; k > 0 && buf[len - 1] > buf[len]; --len, --k) {
        buf[len - 1] = buf[len];
      }
    }
    ++len;
    len -= k;
    buf[len] = 0;
    int start = 1;
    for (; start < len - 1 && buf[start] == '0'; ++start)
      ;
    string res(buf + start);
    delete[] buf;
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string str;
  int k;
  while (cin >> str >> k) {
    cout << s.removeKdigits(str, k) << endl;
  }
  return 0;
}
