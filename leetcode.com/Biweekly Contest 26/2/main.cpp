#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
  }
public:
    vector<string> simplifiedFractions(int n) {
      vector<string> res;
      for (int i = 2; i <= n; ++i) res.push_back("1/"+to_string(i));
        for (int i = 3; i <= n; ++i) {
          for (int j = 2; j < i; ++j) {
            if (gcd(i, j) == 1) {
              res.push_back(to_string(j)+"/"+to_string(i));
            }
          }
        }
        return res;
    }
};
