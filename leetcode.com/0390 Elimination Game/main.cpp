#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int _lastRemaining(int n, bool start_from_left) {
    if (n == 1) return 1;
    if (start_from_left) {
      return _lastRemaining(n / 2, false) * 2;
    } else if (n & 1) {  // start from right, n is odd, remove all odd numbers
      return _lastRemaining(n / 2, true) * 2;
    } else {  // start from right, n is even, remove all even numbers
      return _lastRemaining(n / 2, true) * 2 - 1;
    }
  }

 public:
  int lastRemaining(int n) { return _lastRemaining(n, true); }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int n;
  while (cin >> n) {
    cout << s.lastRemaining(n) << endl;
  }
  return 0;
}
