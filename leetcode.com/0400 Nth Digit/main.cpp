#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findNthDigit(int n) {
    int start = 1;
    int i = 1;
    for (long long cnt = 9; n > i * cnt; cnt *= 10) {
      n -= i++ * cnt;
      start *= 10;
    }
    int num = (n - 1) / i + start;
    for (int j = n % i ? n % i : i; j != i; ++j, num /= 10)
      ;
    return num % 10;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int n;
  while (cin >> n) {
    cout << s.findNthDigit(n) << endl;
  }
  return 0;
}
