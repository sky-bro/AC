#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> closestDivisors(int num) {
    vector<int> res(2);
    res[0] = res[1] = sqrt(num + 2);
    long long product = res[0] * res[1];
    while (product <= num || product > num + 2) {
      if (product <= num)
        ++res[1];
      else
        --res[0];
      product = res[0] * res[1];
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  int num;
  Solution s;
  while (cin >> num) {
    auto p = s.closestDivisors(num);
    cout << p[0] << " " << p[1] << endl;
  }
  return 0;
}
