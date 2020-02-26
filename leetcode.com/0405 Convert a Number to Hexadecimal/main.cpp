#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  char mp[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                 '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

 public:
  string toHex(int num) {
    if (num == 0) return "0";
    unsigned n = num;
    string res = "";
    while (n) {
      res.push_back(mp[n % 16]);
      n /= 16;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int num;
  char buf[10];
  while (cin >> num) {
    cout << s.toHex(num);
    sprintf(buf, "%x", num);
    cout << " " << buf << endl;
  }
  return 0;
}
