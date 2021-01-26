#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxTurbulenceSize(vector<int>& arr) {
    int l = 0, n = arr.size(), res = 1;
    if (n == 1) return 1;
    bool inc_odd = 0;  // increase at odd
    for (int i = 1; i < n; ++i) {
      if (arr[i] < arr[i - 1] && !(inc_odd ^ bool(i & 1))) {
        res = max(i - l + 1, res);
      } else if (arr[i] > arr[i - 1] && (inc_odd ^ bool(i & 1))) {
        res = max(i - l + 1, res);
      } else {
        if (arr[i] == arr[i - 1])
          l = i;
        else {
          res = max(2, res);
          l = i - 1;
          inc_odd = !(bool(i & 1) ^ (arr[i] < arr[i - 1]));
        }
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> arr = {9, 4, 2, 10, 7, 8, 8, 1, 9};
  cout << s.maxTurbulenceSize(arr) << endl;

  return 0;
}
