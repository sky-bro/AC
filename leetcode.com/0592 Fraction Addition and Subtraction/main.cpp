#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
//  in c++17, #include <numeric>, has gcd and lcm
//  https://en.cppreference.com/w/cpp/numeric/gcd

  int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
  }
  int lcm(int a, int b) {
    if (a < b) swap(a, b);
    return a / gcd(a, b) * b;
  }
  void add(int &a, int &b, int c, int d) {
    // compute: b/a + d/c = (x+y)/lcm(a,c)
    // 1. 通分
    int _lcm = lcm(a, c);
    b *= _lcm / a;
    d *= _lcm / c;
    // 2. 相加（减，如果d < 0）
    b += d;
    a = _lcm;
    // 3. 约分
    int _gcd = gcd(a, b < 0 ? -b : b);
    a /= _gcd;
    b /= _gcd;
  }

 public:
  string fractionAddition(string expression) {
    int n = expression.size();
    // cur_res = b/a
    int b = 0, a = 1;
    for (int i = 0; i < n;) {
      // read & add a fraction number each time
      int c = 0, d = 0;
      bool neg = false;
      if (expression[i] == '-') {
        neg = true;
        ++i;
      } else if (expression[i] == '+') {
        ++i;
      }
      while (expression[i] != '/') {
        d = d * 10 + (expression[i++] - '0');
      }
      ++i;
      while (i < n && isdigit(expression[i])) {
        c = c * 10 + (expression[i++] - '0');
      }
      add(a, b, c, neg ? -d : d);
    }
    return to_string(b) + "/" + to_string(a);
  }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str;
    while (cin>>str) {
        cout<<s.fractionAddition(str)<<endl;
    }
    return 0;
}
