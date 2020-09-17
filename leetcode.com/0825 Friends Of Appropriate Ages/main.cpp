#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numFriendRequests(vector<int>& ages) {
    sort(ages.begin(), ages.end());
    int res = 0;
    for (auto age : ages) {
      auto l = upper_bound(ages.begin(), ages.end(), age / 2 + 7);
      auto r = upper_bound(ages.begin(), ages.end(), age);
      if (r > l) {
        res += distance(l, r) - (age > age / 2 + 7);
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> ages = {16, 16};
  ages = {108, 115, 5, 24, 82};  // 3
  cout << s.numFriendRequests(ages) << endl;
  return 0;
}
