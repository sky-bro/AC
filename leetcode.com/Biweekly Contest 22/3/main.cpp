#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  inline int get_steps(int num) {
    int steps = 0;
    while (num != 1) {
      ++steps;
      if (num & 1)
        num = num * 3 + 1;
      else
        num /= 2;
    }
    return steps;
  }

 public:
  int getKth(int lo, int hi, int k) {
    vector<pair<int, int>> nums;
    nums.reserve(hi - lo + 1);
    for (int i = lo; i <= hi; ++i) {
      nums.emplace_back(get_steps(i), i);
    }

    nth_element(nums.begin(), nums.begin() + k - 1, nums.end());
    return (nums.begin() + k - 1)->second;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int lo, hi, k;
  while (cin >> lo >> hi >> k) {
    cout << s.getKth(lo, hi, k) << endl;
  }
  return 0;
}
