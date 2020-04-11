#include <iostream>
#include <vector>

#include "leetcode.hpp"

using namespace std;

// this is a math problem
// need to analyse/simplify different cases
class Solution {
 private:
  // lights are numbered from right to left: 3..1
  // 1 means the swither can flip that light
  vector<int> switchers = {0b111, 0b010, 0b101, 0b001};
  int cnt_bits(int x) {
    int res = 0;
    while (x) {
      res += x & 1;
      x >>= 1;
    }
    return res;
  }

 public:
  // n and m both fit in range [0, 1000].
  int flipLights(int n, int m) {
    if (m == 0 || n == 0) return 1;
    // allocate m to four switchers/plates (only need to know the number is even
    // or odd) [0, 2**4) 0 0 0 0 ~ 1 1 1 1 printArr(switchers);

    // for n, only need to consider n <= 3 
    int lights = 0b111;
    // if n less than 3, just consider n lights
    if (n < 3) lights = (1 << n) - 1;
    // if can reach status i (lights = i), statuses[i] = true
    vector<bool> statuses(lights + 1);
    for (int i = 0; i < 16; ++i) {
      int bit_cnt = cnt_bits(i);
      if (bit_cnt > m || (m - bit_cnt) & 1) continue;
      int switcher = 0;
      // total four switchers, combine the switches (which will be used odd
      // times)
      for (int j = 0; j < 4; ++j) {
        if ((1 << j) & i) switcher ^= switchers[j];
      }
      // flip lights use the combined swither, set the lights' status to true
      statuses[(lights ^ switcher) & lights] = true;
    }

    int res = 0;
    for (bool status : statuses) {
      res += status;
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  int m, n;
  Solution s;
  while (cin >> n >> m) {
    cout << s.flipLights(n, m) << endl;
  }
  return 0;
}
