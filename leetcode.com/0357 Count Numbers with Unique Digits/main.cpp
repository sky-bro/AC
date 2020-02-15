#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int countNumbersWithUniqueDigits(int n) {
    if (n > 10) n = 10;
    int total_sum = 0;
    while (n) {
      long long cur_sum = 1;
      for (int i = 10; i > 10 - n; --i) {
        cur_sum *= i;
      }
      total_sum += cur_sum / 10 * 9;
      --n;
    }
    return total_sum + 1;
  }
};

int main(int argc, char const *argv[]) {
  int n;
  Solution s;
  while (cin >> n) {
    cout << s.countNumbersWithUniqueDigits(n) << endl;
  }
  return 0;
}
