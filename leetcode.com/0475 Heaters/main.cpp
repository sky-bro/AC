#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 private:
  int m, n;
  bool checkValidity(vector<int>& houses, vector<int>& heaters, int radius) {
    int i = 0, j = 0;
    for (; j < n; ++j) {
      while (i < m && heaters[j] + radius >= houses[i] &&
             heaters[j] - radius <= houses[i])
        ++i;
      if (i == m) return true;
      if (houses[i] < heaters[j] - radius) return false;
    }
    return false;
  }

 public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    m = houses.size();
    n = heaters.size();
    if (m == 0) return 0;
    if (n == 0) return -1;  // won't happen?
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    int lo = 0,
        hi = max(houses[m - 1] - heaters[0], heaters[n - 1] - houses[0]);
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (checkValidity(houses, heaters, mid))
        hi = mid;
      else
        lo = mid + 1;
    }
    return lo;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> houses = {4, 3, 2, 1};
  vector<int> heaters = {1, 4};
  houses = {1, 5};
  heaters = {2};
  cout << s.findRadius(houses, heaters) << endl;
  return 0;
}
