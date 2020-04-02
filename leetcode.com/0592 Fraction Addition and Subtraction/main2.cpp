#include <cctype>
#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
 public:
  string fractionAddition(string expression) {
    istringstream in(expression);
    int A = 0, B = 1, a, b;
    char _;
    while (in >> a >> _ >> b) {
      A = A * b + a * B;
      B *= b;
      // use c++17, has gcd
      // clang++ -g main2.cpp -o main -fsanitize=address,undefined -std=c++17
      int g = abs(gcd(A, B));
      A /= g;
      B /= g;
    }
    return to_string(A) + '/' + to_string(B);
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string str;
  while (cin >> str) {
    cout << s.fractionAddition(str) << endl;
  }
  return 0;
}
