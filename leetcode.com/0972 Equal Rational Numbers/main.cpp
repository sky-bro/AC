#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  double f(string S) {
    auto i = S.find("(");
    if (i != string::npos) {
      string base = S.substr(0, i);
      string rep = S.substr(i + 1, S.length() - i - 2);
      for (int j = 0; j < 20; ++j) base += rep;
      return stod(base);
    }
    return stod(S);
  }

 public:
  bool isRationalEqual(string S, string T) { return f(S) == f(T); }
};
