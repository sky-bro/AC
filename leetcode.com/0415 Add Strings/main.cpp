#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string addStrings(string num1, string num2) {
    int m = num1.size(), n = num2.size();
    if (m > n) return addStrings(num2, num1);
    string res = "";
    bool carry = false;
    int digit;
    int i = 0;
    for (; i < m; ++i) {
      digit = carry + num1[m - 1 - i] - '0' + num2[n - 1 - i] - '0';
      carry = digit >= 10;
      digit %= 10;
      res.push_back('0' + digit);
    }
    for (; i < n; ++i) {
      digit = carry + num2[n - 1 - i] - '0';
      carry = digit >= 10;
      digit %= 10;
      res.push_back('0' + digit);
    }
    if (carry) res.push_back('1');
    reverse(res.begin(), res.end());
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string num1, num2;
  num1 = "3238475293472323497529345";
  num2 = "34259347529384579273495872398475293";
  cout << s.addStrings(num1, num2) << endl;
  while (cin >> num1 >> num2) {
    cout << s.addStrings(num1, num2) << endl;
  }
  return 0;
}
