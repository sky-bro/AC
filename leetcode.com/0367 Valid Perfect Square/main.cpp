#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isPerfectSquare(int num) {
    int l = 0, r = num;
    while (l <= r) {
      long long mid = l + (r - l) / 2;
      long long tmp = mid * mid;
      if (tmp < num) {
        l = mid + 1;
      } else if (tmp > num) {
        r = mid - 1;
      } else {
        return true;
      }
    }
    return false;
  }
};

int main(int argc, char const *argv[]) {
  int num;
  Solution s;
  while (cin >> num) {
    cout << s.isPerfectSquare(num) << endl;
  }
  return 0;
}
